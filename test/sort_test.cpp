#include "pch.h"
#include "test_utils.h"
#include "sorts/shuffle.h"
#include "sorts/quicksort.h"

TEST(ShuffleTest, DifferentThenOriginal) {
    auto a = generate_sequence(10000);

    ASSERT_NE(coursera::shuffle_copy(a), a) << "SRSLY !?!";
}

TEST(PartitionTest, ValidatePartitions) {
    auto a = generate_sequence(1000);

    coursera::shuffle(a);

    const std::size_t P = coursera::QuickSort::partition(a, 0, a.size() - 1);

    // Validate left partition:
    for (std::size_t i = 0; i < P; i++) {
        ASSERT_LT(a[i], a[P]);
    }

    // Validate right partition:
    for (std::size_t i = P + 1; i < a.size(); i++) {
        ASSERT_GT(a[i], a[P]);
    }
}

TEST(QuicksortTest, TestSort) {
    auto a = generate_sequence(5000);

    auto to_sort = coursera::shuffle_copy(a);

    ASSERT_NE(a, to_sort) << "REALLY NOW ??!";

    coursera::QuickSort::sort(to_sort);

    ASSERT_EQ(a, to_sort);
}