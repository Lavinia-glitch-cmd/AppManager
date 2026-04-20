#include "Profile.h"
#include "Application.h"
#include <stdexcept>

Profile::Profile() : username("Unknown"), password(""), app(nullptr) {}

Profile::Profile(Application *a, std::string u, std::string p) 
    : username(u), password(p), app(a) {}

Profile::Profile(const Profile &obj) 
    : username(obj.username), password(obj.password), app(obj.app) {}

std::istream& operator>>(std::istream& is, Profile& obj) {
    std::string tempUser, tempPass;

    try {
        std::cout << "Username: ";
        is >> std::ws;
        if (!std::getline(is, tempUser) || tempUser.empty()) {
            throw std::runtime_error("Username invalid.");
        }

        std::cout << "Password (min. 8 chars): ";
        is >> tempPass;
        if (tempPass.length() < 8) {
            throw std::length_error("Parola prea scurta.");
        }

        obj.username = tempUser;
        obj.password = tempPass;

    } catch (const std::exception& e) {
        is.clear();
        is.ignore(1000, '\n');
        throw;
    }

    return is;
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
        os << "App: " << obj.app->getName(); 
    } else {
        os << "No app.";
    }
    return os;
}

void Profile::readData() {
    std::cin >> *this;
}