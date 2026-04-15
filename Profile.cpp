#include "Profile.h"
#include "Application.h"

Profile::Profile() : username("Unknown"), password(""), app(nullptr) {}

Profile::Profile(Application *a, std::string u, std::string p) 
    : username(u), password(p), app(a) {}

Profile::Profile(const Profile &obj) 
{
    username = obj.username;
    password = obj.password;
    app = obj.app;
}

Profile& Profile::operator=(const Profile &obj)
{
    if(this != &obj)
    {
        this->username = obj.username;
        this->password = obj.password;
        this->app = obj.app;
    }
    return *this;
}

Profile::~Profile() {}

std::ostream& operator<<(std::ostream& os, const Profile& obj)
{
    os << "User: " << obj.username << " | ";
    if(obj.app != nullptr)
    {
        os << "App : " << obj.app->getName(); 
    } else {
        os << "No app .";
    }
    return os;
}