#include <unistd.h>
#include <iostream>


void print_environment_variables()
{
	char **env = environ;

	std::cout << "Environment variables:\n";
	while (*env != NULL)
	{
		std::cout << "    " << *(env++) << std::endl;
	}
}
