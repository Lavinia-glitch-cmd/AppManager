#ifndef COMMERCIALPROFILE_H
#define COMMERCIALPROFILE_H

#include <string>
#include "Profile.h"

class CommercialProfile : public Profile{
    private:
        std::string shippingAddres;
        std::string bankName;
        float balance;
        bool Premium;
    public:
        CommercialProfile();

        void readData() override;
        void display() const override;
};

#endif