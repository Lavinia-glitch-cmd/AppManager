#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <vector>
#include "Application.h"
#include "Profile.h"

class AppManager{
    private:
        std::vector<Application*> apps;
        std::vector<Profile*> profiles;

        void addSocialAccount();
        void addCommercialAccount();

    public:
        AppManager();
        ~AppManager();

        void runMenu();
        void displayAll() const;

};

#endif