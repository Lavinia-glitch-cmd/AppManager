#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <string>
#include <vector>

class Application;

class Profile {
    protected:
        std::string username;
        std::string password;
        Application* app;
    public:
        Profile();
        Profile(Application *a, std::string u="", std::string p="");
        Profile(const Profile &obj);
        Profile& operator=(const Profile &obj);
        virtual ~Profile();
        friend std::ostream& operator<<(std::ostream& os, const Profile& obj);
        

        virtual void readData()=0;
        virtual void display() const =0;
        void setApp(Application* a) { this->app = a; }
        Application* getApp() const { return app; } 
};

#endif
