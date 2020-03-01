#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <iostream>

class Email
{
public:
	Email();
	std::string createMailBody();
	void sendEmail();
private:
	std::string email;
	std::string key;
};

#endif