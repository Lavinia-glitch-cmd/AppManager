#include "AppManager.h"
#include "Social.h"
#include "Commercial.h"



AppManager::AppManager() {}
AppManager::~AppManager() {}

void AppManager::runMenu() 
{
    int choice=-1;
    while(choice != 0)
    {
        std::cout << "1. Cont Nou: Social \n";
        std::cout << "2. Cont Nou: Commercial \n";
        std::cout << "3. Afiseaza Toate Conturile\n";
        std::cout << "0. Iesire\n";
        std::cout << "Selectie: ";

        switch (choice) {
            case 1: addSocialAccount(); break;
            case 2: addCommercialAccount(); break;
            case 3: displayAll(); break;
            case 0: std::cout << "Inchidere manager...\n"; break;
            default: std::cout << "Optiune invalida!\n";
        }
    }
}

void AppManager::displayAll() const {
    if (profiles.empty()) {
        std::cout << "\nNu exista conturi inregistrate.\n";
        return;
    }
    for (auto p : profiles) {
        p->display(); 
        std::cout << "-----------------------------\n";
    }
}