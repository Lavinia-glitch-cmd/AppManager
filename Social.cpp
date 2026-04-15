#include "Social.h"

Social::Social() : Application() {}

Social::Social(const Social& obj) : Application(obj) {}

Social& Social::operator=(const Social& obj) {
    if (this != &obj) {
        Application::operator=(obj);
    }
    return *this;
}

Social::~Social() {}

void Social::displayDetails() const {
    std::cout << "Social App: " << name << std::endl;
}
void Social::display() const {
    std::cout<<*this<<std::endl;
}
std::ostream& operator<<(std::ostream& os, const Social& obj) {
    os << "Social App Name: " << obj.name;
    return os;
}

std::istream& operator>>(std::istream& is, Social& obj) {    
    std::cout << "Nume Aplicatie Sociala: "; 
    is >> std::ws; 
    std::getline(is, obj.name);
    return is;
}