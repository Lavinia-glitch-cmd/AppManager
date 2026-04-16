#include "Application.h"

Application::Application() 
    : name("Unknown"),
    developer("Anonymous"), 
    version(1.0f), 
    sizeMB(0) 
{}

Application::Application(std::string name, std::string developer, float version, int sizeMB) 
    : name(name), 
      developer(developer), 
      version(version), 
      sizeMB(sizeMB)
{}

Application::Application(const Application& other) 
    : name(other.name), 
      developer(other.developer), 
      version(other.version), 
      sizeMB(other.sizeMB) 
{}

Application& Application::operator=(const Application& obj)
{
    if (this == &obj)
        return *this;
    (*this).name=obj.name;
    (*this).developer=obj.developer;
    (*this).version=obj.version;
    (*this).sizeMB=obj.sizeMB;

    return *this;
}

Application::~Application(){}

std::ostream& operator<<(std::ostream& os, const Application& obj)
{
    os << "Application: " << obj.name<<"Developer: " << obj.developer<< " | v" << obj.version << " | Size: " << obj.sizeMB<< "MB";
    return os;
}

std::istream& operator>>(std::istream& is, Application& obj)
{
    std::cout << "Enter app name: ";
    is >> obj.name;
    std::cout << "Enter developer: ";
    is >> obj.developer;
    std::cout << "Enter version: ";
    is >> obj.version;
    std::cout << "Enter size: ";
    is >> obj.sizeMB;
    return is;
}       