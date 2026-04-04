#ifndef SOCIALAPP_H
#define SOCIALAPP_H

#include "Social.h"
#include <string>

class Social:virtual public Social{
    protected:
        // int user;
        int followers;
        std::string privacy;
        bool ads;
        bool membership;
        bool blue_check;
        std::string category;

    public:
        Social();
        Social(std::string type, std::string developer, float version, int sizeMB);
        Social(const Social& obj);
        Social& operator=(const Social& obj);
        virtual ~Social();
        friend std::ostream& operator<<(std::ostream& os, const Social& obj);
        friend std::ostream& operator>>(std::istream& is, Social& obj);
        


};

#endif