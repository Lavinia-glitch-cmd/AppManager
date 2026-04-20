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


void Social::display() const {
    std::cout<<*this<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Social& obj) {
    os << static_cast<const Application&>(obj) << "\n";
    return os;
}

std::istream& operator>>(std::istream &is, Social &obj) 
{
    try
    {
        is>>static_cast<Application&>(obj);

    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw;
    }
    return is;
    
}