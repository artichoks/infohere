#include "info_providers.h"


int main(int argc, char **argv)
{
    print_os_version();
    print_cpu_info();
    print_memory_info();
    print_display_info();
    print_mount_info();
    print_environment_variables();

    return 0;
}
