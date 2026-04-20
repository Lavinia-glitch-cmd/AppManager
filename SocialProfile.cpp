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
    
    int tempFriends;
    bool tempReels, tempMembership;
    std::string tempBio;
    try 
    {
    std::cout << "Friends count: ";
    if (!(is >> tempFriends )) throw std::invalid_argument("Numar invalid"); 
    
    std::cout << "Has reels? (1/0): ";
    if (!(is >> tempReels )) throw std::invalid_argument("Numar invalid"); 
    
    std::cout << "Wants membership? (1/0): ";
    if (!(is >> tempMembership )) throw std::invalid_argument("Numar invalid"); 
    
    std::cout << "Enter bio: ";
    is >> std::ws;
    std::getline(is, tempBio);

    obj.friendsCount=tempFriends;
    obj.hasReels=tempReels;
    obj.wantsMembership=tempMembership;
    obj.bio=tempBio;
    
    }catch(const std::exception &e)
    {
        is.clear();
        is.ignore(1000, '\n');
        throw;
    }
    return is;
}

void SocialProfile::readData() {
    std::cin >> *this;
}

void SocialProfile::display() const {
    std::cout << *this << std::endl;
}