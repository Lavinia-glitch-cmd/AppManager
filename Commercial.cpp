#include "Commercial.h"

Commercial::Commercial() 
    : Application(), inventory(0), commision(0.0f), escrowEnabled(false), 
      merchantType("Individual"), activeAds(0), total(0.0) 
{}

Commercial::Commercial(std::string name, std::string type, std::string developer, float version, int sizeMB, int inventory, float commision, bool escrowEnabled, std::string merchantType, int activeAds, double total)
    : Application(name, type, developer, version, sizeMB),inventory(inventory),
      commision(commision),escrowEnabled(escrowEnabled),
      merchantType(merchantType),activeAds(activeAds),total(total)
{}

Commercial::Commercial(const Commercial& obj) 
    : Application(obj),inventory(obj.inventory),
      commision(obj.commision),escrowEnabled(obj.escrowEnabled),
      merchantType(obj.merchantType),activeAds(obj.activeAds),total(obj.total)
{}

Commercial& Commercial::operator=(const Commercial& obj) {
    if (this != &obj) {
        Application::operator=(obj);
        this->inventory = obj.inventory;
        this->commision = obj.commision;
        this->escrowEnabled = obj.escrowEnabled;
        this->merchantType = obj.merchantType;
        this->activeAds = obj.activeAds;
        this->total = obj.total;
    }
    return *this;
}

Commercial::~Commercial() {}

void Commercial::launch() {
    std::cout << "Starting Commercial Store: " << name << "..." << std::endl;
    std::cout << "Marketplace active with " << inventory << " products." << std::endl;
}

void Commercial::displayDetails() const {
    std::cout << "Commercial App: " << name << " | Merchant: " << merchantType 
              << " | Commision: " << commision << "% | Total Volume: " << total << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Commercial& obj) {
    os << (const Application&)obj << "\n" 
       << "Inventory: " << obj.inventory << " | Ads: " << obj.activeAds 
       << " | Escrow: " << (obj.escrowEnabled ? "Yes" : "No")
       << " | Total: " << obj.total;
    return os;
}

std::istream& operator>>(std::istream& is, Commercial& obj) {
    std::cout << "Inventory: "; is >> obj.inventory;
    std::cout << "Commision: "; is >> obj.commision;
    std::cout << "Escrow (0/1): "; is >> obj.escrowEnabled;
    std::cout << "Merchant Type: "; is >> obj.merchantType;
    std::cout << "Active Ads: "; is >> obj.activeAds;
    std::cout << "Total Volume: "; is >> obj.total;
    return is;
}
