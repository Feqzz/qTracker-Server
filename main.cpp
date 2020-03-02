#include "server.h"

int main()
{
	Server server(12399);
	server.start();
	return 0;
}