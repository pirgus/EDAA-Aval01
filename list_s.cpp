#include "list_s.hpp"
#include <fstream>
#include <chrono>
#include <vector>

int main(int argc, char **argv)
{
    list_s *l = new list_s(std::stoi(argv[1]));
    std::string file_name = "inputs/in" + std::string(argv[1]) + ".txt";
    std::ifstream input_file;
    input_file.open(file_name);
    std::string buffer;
    std::vector<long int> values;

    // first read into vector, so the exceution time doesn't count file reading
    while(getline(input_file, buffer)){
        values.push_back(std::stoi(buffer));
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < values.size(); j++)
    {
        l->add_ordered(values[j]);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    // l->print();

    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    delete l;

    return 0;
}