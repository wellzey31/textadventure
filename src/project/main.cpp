#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "Game.h"

int main() {
  Game* txtAdventure = new Game();
  std::string s = "";
  bool c;

  do {
    txtAdventure -> gameStart();
    c = 0;
    while (txtAdventure -> playerTurn()) {}
    std::cout << "Would you like to play again? (Y/N): ";
    std::cin >> s;
    std::transform(s.begin(), s.end(), s.begin(),
      [](unsigned char c){ return std::tolower(c); });
    if (s == "y" || s == "yes") {
      c = 1;
      txtAdventure -> deleteStuff();
    }
  } while (c);

  txtAdventure -> deleteStuff();
  delete txtAdventure;
  return 0;
}
