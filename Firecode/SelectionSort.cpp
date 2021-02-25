#include <algorithm>
#include <iostream>
#include <vector>

int* selection_sort_array(int arr[], size_t size) {
    std::vector<int> vec{};
    vec.reserve(size);
    for (size_t i = 0; i < size; i++ ) {vec.emplace_back(arr[i]);}

    size_t i{};
    while (!vec.empty()) {
        auto minIt = std::min_element(std::begin(vec), std::end(vec));
        arr[i] = *minIt;
        i++;
        vec.erase(minIt);
    }
    vec.shrink_to_fit();
    
    return arr;
}

int main() {
    size_t const size = 10;
    int arr[size] = {3, 5, 1, 2, 8, 12, 20, -4, 0, 1};
    int* riskyArr = selection_sort_array(arr, size);
    for (size_t i = 0; i < size; i++) {std::cout << riskyArr[i] << '\n';}

    return 0;
}
