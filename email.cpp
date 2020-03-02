#include "email.h"

Email::Email(std::vector<std::string> variables)
{
    /* first string in vector should be email
    second string should be invite key or new password */
    int code = std::stoi(variables.at(0));
    recipentEmail = variables.at(1);
    //std::cout << variables.at(1);
    //std::cout << code;
    if(code == 0)
    {
        createInviteBody(variables.at(2));
    }
    else if(code == 1)
    {
        createForgottenPasswordBody(variables.at(2));
    }
}

void Email::createInviteBody(std::string key)
{
    body = "\"<html><body><h1>Invite key:</h1><br>"+key+"</body></html>\"";
}

void Email::createForgottenPasswordBody(std::string password)
{
    body = "\"<html><body><h1>New password:</h1><br>"+password+"</body></html>\"";
}

int Email::send()
{
    std::string sender = "noreply@tarves.no";
    std::string subject = "\"testing cpp\"";
    std::string content = "\"Content-Type: text/html\"";
    std::string fileName = getRandomFilename();
    std::string shellCommand = "echo "+body+
            " > /tmp/"+fileName+" && mail -a "+content+
            " -s "+subject+" -r "+sender+" "+recipentEmail+
            " < /tmp/"+fileName+" && rm /tmp/"+fileName+"";
    //std::cout << shellCommand << std::endl;
    return system(shellCommand.c_str());
}

std::string Email::getRandomFilename(){
    std::string output = "";
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 15; ++i) {
        output += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return output;
}