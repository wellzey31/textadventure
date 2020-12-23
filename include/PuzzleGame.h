#pragma once
#include <iostream>
#include <string>
#include "Character.h"
#include "Item.h"

/// \brief Contains all informations related to athe PuzzleGame.
/// Allows the mini game to be played.

/// \class PuzzleGame PuzzleGame.h <PuzzleGame.h>
class PuzzleGame {
 private:
  std::string answer = "1541";
  std::string playerAnswer;

 public:
  /// \brief Plays the text mini puzzle game between the player and the hermit
  /// \param[in] p Player*
  /// \param[in] hermit NPC*
  void play(Player* p, NPC *hermit);
};
