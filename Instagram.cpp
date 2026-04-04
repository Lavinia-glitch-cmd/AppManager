#include "Instagram.h"

Instagram::Instagram() 
    : Application(), Social(), followers(0), following(0), photos(0) {}

Instagram::Instagram(std::string name, std::string type, std::string developer, float version, int sizeMB, 
                     int users, std::string privacy, bool ads, float membership, bool blue_check, 
                     std::string category, bool reels, int followers, int following, int photos)
    : Application(name, type, developer, version, sizeMB), // Trimitem la Bunic
      Social(name, developer, version, sizeMB, users, privacy, ads, membership, blue_check, category, reels), // Trimitem la Tata
      followers(followers), 
      following(following), 
      photos(photos) 
{}

Instagram::Instagram(const Instagram& obj) 
    : Application(obj), 
      Social(obj), 
      followers(obj.followers), 
      following(obj.following), 
      photos(obj.photos) {}

Instagram& Instagram::operator=(const Instagram& obj) {
    if (this != &obj) {
        Social::operator=(obj);
        this->followers = obj.followers;
        this->following = obj.following;
        this->photos = obj.photos;
    }
    return *this;
}

Instagram::~Instagram() {}

std::ostream& operator<<(std::ostream& os, const Instagram& obj) {
    os << (const Social&)obj;
    os << " | Followers: " << obj.followers 
       << " | Following: " << obj.following 
       << " | Photos: " << obj.photos;
    return os;
}

std::istream& operator>>(std::istream& is, Instagram& obj) {
    is >> (Social&)obj;
    std::cout << "Followers: "; is >> obj.followers;
    std::cout << "Following: "; is >> obj.following;
    std::cout << "Photos: "; is >> obj.photos;
    return is;
}

void Instagram::launch() {
    std::cout << "Opening Instagram... Loading feed for " << followers << " followers.\n";
}

void Instagram::displayDetails() const {
    Social::displayDetails();
    std::cout << " [Instagram Stats] " << photos << " photos posted.\n";
}