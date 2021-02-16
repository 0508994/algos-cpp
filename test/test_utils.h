#pragma once

std::vector<int> generate_sequence(std::size_t size) {
    std::vector<int> sequence(size);
    std::iota(sequence.begin(), sequence.end(), 0);

    return sequence;
}
