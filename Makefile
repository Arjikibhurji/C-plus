CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra

.PHONY: all clean
all: bubble_sort bubble_sort_visual

bubble_sort: bubble_sort.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

bubble_sort_visual: bubble_sort_visual.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f bubble_sort bubble_sort_visual
