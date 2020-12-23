#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdio>
#include "Input.h"


Input::Input() {}

std::string Input::getInput() {
  std::string s;
  std::cin >> s;
  //make sure all inputs are in lowercase for easy processing
  std::transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });
  if (s == "help") help();
  if (checkValid(s)) return s;
  else
    s = getInput(); //gets a new input
  return s;
}

bool Input::checkValid(std::string in) {
  std::string validStr[18] = {"help", "quit", "search", "inspectitem",
  "useitem", "getitem",
   "talk", "attack", "get", "steal", "drop", "up", "down", "left", "right",
  };
  for (int i = 0; i < 18; i++) {
    if (in == validStr[i]) return true;
  }
  std::cout <<
  "Invalid input, enter a new input. Type 'help' for more information."
  << std::endl;
  return false;
}

void Input::help() {
  std::string strings[18] = {"help", "quit", "search", "inspectitem",
  "useitem", "getitem", "talk", "attack", "get", "steal", "drop", "up", "down",
   "left", "right",
  };
  std::cout << "Help: " << std::endl <<
  "The following commands are possible" << std::endl;
  for (auto& x : strings) {
    std::cout<< " " << x << std::endl;
  }
  std::cout << "Type help at any time to return to this menu." << std::endl;
}
