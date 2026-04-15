#include "AppManager.h"
#include "Social.h"
#include "Commercial.h"
#include "SocialProfile.h"


AppManager::AppManager() {}
AppManager::~AppManager() {}

void AppManager::addSocialAccount() {
    std::string tempUser;
    bool unique = false;
    while (!unique) {
        std::cout << "Introduceti username: ";
        std::cin >> std::ws;
        std::getline(std::cin, tempUser);

        unique = true; 
        for (auto p : profiles) {
            if (p->getUsername() == tempUser) {
                std::cout << "[Eroare] Username-ul deja exista! Incearca altul.\n";
                unique = false; 
                break;
            }
        }
    }
    Social* sApp = new Social();
    SocialProfile* sProf = new SocialProfile();

    sProf->setUsername(tempUser); 

    std::cin >> *sApp;
    sProf->setApp(sApp);
    sProf->readData(); 

    apps.push_back(sApp);
    profiles.push_back(sProf);

    std::cout << "\n[Succes] Contul pentru " << sApp->getName() << " a fost creat.\n";
}
void AppManager::addCommercialAccount(){}

void AppManager::runMenu() 
{
    int choice=-1;
    while(choice != 0)
    {
        std::cout << "1. Creare Cont Nou (Social/Comercial)\n";
        std::cout << "2. Afiseaza Toate Conturile\n";
        std::cout << "0. Iesire\n";
        std::cout << "Selectie: ";std::cin>>choice;

        switch (choice) {
            case 1: 
                menuCreareCont(); 
                break;
            case 2: 
                displayAll(); 
                break;
            case 0: 
                std::cout << "Inchidere...\n"; 
                return;
            default: 
                std::cout << "Optiune invalida.\n";
        }
    }
}
void AppManager::menuCreareCont() 
{
    int option=-1;
    std::cout << "1. Cont Social (ex: Facebook)\n";
    std::cout << "2. Cont Comercial (ex: eMAG)\n";
    std::cout << "0. Inapoi la meniul principal\n";
    std::cout << "Selectie: "; std::cin>>option;

    switch(option)
    { 
        case 1: 
            addSocialAccount(); break;
        case 2:
            addCommercialAccount(); break;
        case 0:
            return;
        default:
            std::cout << "Optiune invalida.\n";
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