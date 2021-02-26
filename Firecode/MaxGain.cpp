#include <algorithm>
#include <limits>
#include <deque>

int max_gain(int arr[], int size) {
    std::deque<int> deq{};
    auto maxNumber = std::numeric_limits<int>::min();

    for(size_t i = 0; i < size; i++) {
        if(arr[i] > maxNumber) {
            maxNumber = arr[i];
            deq.emplace_back(arr[i]);
        }
    }

    return *std::max_element(deq.begin(), deq.end()) - *std::min_element(deq.begin(), deq.end());
}

int main() {
    const int size = 5;
    int arr[size] = {0, 50, 10, 100, 30};
    auto result = max_gain(arr, size);

    return 0;
}
