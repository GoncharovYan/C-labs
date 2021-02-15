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

void DoubleToU8(double x, unsigned char* buf, int offset)
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

int main()
{
	for (;;)
	{
		try
		{
			asio::io_context io_context;
			udp::socket s(io_context, udp::endpoint(udp::v4(), 0));
			udp::resolver resolver(io_context);
			udp::resolver::results_type endpoints = resolver.resolve(udp::v4(), "127.0.0.1", "7000");
			unsigned char request[100] = { 0 };
			std::cout << "Enter your message: \n";
			int x;
			double y;
			std::cin >> x >> y;
			U32ToU8(x, request, 0);
			DoubleToU8(y, request, 4);
			request[8] = CRCSum(request);
			s.send_to(asio::buffer(request, 100), *endpoints.begin());
			char reply[100];
			udp::endpoint sender_endpoint;
			size_t lenght = s.receive_from(asio::buffer(reply, 10), sender_endpoint);
			std::cout << reply << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}