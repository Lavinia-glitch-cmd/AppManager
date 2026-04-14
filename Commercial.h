#ifndef Commercial_H
#define Commercial_H
#include <iostream>
#include <string>
#include "Application.h"

class Commercial: virtual public Application
{
  protected:
    int inventory;
    float commision;
    bool escrowEnabled;
    std::string merchantType;
    int activeAds;
    double total;
    
    public:
      Commercial();
      Commercial(std::string name, std::string type, std::string developer, float version, int sizeMB, int inventory, float commision, bool escrowEnabled, std::string merchantType, int activeAds, double total);
      Commercial(const Commercial& obj);
      Commercial& operator=(const Commercial& obj);
      virtual ~Commercial();
      
      friend std::ostream& operator<<(std::ostream& os, const Commercial& obj);
      friend std::istream& operator>>(std::istream& is, Commercial& obj);
      
      void displayDetails() const =0;
};

#endif
