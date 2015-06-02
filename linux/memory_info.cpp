#include <iostream>
#include <fstream>
#include <string>
#include "../error_check.h"


const char *PROC_MEMINFO = "/proc/meminfo";


void print_memory_info()
{
	ERRNO_CLEAR;
	std::ifstream cpuinfo_file(PROC_MEMINFO, std::ifstream::in);
	ERRNO_EXIT_IF_ERROR("Can't get memory info");

	std::cout << "Memory info:\n";

	std::string line;
	while (std::getline(cpuinfo_file, line))
		std::cout << "    " << line << std::endl;
	std::cout << std::endl;
}
