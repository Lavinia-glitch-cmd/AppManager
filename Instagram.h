#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include "Social.h"
#include <iostream>
#include <string>

class Instagram : public Social {
    protected:
        

    public:
        Instagram();

        Instagram(const Instagram& obj);
        Instagram& operator=(const Instagram& obj);
        virtual ~Instagram();

        friend std::ostream& operator<<(std::ostream& os, const Instagram& obj);
        friend std::istream& operator>>(std::istream& is, Instagram& obj);

        void launch() override;
        void displayDetails() const override;
};

#endif