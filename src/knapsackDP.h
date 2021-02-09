
#ifndef __KNAPSACK_DP_H__
#define __KNAPSACK_DP_H__

#include <chrono>
#include <cmath>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
namespace fs = filesystem;

using optimal = int;
using elapsedTime = double;
using p = int;
using w = int;
using results = std::pair<optimal, elapsedTime>;

class KnapsackDP {
   public:
    KnapsackDP(const string& filename, const fs::path& pathToResults);

    KnapsackDP(const int& nItems, vector<p>& profits, vector<w>& weights,
               const p& capacity);

    virtual ~KnapsackDP();

    results run();

   private:
    // Maximum weight the knapsack can carry
    p maximumCapacity;
    // Number of items to put in the KP
    int numberOfItems;
    // Weights and profits of each item
    vector<w> weights;
    vector<p> profits;
    // Elapsed time of the algorithm
    double elapsedCPUTime;
    double elapsedWallTime;
    // File which defines the instance
    string instanceFile;
    // File where the results are saved
    string outputFile;
    // Variables of the DP algorithm
    vector<vector<p>> table;

   private:
    static const string INST_NONE;
    static const char ESCAPE;
    static const string EXTENSION;

   private:
    void writeResults();
};

#endif