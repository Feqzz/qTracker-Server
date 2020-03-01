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

#include "email.h"

#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/wait.h>

class Server
{
public:
	Server(int port);
	void start();
private:
	void handleClient(SSL *ssl);
	int pid;
	int sock;
	SSL_CTX *ctx;
	void parseBuffer(char* buffer,int length);
	int createSocket(int port);
	void initOpenSSL();
	void cleanupSSL();
	SSL_CTX* createContext();
	void configureContect(SSL_CTX *ctx);
};

#endif