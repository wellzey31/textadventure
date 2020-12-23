#include "Item.h"
#include "Character.h"
#include "Room.h"

#include <string>

Item::Item(std::string qname, std::string qdescription) {
  name = qname;
  description = qdescription;
}

bool Item::useItem(Player* p1) {
  if (this -> getName() == "Pie") {
    std::cout << "You devour the pie, it was tasty." << std::endl;
    p1->removeItem(this);
    return true;
  } else if (this -> getName() == "Coin") {
    std::cout << "You rub the coin and feel a bit luckier." << std::endl;
    return true;
  } else if (this -> getName() == "Cake") {
    std::cout << "You attempt to eat the cake but it vanishes." <<
    std::endl; //the cake is a lie
    p1->removeItem(this);
    return true;
  } else if (this -> getName() == "Map") {
      std::cout <<
      ".........[x]Dragon..\n"
      "....../=maze=/......\n"
      ".....| |............\n"
      ".....| |............\n"
      ".....| =[]Hut.......\n"
      ".....| |............\n"
      ".....| |............\n"
      ".Town| =[]Tavern....\n"
      ".....| |............\n";
    return true;
  } else if (this -> getName() == "Potion") {
    std::cout <<
    "You drink the potion. You feel unwell, why did you drink that?"
    << std::endl;
    std::cout << "You die a slow death from the poisonous potion.\n";
    p1->setLose(1);
    p1->removeItem(this);
    return true;
  } else if (this -> getName() == "Ale") {
    std::cout << "The ale is hoppy and refreshing." <<
    std::endl;
    p1->removeItem(this);
    p1->countAle();
    return true;
  }
  return false;
}
