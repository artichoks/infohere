#include <fstream>
#include <iostream>


const char *PROC_MEMINFO = "/proc/meminfo";


void print_memory_info()
{
	std::ifstream cpuinfo_file(PROC_MEMINFO, std::ifstream::in);
	std::cout << "Memory info:\n";

	std::string line;
	while (std::getline(cpuinfo_file, line))
		std::cout << "    " << line << std::endl;
	std::cout << std::endl;
}
