cxx = g++-12
# cxx = zig c++

sources = $(wildcard *.cpp *.h)

build: main.cpp
	$(cxx) -std=c++20 -O $(sources)

run: main.cpp
	$(cxx) -std=c++20 -O $(sources) && ./a.out
