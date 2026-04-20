#include "CommercialProfile.h"
#include <stdexcept>

CommercialProfile::CommercialProfile() 
    : Profile(), shippingAddress(""), bankName(""), 
      balance(0.0f), Premium(false)
{}

CommercialProfile::~CommercialProfile() {}

CommercialProfile::CommercialProfile(const CommercialProfile& obj) 
    : Profile(obj), shippingAddress(obj.shippingAddress), 
      bankName(obj.bankName), balance(obj.balance), Premium(obj.Premium) 
{}

CommercialProfile& CommercialProfile::operator=(const CommercialProfile& obj) 
{
    if (this != &obj) {
        Profile::operator=(obj);
        this->shippingAddress = obj.shippingAddress;
        this->bankName = obj.bankName;
        this->balance = obj.balance;
        this->Premium = obj.Premium;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CommercialProfile &obj)
{
    os << static_cast<const Profile&>(obj) << "\n";
    os << "Shipping: " << obj.shippingAddress << " | Bank: " << obj.bankName 
       << " | Balance: " << obj.balance << " | Premium: " << (obj.Premium ? "Yes" : "No");
    return os;
}

std::istream& operator>>(std::istream &is, CommercialProfile &obj)
{
    is >> static_cast<Profile&>(obj);
    
    std::string tempAddress, tempBank;
    float tempBalance;
    bool tempPremium;

    try {
        std::cout << "Enter Shipping Address: ";
        is >> std::ws;
        if (!std::getline(is, tempAddress) || tempAddress.empty()) 
            throw std::runtime_error("Adresa vida.");

        std::cout << "Enter Bank Name: ";
        if (!std::getline(is, tempBank) || tempBank.empty()) 
            throw std::runtime_error("Banca vida.");

        std::cout << "Enter Balance: ";
        if (!(is >> tempBalance)) 
            throw std::invalid_argument("Numar invalida.");

        std::cout << "Enter Premium (1/0): ";
        if (!(is >> tempPremium)) 
            throw std::invalid_argument("Optiune Premium invalida.");

        obj.shippingAddress = tempAddress;
        obj.bankName = tempBank;
        obj.balance = tempBalance;
        obj.Premium = tempPremium;

    } catch (const std::exception& e) {
        is.clear();
        is.ignore(1000, '\n');
        throw;
    }

    return is;
}

void CommercialProfile::readData() {
    std::cin >> *this;
}

void CommercialProfile::display() const
{
    std::cout << *this << std::endl;
}