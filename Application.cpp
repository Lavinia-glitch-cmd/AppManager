#include "Application.h"

Application::Application() 
    : name("Unknown"),
    type("Unknown"),
    developer("Anonymous"), 
    version(1.0f), 
    sizeMB(0) 
{}

Application::Application(std::string name,std::string type, std::string developer, float version, int sizeMB) 
    : name(name), 
      developer(developer), 
      version(version), 
      sizeMB(sizeMB)
{}

Application::Application(const Application& other) 
    : name(other.name), 
      type("other.type"),
      developer(other.developer), 
      version(other.version), 
      sizeMB(other.sizeMB) 
{
        std::cout << " Creating a copy of " << other.name << "\n";
}

Application& Application::operator=(const Application& obj)
{
    if (this == &obj)
        return *this;
    (*this).name=obj.name;
    (*this).type=obj.type;
    (*this).developer=obj.developer;
    (*this).version=obj.version;
    (*this).sizeMB=obj.sizeMB;

    return *this;
}

Application::~Application(){}

std::ostream& operator<<(std::ostream& os, const Application& obj)
{
    os << "Application: " << obj.name<<"Type: " << obj.type<< " | Developer: " << obj.developer<< " | v" << obj.version << " | Size: " << obj.sizeMB<< "MB";
    return os;
}

std::ostream& operator>>(std::istream& is, Application& obj)
{
    std::cout << "Enter name: ";
    is >> obj.name;
    std::cout << "Enter type: ";
    is >> obj.type;
    std::cout << "Enter developer: ";
    is >> obj.developer;
    std::cout << "Enter version: ";
    is >> obj.version;
    std::cout << "Enter size: ";
    is >> obj.sizeMB;
}       