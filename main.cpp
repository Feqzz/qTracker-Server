#include "server.h"
/*! \mainpage QTracker Server Documentation
 *
 * \section intro_sec Introduction
 *
 * This document describes all the C++ classes used in our QTracker Server
 *
 */
int main()
{
	Server server(12321);
	server.start();
	return 0;
}