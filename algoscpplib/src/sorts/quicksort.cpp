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

int QuickSort::select(std::vector<int>& a, std::size_t k) {
    shuffle(a);
    std::size_t lo = 0;
    std::size_t hi = a.size() - 1;
    while (hi > lo) {
        const std::size_t P = partition(a, lo, hi);
        if (P < k) {
            lo = P + 1;
        }
        else if (P > k && P > 0) {
            hi = P - 1;
        }
        else {
            return a[k];
        }
    }
}

int QuickSort::select_copy(const std::vector<int>& a, std::size_t k) {
    std::vector<int> aux(a);
    return select(aux, k);
}

void QuickSort::sort(std::vector<int>& a, std::size_t lo, std::size_t hi) {
    if (hi <= lo) return;
    const std::size_t P = partition(a, lo, hi);

    // They are using in 'int' in tutorial so they don't need to check this...
    if (P != 0) {
        sort(a, lo, P - 1);
    } // or add hi == std::numeric_limits<std::size_t>::max() to a recursion exit condition which is kinda bad solution?
      // or cast P to int64_t before decrementing??

    sort(a, P + 1, hi);
}

std::vector<int> QuickSort::sort_dijkstra_three_way_copy(const std::vector<int>& a) {
    std::vector<int> aux(a);
    sort_dijkstra_three_way(aux);
    return aux;
}


void QuickSort::sort_dijkstra_three_way(std::vector<int>& a) {
    shuffle(a);
    sort_dijkstra_three_way(a, 0, a.size() - 1);
}

void QuickSort::sort_dijkstra_three_way(std::vector<int>& a, std::size_t lo, std::size_t hi) {
    if (hi <= lo) {
        return;
    }

    std::size_t lt = lo;
    std::size_t gt = hi;
    std::size_t i = lo;
    int v = a[lo];

    while (i <= gt) {
        if (a[i] < v) {
            std::swap(a[lt++], a[i++]);
        } else if (a[i] > v) {
            // Do not increment i [still not compared with the partitioning element]
            std::swap(a[i], a[gt--]);
        } else {
            i++;
        }
    }

    if (lt > 0) {
        sort_dijkstra_three_way(a, lo, lt - 1);
    }
    sort(a, gt + 1, hi);
}

}