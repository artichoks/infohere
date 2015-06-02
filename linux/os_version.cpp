#include <iostream>
#include <sys/utsname.h>
#include "../error_check.h"


void print_os_version()
{
	ERRNO_CLEAR;
	struct utsname os = {};
	uname(&os);
	ERRNO_EXIT_IF_ERROR("Can't get os version");

	std::cout << "Operating system info:\n";
    std::cout << "    " << os.sysname << " "
    		  << os.release << " "
			  << os.version << std::endl;
	std::cout << std::endl;
}
