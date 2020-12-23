#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Game.h"
#include "Room.h"
#include <string>


/// \brief Contains all informations related to an Environment.
/// setups the structure of Room*'s

/// \class Environment Environment.h <Environment.h>
class Environment : public Game {
 public:
  /// \brief Class constructor
  /// \param[in] name string
  /// \param[in] description string
  /// \param[in] row, col int for size of environment grid
  Environment(std::string name, std::string description, int row, int col);

  /// \brief Class destructor
  ~Environment();

  /// \brief setRoom adds a Romm* to a place in the grid
  /// \param[in] r Room*
  /// \param[in] row int
  /// \param[in] col int
  bool setRoom(Room* r, int row, int col);

  /// \brief getRoom returns a Room* from a place in the grid
  /// \param[in] row int
  /// \param[in] col int
  Room* getRoom(int row, int col);

  /// \brief getRoom returns a Room* from a string name
  /// \param[in] name string
  Room* getRoom(std::string name);

  /// \brief sets adjacent Room*'s based on location in the grid. Necessary
  /// for game movement. Each room points to neighboring Rooms
  void setAdjacentRooms();

  /// \brief sets adjacent Environment*'s.
  /// \param[in] n Environment* is the next Environment chronologically
  /// \param[in] p Environment* is the previous Environment chronologically
  void setNeighborEnv(Environment* n, Environment* p);

  /// \brief returns the next Environment chronologically
  Environment* getNextEnv();

  /// \brief returns the previous Environment chronologically
  Environment* getPrevEnv();

  /// \brief sets the starting room of an Environment.
  /// \param[in] s Room* is the start Room chronologically
  void setStart(Room* s);

  /// \brief returns the start Room chronologically
  Room* getStartRoom();

  /// \brief checks if a room is the Start of an Environment
  /// \param[in] r Room* is the Room being checked
  bool isStart(Room* r);

  /// \brief sets the ending room of an Environment.
  /// \param[in] e Room* is the end Room chronologically
  void setEnd(Room* e);

  /// \brief returns the end Room chronologically
  Room* getEndRoom();

  /// \brief checks if a room is the end of an Environment
  /// \param[in] r Room* is the Room being checked
  bool isEnd(Room* r);

 private:
  /// \brief checks the boundaries of an Environment
  /// \param[in] row, col int for environment position
  bool checkBounds(int row, int col);

  Room*** grid = nullptr;
  int cols;
  int rows;
  Room* start = nullptr;
  Room* end = nullptr;
  Environment* next = nullptr;
  Environment* prev = nullptr;
};

#endif
