#include <iostream>

int single_number(int arr[], int sz) {
    if (sz <= 0) {
        return 0;
    }
    int number{};
    int counter{};

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (arr[i] == arr[j]) {
                counter++;
            }
        }

        if (counter == 1) {
            number = arr[i];
        }

        counter = 0;
    }

    return number;
}

int main() {
    int arr[7] = {1, 1, 2, 2, 3, 3, 7};
    std::cout << single_number(arr, 7) << '\n';

    return 0;
}
