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
#include <vector>

#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/wait.h>

class Server
{
public:
	Server(int);
	void start();
private:
	void handleClient(SSL*);
	int pid;
	int sock;
	SSL_CTX *ctx;
	std::vector<std::string> parseBuffer(char*,int);
	int createSocket(int);
	void initOpenSSL();
	void cleanupSSL();
	SSL_CTX* createContext();
	void configureContect(SSL_CTX*);
	int sendEmail (std::vector<std::string>);
};

#endif