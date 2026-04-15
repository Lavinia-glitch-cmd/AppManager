#include "CommercialProfile.h"
#include "Application.h"
CommercialProfile::CommercialProfile() 
    : Profile(), shippingAddress(""), bankName(""), 
    balance(0.0f), Premium(false)
     {}

void CommercialProfile::readData() {
    std::cout << "Password: ";
    std::cin >> std::ws;
    std::getline(std::cin, password);

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
    std::cout << "Bank: " << bankName << "\n";
    std::cout << "Balance: " << balance << " USD\n";
    std::cout << "Shipping to: " << shippingAddress << "\n";
    std::cout << "Premium: " << (Premium ? "Premium/Prime Member" : "Standard Account") << "\n";
    
    if (app != nullptr) {
        std::cout << "Connected via: " << app->getName() << "\n";
    }
}