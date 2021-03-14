#include "sorts/shuffle.h"

namespace coursera {

void shuffle(std::vector<int>& a) {
    std::random_device seed_gen;

    // Apperently too bigggu for the stack?
    auto random_engine = std::make_unique<std::mt19937_64>(seed_gen());

    // Knuth shuffle
    // In iteration i, pick integer r between 0 and i uniformly at random.
    // Swap a[i] and a[r]

    const std::size_t N = a.size();

    for (std::size_t i = 0; i < N; i++) {
        // TODO: How expensive is distr creation? Can this be done in a better way?
        std::uniform_int_distribution<std::size_t> distr(0, i);
        const std::size_t r = distr(*random_engine);
        std::swap(a[i], a[r]);
    }
}

std::vector<int> shuffle_copy(const std::vector<int>& a) {
    std::vector<int> aux(a);
    shuffle(aux);
    return aux;
}

}