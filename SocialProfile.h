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
    virtual ~SocialProfile();
    SocialProfile(const SocialProfile& obj);
    SocialProfile& operator=(const SocialProfile& obj);
    friend std::ostream& operator<<(std::ostream &os, const SocialProfile& obj);
    friend std::istream& operator>>(std::istream &is, SocialProfile& obj);

    void readData() override;
    void display() const override;
};

#endif