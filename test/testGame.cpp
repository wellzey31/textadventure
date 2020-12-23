#include <string>

#include "Game.h"
#include "Character.h"
#include "Room.h"
#include "Environment.h"
#include "PuzzleGame.h"
#include "Move.h"
#include "Action.h"

#include "gtest/gtest.h"

TEST(TestGame, gameTest) {
  Game* txtAdventure = new Game();
  std::string s = "";
  EXPECT_NO_THROW(txtAdventure -> gameStart());
  txtAdventure -> doAction(Search);
  txtAdventure -> doAction(Talk);
  txtAdventure -> doAction(Attack);
  txtAdventure -> doAction(GetItem);
  txtAdventure -> doAction(Steal);
  txtAdventure -> doMove(North);
  txtAdventure -> doMove(East);
  txtAdventure -> doMove(West);
  txtAdventure -> doMove(South);
  EXPECT_TRUE(txtAdventure -> isMove("south"));
  EXPECT_TRUE(txtAdventure -> isMove("north"));
  EXPECT_TRUE(txtAdventure -> isMove("west"));
  EXPECT_TRUE(txtAdventure -> isMove("east"));
  EXPECT_EQ(txtAdventure->getMove("north"), North);
  EXPECT_EQ(txtAdventure->getMove("south"), South);
  EXPECT_EQ(txtAdventure->getMove("east"), East);
  EXPECT_EQ(txtAdventure->getMove("west"), West);
  EXPECT_TRUE(txtAdventure->isAction("search"));
  EXPECT_TRUE(txtAdventure->isAction("inspectitem"));
  EXPECT_TRUE(txtAdventure->isAction("useitem"));
  EXPECT_TRUE(txtAdventure->isAction("talk"));
  EXPECT_TRUE(txtAdventure->isAction("attack"));
  EXPECT_TRUE(txtAdventure->isAction("getitem"));
  EXPECT_TRUE(txtAdventure->isAction("steal"));
  EXPECT_TRUE(txtAdventure->isAction("drop"));
  EXPECT_TRUE(txtAdventure->isAction("quit"));
  EXPECT_EQ(txtAdventure->getAction("search"), Search);
  EXPECT_EQ(txtAdventure->getAction("inspectitem"), InspectItem);
  EXPECT_EQ(txtAdventure->getAction("useitem"), UseItem);
  EXPECT_EQ(txtAdventure->getAction("talk"), Talk);
  EXPECT_EQ(txtAdventure->getAction("attack"), Attack);
  EXPECT_EQ(txtAdventure->getAction("getitem"), GetItem);
  EXPECT_EQ(txtAdventure->getAction("steal"), Steal);
  EXPECT_EQ(txtAdventure->getAction("drop"), Drop);
  EXPECT_EQ(txtAdventure->getAction("quit"), Quit);
  txtAdventure -> deleteStuff();
  delete txtAdventure;
}
