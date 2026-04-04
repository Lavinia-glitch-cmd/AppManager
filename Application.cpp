#include "Application.h"

Application::Application(){
    name="Unknown";
    developer="Unknown";
    version=0.0;
    sizeMB=0;

}

Application::Application(std::string name, std::string developer, float version, int sizeMB) 
    : name(name), 
      developer(developer), 
      version(version), 
      sizeMB(sizeMB)
{

}

Application::Application(const Application& other) 
    : name(other.name), 
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
    (*this).developer=obj.developer;
    (*this).version=obj.version;
    (*this).sizeMB=obj.sizeMB;

    return *this;
}

Application::~Application(){}

