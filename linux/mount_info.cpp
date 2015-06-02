#include <mntent.h>
#include <stdio.h>
#include <iostream>


const char *PROC_MOUNTS = "/proc/mounts";
const char *OUTPUT_TEMPLATE = "    %11s\t%30s\t%s\n";


void print_mount_info()
{
	FILE *mnt_file = setmntent(PROC_MOUNTS, "r");

	std::cout << "Mount point info:\n";
	printf(OUTPUT_TEMPLATE, "Mount Type:", "Path:", "Options:");

	struct mntent *mount_entry;
	while ((mount_entry = getmntent(mnt_file)) != NULL)
	{
		printf(OUTPUT_TEMPLATE, mount_entry->mnt_type, mount_entry->mnt_dir, mount_entry->mnt_opts);
	}
}


