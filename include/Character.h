#ifndef CHARACTER_H
#define CHARACTER_H

#include "Game.h"
#include "Action.h"
#include <map>
#include <vector>
#include <string>

class Room;
class Item;

/// \brief Contains all informations related to a Character.
/// Allows manipulation of movement and inventory.
/// Stores posion of player and win/lose conditions.

/// \class Character Character.h <Character.h>
class Character : public Game {
 public:
  /// \brief Class constructor
  Character();

  /// \brief Class constructor
  /// \param[in] name string
  /// \param[in] description string
  Character(std::string name, std::string description);

  /// \brief Class destructor
  virtual ~Character() {}

  /// \brief Sets or changes name
  /// \param[in] name string
  void setName(std::string name);

  /// \brief Gets the vector of inventory items stored in a Character
  std::vector<Item*> getInventory();

  /// \brief Prints the vector of inventory items stored in a Character
  void printInventory();

  /// \brief Gets an Item* at a position in the inventory
  /// \param[in] i int is the position
  Item* getItem(int i);

  /// \brief adds an Item* to the inventory
  /// \param[in] item Item*
  void addItem(Item* item);

  /// \brief removes an Item* from the inventory returns true if it was removed
  /// \param[in] item Item*
  bool removeItem(Item* item);

  /// \brief checks if a player can do an ACTION
  /// \param[in] a ACTION
  bool checkAction(ACTION a);

 protected:
      std::vector<Item*> inventory;
      std::map<ACTION, bool> actions;
      std::string dialogue = "";
  
 private:
};

/// \brief Contains all informations related to a Player. Allows manipulation of
/// movement and inventory. Stores posion of player and win/lose conditions.

/// \class Player Character.h <Character.h>
class Player : public Character {
 public:
  /// \brief Class constructor
  /// \param[in] name string
  /// \param[in] description string
  Player(std::string name, std::string description);

  ~Player() {}

  /// \brief gets a choice for the player
  int getChoice();

  /// \brief returns the Room* that the player is in
  Room* getLocation();

  /// \brief sets the Room* that the player is in
  /// \param[in] pos Room* the room the player moves into
  void setLocation(Room* pos);

  /// \brief sets if the Player has won
  /// \param[in] w bool
  void setWin(bool w);

  /// \brief sets if the Player has lost
  /// \param[in] l bool
  void setLose(bool l);

  /// \brief returns if the player has won, used in player turn
  bool checkWin();

  /// \brief returns if the player has lost, used in player turn
  bool checkLose();

  /// \brief checks if the Player has a specific Item*
  /// \param[in] item Item*
  bool haveItem(Item* item);

  /// \brief counts how many Ales a player has drank, get drunk -> you lose >:(
  void countAle();

 private:
  Room* location;
  bool win = 0;
  bool lose = 0;
  int alecounter = 0;
};

/// \brief Contains all informations related to a NPC. Allows manipulation of
/// movement and inventory. Stores posion of an NPC and dialogue.

/// \class NPC Character.h <Character.h>
class NPC : public Character {
 public:
  /// \brief Class constructor
  /// \param[in] name string
  /// \param[in] description string
  NPC(std::string name, std::string description, std::string dialogue);

  NPC(std::string name, std::string description);

  /// \brief Class deconstructor
  ~NPC();

  /// \brief Returns the stored dialogue
  std::string getDialogue();

  /// \brief adds Dialougue, used in game setup
  /// \param[in] s string
  void addDialogue(std::string s);

  /// \brief reomves all items stored in NPC inventory
  void removeAllItems();

 private:
};
#endif
