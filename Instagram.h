#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include "Social.h"
#include <iostream>
#include <string>

class Instagram : public Social {
    protected:
        int followers;
        int following;
        int photos;
        
    public:
        Instagram();
        Instagram(std::string name, std::string type, std::string developer, float version, int sizeMB, 
          int users, std::string privacy, bool ads, float membership, bool blue_check, 
          std::string category, bool reels, int followers, int following, int photos);
        Instagram(const Instagram& obj);
        Instagram& operator=(const Instagram& obj);
        virtual ~Instagram();

        friend std::ostream& operator<<(std::ostream& os, const Instagram& obj);
        friend std::istream& operator>>(std::istream& is, Instagram& obj);

        void launch() override;
        void displayDetails() const override;
};

#endif