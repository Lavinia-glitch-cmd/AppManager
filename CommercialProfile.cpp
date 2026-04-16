#include "CommercialProfile.h"
#include "Application.h"

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
    if (this == &obj)
        return *this;
    Profile::operator=(obj);
    this->shippingAddress = obj.shippingAddress;
    this->bankName = obj.bankName;
    this->balance = obj.balance;
    this->Premium = obj.Premium;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CommercialProfile &obj)
{
    os << static_cast<const Profile&>(obj) << "\n";
    os << "Shipping Address: " << obj.shippingAddress << " | Bank: " << obj.bankName 
       << " | Balance: " << obj.balance << " | Premium: " << (obj.Premium ? "Yes" : "No");
    return os;
}

std::istream& operator>>(std::istream &is, CommercialProfile &obj)
{
    is >> static_cast<Profile&>(obj);
    std::cout << "Enter Shipping Address: ";
    is >> std::ws;
    std::getline(is, obj.shippingAddress);
    std::cout << "Enter Bank Name: ";
    std::getline(is, obj.bankName);
    std::cout << "Enter Balance: ";
    is >> obj.balance;
    std::cout << "Enter Premium (1/0): ";
    is >> obj.Premium;
    return is;
}

void CommercialProfile::readData() {
    std::cin >> *this;
}

void CommercialProfile::display() const
{
    std::cout << *this << std::endl;
}