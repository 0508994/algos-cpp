#include "pch.h"

TEST(TestGTestDll, Test) {
  EXPECT_EQ(test::test(), 3);
}