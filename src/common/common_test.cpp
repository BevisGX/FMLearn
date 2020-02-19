//
// Created by naihai on 2020/1/20.
//

#include "gtest/gtest.h"

#include "common/log.h"
#include "common/check.h"

TEST(COMMON_TEST, Logging) {
  Logging::SetLevel(0);
  SetLoggingDir("log");
  LogDebug("debug");
  LogInfo("info");

  Logging::SetLevel(1);
  LogDebug("debug");
  LogInfo("info");

  Logging::SetLevel("error");
  LogDebug("debug");
  LogInfo("info");
  LogError("error");
  LogInfo("Hello");

}

TEST(COMMON_TEST, Check){
  CHECK_LT(9, 12);
  CHECK_LT(12, 9);

  CHECK_GT(12, 9);
  CHECK_GT(9, 12);

  CHECK_LE(9, 9);
  CHECK_GE(12, 12);

  CHECK_EQ(12, 12);
  CHECK_EQ(true, true);
  CHECK_NE((12==12), false);
}


void func(int id) {
  printf("Hello %i\n", id);
}



int main(int argc, char* argv[]) {

  testing::InitGoogleTest(&argc, argv);
  LogInfo("\n");
  return RUN_ALL_TESTS();
}


