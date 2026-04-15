#ifndef SOCIALPROFILE_H
#define SOCIALPROFILE_H

#include "Profile.h"
#include <iostream>
#include <string>

class SocialProfile : public Profile {
private:
    bool hasReels;
    bool wantsMembership;
    int friendsCount;
    std::string bio;

public:
    SocialProfile() ;

    void readData() override;
    void display() const override;
};

#endif