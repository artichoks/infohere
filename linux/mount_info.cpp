#include <mntent.h>
#include <iostream>
#include "../error_check.h"


const char *PROC_MOUNTS = "/proc/mounts";
const char *OUTPUT_TEMPLATE = "%15s\t%35s\t%s\n";


void print_mount_info()
{
	ERRNO_CLEAR;
	FILE *mnt_file = setmntent(PROC_MOUNTS, "r");
	ERRNO_EXIT_IF_ERROR("Can't get mount entries");

	std::cout << "Mount point info:\n";
	printf(OUTPUT_TEMPLATE, "Mount Type:", "Path:", "Options:");

	ERRNO_CLEAR;
	struct mntent *mount_entry;
	while ((mount_entry = getmntent(mnt_file)) != NULL)
	{
		printf(OUTPUT_TEMPLATE, mount_entry->mnt_type, mount_entry->mnt_dir, mount_entry->mnt_opts);
	}
	// Проверка должна быть здесь: если getmntent() выполнится с ошибкой, то эта функция вернет NULL и цикл будет прерван
	ERRNO_EXIT_IF_ERROR("Can't get mount entries");

	std::cout << std::endl;
}


