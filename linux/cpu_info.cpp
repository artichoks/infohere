#include <fstream>
#include <iostream>
#include <string>

const char *PROC_CPUINFO = "/proc/cpuinfo";


void print_cpu_info()
{
	std::ifstream cpuinfo_file(PROC_CPUINFO, std::ifstream::in);
	std::cout << "CPU Info:\n";

	std::string line;
	while (std::getline(cpuinfo_file, line))
		std::cout << "    " << line << std::endl;
	std::cout << std::endl;
}
