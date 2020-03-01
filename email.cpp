#include "email.h"

Email::Email()
{

}

std::string Email::createMailBody()
{
    std::string body = "\"<html><body>"+key+"</body></html>\"";
    return body;
}

void Email::sendEmail()
{
    std::string sender = "noreply@tarves.no";
    std::string subject = "\"testing cpp\"";
    std::string content = "\"Content-Type: text/html\"";
    std::string shellCommand = "echo "+createMailBody()+
            " > /tmp/mailbody && mail -a "+content+
            " -s "+subject+" -r "+sender+" "+email+
            " < /tmp/mailbody";
    std::cout << shellCommand << std::endl;
    system(shellCommand.c_str());

}