#ifndef SOCIAL_H
#define SOCIAL_H

#include <iostream>
#include <string>
#include "Application.h"

class Social : virtual public Application {
        public:
        Social();
        
        Social(std::string name, std::string developer, float version, int sizeMB);
        
        Social(const Social& obj);
        Social& operator=(const Social& obj);
        virtual ~Social();

        friend std::ostream& operator<<(std::ostream& os, const Social& obj);
        friend std::istream& operator>>(std::istream& is, Social& obj);
        void display() const override;
        //void displayDetails() const override;
};

#endif