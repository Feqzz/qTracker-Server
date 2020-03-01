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
	int code;
	void parseBuffer(char* buffer,int length);
	int createSocket(int port);
	void initOpenSSL();
	void cleanupSSL();
	SSL_CTX* createContext();
	void configureContect(SSL_CTX *ctx);
};

#endif