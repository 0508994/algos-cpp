#pragma once
#include "common.h"

#include <vector>
#include <random>
#include <memory>

namespace coursera {

void API shuffle(std::vector<int>& a);
std::vector<int> API shuffle_copy(const std::vector<int>& a);

}