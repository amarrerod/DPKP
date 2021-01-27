CPP=g++


all: knapsack_exact

knapsack_exact: main.cpp src/knapsackDP.cpp
	$(CPP) -g -std=c++17 -O3 -Wall main.cpp src/knapsackDP.cpp -o knapsack_exact

solve_all: knapsack_exact
	for instance in ./data/instances/*/*.kp; do \
		echo Solving instance: $$instance ; \
		./knapsack_exact $$instance ./data/results; \
	done
	

clean:
	rm knapsack_exact
