#include <iostream>
#include <C:\Lib\asio-1.16.1\include\asio.hpp>

using asio::ip::udp;

void U32ToU8(unsigned int x, unsigned char* buf, int offset)
{
	buf[offset] = x >> 24;
	buf[offset + 1] = (x >> 16) && 0xFF;
	buf[offset + 2] = (x >> 8) && 0xFF;
	buf[offset + 3] = x & 0xFF;
}
unsigned int U8ToU32(unsigned char* buf, int offset)
{
	return(buf[offset] << 24) | (buf[offset + 1] << 16) | (buf[offset + 2] << 8) | (buf[offset + 3]);
}
union RealToBytes
{
	float f;
	double d;
	unsigned char b[8];
};

void DoubletToU8(double x, unsigned char* buf, int offset)
{
	RealToBytes u;
	u.f = x;
	for (int i = 0; i < 4; i++)
		buf[offset + i] = u.b[i];
}
double U8ToDouble(unsigned char* buf, int offset)
{
	RealToBytes u;
	for (int i = 0; i < 4; i++)
		u.b[i] = buf[offset + i];
	return u.f;
}

unsigned char CRCSum(unsigned char* buf)
{
	unsigned int sum = 0;
	for (int i = 0; i < 8; i++)
		sum += buf[i];
	unsigned char CRC = 255 - (sum % 256);
	return CRC;
}

void server(asio::io_context& io_context, unsigned short port)
{
	udp::socket sock(io_context, udp::endpoint(udp::v4(), port));
	for (;;)
	{
		unsigned char data[100] = { 0 };
		udp::endpoint sender_endpoint;
		size_t length = sock.receive_from(asio::buffer(data, 100), sender_endpoint);
		unsigned char CRC_Sum_server = CRCSum(data);
		unsigned char CRC_Sum_from_client = data[8];
		if (CRC_Sum_server == CRC_Sum_from_client)
		{
			int x = U8ToU32(data, 0);
			double y = U8ToDouble(data, 4);
			std::cout << x << " " << y << std::endl;
		}
		else
			std::cout << "Error" << std::endl;
	}
}

int main()
{
	try
	{
		asio::io_context io_context;
		server(io_context, 7000);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}