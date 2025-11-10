// bubble_sort.cpp
// Simple demonstration of Bubble Sort in C++
// - Prints the array before and after sorting
// - Measures elapsed time
// - Optional verbose mode: print array after each outer pass

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

void printArray(const std::vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i];
        if (i + 1 < a.size()) std::cout << " ";
    }
    std::cout << '\n';
}

// Classic bubble sort with early-exit optimization
void bubbleSort(std::vector<int>& a, bool verbose = false) {
    const size_t n = a.size();
    if (n < 2) return;

    for (size_t pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        for (size_t i = 0; i < n - 1 - pass; ++i) {
            if (a[i] > a[i+1]) {
                std::swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        if (verbose) {
            std::cout << "After pass " << (pass + 1) << ": ";
            printArray(a);
        }
        if (!swapped) break; // array already sorted
    }
}

int main(int argc, char** argv) {
    // Defaults
    size_t size = 10;
    bool verbose = false;

    // Simple CLI parsing: [size] [-v]
    for (int i = 1; i < argc; ++i) {
        std::string s = argv[i];
        if (s == "-v" || s == "--verbose") {
            verbose = true;
        } else {
            std::istringstream iss(s);
            size_t t;
            if (iss >> t) size = t;
        }
    }

    // Generate random data
    std::vector<int> a;
    a.reserve(size);
    std::mt19937 rng((unsigned)std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 99);
    for (size_t i = 0; i < size; ++i) a.push_back(dist(rng));

    std::cout << "Bubble Sort Demo (size=" << size << ")\n";
    std::cout << "Unsorted: "; printArray(a);

    auto t0 = std::chrono::high_resolution_clock::now();
    bubbleSort(a, verbose);
    auto t1 = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted:   "; printArray(a);
    std::chrono::duration<double, std::milli> ms = t1 - t0;
    std::cout << "Elapsed: " << ms.count() << " ms\n";

    // Quick correctness check
    if (!std::is_sorted(a.begin(), a.end())) {
        std::cerr << "Error: result not sorted!\n";
        return 2;
    }

    return 0;
}
