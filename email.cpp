#include "email.h"
/**
 * Reads the first variable in the vector and
 * sends a invite email or forgotten password email
 * depending on the int.
 * @param variables vector with strings
 * @return Email object
 */
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
/**
 * Creates a html body for use in a invite email
 * @param key string containing the invite key
 */
void Email::createInviteBody(std::string key)
{
    body = "\"<html><body><h1>Invite key:</h1><br>"+key+"</body></html>\"";
}
/**
 * Creates a html body for use in a forgotten password email
 * @param key string containing the password
 */
void Email::createForgottenPasswordBody(std::string password)
{
    body = "\"<html><body><h1>New password:</h1><br>"+password+"</body></html>\"";
}
/**
 * Creates a shell command, and executes it with a system() call
 * @return int 0 or 1 depending on success
 */
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
/**
 * The system call needs a file to temporarily store the email body.
 * So we generate a random filename.
 * @return string the random filename
 */
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