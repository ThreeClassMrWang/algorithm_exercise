//
// Created by wcj on 3/3/18.
//

#include "gtest/gtest.h"
#include "huawei.hpp"

using namespace huawei;

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include "1_last_word_length.hpp"

TEST(last_word_length, test) {
  std::string in;
  std::size_t res;

  in = "";
  res = LastWordLength::length(in);
  EXPECT_EQ(res, 0);

  in = " ";
  res = LastWordLength::length(in);
  EXPECT_EQ(res, 0);

  in = "hello";
  res = LastWordLength::length(in);
  EXPECT_EQ(res, 5);

  in = "hello world63";
  res = LastWordLength::length(in);
  EXPECT_EQ(res, 7);
}

#include "2_char_count.hpp"

TEST(char_count, test) {
  std::string in;
  char c;
  std::size_t res;

  in = "ABCAE";
  c = 'A';
  res = CharCount::count(in, c);
  EXPECT_EQ(res, 2);

  in = "aBcAe";
  c = 'A';
  res = CharCount::count(in, c);
  EXPECT_EQ(res, 2);

  in = "abcAe";
  c = 'a';
  res = CharCount::count(in, c);
  EXPECT_EQ(res, 2);

  in = "@&^#&%#**&^&%@^@&%@!%&^&!";
  c = '@';
  res = CharCount::count(in, c);
  EXPECT_EQ(res, 4);
}
