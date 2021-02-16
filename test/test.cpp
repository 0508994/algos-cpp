#include "pch.h"
#include "testdll/testdll.h"

TEST(TestGTestDll, Test) {
    EXPECT_EQ(test::test(), 3);
}