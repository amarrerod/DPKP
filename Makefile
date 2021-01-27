CPP=g++


all: knapsack_exact

knapsack_exact: main.cpp src/knapsackDP.cpp
	$(CPP) -g -std=c++17 -O3 -Wall main.cpp src/knapsackDP.cpp -o knapsack_exact

clean:
	rm knapsack_exact
