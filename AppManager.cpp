#include "AppManager.h"
#include "Social.h"
#include "Commercial.h"
#include "SocialProfile.h"
#include "CommercialProfile.h"
#include <iostream>

AppManager::AppManager() {}

AppManager::~AppManager() {
    for (auto a : apps) delete a;
    for (auto p : profiles) delete p;
    apps.clear();
    profiles.clear();
}

void AppManager::createApp() {
    int typeChoice;
    std::cout << "\n--- ADMIN: CREARE APLICATIE NOUA ---\n";
    std::cout << "1. Aplicatie Comerciala (Magazin)\n";
    std::cout << "2. Aplicatie Sociala (Retea Sociala)\n";
    std::cout << "Selectie tip: ";
    std::cin >> typeChoice;

    Application* newApp = nullptr;

    switch (typeChoice) {
        case 1: {
            Commercial* cApp = new Commercial();
            std::cin >> *cApp; 
            newApp = cApp;
            break;
        }
        case 2: {
            Social* sApp = new Social();
            std::cin >> *sApp; 
            newApp = sApp;
            break;
        }
        default:
            std::cout << "[Eroare] Optiune invalida! Revenire la meniu.\n";
            return;
    }

    if (newApp != nullptr) {
        for (auto a : apps) {
            if (a->getName() == newApp->getName()) {
                std::cout << "[Eroare] Aplicatia '" << newApp->getName() << "' exista deja!\n";
                delete newApp;
                return;
            }
        }
        apps.push_back(newApp);
        std::cout << "[OK] Aplicatia '" << newApp->getName() << "' a fost creata.\n";
    }
}

void AppManager::addSocialAccount() {
    std::string targetAppName, tempUser;
    Social* existingApp = nullptr;

    while (existingApp == nullptr) {
        std::cout << "Numele retelei sociale (sau 'exit' pentru renuntare): ";
        std::cin >> std::ws;
        std::getline(std::cin, targetAppName);

        if (targetAppName == "exit") return;

        for (auto a : apps) {
            if (a->getName() == targetAppName) {
                existingApp = dynamic_cast<Social*>(a);
                break;
            }
        }

        if (existingApp == nullptr) {
            std::cout << "[Eroare] Aplicatia '" << targetAppName << "' nu exista!\n";
        }
    }

    bool unique = false;
    while (!unique) {
        std::cout << "Username: ";
        std::getline(std::cin, tempUser);
        unique = true;
        for (auto p : profiles) {
            if (p->getUsername() == tempUser) {
                std::cout << "[Eroare] Username existent! Incearca altul.\n";
                unique = false;
                break;
            }
        }
    }

    SocialProfile* sProf = new SocialProfile();
    sProf->setApp(existingApp);
    sProf->setUsername(tempUser);
    sProf->readData();

    profiles.push_back(sProf);
    std::cout << "\n[Succes] Contul pentru " << existingApp->getName() << " a fost creat.\n";
}

void AppManager::addCommercialAccount() {
    std::string targetAppName, tempUser;
    Commercial* existingApp = nullptr;

    // ADAUGAT: Bucla while ca sa nu te scoata in meniu la greseala
    while (existingApp == nullptr) {
        std::cout << "Numele aplicatiei comerciale (sau 'exit' pentru renuntare): ";
        std::cin >> std::ws;
        std::getline(std::cin, targetAppName);

        if (targetAppName == "exit") return;

        for (auto a : apps) {
            if (a->getName() == targetAppName) {
                existingApp = dynamic_cast<Commercial*>(a);
                break;
            }
        }

        if (existingApp == nullptr) {
            std::cout << "[Eroare] Aplicatia nu exista! Reincercati.\n";
        }
    }

    bool unique = false;
    while (!unique) {
        std::cout << "Username: ";
        std::getline(std::cin, tempUser);
        unique = true;
        for (auto p : profiles) {
            if (p->getUsername() == tempUser) {
                std::cout << "[Eroare] Username existent! Incearca altul.\n";
                unique = false;
                break;
            }
        }
    }

    CommercialProfile* cProf = new CommercialProfile();
    cProf->setApp(existingApp);
    cProf->setUsername(tempUser);
    cProf->readData();

    profiles.push_back(cProf);
    std::cout << "\n[Succes] Contul pentru " << existingApp->getName() << " a fost creat.\n";
}

void AppManager::runMenu() {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n1. Creare Cont Nou (Social/Comercial)\n";
        std::cout << "2. Afiseaza Toate Conturile (Admin)\n";
        std::cout << "3. Creare Aplicatie Noua (Admin)\n";
        std::cout << "4. Afiseaza Toate Aplicatiile (Admin)\n";
        std::cout << "5. LOGIN (Intra in cont)\n";
        std::cout << "0. Iesire\n";
        std::cout << "Selectie: "; 
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: menuCreareCont(); break;
            case 2: displayAllProfiles(); break;
            case 3: createApp(); break;
            case 4: displayAllApps(); break;
            case 5: login(); break;
            case 0: std::cout << "Inchidere program...\n"; break;
            default: std::cout << "Optiune invalida!\n";
        }
    }
}

void AppManager::menuCreareCont() {
    int option = -1;
    std::cout << "1. Cont Social \n";
    std::cout << "2. Cont Comercial\n";
    std::cout << "0. Inapoi la meniul principal\n";
    std::cout << "Selectie: "; std::cin >> option;

    switch (option) { 
        case 1: addSocialAccount(); break;
        case 2: addCommercialAccount(); break;
        case 0: return;
        default: std::cout << "Optiune invalida.\n";
    }
}

void AppManager::displayAllProfiles() const {
    if (profiles.empty()) {
        std::cout << "\nNu exista conturi inregistrate.\n";
        return;
    }
    std::cout << "\n--- LISTA CONTURI UTILIZATORI ---\n";
    for (size_t i = 0; i < profiles.size(); ++i) {
        std::cout << i + 1 << ". ";
        profiles[i]->display(); 
        std::cout << "--------------------------------\n";
    }
}

void AppManager::displayAllApps() const {
    if (apps.empty()) {
        std::cout << "\n[Info] Nu exista nicio aplicatie creata.\n";
        return;
    }
    std::cout << "\n==== LISTA APLICATII DISPONIBILE ====\n";
    for (size_t i = 0; i < apps.size(); ++i) {
        std::cout << i + 1 << ". ";
        apps[i]->display(); 
        std::cout << "--------------------------------\n";
    }
}

void AppManager::login() {
    std::string searchAppName, searchUser, searchPass;
    std::cout << "Numele aplicatiei: "; std::cin >> std::ws; std::getline(std::cin, searchAppName);
    std::cout << "Username: "; std::getline(std::cin, searchUser);
    std::cout << "Parola: "; std::getline(std::cin, searchPass);

    bool found = false;
    for (auto p : profiles) {
        if (p->getApp() != nullptr) {
            if (p->getApp()->getName() == searchAppName && 
                p->getUsername() == searchUser && 
                p->getPassword() == searchPass) {
                std::cout << "\n[SUCCESS] Autentificare reusita!\n";
                p->display(); 
                found = true;
                break;
            }
        }
    }
    if (!found) std::cout << "\n[EROARE] Date incorecte.\n";
}