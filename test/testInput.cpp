#include <string>

#include "Input.h"

#include "gtest/gtest.h"

TEST(TestInput, inputTest) {
  Input* in = new Input();
  EXPECT_TRUE(in->checkValid("up"));
  in->help();
  delete in;
}
