
#include "knapsackDP.h"

#define DEBUG

const string KnapsackDP::INST_NONE = "None";
const char KnapsackDP::ESCAPE = '/';
const string KnapsackDP::EXTENSION = ".DP";

KnapsackDP::KnapsackDP(const int& nItems, vector<p>& profits,
                       vector<w>& weights, const p& capacity)
    : maximumCapacity(capacity), numberOfItems(nItems) {
    this->profits.reserve(nItems);
    this->weights.reserve(nItems);
    for (int i = 0; i < nItems; i++) {
        this->profits[i] = profits[i];
        this->weights[i] = weights[i];
    }
    instanceFile = INST_NONE;
}

KnapsackDP::KnapsackDP(const string& filename, const fs::path& pathToResults)
    : maximumCapacity(0), numberOfItems(0) {
    ifstream input(filename.c_str());
    if (!input.is_open()) {
        cerr << "Error while opening instance file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    string readLine;
    // Leemos la configuracion de la instance y adaptamos los vectores
    input >> numberOfItems >> maximumCapacity;
    profits.reserve(numberOfItems);
    weights.reserve(numberOfItems);
    table.resize(numberOfItems + 1, vector<int>(maximumCapacity + 1, 0.0));
    int w, p;
    while (input >> w >> p) {
        weights.push_back(w);
        profits.push_back(p);
    }
    input.close();
    // Creamos el directorio de resultados si no existe
    fs::create_directories(pathToResults);
    fs::path instancePath = filename;
    outputFile = (pathToResults / instancePath.filename().replace_extension(EXTENSION));
#ifdef DEBUG
    cout << "Filename: " << filename << endl;
    cout << "Output file: " << outputFile << endl;
    cout << "Number of items: " << numberOfItems << endl;
    cout << "Maximum Capacity: " << maximumCapacity << endl;
#endif
}

KnapsackDP::~KnapsackDP() {
    table.clear();
    table.shrink_to_fit();
}

/**
 *
 * Dynamic Programming Algorithm for solving the 0/1 Knapsack Problem
 *
 * */
results KnapsackDP::run() {
    clock_t startCPUTime = clock();
    auto startWallTime = chrono::system_clock::now();
    for (int i = 0; i <= numberOfItems; i++) {
        for (int j = 0; j <= maximumCapacity; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else {
                if (weights[i - 1] <= j) {
                    table[i][j] = max(profits[i - 1] + table[i - 1][j - weights[i - 1]],
                                      table[i - 1][j]);
                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
    }
    clock_t stopCPUTime = clock();
    auto stopWallTime = chrono::system_clock::now();
    elapsedCPUTime = (stopCPUTime - startCPUTime) / (double)CLOCKS_PER_SEC;
    chrono::duration<double> WallTime = (stopWallTime - startWallTime);
    elapsedWallTime = WallTime.count();
    std::cout << "Optimal: " << table[numberOfItems][maximumCapacity]
              << std::endl;
    std::cout << "Finished in " << std::endl;
    std::cout << "\t- " << elapsedCPUTime << " seconds [CPU Clock]" << std::endl;
    std::cout << "\t- " << elapsedWallTime << " seconds [Wall Clock]"
              << std::endl;

    if (instanceFile != INST_NONE) {
        writeResults();
    }
    return {table[numberOfItems][maximumCapacity], elapsedWallTime};
}

void KnapsackDP::writeResults() {
    // Guardamos los resultados en un fichero
    ofstream outStream(outputFile, fstream::out);
    outStream << table[numberOfItems][maximumCapacity] << endl
              << elapsedWallTime;
    outStream.close();
}
