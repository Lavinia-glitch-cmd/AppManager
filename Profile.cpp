#include "Profile.h"
#include "Application.h"

class Application;

        std::string username;
        std::string password;
        Application* app;

Profile::Profile() : username("Unknown"), password(""), app(nullptr) {}

Profile::Profile(Application *a, std::string u, std::string p) : username(u), app(a), password(p) {}

Profile::Profile(const Profile &obj) 
{
    username = obj.username;
    password = obj.password;
    app= obj.app;
}
Profile& Profile::operator=(const Profile &obj)
{
    if( this != &obj)
    {
        this->username = obj.username;
        this->password = obj.password;
        this->app= obj.app;
    }
    return *this;
}
Profile::~Profile() {}

std::ostream& operator<<(std::ostream& os, const Profile& obj)
{
    os<<"User"<<obj.username;
    if(obj.app != nullptr)
    {
        os<<obj.app->getName();
    }
    return os;
}

std::istream& operator>>(std::istream& is, Profile& obj)
{
    std::cout<<"Enter username: "; is>> obj.username;
    std::cout << "Enter password: ";is >> obj.password;
    return is;
}


