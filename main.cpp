#include <getopt.h>
#include <iostream>
#include "info_providers.h"



const char *help_string = ""
		"Usage: ./infohere [-chmodtea] [--help] [--os] [--cpu] [--memory] [--display] [--mount] [--environment] [--all]\n"
		"	--help		-h		Show help\n"
		"	--os		-o		Show information about operating system version\n"
		"	--cpu		-c		Show information about CPU\n"
		"	--memory	-m		Show information about memory\n"
		"	--display	-d		Show information about Show\n"
		"	--mount		-t		Show information about mount points\n"
		"	--environment	-e		Show information about environment\n"
		"	--all		-a		Show all available information\n";


const struct option long_options[] =
        {
          {"os",			no_argument, 0, 'o'},
          {"cpu",			no_argument, 0, 'c'},
          {"memory", 		no_argument, 0, 'm'},
          {"display",		no_argument, 0, 'd'},
          {"mount",			no_argument, 0, 't'},
          {"environment",	no_argument, 0, 'e'},
          {"all",			no_argument, 0, 'a'},
          {"help",			no_argument, 0, 'h'},
		  {}
        };


int main(int argc, char **argv)
{
	int opt;
	int opt_index = 0;

	while ((opt = getopt_long(argc, argv, "hocmdtea", long_options, &opt_index)) != -1)
	{
	    switch (opt)
	    {
	    	case 'h':
	    		std::cout << help_string;
	    		return 0;
	    	case 'o':
	    		print_os_version();
	    		break;
	    	case 'c':
	    		print_cpu_info();
	    		break;
	    	case 'm':
	    		print_memory_info();
	    		break;
	    	case 'd':
	    		print_display_info();
	    		break;
	    	case 't':
	    		print_mount_info();
	    		break;
	    	case 'e':
	    		print_environment_variables();
	    		break;
	    	case 'a':
	    		print_os_version();
	    		print_cpu_info();
	    		print_memory_info();
	    		print_display_info();
	    		print_mount_info();
	    		print_environment_variables();
	    		break;
	    	default:
	    		std::cout << help_string;
	    		return 0;
	    }
	}

    return 0;
}

