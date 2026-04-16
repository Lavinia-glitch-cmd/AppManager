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

std::istream& operator>>(std::istream& is, Profile& obj) {
    std::cout << "Username: ";
    is >> std::ws;
    std::getline(is, obj.username);

    std::string tempPass;
    while (true) {
        std::cout << "Password (min. 8 chars): ";
        is >> tempPass;
        if (tempPass.length() >= 8) {
            obj.password = tempPass;
            break;
        }
        std::cout << "[Eroare] Parola prea scurta! Reincercati.\n";
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
        os << "App : " << obj.app->getName(); 
    } else {
        os << "No app .";
    }
    return os;
}

void Profile::readData() {
    std::string tempPass;
    while (true) {
        std::cout << "Enter password (min. 8 chars): ";
        std::cin >> tempPass;
        if (tempPass.length() >= 8) {
            this->password = tempPass;
            break;
        }
        std::cout << "[Eroare] Parola prea scurta! Ai nevoie de 8 caractere.\n";
    }
}