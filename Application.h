#ifndef Application_H
#define Application_H

#include <iostream>
#include <string>

class Application {
    protected:
        std::string name;
        std::string type;
        std::string developer;
        float version;
        int sizeMB;

    public:
        Application();
        Application(std::string name,std::string type, std::string developer, float version, int sizeMB);
        Application(const Application& obj);
        Application& operator=(const Application& obj);
        virtual ~Application();
        friend std::ostream& operator<<(std::ostream& os, const Application& obj);
        friend std::ostream& operator>>(std::istream& is, Application& obj);
        
        std::string getName() const { return name; }
        float getVersion() const { return version; }
        void setName(std::string name) {name = name; }
        void setVersion(float version) {version = version; }

        virtual void launchApp() = 0;
        virtual void displayDetails() = 0;

};
#endif