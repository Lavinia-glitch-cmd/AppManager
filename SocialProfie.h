#ifndef SOCIALPROFILE_H
#define SOCIALPROFILE_H

#include "Profile.h"
#include <iostream>

class SocialProfile : public Profile {
public:
    void readData() override {
        std::cout << "Username: "; std::cin >> username;
        std::cout << "Password: "; std::cin >> password;
    }

    void display() const override {
        std::cout << "Profile Social - User: " << username << "\n";
    }
};

#endif