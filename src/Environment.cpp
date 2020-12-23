#include "Environment.h"

#include "Room.h"
#include <string>
#include <iostream>

Environment::Environment(std::string name, std::string description,
  int row, int col) {
  this -> name = name;
  this -> description = description;
  rows = row;
  cols = col;

  grid = new Room**[rows];
  for (int i = 0; i < rows; ++i) {
    grid[i] = new Room*[cols];
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      grid[i][j] = nullptr;
    }
  }
}

Environment::~Environment() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      delete grid[i][j];
    }
    delete[] grid[i];
  }
  delete[] grid;
}

bool Environment::setRoom(Room* r, int row, int col) {
  if (!checkBounds(row, col)) {
    return false;
  }

  if (getRoom(row, col) == nullptr) {
    grid[row][col] = r;
    return 1;
  }
  return 0;
}

Room* Environment::getRoom(int row, int col) {
  if (checkBounds(row, col)) {
    return grid[row][col];
  }
  return nullptr;
}

Room* Environment::getRoom(std::string name) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] -> getName() == name) {
        return grid[i][j];
      }
    }
  }
  return nullptr;
}

void Environment::setAdjacentRooms() {
  Room* temp = nullptr;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      temp = grid[i][j];
      if (temp != nullptr) {
        if (checkBounds(i - 1, j)) {
          temp -> setNeighborRoom(North, grid[i - 1][j]);
        }
        if (checkBounds(i, j + 1)) {
          temp -> setNeighborRoom(East, grid[i][j + 1]);
        }
        if (checkBounds(i + 1, j)) {
          temp -> setNeighborRoom(South, grid[i + 1][j]);
        }
        if (checkBounds(i, j - 1)) {
          temp -> setNeighborRoom(West, grid[i][j - 1]);
        }
      }
    }
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (isStart(grid[i][j])) {
        if (grid[i][j] -> getCollision(North) == true &&
         grid[i][j] -> getNeighborRoom(North) == nullptr) {
          grid[i][j] -> setNeighborRoom(North, getPrevEnv() -> getEndRoom());
        }
        if (grid[i][j] -> getCollision(East) == true &&
         grid[i][j] -> getNeighborRoom(East) == nullptr) {
          grid[i][j] -> setNeighborRoom(East, getPrevEnv() -> getEndRoom());
        }
        if (grid[i][j] -> getCollision(South) == true &&
         grid[i][j] -> getNeighborRoom(South) == nullptr) {
          grid[i][j] -> setNeighborRoom(South, getPrevEnv() -> getEndRoom());
        }
        if (grid[i][j] -> getCollision(West) == true &&
         grid[i][j] -> getNeighborRoom(West) == nullptr) {
          grid[i][j] -> setNeighborRoom(West, getPrevEnv() -> getEndRoom());
        }
      }
      if (isEnd(grid[i][j])) {
        if (grid[i][j] -> getCollision(North) == true &&
         grid[i][j] -> getNeighborRoom(North) == nullptr) {
          grid[i][j] -> setNeighborRoom(North, getNextEnv() -> getStartRoom());
        }
        if (grid[i][j] -> getCollision(East) == true &&
         grid[i][j] -> getNeighborRoom(East) == nullptr) {
          grid[i][j] -> setNeighborRoom(East, getNextEnv() -> getStartRoom());
        }
        if (grid[i][j] -> getCollision(South) == true &&
         grid[i][j] -> getNeighborRoom(South) == nullptr) {
          grid[i][j] -> setNeighborRoom(South, getNextEnv() -> getStartRoom());
        }
        if (grid[i][j] -> getCollision(West) == true &&
         grid[i][j] -> getNeighborRoom(West) == nullptr) {
          grid[i][j] -> setNeighborRoom(West, getNextEnv() -> getStartRoom());
        }
      }
    }
  }
}

void Environment::setNeighborEnv(Environment* n, Environment* p) {
  next = n;
  prev = p;
}

Environment* Environment::getNextEnv() {
  return next;
}

Environment* Environment::getPrevEnv() {
  return prev;
}

void Environment::setStart(Room* s) {
  start = s;
}

Room* Environment::getStartRoom() {
  return start;
}

bool Environment::isStart(Room* r) {
  if (r == nullptr || getStartRoom() == nullptr) {
    return 0;
  }

  if (getStartRoom() -> getName() == r -> getName()) {
    return 1;
  }
  return 0;
}

void Environment::setEnd(Room* e) {
  end = e;
}

Room* Environment::getEndRoom() {
  return end;
}

bool Environment::isEnd(Room* r) {
  if (r == nullptr || getEndRoom() == nullptr) {
    return 0;
  }

  if (getEndRoom() -> getName() == r -> getName()) {
    return 1;
  }
  return 0;
}

bool Environment::checkBounds(int row, int col) {
  if (row < rows && col < cols && row >= 0 && col >= 0) {
    return true;
  }
  return false;
}
