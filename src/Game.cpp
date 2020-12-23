#include <iostream>
#include <string>
#include <vector>
#include "Game.h"

#include "Action.h"
#include "Environment.h"
#include "Character.h"
#include "Item.h"
#include "PuzzleGame.h"

Game::Game() {
}

Game::~Game() {
}

void Game::gameStart() {
    // print welcome message and ask player their name,
    // then create player character.
    std::string name = "";
    std::cout <<
    "Welcome to our Text Based Adventure Game!"
    << std::endl << std::endl <<
    "You find yourself living an impoverished life. Young and weak, you\n"
    "huddle against a wall outside warmed by a travers oven under the \n"
    "starless sky. Thinking about how you ended up here, you hear an armed\n"
    "man strolling down the streets, bragging to his comrades about a map\n"
    "that will lead him to fame and riches. Perhaps this is a chance given\n"
    "by the gods that you thought had abandoned." << std::endl <<
    std::endl << "What is your name?" << std::endl;
    std::cin >> name;
    std::cout << "Hello, " << name << " you are an adventurer!" << std::endl;
    std::string player1desc = "An adventurer!";
    p1 = new Player(name, player1desc);

    //create Town starting point for the adventure
    std::string townDesc =
    "The town of Goldcrest is an quiet resting place that served traveling\n"
    "miners headed to the cavernous region of the Ember mountains. There's a\n"
    "town square with a Tavern that appears to be the only notable building\n"
    "in sight.";
    Environment *myTown = new Environment("Goldcrest", townDesc, 3, 3);
    eVec.push_back(myTown);

    //add rooms to town [townSquare, northRoad, southRoad]
    /*  MAP of Goldcrest
        {[0,1,0]}
        {[0,1,1]}
        {[0,1,0]}
    */
    std::string townSqDesc =
    "Goldcrest town square is quite in the dying light. The shop owners have\n"
    "closed their stalls and gone home for the night. Few people are outside\n"
    "this evening.";
    Room *townSquare = new Room("Town Square", townSqDesc, 1, 1, 1, 0);
    std::string northRoadDesc =
    "A wide cobbled road leading to the northern gate of the town.";
    Room *northRoad = new Room("North Road", northRoadDesc, 1, 1, 0, 0);
    std::string southRoadDesc =
    "A wide cobbled road leading back to the slums. Quite a few people sleep\n"
    "on the side of the road and in the alleyways.";
    Room *southRoad = new Room("South Road", southRoadDesc, 1, 0, 0, 0);
    std::string tavernDoorDesc =
    "A heavy wooded door to the tavern is in front of you. You hear muffled\n"
    "noise coming from inside.";
    Room *tavernDoor = new Room("Tavern Door", tavernDoorDesc, 0, 0, 1, 1);
    myTown->setRoom(northRoad, 0, 1);
    myTown->setRoom(townSquare, 1, 1);
    myTown->setRoom(southRoad, 2, 1);
    myTown->setRoom(tavernDoor, 1, 2);
    myTown->setStart(tavernDoor);
    myTown->setEnd(northRoad);


    //create character


    //create Warring Griffon Tavern
    std::string tavernDesc =
    "You are in the local Tavern, the Warring Griffon, a large aging\n"
    "establishment. An old gentleman with an eyepatch tends the bar and a\n"
    "larger rosy cheeked man is loudly conversing with him. Another individual"
    "\n"
    "is reading by a hearth in the corner.";
    Environment *myTavern = new Environment("Tavern", tavernDesc, 3, 3);
    eVec.push_back(myTavern);

    //add rooms to town [bar, cornerTable, entry, lounge]
    /*  MAP of Tavern
        {[0,0,1]}
        {[1,1,1]}
        {[0,0,0]}
    */
    std::string loungeDesc = "You stand central in the lounge facing the bar.";
    Room *lounge = new Room("Lounge", loungeDesc, 0, 0, 1, 1);
    std::string barDesc =
    "A rough wooden bar with stools spanning it. The bartender glances at you.";
    Room *bar = new Room("Bar", barDesc, 1, 0, 0, 1);
    std::string entryDesc =
    "Smoke fills your nostrils as you step into the dimly lit Tavern.";
    Room *entry = new Room("Entryway", entryDesc, 0, 0, 1, 1);
    std::string cornerDesc =
    "The man reading doesn't bother to look up as he waves you away with one\n"
    "word, 'Leave.' A simple sword hangs from his belt, and a feathered hat\n"
    "adorns his head.";
    Room *corner = new Room("Corner Table", cornerDesc, 0, 1, 0, 0);
    myTavern->setRoom(corner, 0, 2);
    myTavern->setRoom(bar, 1, 2);
    myTavern->setRoom(lounge, 1, 1);
    myTavern->setRoom(entry, 1, 0);
    myTavern->setStart(entry);
    myTavern->setEnd(entry);

    //create forest
    std::string forestDesc =
    "A thick wall of pines and varius underbrush block any other path except\n"
    "for the well traveled path, however with the evening's thick fog you can\n"
    "only see so far ahead.";
    Environment *myForest = new Environment("Forest", forestDesc, 3, 3);
    eVec.push_back(myForest);

    //add rooms to forest [northPath, southPath, midForest, creepyPath, hut]
    /*  MAP of Forest
        {[1,0,0]}
        {[1,1,1]}
        {[1,0,0]}
    */
    std::string midForestDesc =
    "Surrounded by trees in the dark and misty night, a signpost marks the\n"
    "branching of the path into three.";
    Room *midForest = new Room("Forest Center", midForestDesc, 1, 1, 1, 0);
    std::string northPathDesc =
    "The path continues north to the Ember mountains. A stone door appears\n"
    "through the parting trees.";
    Room *northPath = new Room("North Path", northPathDesc, 1, 1, 0, 0);
    std::string southPathDesc =
    "A short walk after leaving town you enter a heavily forested region with\n"
    "one ominous path headed into it.";
    Room *southPath = new Room("South Path", southPathDesc, 1, 1, 0, 0);
    std::string creepyPathDesc =
    "Looking to the right, the path could just barely be called that as the\n"
    "underbrush has taken it over. The trees seem to wither away, cobwebs\n"
    "spanning the branches.";
    Room *creepyPath = new Room("Creepy Path", creepyPathDesc, 0, 0, 1, 1);
    std::string hutDesc =
    "At the end of the path you find an old wooden hut with a man sitting on\n"
    "a chair in front of it, reading.";
    Room *hut = new Room("Hermit's Hut", hutDesc, 0, 0, 0, 1);


    myForest->setRoom(northPath, 0, 0);
    myForest->setRoom(midForest, 1, 0);
    myForest->setRoom(creepyPath, 1, 1);
    myForest->setRoom(hut, 1, 2);
    myForest->setRoom(southPath, 2, 0);
    myForest->setStart(southPath);
    myForest->setEnd(northPath);

    //create Cave
    std::string caveDesc = "The caze twists and turns into darkness.";
    Environment *myCave = new Environment("Cave", caveDesc, 5, 5);
    eVec.push_back(myCave);

    //add rooms to Cave [northPath, southPath, midForest, creepyPath, hut]
    /*  MAP of Cave
        {[0,0,1]}
        {[1,1,1]}
        {[1,0,0]}
    */
    std::string midCaveDesc =
    "The branching tunnels have numbers engraved above them.\n"
    "It appears the dragon has and affinity for prime numbers, \n"
    "follow them to find the dragon and the treasure.\n"
    "The tunnel to your left is labled: 87\n"
    "Directly ahead: 129\n"
    "To your right you see: 97";
    Room *mainCave = new Room("Main Cavern", midCaveDesc, 1, 1, 1, 1);
    std::string tunnel1Desc =
    "This tunnel appears to be a dead end. 'Right' to go back.\n";
    Room *tunnel1 = new Room("Tunnel", tunnel1Desc, 0, 0, 1, 0);
    std::string tunnel2Desc =
    "This tunnel appears to be a dead end. 'Down' to go back.\n";
    Room *tunnel2 = new Room("Tunnel", tunnel2Desc, 0, 1, 0, 0);
    std::string tunnel3Desc =
    "The tunnel to your left is labled: 119\n"
    "To your right you see: 241";
    Room *tunnel3 = new Room("Tunnel", tunnel3Desc, 0, 0, 1, 1);
    std::string tunnel4Desc =
    "The tunnel to your left is labled: 69\n"
    "The tunnel leading up is labled: 57\n"
    "To your right you see: 67";
    Room *tunnel4 = new Room("Tunnel", tunnel4Desc, 1, 0, 1, 1);
    std::string tunnel5Desc =
    "The tunnel leading up is labled: 143\n"
    "Behind you, you see: 41";
    Room *tunnel5 = new Room("Tunnel", tunnel5Desc, 1, 1, 0, 0);
    std::string tunnel6Desc =
    "The tunnel leading left is labled: 77\n"
    "Behind you, you see: 113";
    Room *tunnel6 = new Room("Tunnel", tunnel6Desc, 0, 1, 0, 1);
    std::string tunnel7Desc =
    "The tunnel leading left is labled: 85\n"
    "On your right, you see: 263";
    Room *tunnel7 = new Room("Tunnel", tunnel7Desc, 0, 0, 1, 1);
    std::string tunnel8Desc =
    "The tunnel leading up is labled: 146\n"
    "On your right, you see: 569";
    Room *tunnel8 = new Room("Tunnel", tunnel8Desc, 1, 0, 1, 0);
    std::string tunnel9Desc =
    "This tunnel appears to be a dead end. 'Down' to go back.\n";
    Room *tunnel9 = new Room("Tunnel", tunnel9Desc, 1, 0, 1, 0);
    std::string tunnel10Desc =
    "The tunnel leading up is labled: 41\n"
    "On your left, you see: 82";
    Room *tunnel10 = new Room("Tunnel", tunnel10Desc, 1, 0, 0, 1);
    std::string tunnel11Desc =
    "The tunnel leading up is labled: 571\n"
    "Behind you, you see: 91";
    Room *tunnel11 = new Room("Tunnel", tunnel11Desc, 1, 1, 0, 0);
    std::string tunnel12Desc =
    "The tunnel leading up is labled: 277\n"
    "Behind you, you see: 123";
    Room *tunnel12 = new Room("Tunnel", tunnel12Desc, 1, 1, 0, 0);
    std::string caveEntryDesc =
    "A stone door is embedded into the mountain. It looks to have a crudely\n"
    "drawn face on it and red text 'NO RETURN'.";
    Room *caveEntry = new Room("Entry Cavern", caveEntryDesc, 1, 0, 0, 0);
    std::string dragonCaveDesc =
    "A mountain of gold, blanketing a beast of scales, tooth and claw,\n"
    " shifts with its breathing. Other piles of gold seem to contain relics\n"
    " and other priceless treasures.";
    Room *dragonCave = new Room("Dragon's Den", dragonCaveDesc, 0, 0, 0, 0);
    myCave->setRoom(mainCave, 3, 1);
    myCave->setRoom(tunnel1, 3, 0);
    myCave->setRoom(caveEntry, 4, 1);
    myCave->setRoom(dragonCave, 0, 4);
    myCave->setRoom(tunnel2, 2, 1);
    myCave->setRoom(tunnel3, 3, 2);
    myCave->setRoom(tunnel4, 3, 3);
    myCave->setRoom(tunnel5, 2, 3);
    myCave->setRoom(tunnel6, 1, 3);
    myCave->setRoom(tunnel7, 1, 2);
    myCave->setRoom(tunnel8, 1, 1);
    myCave->setRoom(tunnel9, 0, 1);
    myCave->setRoom(tunnel10, 3, 4);
    myCave->setRoom(tunnel11, 2, 4);
    myCave->setRoom(tunnel12, 1, 4);
    myCave->setStart(caveEntry);
    myCave->setEnd(dragonCave);

    //setAdjacentRooms
    myTown->setNeighborEnv(myForest, myTavern);
    myTavern->setNeighborEnv(nullptr, myTown);
    myForest->setNeighborEnv(myCave, myTown);
    myCave->setNeighborEnv(nullptr, myForest);
    myTown->setAdjacentRooms();
    myTavern->setAdjacentRooms();
    myForest->setAdjacentRooms();
    myCave->setAdjacentRooms();
    northRoad->setNeighborRoom(South, townSquare);
    northPath->setNeighborRoom(South, midForest);
    entry->setNeighborRoom(West, tavernDoor);
    caveEntry->setNeighborRoom(South, northPath);
    tavernDoor->setNeighborRoom(West, townSquare);

    //Create game items
    std::string cakeDesc =
    "A double layer chocolate cake with cherries cycling a single lit candle.";
    Item* cake = new Item("Cake", cakeDesc);
    std::string pieDesc =
    "A steaming slice of apple pie with a golden crust.";
    Item* pie = new Item("Pie", pieDesc);
    std::string mapDesc =
    "A canvas sheet with a map inked onto the surface. As you look at it\n"
    "seems to shift.";
    Item* map = new Item("Map", mapDesc);
    std::string coinDesc =
    "A rusted iron coin with an indistinguishable image on its face.\n"
    " It feels lucky.";
    Item* coin = new Item("Coin", coinDesc);
    std::string swordDesc =
    "A simple iron sword with rune engravings down the center of the blade.";
    Item* sword = new Item("Sword", swordDesc);
    std::string potionDesc =
    "A vial containing a thick purple liquid.";
    Item* potion = new Item("Potion", potionDesc);
    std::string aleDesc =
    "A large tankard of frothy liquid.";
    Item* ale = new Item("Ale", aleDesc);

    //set player location
    p1 -> setLocation(southRoad);

    std::string bartenderDia =
    "An, ale for you? (getitem for Ale)";
    std::string bartendDesc =
    "A man who sells many drinks.";
    NPC* bartender = new NPC("Bartender", bartendDesc, bartenderDia);
    bar->setChar(bartender);
    std::string mayorDia =
    "I have a quest for you! There's a Dragon that has been stealing gold\n"
    "from the towns people. We need it killed, and any treasure the Dragon\n"
    "has will be yours! Head north to find the cave! Help can be found in\n"
    "the Town's Tavern. You can find a weapon in the forest to aid you.";
    std::string mayorDesc =
    "He looks burdened by worries.";
    NPC* mayor = new NPC("Mayor", mayorDesc, mayorDia);
    southRoad->setChar(mayor);
    std::string drunkDia =
    "Arrghghh this ale is my best friend. Ughh.. we're going to go find some\n"
    "treasure together! I have a map to the *hick* dragon's lair.";
    std::string drunkDesc =
    "He looks like he enjoys a drink or ten.";
    NPC* drunk = new NPC("Drunkard", drunkDesc, drunkDia);
    corner->setChar(drunk);
    std::string maidDia =
    "Hey sweetie, welcome!";
    std::string maidDesc =
    "A friendly young lady.";
    NPC* maid = new NPC("Bar Maid", maidDesc, maidDia);
    lounge->setChar(maid);
    std::string hermitDesc =
    "A older fellow that enjoys his solitude.";
    NPC* hermit = new NPC("Hermit", hermitDesc);
    hut->setChar(hermit);
    std::string dragonDesc =
    "A fearsome dragon that enjoys naps.";
    NPC* dragon = new NPC("Dragon", dragonDesc);
    dragonCave->setChar(dragon);

    //add everything to vectors so it can be deleted later
    iVec.push_back(pie);
    iVec.push_back(cake);
    iVec.push_back(coin);
    iVec.push_back(map);
    iVec.push_back(potion);
    iVec.push_back(sword);
    iVec.push_back(ale);


    //need to place items in rooms to be found

    drunk->addItem(map);
    hermit->addItem(sword);
    bar->setTreasure(ale);
    entry->setTreasure(coin);
    creepyPath->setTreasure(potion);
    townSquare->setTreasure(cake);
    hut->setTreasure(pie);

    //set character dialogue
    /*std::string drunkDia =
    "Arrghghh this ale is my best friend. Ughh.. we're going to go find some\n"
    "treasure together! I have a map to the *hick* dragon's lair.";
    drunk->addDialogue(drunkDia);
    std::string maidDia =
    "Hey sweetie, welcome!";
    maid->addDialogue(maidDia);
    std::string bartenderDia =
    "An, ale for you? (getitem for Ale)";
    bartender->addDialogue(bartenderDia);
    std::string mayorDia =
    "I have a quest for you! There's a Dragon that has been stealing gold\n"
    "from the towns people. We need it killed, and any treasure the Dragon\n"
    "has will be yours! Head north to find the cave! Help can be found in\n"
    "the Town's Tavern. You can find a weapon in the forest to aid you.";
    mayor->addDialogue(mayorDia);*/

    //print initial location
    std::cout << "You are start at " << p1->getLocation()->getName() << "\n";
    std::cout << p1 -> getLocation()
      -> getDescription() << std::endl;
    p1->getLocation()->printChars();
    doAction(Talk);

    cVec.push_back(drunk);
    cVec.push_back(bartender);
    cVec.push_back(mayor);
    cVec.push_back(maid);
    cVec.push_back(hermit);
    cVec.push_back(dragon);
}

bool Game::playerTurn() {
  if (p1->checkLose()) {
    std::cout << "YOU LOSE!" << std::endl;
    return false;
  } else if (p1->checkWin()) {
    std::cout << "You slay the dragon and the treasure is yours to take.\n"
     << "CONGRATULATIONS! YOU WIN!" << std::endl;
     return false;
  }
  Input in;
  std::cout << "What would you like to do" << std::endl;
  std::string str = in.getInput();
  if (isAction(str)) {
    doAction(getAction(str));
  } else if (isMove(str)) {
    doMove(getMove(str));
  } else {
    std::cout << "This should not print..." << std::endl;
  }
  return true;
}

void Game::doAction(ACTION a) {
  std::vector<Item*>::iterator it;
  std::string itemName;
  bool c = false;
  switch (a) {
    case Search:
      if (p1->getLocation()->getTreasure() != nullptr) {
        std::cout << "You search the area and find a " <<
        p1->getLocation()->getTreasure()->getName() <<
        ", type 'getitem' to add\n"
        "this to your inventory.\n";
      } else if (p1->getLocation()->getName() == "Dragon's Den") {
        std::cout << "The only items in the room are the dragon's gold.\n"
        "You won't be able to grab any while the dragon's alive.\n";
      } else {
        std::cout << "You search the area and find nothing of use.\n";
      }
      break;
    case InspectItem:
      std::cout << "Which item would you like to inspect? (case sensitive)"
      << std::endl;
      p1->printInventory();
      std::cin >> itemName;
      std::cout << std::endl;
      for (int i = 0; i < p1->getInventory().size(); i++) {
        if (p1->getItem(i)->getName() == itemName) {
          std::cout << p1->getItem(i)->getDescription() << std::endl;
          c = true;
          break;
        }
      }
      if (!c) {
        std::cout << "There is no item by that name in your inventory.\n";
      }
      break;
    case UseItem:
      std::cout << "Which item would you like to use? (case sensitive)"
      << std::endl;
      p1->printInventory();
      std::cin >> itemName;
      std::cout << std::endl;
      for (int i = 0; i < p1->getInventory().size(); i++) {
        if (p1->getItem(i)->getName() == itemName) {
          p1->getItem(i)->useItem(p1);
          c = 1;
          break;
        }
      }
      if (!c) {
          std::cout << "That item isn't in your inventory." << std::endl;
      }
      break;
    case Talk:
      //need to engage another character.
      //check if char and p1 in same rooms
      if (p1->getLocation()->getName() == "Hermit's Hut") {
        PuzzleGame p;
        p.play(p1, p1->getLocation()->getNPC());
      } else if (p1->getLocation()->getName() == "Dragon's Den") {
        std::cout << "As you open your mouth to speak " <<
        "the dragon incinerates you with his fire breath.\n"
        "I'm not sure what you expected to happen there.\n";
        "Who tries to talk to a dragon?\n";
        p1->setLose(1);
      } else if (p1->getLocation()->isChar()) {
        std::cout << p1->getLocation()->getNPC()->getDialogue() << std::endl;
      }
      //enter dialogue -> dialogue handles linear discussion
      break;
    case Attack:
      //can attack in certain rooms
      if (p1->getLocation()->getName() == "Dragon's Den") {
        //set win if player has sword, loss otherwise
        for (int i = 0; i < p1->getInventory().size(); i++) {
          if ("Sword" == p1->getItem(i)->getName()) {
            p1->getItem(i)->useItem(p1);
            p1->setWin(1);
            c = true;
          }
        }
        if (!c) {
          std::cout << "You try attacking the dragon without a weapon.\n"
          "Silly adventurer, you are burnt to a crisp.\n";
          p1->setLose(1);
        }
      } else {
        std::cout <<
        "You attack nothing, keep this up and people might think you're crazy."
        << std::endl;
      }
      break;
    case GetItem:
    //check if item can be added
      if (p1->getLocation()->getTreasure() != nullptr &&
       p1->getLocation()->getName() != "Bar") {
        //print confirmation message
        std::cout << p1->getLocation()->getTreasure()->getName() <<
        " was added to your inventory." << std::endl;
        //add the item to getInventory
        p1->addItem(p1->getLocation()->getTreasure());
        p1->getLocation()->removeTreasure();
      } else if (p1->getLocation()->getName() == "Bar") {
          //add ale here
          p1->addItem(p1->getLocation()->getTreasure());
          std::cout <<
          " was added to your inventory. Can you outdrink the man in the\n"
          "man in the corner?" << std::endl;
      } else if (p1->getLocation()->getName() == "Dragon's Den") {
        std::cout << "You reach for a gold coin by your feet.\n"
        "The dragon incinerates you with his fire breath.\n"
        "I'm not sure what you expected to happen there.\n";
        p1->setLose(1);
      } else {
          std::cout << "There is no available item." << std::endl;
      }
      break;
    case Steal:
      if (p1->getLocation()->getName() == "Corner Table") {
      //can steal in certain spot -> check for that room
        p1->addItem(p1->getLocation()->getNPC()->getItem(0)); //adds map
        p1->getLocation()->getNPC()->removeAllItems();
        std::cout << "You steal the map the drunkard boasted about.\n" <<
        "He was to busy drinking to notice..." << std::endl;
      } else if (p1->getLocation()->getName() == "Hermit's Hut") {
        std::cout << "The Hermit notices you trying to steal his wares.\n" <<
        "He quickly pulls a knife and throws it, it was the last thing you saw."
        << std::endl << "YOU DIED!" << std::endl;
        p1->setLose(1);
      } else if (p1->getLocation()->getName() == "Dragon's Den") {
        std::cout << "You reach for a gold coin by your feet.\n"
        "The dragon incinerates you with his fire breath.\n"
        "I'm not sure what you expected to happen there.\n";
        p1->setLose(1);
      } else {
        std::cout << "Be careful who you try to steal from." << std::endl;
      }
      break;
    case Drop:
      std::cout << "Which item would you like to drop? (case sensitive)"
      << std::endl;
      p1->printInventory();
      std::cin >> itemName;
      break;
    case Quit:
      p1->setLose(1);
      break;
  }
}

void Game::doMove(MOVE m) {
  if (p1->getLocation()->getCollision(m)) {
    switch (m) {
      case North:
        p1->setLocation(p1->getLocation()->getNeighborRoom(m));
        std::cout << "You've entered " << p1->getLocation()->getName() <<
        std::endl;
        std::cout << p1->getLocation()->getDescription() << std::endl;
        p1->getLocation()->printChars();
        break;
      case East:
        p1->setLocation(p1->getLocation()->getNeighborRoom(m));
        std::cout << "You've entered " << p1->getLocation()->getName() <<
        std::endl;
        std::cout << p1->getLocation()->getDescription() << std::endl;
        p1->getLocation()->printChars();
        break;
      case South:
        p1->setLocation(p1->getLocation()->getNeighborRoom(m));
        std::cout << "You've entered " << p1->getLocation()->getName() <<
        std::endl;
        std::cout << p1->getLocation()->getDescription() << std::endl;
        p1->getLocation()->printChars();
        break;
      case West:
        p1->setLocation(p1->getLocation()->getNeighborRoom(m));
        std::cout << "You've entered " << p1->getLocation()->getName() <<
        std::endl;
        std::cout << p1->getLocation()->getDescription() << std::endl;
        p1->getLocation()->printChars();
        break;
    }
  } else {
    std::cout << "You cannot move in that direction." << std::endl;
  }
}

std::string Game::getDescription() {
  return description;
}

void Game::setDescription(std::string d) {
  description = d;
}

std::string Game::getName() {
  return name;
}

bool Game::isAction(std::string a) {
  if (a == "search") {
    return true;
  } else if (a == "inspectitem") {
    return true;
  } else if (a == "useitem") {
    return true;
  } else if (a == "talk") {
    return true;
  } else if (a == "attack") {
    return true;
  } else if (a == "getitem") {
    return true;
  } else if (a == "steal") {
    return true;
  } else if (a == "drop") {
    return true;
  } else if (a == "quit") {
    return true;
  } else {
  return false;
}
}

bool Game::isMove(std::string m) {
  if (m == "up" || m == "north") {
    return true;
  } else if (m == "right" || m == "east") {
    return true;
  } else if (m == "down" || m == "south") {
    return true;
  } else if (m == "west" || m == "left") {
    return true;
  } else {
  return false;
}
}

ACTION Game::getAction(std::string a) {
  if (a == "search") {
    return Search;
  } else if (a == "inspectitem") {
    return InspectItem;
  } else if (a == "useitem") {
    return UseItem;
  } else if (a == "talk") {
    return Talk;
  } else if (a == "attack") {
    return Attack;
  } else if (a == "getitem") {
    return GetItem;
  } else if (a == "steal") {
    return Steal;
  } else if (a == "drop") {
    return Drop;
  } else if (a == "quit") {
    return Quit;
  } else {
  return Drop;
}
}

MOVE Game::getMove(std::string m) {
  if (m == "up" || m == "north") {
    return North;
  } else if (m == "right" || m == "east") {
    return East;
  } else if (m == "down" || m == "south") {
    return South;
  } else if (m == "west" || m == "left") {
    return West;
  } else {
  std::cout << "Invalid move";
  return West;
}
}

//we realize we should have not used game as the superclass now. lesson learned
void Game::deleteStuff() {
  //need to delete rooms, environments, items etc.
  delete p1;
  for (auto& x : iVec) {
    delete x;
  }
  for (auto& x : cVec) {
    delete x;
  }
  for (auto& x : eVec) {
    delete x;
  }
}
