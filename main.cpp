#include "server.h"

int main()
{
	Server server(12321);
	server.start();
	return 0;
}