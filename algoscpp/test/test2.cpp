#include "pch.h"

TEST(TestGTestDll2, Test) {
  EXPECT_EQ(test::test(), 3);
}