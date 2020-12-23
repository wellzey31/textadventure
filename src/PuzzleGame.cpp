#include "PuzzleGame.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string>



void PuzzleGame::play(Player *p, NPC *hermit) {
  if (hermit -> getInventory().size() != 0) {
    std::cout << std::endl << std::endl;
    std::cout << "The hermit looks up at you and asks if you can help him. "<<
    std::endl;
    std::cout << "He tells you there is a strange rock behind his hut" <<
    std::endl;
    std::cout <<
    "The hermit guides you behind his house where you find a rock with "
    "enscriptions on it" << std::endl << std::endl;
    std::cout << "Three numbers are inscribed on the rock....a pattern?" <<
      std::endl;
      std::cout << "I think I have to enter the fouth sequence" << std::endl;
      std::cout << "1241....1431....1351....xxxx" << std::endl;
    std::cout <<
    "I could walk away and come back later if I cant figure this out (0)"
    << std::endl;
    while (answer.compare(playerAnswer) != 0 && playerAnswer != "0") {
      std::cin >> playerAnswer;
      if (playerAnswer.compare(answer) == 0) {
        std::cout << "That was it!" << std::endl;
      } else if (playerAnswer != "0") {
        std::cout << "Hmm...I better try that again" << std::endl;
        std::cout << "The sequence goes" << std::endl;
        std::cout << "1321....1241....1431....1351....xxxx" << std::endl;
      }
    }
    if (answer.compare(playerAnswer) == 0) {
      std::cout << "The rock falls apart revealing a sword" << std::endl;
      std::cout << "The herit looks to you and tells you he has no";
      std::cout << " use for a sword and that you can keep it" << std::endl;
      std::cout << "You got a sword!!" << std::endl;
      p->addItem(hermit->getItem(0));
      hermit -> removeAllItems();
    }
  } else {
    std::cout << "Thank you for the help friend." << std::endl;
  }
}
