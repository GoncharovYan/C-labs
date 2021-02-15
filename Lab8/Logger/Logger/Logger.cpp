#include "Logger.h"

void Logger::write(std::string message)
{
	std::cout << "###" << message << std::endl;
}