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
        friend std::istream& operator>>(std::istream& is, Profile& obj);
        
        std::string getUsername() const { return username; }
        std::string getPassword() const { return password; }
        Application* getApp() const { return app; } 

        void setUsername(std::string u) { username = u; }
        virtual void readData()=0;
        virtual void display() const=0;
        void setApp(Application* a) { this->app = a; }
};

std::ostream& operator<<(std::ostream& os, const Profile& obj);
std::istream& operator>>(std::istream& is, Profile& obj);

#endif
