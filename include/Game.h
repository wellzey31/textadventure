#ifndef GAME_H
#define GAME_H

#include "Input.h"

#include "Move.h"

class Action;
class Environment;
class Player;
class PuzzleGame;
class Character;
class Item;

#include <string>
#include <vector>

/// \brief Contains all informations related to a Game.

/// \class Game Game.h <Game.h>
class Game {
 public:
    /// \brief Class constructor
    Game();

    /// \brief Class destructor
    ~Game();

    /// \brief sets up a fresh instance of game. Creates all game entities
    void gameStart();

    /// \brief Handles a player turn. get's input -> does move or action.
    bool playerTurn();

    /// \brief Handles a player ACTION
    void doAction(ACTION a);

    /// \brief Handles a player ACTION
    void doMove(MOVE m);

    /// \brief Returns description of game entity
    std::string getDescription();

    /// \brief Sets description of entity
    /// \param[in] description string
    void setDescription(std::string d);

    /// \brief Returns name of game entity
    std::string getName();

    /// \brief Checks if a string is an ACTION
    /// \param[in] a string
    bool isAction(std::string a);

    /// \brief Checks if a string is an MOVE
    /// \param[in] m string
    bool isMove(std::string m);

    /// \brief returns an ACTION from a string input
    /// \param[in] a string
    ACTION getAction(std::string a);

    /// \brief returns an MOVE from a string input
    /// \param[in] m string
    MOVE getMove(std::string m);

    /// \brief deletes all the pointers contained in the game
    void deleteStuff();

 protected:
    std::string description;
    std::string name;
    Player* p1 = nullptr;

 private:
    std::vector<Environment*> eVec;
    std::vector<Character*> cVec;
    std::vector<Item*> iVec;
};
#endif
