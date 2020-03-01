#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

class Server
{
public:
	Server();
private:
	string email;
	string key;
	int code;
};

#endif