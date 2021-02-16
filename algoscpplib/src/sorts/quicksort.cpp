#include "sorts/quicksort.h"

namespace coursera {

std::size_t QuickSort::partition(std::vector<int>& a, std::size_t lo, std::size_t hi) {
    std::size_t i = lo;
    std::size_t j = hi + 1;

    while (true) {
        // Find item on left to swap.
        while (a[++i] < a[lo]) {
            if (i == hi) break;
        }

        // Find item on right to swap.
        while (a[lo] < a[--j]) {
            if (j == lo) break;
        }

        // Check if pointers cross.
        if (i >= j) break;

        std::swap(a[i], a[j]);
    }

    // Swap with partitioning item.
    std::swap(a[lo], a[j]);

    // Return index of item now known to be in place.
    return j;
}

}