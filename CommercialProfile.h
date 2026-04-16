#ifndef COMMERCIALPROFILE_H
#define COMMERCIALPROFILE_H

#include <string>
#include "Profile.h"

class CommercialProfile : public Profile{
    private:
        std::string shippingAddress;
        std::string bankName;
        float balance;
        bool Premium;
    public:
        CommercialProfile();
        ~CommercialProfile();
        CommercialProfile(const CommercialProfile& obj);
        CommercialProfile& operator=(const CommercialProfile& obj);

        friend std::ostream& operator<<(std::ostream& os, const CommercialProfile &obj);
        friend std::istream& operator>>(std::istream &is, CommercialProfile &obj);
        void readData() override;

        void display() const override;
};

#endif