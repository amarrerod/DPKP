#include <filesystem>
#include <iostream>
#include <string>

#include "src/knapsackDP.h"

using namespace std;
namespace fs = filesystem;

const int NUM_ARGS = 3;

int main(int argc, char** argv) {
  if (argc != NUM_ARGS) {
    cerr << "Error in args. Usage: ./knapsack_exact <instance_file> "
            "<path_to_results>"
         << endl;
    exit(EXIT_FAILURE);
  } else {
    string file = argv[1];
    fs::path pathToResults = argv[2];
    KnapsackDP knapsackSolver(file, pathToResults);
    results solution = knapsackSolver.run();
  }
  return 0;
}
