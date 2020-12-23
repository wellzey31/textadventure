#include <sstream>

#include "Environment.h"
#include "Room.h"
#include "Move.h"
#include "gtest/gtest.h"

TEST(TestEnvironment, getRoomByPosTest) {
  Environment* e1 = new Environment("e1", "Test Environment", 2, 2);
  Room* r1 = new Room("r1", "Test Room 1", 1, 1, 1, 1);
  Room* r2 = new Room("r2", "Test Room 2", 1, 1, 1, 1);
  Room* r3 = new Room("r3", "Test Room 3", 1, 1, 1, 1);
  Room* r4 = new Room("r4", "Test Room 4", 1, 1, 1, 1);

  e1 -> setRoom(r1, 0, 0);
  e1 -> setRoom(r2, 1, 0);
  e1 -> setRoom(r3, 0, 1);
  e1 -> setRoom(r4, 1, 1);

  EXPECT_EQ(e1 -> getRoom(0, 0) -> getName(), "r1");
  EXPECT_EQ(e1 -> getRoom(1, 0) -> getName(), "r2");
  EXPECT_EQ(e1 -> getRoom(0, 1) -> getName(), "r3");
  EXPECT_EQ(e1 -> getRoom(1, 1) -> getName(), "r4");

  EXPECT_EQ(e1 -> getRoom(2, 0), nullptr);
  EXPECT_EQ(e1 -> getRoom(0, 2), nullptr);
  EXPECT_EQ(e1 -> getRoom(-1, 0), nullptr);
  EXPECT_EQ(e1 -> getRoom(0, -1), nullptr);

  delete e1;
}

TEST(TestEnvironment, getRoomByNameTest) {
  Room* r1 = new Room("r1", "Test Room 1", 1, 1, 1, 1);
  Room* r2 = new Room("r2", "Test Room 2", 1, 1, 1, 1);
  Room* r3 = new Room("r3", "Test Room 3", 1, 1, 1, 1);
  Room* r4 = new Room("r4", "Test Room 4", 1, 1, 1, 1);
  Environment* e1 = new Environment("e1", "Test Environment", 2, 2);

  e1 -> setRoom(r1, 0, 0);
  e1 -> setRoom(r2, 1, 0);
  e1 -> setRoom(r3, 0, 1);
  e1 -> setRoom(r4, 1, 1);

  EXPECT_EQ(e1 -> getRoom("r1"), r1);
  EXPECT_EQ(e1 -> getRoom("r2"), r2);
  EXPECT_EQ(e1 -> getRoom("r3"), r3);
  EXPECT_EQ(e1 -> getRoom("r4"), r4);

  EXPECT_EQ(e1 -> getRoom("R1"), nullptr);
  EXPECT_EQ(e1 -> getRoom(""), nullptr);

  delete e1;
}

TEST(TestEnvironment, setAdjacentRoomsTest) {
  Room* r1 = new Room("r1", "Test Room 1", 0, 1, 1, 0);
  Room* r2 = new Room("r2", "Test Room 2", 1, 0, 1, 0);
  Room* r3 = new Room("r3", "Test Room 3", 0, 1, 0, 1);
  Room* r4 = new Room("r4", "Test Room 4", 1, 0, 0, 1);
  Environment* e1 = new Environment("e1", "Test Environment", 2, 2);

  e1 -> setRoom(r1, 0, 0);
  e1 -> setRoom(r2, 1, 0);
  e1 -> setRoom(r3, 0, 1);
  e1 -> setRoom(r4, 1, 1);

  e1 -> setAdjacentRooms();

  EXPECT_EQ(e1 -> getRoom("r1") -> getNeighborRoom(East) -> getName(), "r3");
  EXPECT_EQ(e1 -> getRoom("r1") -> getNeighborRoom(South) -> getName(), "r2");
  EXPECT_EQ(e1 -> getRoom("r4") -> getNeighborRoom(North) -> getName(), "r3");
  EXPECT_EQ(e1 -> getRoom("r4") -> getNeighborRoom(West) -> getName(), "r2");

  delete e1;
}

TEST(TestEnvironment, setAdjacentRoomsBetweenEnvTest) {
  Room* r11 = new Room("r11", "Test Room 1", 1, 1, 1, 0);
  Room* r21 = new Room("r21", "Test Room 2", 1, 0, 1, 0);
  Room* r31 = new Room("r31", "Test Room 3", 0, 1, 0, 1);
  Room* r41 = new Room("r41", "Test Room 4", 1, 0, 0, 1);
  Environment* e1 = new Environment("e1", "Test Environment", 2, 2);

  Room* r12 = new Room("r12", "Test Room 1", 0, 1, 1, 0);
  Room* r22 = new Room("r22", "Test Room 2", 1, 0, 1, 0);
  Room* r32 = new Room("r32", "Test Room 3", 0, 1, 0, 1);
  Room* r42 = new Room("r42", "Test Room 4", 1, 1, 0, 1);
  Environment* e2 = new Environment("e2", "Test Environment", 2, 2);

  e1 -> setRoom(r11, 0, 0);
  e1 -> setRoom(r21, 1, 0);
  e1 -> setRoom(r31, 0, 1);
  e1 -> setRoom(r41, 1, 1);
  e1 -> setEnd(r11);

  e2 -> setRoom(r12, 0, 0);
  e2 -> setRoom(r22, 1, 0);
  e2 -> setRoom(r32, 0, 1);
  e2 -> setRoom(r42, 1, 1);
  e2 -> setStart(r42);

  e1 -> setNeighborEnv(e2, nullptr);
  e2 -> setNeighborEnv(nullptr, e1);

  e1 -> setAdjacentRooms();
  e2 -> setAdjacentRooms();

  EXPECT_EQ(e1 -> getRoom("r11") -> getNeighborRoom(North) -> getName(), "r42");

  delete e1;
  delete e2;
}
