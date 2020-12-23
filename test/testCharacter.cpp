#include <sstream>
#include <string>
#include <vector>

#include "Item.h"
#include "Character.h"
#include "Room.h"

#include "gtest/gtest.h"

TEST(TestCharacter, NPCTest) {
  NPC* n1 = new NPC("n1", "test");
  n1->addDialogue("dia");
  EXPECT_EQ(n1->getDialogue(), "dia");
  n1->setName("n0");
  EXPECT_EQ(n1->getName(), "n0");
  EXPECT_EQ(n1->getDescription(), "test");
  EXPECT_EQ(n1->getInventory().size(), 0);
  n1->printInventory();
  Item* i1 = new Item("i1", "item");
  n1->addItem(i1);
  EXPECT_EQ(n1->getItem(0)->getName(), "i1");
  EXPECT_TRUE(n1->removeItem(i1));
  EXPECT_FALSE(n1->checkAction(GetItem));
  n1->removeAllItems();
  EXPECT_EQ(n1->getInventory().size(), 0);
  delete n1;
  delete i1;
}

TEST(TestCharacter, PlayerTest) {
  Player* p1 = new Player("p1", "test");
  p1->setName("p0");
  EXPECT_EQ(p1->getName(), "p0");
  EXPECT_EQ(p1->getDescription(), "test");
  EXPECT_EQ(p1->getInventory().size(), 0);
  p1->printInventory();
  Item* i1 = new Item("i1", "item");
  p1->addItem(i1);
  EXPECT_EQ(p1->getItem(0)->getName(), "i1");
  EXPECT_TRUE(p1->haveItem(i1));
  EXPECT_TRUE(p1->removeItem(i1));
  EXPECT_FALSE(p1->haveItem(i1));
  EXPECT_FALSE(p1->checkAction(GetItem));
  EXPECT_EQ(p1->getInventory().size(), 0);
  Room* r1 = new Room("r1", "Test Room 1", 1, 1, 1, 1);
  p1->setLocation(r1);
  EXPECT_EQ(p1->getLocation(), r1);
  EXPECT_EQ(p1->checkWin(), false);
  EXPECT_EQ(p1->checkLose(), false);
  p1->setWin(true);
  p1->setLose(true);
  EXPECT_EQ(p1->checkWin(), true);
  EXPECT_EQ(p1->checkLose(), true);
  p1->countAle();
  delete p1;
  delete i1;
  delete r1;
}
