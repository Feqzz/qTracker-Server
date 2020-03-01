#include "email.h"

Email::Email()
{

}

string Email::createMailBody()
{
    string body = "\"<html><body>"+key+"</body></html>\"";
    return body;
}

void Email::sendEmail()
{
    string sender = "noreply@tarves.no";
    string subject = "\"testing cpp\"";
    string content = "\"Content-Type: text/html\"";
    string shellCommand = "echo "+createMailBody()+
            " > /tmp/mailbody && mail -a "+content+
            " -s "+subject+" -r "+sender+" "+email+
            " < /tmp/mailbody";
    cout << shellCommand << endl;
    system(shellCommand.c_str());

}