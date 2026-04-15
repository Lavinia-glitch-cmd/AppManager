#include "Commercial.h"
#include <sstream>
#include <algorithm>

Commercial::Commercial() 
    : Application(), premiumDiscount(0), shippingThreshold(0), region("Unknown"), acceptsReturns(false) {}

Commercial::Commercial(std::string name, std::string developer, float version, int sizeMB, 
                       std::vector<std::string> inv, float discount, int threshold, 
                       std::string reg, bool returns)
    : Application(name,"Commercial", developer, version, sizeMB), inventory(inv), 
      premiumDiscount(discount), shippingThreshold(threshold), 
      region(reg), acceptsReturns(returns) {}

Commercial::Commercial(const Commercial& obj) : Application(obj) {
    this->inventory = obj.inventory;
    this->premiumDiscount = obj.premiumDiscount;
    this->shippingThreshold = obj.shippingThreshold;
    this->region = obj.region;
    this->acceptsReturns = obj.acceptsReturns;
}

Commercial& Commercial::operator=(const Commercial& obj) {
    if (this != &obj) {
        Application::operator=(obj);
        this->inventory = obj.inventory;
        this->premiumDiscount = obj.premiumDiscount;
        this->shippingThreshold = obj.shippingThreshold;
        this->region = obj.region;
        this->acceptsReturns = obj.acceptsReturns;
    }
    return *this;
}

Commercial::~Commercial() {}

std::istream& operator>>(std::istream& is, Commercial& obj) {
    std::cout << "Nume Magazin: ";
    is >> std::ws;
    std::getline(is, obj.name);

    std::cout << "Introdu produsele separate prin spatiu: ";
    std::string line;
    is >> std::ws;
    std::getline(is, line);
    
    std::stringstream ss(line);
    std::string tempProduct;
    obj.inventory.clear();
    while (ss >> tempProduct) {
        obj.inventory.push_back(tempProduct);
    }

    std::cout << "Reducere Premium (%): ";
    is >> obj.premiumDiscount;

    std::cout << "Prag Transport Gratuit: ";
    is >> obj.shippingThreshold;

    std::cout << "Regiune: ";
    is >> std::ws;
    std::getline(is, obj.region);

    std::cout << "Accepta retur? (1-Da / 0-Nu): ";
    is >> obj.acceptsReturns;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Commercial& obj) {
    os << "Magazin: " << obj.name << " | Regiune: " << obj.region << "\n";
    os << "Inventar: ";
    if (obj.inventory.empty()) os << "Gol";
    else {
        for (const auto& item : obj.inventory) os << "[" << item << "] ";
    }
    os << "\nReducere Premium: " << obj.premiumDiscount << "% | Prag Livrare: " << obj.shippingThreshold << "\n";
    os << "Retur disponibil: " << (obj.acceptsReturns ? "Da" : "Nu");
    return os;
}

void Commercial::displayDetails() const {
    std::cout << *this << std::endl;
}
void Commercial::display() const {
    std::cout<< *this <<std::endl;
}
bool Commercial::hasProduct(std::string productName) const {
    return std::find(inventory.begin(), inventory.end(), productName) != inventory.end();
}