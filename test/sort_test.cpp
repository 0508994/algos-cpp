#include "pch.h"
#include "test_utils.h"
#include "sorts/shuffle.h"
#include "sorts/quicksort.h"

TEST(Sorts, ShuffleTestDifferentThenOriginal) {
    auto a = generate_sequence(10000);

    ASSERT_NE(coursera::shuffle_copy(a), a) << "SRSLY !?!";
}

TEST(Sorts, PartitionTestValidatePartitions) {
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

TEST(Sorts, QuickSort) {
    auto a = generate_sequence(5000);

    auto to_sort = coursera::shuffle_copy(a);

    ASSERT_NE(a, to_sort) << "REALLY NOW ??!";

    coursera::QuickSort::sort(to_sort);

    ASSERT_EQ(a, to_sort);
}

TEST(Sorts, QuickSelect) {
    auto a = generate_sequence(100);

    ASSERT_EQ(coursera::QuickSort::select(a, 1), 1);
    ASSERT_EQ(coursera::QuickSort::select(a, 10), 10);
    ASSERT_EQ(coursera::QuickSort::select(a, 65), 65);
    ASSERT_EQ(coursera::QuickSort::select(a, 99), 99);
}

TEST(Sorts, DijsktraThreeWayPartitonQuickSort) {
    std::vector<int> a{ 1, 1, 1, 1, 1, 3, 3, 3, 3, 5, 6, 7, 7, 7, 7, 8, 8, 9, 10 };
    auto to_sort = coursera::shuffle_copy(a);

    ASSERT_NE(a, to_sort) << "REALLY NOW ??!";

    coursera::QuickSort::sort_dijkstra_three_way(to_sort);
    ASSERT_EQ(to_sort, a);
}