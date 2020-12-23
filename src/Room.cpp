#include "Room.h"

#include "Item.h"
#include "Character.h"

#include <string>
#include <iostream>

Room::Room(std::string name, std::string description,
  bool colUp, bool colDown, bool colRight, bool colLeft) {
  this -> name = name;
  this -> description = description;

  collision[North] = colUp;
  collision[East] = colRight;
  collision[South] = colDown;
  collision[West] = colLeft;
}

bool Room::getCollision(MOVE m) {
  return collision[m];
}

void Room::setCollision(MOVE m, bool b) {
  collision[m] = b;
}

Item* Room::getTreasure() {
  return treasure;
}

void Room::setTreasure(Item* item) {
  if (treasure == nullptr) {
    treasure = item;
  }
}

bool Room::removeTreasure() {
  if (treasure == nullptr) {
    return 0;
  } else {
    treasure = nullptr;
    return 1;
  }
}

void Room::setNeighborRoom(MOVE m, Room* r) {
  switch (m) {
    case North:
      northRoom = r;
    case East:
      eastRoom = r;
    case South:
      southRoom = r;
    case West:
      westRoom = r;
    }
}

Room* Room::getNeighborRoom(MOVE m) {
  switch (m) {
    case North:
      return northRoom;
    case East:
      return eastRoom;
    case South:
      return southRoom;
    case West:
      return westRoom;
  }
  return nullptr;
}

NPC* Room::getNPC() {
  return character;
}

bool Room::setChar(NPC* c) {
  if (c == nullptr) {
    return 0;
  }
  character = c;
  return 1;
}

bool Room::removeChar() {
  if (character == nullptr) {
    return 0;
  }
  character = nullptr;
  return 1;
}

void Room::printChars() {
  if (character != nullptr) {
    std::cout << "You may interact with " << character->getName()
    << std::endl;
  }
}

bool Room::isChar() {
  if (character != nullptr) {
    return 1;
  }
  return 0;
}

Room::~Room() {}
