#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <iostream>
#include <vector>

class Email
{
public:
	Email(int code,std::vector<std::string> v);
	void send();
private:
	void createInviteBody(std::string);
	void createForgottenPasswordBody(std::string);
	std::string body;
	std::string recipentEmail;
	std::string getRandomFilename();
};

#endif