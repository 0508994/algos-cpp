#pragma once

#include "common.h"

#include <vector>

namespace coursera {

class API QuickSort {
public:
    static std::size_t partition(std::vector<int>& a, std::size_t lo, std::size_t hi);
    static void sort(std::vector<int>& a);
    static std::vector<int> sort_copy(const std::vector<int>& a);
    static int select(std::vector<int>& a, std::size_t k);
    static int select_copy(const std::vector<int>& a, std::size_t k);
    
    /* Useful when the array has many duplicate keys. */
    static void sort_dijkstra_three_way(std::vector<int>& a);
    static std::vector<int> sort_dijkstra_three_way_copy(const std::vector<int>& a);

private:
    static void sort(std::vector<int>& a, std::size_t lo, std::size_t hi);
    static void sort_dijkstra_three_way(std::vector<int>& a, std::size_t lo, std::size_t hi);
};


}