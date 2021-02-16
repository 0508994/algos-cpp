#include "sorts/quicksort.h"
#include "sorts/shuffle.h"

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

void QuickSort::sort(std::vector<int>& a) {
    shuffle(a);
    sort(a, 0, a.size() - 1);
}

std::vector<int> QuickSort::sort_copy(const std::vector<int>& a) {
    std::vector<int> aux(a);
    
    sort(aux);

    return aux;
}

void QuickSort::sort(std::vector<int>& a, std::size_t lo, std::size_t hi) {
    if (hi <= lo) return;
    const std::size_t P = partition(a, lo, hi);
    sort(a, lo, P - 1);
    sort(a, P + 1, hi);
}

}