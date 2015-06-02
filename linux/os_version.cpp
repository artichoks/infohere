#include <iostream>
#include <sys/utsname.h>


void print_os_version()
{
	struct utsname os = {};
	uname(&os);
	std::cout << "Operating system info:\n";
    std::cout << "    " << os.sysname << " "
    		  << os.release << " "
			  << os.version << std::endl;
	std::cout << std::endl;
}
