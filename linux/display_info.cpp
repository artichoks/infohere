#include <X11/Xlib.h>
#include <iostream>


void printf_display_info()
{
	Display* display = XOpenDisplay(NULL);
	Screen*  screen = DefaultScreenOfDisplay(display);


	std::cout << "Display info:\n"
			  << "    vendor: " << ServerVendor(display) << "\n"
			  << "    version: " << VendorRelease(display) << "\n"
			  << "    screen count : " << ScreenCount(display) << "\n"

			  << "    resolution: " << screen->width <<  "x" << screen->height << "\n"
			  << "    size: "       << screen->mwidth << "mmx" << screen->mheight << "mm\n"
			  << "    depth: "      << screen->root_depth << "\n";
	std::cout << std::endl;
}
