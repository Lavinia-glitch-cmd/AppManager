#include "SocialProfile.h"
#include "Social.h"
#include <iostream>

SocialProfile::SocialProfile() : Profile(), hasReels(false), wantsMembership(false), 
                    friendsCount(0), bio("") {}

void SocialProfile::readData() {
    
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

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
        app->displayDetails(); 
    }
}