#include <iostream>
#include <string>

#include "src/knapsackDP.h"

const int NUM_ARGS = 2;

int main(int argc, char** argv) {
  if (argc != NUM_ARGS) {
    cerr << "Error in args. Usage: ./knapsack_exact <instance_file>" << endl;
    exit(EXIT_FAILURE);
  } else {
    string file = argv[1];
    KnapsackDP knapsackSolver(file);
    results solution = knapsackSolver.run();
    std::cout << "Optimal: " << solution.first << " in " << solution.second
              << "\"\n";
  }
  return 0;
}
