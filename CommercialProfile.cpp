#include "CommercialProfile.h"
#include "Application.h"
CommercialProfile::CommercialProfile() 
    : Profile(), shippingAddress(""), bankName(""), 
    balance(0.0f), Premium(false)
     {}
    

CommercialProfile::~CommercialProfile() {}
CommercialProfile::CommercialProfile(const CommercialProfile& obj) : shippingAddress(obj.shippingAddress), bankName(obj.bankName), balance(obj.balance), Premium(obj.Premium) {}
CommercialProfile& CommercialProfile::operator=(const CommercialProfile& obj) 
{
    if (this == &obj)
        return *this;
    this->shippingAddress=obj.shippingAddress;
    this->bankName=obj.bankName;
    this->balance=obj.balance;
    this->Premium=obj.Premium;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CommercialProfile &obj)
{
    os << "Shipping Address: " << obj.shippingAddress<<"Bank Name: " << obj.bankName<< " | Balance" << obj.balance << " | Premium version: " << obj.Premium;
    return os;
}
std::istream& operator>>(std::istream &is, CommercialProfile &obj)
{
    std::cout << "Enter Shipping Address : ";
    is >> obj.shippingAddress;
    std::cout << "Enter Bank Name: ";
    is >> obj.bankName;
    std::cout << "Enter Balance: ";
    is >> obj.balance;
    std::cout << "Enter premium: ";
    is >> obj.Premium;
    return is;
}

void CommercialProfile::readData() {
    Profile::readData();

    std::cout << "Adresa de livrare: ";
    std::getline(std::cin, shippingAddress);

    std::cout << "Banca (ex: BT, ING, BCR): ";
    std::getline(std::cin, bankName);

    std::cout << "Suma initiala de depus in cont ($): ";
    std::cin >> balance;

    std::cout << "Doriti abonament Premium/Prime? (1-Da / 0-Nu): ";
    std::cin >> Premium;
}
void CommercialProfile::display() const
{
    std::cout << "Username: " << username << "\n";
    std::cout << "Bank: " << bankName << "\n";
    std::cout << "Balance: " << balance << "\n";
    std::cout << "Shipping Address: " << shippingAddress << "\n";
    std::cout << "Status: " << (Premium ? "Premium/Prime Member" : "Standard Account") << "\n";
    
    if (app != nullptr) {
        std::cout << "App Platform: " << app->getName() << "\n";
    }
}