#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>


int main(int argc, char **argv){
    std::ofstream outdata;
    int i;
    int N = std::stoi(argv[1]);
    std::vector<int> values;
    for(i = 0; i < N; i++){
        values.push_back(i);
    }

    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(values.begin(), values.end(), std::default_random_engine(seed));

    std::string filename = "inputs/in" + std::string(argv[1]) + ".txt";

    outdata.open(filename);
    if(!outdata){
        std::cerr << "Error: file could not be opened" << std::endl;
        return -1;
    }

    for(i = 0; i < N; i++){
        outdata << values[i] << std::endl;
    }

    outdata.close();
    return 0;
}