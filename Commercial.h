#ifndef Commercial_H
#define Commercial_H

#include <iostream>
#include <string>
#include <vector>
#include "Application.h"

class Commercial : virtual public Application
{
  protected:
    std::vector<std::string> inventory; 
    float premiumDiscount;             
    int shippingThreshold;            
    std::string region;                
    bool acceptsReturns;               
    
  public:
    Commercial();
    Commercial(std::string name, std::string developer, float version, int sizeMB, 
               std::vector<std::string> inv, float discount, int threshold, 
               std::string reg, bool returns);
    
    Commercial(const Commercial& obj);
    Commercial& operator=(const Commercial& obj);
    virtual ~Commercial();
    
    friend std::ostream& operator<<(std::ostream& os, const Commercial& obj);
    friend std::istream& operator>>(std::istream& is, Commercial& obj);
    
    void displayDetails() const;
    void display() const override;
    bool hasProduct(std::string productName) const;
};

#endif