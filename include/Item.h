#ifndef ITEM_H
#define ITEM_H

#include "Game.h"
#include "Action.h"
#include <map>
#include <iostream>
#include <string>

/// \brief Contains all informations related to a Item.

/// \class Item Item.h <Item.h>
class Item: public Game {
 public:
  /// \brief Class constructor
  /// \param[in] name string
  /// \param[in] description string
  Item(std::string name, std::string description);

  /// \brief Handles if a player can use an Item*
  /// \param[in] p1 Player*
  bool useItem(Player* p1);

 private:
};
#endif
