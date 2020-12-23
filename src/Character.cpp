#include "Game.h"
#include "Character.h"
#include "Room.h"
#include "Item.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>

Character::Character() {
  this->name;
  this->description;
}

Character::Character(std::string name, std::string description) {
  this->name = name;
  this->description = description;
}

void Character::setName(std::string name) {
  this->name = name;
}

std::vector<Item*> Character::getInventory() {
  return inventory;
}

void Character::printInventory() {
  std::cout << "inventory List: " << std::endl;
  for (auto& x : inventory) {
    std::cout << x->getName() << std::endl;
  }
  if (inventory.size() == 0) {
    std::cout << "Empty inventory" << std::endl;
  }
}

Item* Character::getItem(int i) {
  return inventory.at(i);
}

void Character::addItem(Item* item) {
  inventory.push_back(item);
}

bool Character::removeItem(Item* item) {
  for (int i = 0; i < inventory.size(); i++) {
    if (inventory[i]->getName() == item->getName()) {
      std::cout << item->getName() << " was removed from your inventory.\n";
      inventory.erase(inventory.begin()+i);
      return true;
    }
  }
  return false;
}

bool Character::checkAction(ACTION a) {
  if (actions[a] == true) {
    return true;
  } else {
    return false;
  }
}

Player::Player(std::string name, std::string description) {
  this->name = name;
  this->description = description;
}

Room* Player::getLocation() {
  return location;
}

void Player::setLocation(Room* pos) {
  location = pos;
}

void Player::setWin(bool w) {
  win = w;
}

void Player::setLose(bool l) {
  lose = l;
}

bool Player::checkWin() {
  return win;
}

bool Player::checkLose() {
  return lose;
}

bool Player::haveItem(Item* item) {
  for (int i = 0; i < this->getInventory().size(); i++) {
    if (this->getItem(i)->getName() == item->getName()) {
      return true;
    }
  }
  return false;
}

void Player::countAle() {
  alecounter++;
  if (alecounter > 3) {
    setLose(1);
    std::cout << "You're too drunk. You fell and hit your head." << std::endl;
  }
}

NPC::NPC(std::string name, std::string description) {
  this->name = name;
  this->description = description;
}

NPC::NPC(std::string name, std::string description,
  std::string dialogue) {
  this->name = name;
  this->description = description;
  this->dialogue = dialogue;
}

NPC::~NPC() {}

void NPC::addDialogue(std::string s) {
  dialogue = s;
}

void NPC::removeAllItems() {
  this->inventory.clear();
}

std::string NPC::getDialogue() {
  return dialogue;
}
