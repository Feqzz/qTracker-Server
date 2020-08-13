#include "server.h"
/*! \mainpage QTracker-Server Documentation
 *
 * \section intro_sec Introduction
 *
 * This document describes all the C++ classes used in our QTracker-Server.<br>
 * There are no ads on this page, but due to the unforunate name of the software,
 * adblockers will disable some functionality. Disable it to view the webpage as
 * intended.
 *
 */
int main()
{
	Server server(12321);
	server.start();
	return 0;
}