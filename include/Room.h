#ifndef ROOM_H
#define ROOM_H

#include "Game.h"

class Item;
class Character;
class NPC;

#include <map>
#include <vector>
#include <string>

/// \brief Contains all informations related to a Room. Allows manipulation of
/// the contents of a room and helps player movement.

/// \class Room Room.h <Room.h>
class Room : public Game {
 public:
  /// \brief Class constructor
  /// \param[in] name string
  /// \param[in] description string
  /// \param[in] up down left right bools from movement. label walls
  Room(std::string name, std::string description,
  bool colUp, bool colDown, bool colRight, bool colLeft);

  /// \brief Class destructor
  ~Room();

  /// \brief Checks for a wall and returns true/false
  /// \param[in] the MOVE trying to be made
  bool getCollision(MOVE m);

  /// \brief Changes if there is a wall or not
  /// \param[in] the MOVE and associated bool value
  void setCollision(MOVE m, bool b);

  /// \brief Returns Item* if there is one stored in the room
  Item* getTreasure();

  /// \brief Stores an Item* in the Room
  /// \param[in] the Item* to be stored
  void setTreasure(Item* item);

  /// \brief Removes all Item*'s in the Room
  bool removeTreasure();

  /// \brief Sets Room Neighbors like linked list pointers
  /// \param[in] the MOVE choice
  /// \param[in] the Room* neighbor
  void setNeighborRoom(MOVE m, Room* r);

  /// \brief Gets Room Neighbor based on MOVE choice
  /// \param[in] the MOVE choice
  Room* getNeighborRoom(MOVE m);

  /// \brief Gets NPCif one exists in Room
  NPC* getNPC();

  /// \brief Sets NPC in Room
  /// \param[in] the NPC Character
  bool setChar(NPC* c);

  /// \brief Removes NPC in Room
  bool removeChar();

  /// \brief Prints NPC that can be interacted with in Room
  void printChars();

  /// \brief Checks if there is an NPC in Room
  bool isChar();

 private:
  Item* treasure = nullptr;
  std::map<MOVE, bool> collision;
  NPC* character = nullptr;
  Room* northRoom = nullptr;
  Room* eastRoom = nullptr;
  Room* southRoom = nullptr;
  Room* westRoom = nullptr;
};

#endif
