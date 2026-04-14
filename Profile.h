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
        Profile(std::string u="", std::string p="");
        Profile(const Profile &obj);
        Profile& operator=(const Profile &obj);
        virtual ~Profile();
        friend std::ostream& operator<<(std::ostream& os, const Profile& obj);
        friend std::istream& operator>>(std::istream& is, Profile& obj);
        

        virtual void readData()=0;
        virtual void display() const =0;
        void setApp(Application* app) {this-> app= app;} 
        void createSocialAccount();
        void createCommercialAccount();
};

#endif
