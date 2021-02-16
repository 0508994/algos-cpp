#pragma once

#include "common.h"

#include <vector>

namespace coursera {

class API QuickSort {
public:
    static std::size_t partition(std::vector<int>& a, std::size_t lo, std::size_t hi);
};


}