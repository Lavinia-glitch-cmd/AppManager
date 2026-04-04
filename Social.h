#ifndef Social_H
#define Social_H
#include <iostream>
#include <string>
#include "Application.h"
class Social:virtual public Application{
    protected:
        int users;
        std::string privacy;
        bool ads;
        float membership;
        bool blue_check;
        std::string category;

    public:
        Social();
        Social(std::string n, std::string d, float v, int s, int u, std::string p, bool a, float m, bool b, std::string c);
        Social(const Social& obj);
        Social& operator=(const Social& obj);
        virtual ~Social();
        friend std::ostream& operator<<(std::ostream& os, const Social& obj);
        friend std::istream& operator>>(std::istream& is, Social& obj);

        void launch() override;
        void displayDetails() const override;


};

#endif


