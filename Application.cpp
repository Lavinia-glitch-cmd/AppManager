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

