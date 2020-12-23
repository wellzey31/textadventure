#include <sstream>
#include <string>
#include <vector>

#include "Item.h"
#include "Character.h"
#include "Room.h"

#include "gtest/gtest.h"

TEST(TestRoom, collisionTest) {
  Room* r1 = new Room("r1", "Test Room", 1, 1, 1, 1);
  EXPECT_EQ(r1 -> getCollision(MOVE::North), 1);
  EXPECT_EQ(r1 -> getCollision(MOVE::South), 1);
  EXPECT_EQ(r1 -> getCollision(MOVE::West), 1);

  r1 -> setCollision(MOVE::North, 1);
  EXPECT_EQ(r1 -> getCollision(MOVE::North), 1);

  r1 -> setCollision(MOVE::North, 0);
  EXPECT_EQ(r1 -> getCollision(MOVE::North), 0);
  EXPECT_EQ(r1 -> getCollision(MOVE::East), 1);
  EXPECT_EQ(r1 -> getCollision(MOVE::South), 1);
  EXPECT_EQ(r1 -> getCollision(MOVE::West), 1);

  r1 -> setCollision(MOVE::East, 0);
  EXPECT_EQ(r1 -> getCollision(MOVE::East), 0);

  r1 -> setCollision(MOVE::South, 0);
  EXPECT_EQ(r1 -> getCollision(MOVE::South), 0);

  r1 -> setCollision(MOVE::West, 0);
  EXPECT_EQ(r1 -> getCollision(MOVE::West), 0);

  delete r1;
}

TEST(TestRoom, treasureTest) {
  Room* r1 = new Room("r1", "Test Room", 1, 1, 1, 1);
  Item* i1 = new Item("i1", "Test Item");
  Item* i2 = new Item("i2", "Test Item 2");

  r1 -> setTreasure(i1);
  EXPECT_EQ(r1 -> getTreasure() -> getName(), "i1");
  EXPECT_EQ(r1 -> getTreasure() -> getDescription(), "Test Item");

  r1 -> setTreasure(i2);
  EXPECT_EQ(r1 -> getTreasure() -> getName(), "i1");

  EXPECT_EQ(r1 -> removeTreasure(), 1); //segfault is here
  EXPECT_EQ(r1 -> getTreasure(), nullptr);

  r1 -> setTreasure(i2);
  EXPECT_EQ(r1 -> getTreasure() -> getName(), "i2");

  delete r1;
  delete i1;
  delete i2;
}

TEST(TestRoom, getCharTest) {
  Room* r1 = new Room("r1", "Test Room", 1, 1, 1, 1);
  NPC* n1 = new NPC("n1", "Test NPC 1");

  EXPECT_EQ(r1 -> getNPC(), nullptr);

  r1 -> setChar(n1);

  EXPECT_EQ(r1 -> getNPC(), n1);

  EXPECT_TRUE(r1->removeChar());

  delete r1;
  delete n1;
}

TEST(TestRoom, charactersTest) {
  Room* r1 = new Room("r1", "Test Room", 1, 1, 1, 1);
  NPC* n1 = new NPC("n1", "Test NPC 1");
  NPC* n2 = new NPC("n2", "Test NPC 2");
  NPC* n3 = nullptr;

  EXPECT_EQ(r1 -> setChar(n1), 1);
  EXPECT_EQ(r1 -> setChar(n2), 1);

  EXPECT_EQ(r1 -> getNPC(), n2);

  EXPECT_EQ(r1 -> setChar(n1), 1);
  EXPECT_EQ(r1 -> setChar(n3), 0);

  EXPECT_EQ(r1 -> removeChar(), 1);
  EXPECT_EQ(r1 -> removeChar(), 0);
  EXPECT_EQ(r1 -> getNPC(), nullptr);

  delete r1;
  delete n1;
  delete n2;
}
