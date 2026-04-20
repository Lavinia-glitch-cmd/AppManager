#include "Commercial.h"
#include <sstream>
#include <algorithm>

Commercial::Commercial() 
    : Application(), premiumDiscount(0), shippingThreshold(0), region("Unknown"), acceptsReturns(false) {}

Commercial::Commercial(std::string name, std::string developer, float version, int sizeMB, 
                       std::vector<std::string> inv, float discount, int threshold, 
                       std::string reg, bool returns)
    : Application(name, developer, version, sizeMB), inventory(inv), 
      premiumDiscount(discount), shippingThreshold(threshold), 
      region(reg), acceptsReturns(returns) {}

Commercial::Commercial(const Commercial& obj) 
    : Application(obj), inventory(obj.inventory), premiumDiscount(obj.premiumDiscount), 
      shippingThreshold(obj.shippingThreshold), region(obj.region), acceptsReturns(obj.acceptsReturns) 
{}

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
    is >> static_cast<Application&>(obj);

    std::string line, tempRegion;
    float tempDiscount;
    int tempThreshold;
    bool tempReturns;
    std::vector<std::string> tempInventory;

    try {
        std::cout << "Introdu produsele (separate prin spatiu): ";
        is >> std::ws;
        std::getline(is, line);
        std::stringstream ss(line);
        std::string p;
        while (ss >> p) tempInventory.push_back(p);

        std::cout << "Reducere Premium (%): ";
        if (!(is >> tempDiscount)) throw std::invalid_argument("Reducerea trebuie sa fie numar.");
        if (tempDiscount < 0 || tempDiscount > 100) throw std::out_of_range("Reducere invalida (0-100).");

        std::cout << "Prag Transport Gratuit: ";
        if (!(is >> tempThreshold)) throw std::invalid_argument("Pragul trebuie sa fie numar.");

        std::cout << "Regiune: ";
        is >> std::ws;
        std::getline(is, tempRegion);

        std::cout << "Accepta retur? (1-Da / 0-Nu): ";
        if (!(is >> tempReturns)) throw std::invalid_argument("Optiune retur invalida.");

        obj.inventory = tempInventory;
        obj.premiumDiscount = tempDiscount;
        obj.shippingThreshold = tempThreshold;
        obj.region = tempRegion;
        obj.acceptsReturns = tempReturns;

    } catch (const std::exception& e) {
         is.clear();
        is.ignore(1000, '\n');
         throw; 
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Commercial& obj) {
    os << static_cast<const Application&>(obj) << "\n";
    os << "Regiune: " << obj.region << "\n";
    os << "Inventar: ";
    if (obj.inventory.empty()) {
        os << "Gol";
    } else {
        for (const auto& item : obj.inventory) os << "[" << item << "] ";
    }
    os << "\nReducere Premium: " << obj.premiumDiscount << "% | Prag Livrare: " << obj.shippingThreshold << "\n";
    os << "Retur disponibil: " << (obj.acceptsReturns ? "Da" : "Nu");
    return os;
}

void Commercial::display() const {
    std::cout << *this << std::endl;
}

bool Commercial::hasProduct(std::string productName) const {
    return std::find(inventory.begin(), inventory.end(), productName) != inventory.end();
}