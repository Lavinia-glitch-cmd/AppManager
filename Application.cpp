#include "Application.h"
#include <stdexcept>
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
    if (this != &obj) {
        this->name = obj.name;
        this->developer = obj.developer;
        this->version = obj.version;
        this->sizeMB = obj.sizeMB;
    }
    return *this;
}

Application::~Application() {}

std::ostream& operator<<(std::ostream& os, const Application& obj)
{
    os << "Application: " << obj.name << " | Developer: " << obj.developer 
       << " | v" << obj.version << " | Size: " << obj.sizeMB << "MB";
    return os;
}

std::istream& operator>>(std::istream& is, Application& obj)
{
    std::string tempName, tempDev;
    float tempVer;
    int tempSize;

    try {
        std::cout << "Enter app name: ";
        is >> std::ws;
        if (!std::getline(is, tempName) || tempName.empty()) {
            throw std::runtime_error("Introdu numele aplicatiei!!!");
        }

        std::cout << "Enter developer: ";
        if (!std::getline(is, tempDev) || tempDev.empty()) {
            throw std::runtime_error("Introdu numele developerului!!!");
        }

        std::cout << "Enter version: ";
        if (!(is >> tempVer)) {
            is.clear();
            is.ignore(1000, '\n');
            throw std::invalid_argument("Versiunea trebuie sa fie un numar (ex: 1.2)!");
        }

        std::cout << "Enter size (MB): ";
        if (!(is >> tempSize)) {
            is.clear();
            is.ignore(1000, '\n');
            throw std::invalid_argument("Dimensiunea trebuie sa fie un numar!!!");
        }
        
        
        obj.name = tempName;
        obj.developer = tempDev;
        obj.version = tempVer;
        obj.sizeMB = tempSize;

    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << std::endl;
         
        throw; 
    }

    return is;
}