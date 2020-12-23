#include <sstream>
#include <string>
#include <vector>

#include "Item.h"
#include "Character.h"
#include "Room.h"

#include "gtest/gtest.h"

TEST(TestItem, itemTest) {
  Item* i1 = new Item("i1", "test");
  Item* ale = new Item("Ale", "test");
  Player* p1 = new Player("p1", "test");
  EXPECT_FALSE(i1->useItem(p1));
  EXPECT_TRUE(ale->useItem(p1));
  delete i1;
  delete ale;
  delete p1;
}
