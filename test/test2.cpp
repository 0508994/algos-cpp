#include "pch.h"
#include "testdll/testdll.h"

TEST(TestGTestDll2, Test) {
    EXPECT_EQ(test::test(), 3);
}