#include "list_s.hpp"
#include <fstream>
#include <chrono>

int main(int argc, char **argv)
{
    list_s *l = new list_s(std::stoi(argv[1]));
    std::string file_name = "inputs/in" + std::string(argv[1]) + ".txt";
    std::ifstream input_file;
    input_file.open(file_name);
    std::string buffer;

    auto t1 = std::chrono::high_resolution_clock::now();
    while (getline(input_file, buffer))
    {
        std::cout << " i = " << l->add_ordered(std::stoi(buffer)) << std::endl;
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    l->print();

    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    delete l;

    return 0;
}