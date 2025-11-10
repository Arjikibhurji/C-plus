// bubble_sort_visual.cpp
// ASCII visualizer for Bubble Sort. No external libraries required.
// Usage:
//   ./bubble_sort_visual [size] [-s ms] [-k]
// Options:
//   size   - number of elements (default 20)
//   -s ms  - auto-play delay in milliseconds (default 150)
//   -k     - step mode: wait for key press between steps

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <vector>

// minimal includes are enough; we avoid platform-specific ioctl/termios helpers
static void clearScreen() {
    std::cout << "\x1b[2J\x1b[H";
}

static void hideCursor() { std::cout << "\x1b[?25l"; }
static void showCursor() { std::cout << "\x1b[?25h"; }

std::string bar(int value, int maxVal, int width) {
    int len = (maxVal == 0) ? 0 : (value * width) / maxVal;
    std::string s;
    s.reserve(width);
    for (int i = 0; i < len; ++i) s.push_back('#');
    for (int i = len; i < width; ++i) s.push_back(' ');
    return s;
}

void draw(const std::vector<int>& a, int i_high = -1, int j_high = -1) {
    clearScreen();
    int n = (int)a.size();
    int maxv = 1;
    for (int v : a) if (v > maxv) maxv = v;

    std::cout << "Bubble Sort Visualizer (press Ctrl+C to quit)\n\n";
    int barWidth = 40;
    for (int i = 0; i < n; ++i) {
        bool hi = (i == i_high) || (i == j_high);
        if (hi) std::cout << "\x1b[38;5;226m"; // yellow
        std::cout << '[' << (i < 10 ? ' ' : (i < 100 ? ' ' : ' ')) << i << "] ";
        std::cout << bar(a[i], maxv, barWidth) << " ";
        std::cout << a[i];
        if (hi) std::cout << "\x1b[0m";
        std::cout << "\n";
    }
    std::cout << std::flush;
}

int main(int argc, char** argv) {
    size_t size = 20;
    int delayMs = 150;
    bool stepMode = false;

    for (int i = 1; i < argc; ++i) {
        std::string s = argv[i];
        if (s == "-k") stepMode = true;
        else if (s == "-s" && i + 1 < argc) {
            delayMs = std::atoi(argv[++i]);
            if (delayMs < 0) delayMs = 0;
        } else {
            size_t t = std::atoi(s.c_str());
            if (t > 0) size = t;
        }
    }

    std::vector<int> a;
    a.reserve(size);
    std::mt19937 rng((unsigned)std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(1, 100);
    for (size_t i = 0; i < size; ++i) a.push_back(dist(rng));

    hideCursor();
    draw(a);
    if (stepMode) std::cout << "Step mode: press Enter to advance...\n";
    else std::cout << "Auto mode: delay " << delayMs << " ms per step\n";

    for (size_t pass = 0; pass + 1 < a.size(); ++pass) {
        bool swapped = false;
        for (size_t i = 0; i + 1 < a.size() - pass; ++i) {
            draw(a, (int)i, (int)(i+1));
            if (stepMode) {
                std::cin.get();
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            }

            if (a[i] > a[i+1]) {
                std::swap(a[i], a[i+1]);
                swapped = true;
                draw(a, (int)i, (int)(i+1));
                if (stepMode) std::cin.get();
                else std::this_thread::sleep_for(std::chrono::milliseconds(delayMs / 2 + 10));
            }
        }
        if (!swapped) break;
    }

    draw(a, -1, -1);
    showCursor();
    std::cout << "\nSorted.\n";
    return 0;
}
