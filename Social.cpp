#include "Social.h"

Social::Social() 
    : Application(), users(0), privacy("Public"), ads(false), 
      membership(0.0f), blue_check(false), category("General") 
{}

Social::Social(const Social& obj) 
    : Application(obj),
      users(obj.users), 
      privacy(obj.privacy), 
      ads(obj.ads), 
      membership(obj.membership), 
      blue_check(obj.blue_check), 
      category(obj.category)
{}


Social& Social::operator=(const Social& obj) {
    if (this != &obj) {
        Application::operator=(obj);
        
        this->users = obj.users;
        this->privacy = obj.privacy;
        this->ads = obj.ads;
        this->membership = obj.membership;
        this->blue_check = obj.blue_check;
        this->category = obj.category;
    }
    return *this;
}

Social::~Social() {}




void Social::displayDetails() const {
    std::cout << "Social App Name: " << name << " | Privacy: " << privacy<< " | Verified: " <<blue_check << "|Has adds ? "<<ads<<std::endl;
}


std::ostream& operator<<(std::ostream& os, const Social& obj) {
    os << (const Application&)obj << "\n" 
       << "Users: " << obj.users << " | Privacy: " << obj.privacy 
       << " | Ads: " << (obj.ads ? "On" : "Off");
    return os;
}

std::istream& operator>>(std::istream& is, Social& obj) {    
    std::cout << "Enter users: "; is >> obj.users;
    std::cout << "Enter privacy: "; is >> obj.privacy;
    std::cout << "Enter ads (0/1): "; is >> obj.ads;
    std::cout << "Enter membership price: "; is >> obj.membership;
    std::cout << "Enter blue check (0/1): "; is >> obj.blue_check;
    return is;
}