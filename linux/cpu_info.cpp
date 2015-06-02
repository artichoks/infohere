#include <iostream>
#include <fstream>
#include <string>
#include "../error_check.h"


const char *PROC_CPUINFO = "/proc/cpuinfo";


void print_cpu_info()
{
	ERRNO_CLEAR;
	std::ifstream cpuinfo_file(PROC_CPUINFO, std::ifstream::in);
	ERRNO_EXIT_IF_ERROR("Can't get cpu info");

	std::cout << "CPU Info:\n";

	std::string line;
	while (std::getline(cpuinfo_file, line))
		std::cout << "    " << line << std::endl;
	std::cout << std::endl;
}
