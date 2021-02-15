#include <iostream> 
#include <ctime>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <fstream> 
 
#include <yaml-cpp/yaml.h> 

using namespace std; 


char* Read(const char* file)  
{  
	FILE* fd = fopen(file, "r");
	long h;
	if (fd == NULL) {   return 0;  }  
	else
	{   
		fseek(fd, 0, SEEK_END);
		h = ftell(fd);
	}  
	char* File = (char*)malloc(h + 1);
	fseek(fd, 0, SEEK_SET);
	fread(File, h, 1, fd);
	File[h] = 0;  fclose(fd);
	return File;
} 

int main() 
{
	time_t Sec = time(NULL);
	tm* TInfo = localtime(&Sec);  
	string ct = asctime(TInfo);

	cin.get();
	char* WayTo = new char[128];

	scanf("%s", WayTo);
	char* c = (Read(WayTo));

	YAML::Node config = YAML::LoadFile("config.yaml");
	std::string time = config["time"].as<std::string>();
	cout << time;

	config["time"] = ct;
	std::ofstream fout("config.yaml");
	fout << config;
	
	return 0;
}