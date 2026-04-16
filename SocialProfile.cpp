#include "SocialProfile.h"
#include "Social.h"
#include <iostream>

bool hasReels;
    bool wantsMembership;
    int friendsCount;
    std::string bio;

SocialProfile::SocialProfile() : Profile(), hasReels(false), wantsMembership(false), 
                    friendsCount(0), bio("") {}

SocialProfile::~SocialProfile() {}
SocialProfile::SocialProfile(const SocialProfile& obj) : Profile(obj), hasReels(obj.hasReels), wantsMembership(obj.wantsMembership), friendsCount(obj.friendsCount), bio(obj.bio)
{}
SocialProfile& SocialProfile::operator=(const SocialProfile& obj)
{
    if (this == & obj)
    {
        return *this;
    }
    Profile::operator=(obj);
    this->hasReels=obj.hasReels;
    this->wantsMembership=obj.wantsMembership;
    this->friendsCount = obj.friendsCount;
    this->bio = obj.bio;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SocialProfile& obj) {
    os << static_cast<const Profile&>(obj) << "\n";
    os << "Friends: " << obj.friendsCount << " | Reels: " << (obj.hasReels ? "Yes" : "No") 
       << " | Membership: " << (obj.wantsMembership ? "Yes" : "No") << "\n";
    if (!obj.bio.empty()) {
        os << "Bio: " << obj.bio << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, SocialProfile& obj) {
    is >> static_cast<Profile&>(obj);
    
    std::cout << "Friends count: ";
    is >> obj.friendsCount;
    
    std::cout << "Has reels? (1/0): ";
    is >> obj.hasReels;
    
    std::cout << "Wants membership? (1/0): ";
    is >> obj.wantsMembership;
    
    std::cout << "Enter bio: ";
    is >> std::ws;
    std::getline(is, obj.bio);
    
    return is;
}


void SocialProfile::readData() {
    
    Profile::readData();

    std::cout << "How many friends do you have? ";
    std::cin >> friendsCount;

    std::cout << "Does it have reels? (1-Yes / 0-No): ";
    std::cin >> hasReels;

    std::cout << "Do you want a membership? (1-Yes / 0-No): ";
    std::cin >> wantsMembership;
}

void SocialProfile::display() const {
    std::cout << "\n--- SOCIAL ACCOUNT DETAILS ---\n";
    std::cout << "User: " << username << "\n";
    std::cout << "Friends: " << friendsCount << "\n";
    std::cout << "Features: " << (hasReels ? "Reels Active" : "No Reels") 
              << " | Premium: " << (wantsMembership ? "Yes" : "No") << "\n";

    if (app != nullptr) {
        app->display(); 
    }
}