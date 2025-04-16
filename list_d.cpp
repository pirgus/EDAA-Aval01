#include "list_d.hpp"
#include <fstream>
#include <string>
#include <chrono>

int main(int argc, char **argv)
{
    std::string file_name = "inputs/in" + std::string(argv[1]) + ".txt";
    std::ifstream input_file;
    input_file.open(file_name);
    std::string buffer;

    double mean = 0;

    for(int i = 0; i < 10; i++){
        list_d *l = new list_d;
        input_file.clear();
        input_file.seekg(0);
    
        auto t1 = std::chrono::high_resolution_clock::now();
    
        while (getline(input_file, buffer)){
            l->add_ordered(std::stoi(buffer));   
        }
    
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        std::cout << ms_double.count() << "ms\n";
        mean += ms_double.count();
        delete l;
    }

    mean /= 10;
    std::cout << "mean time = " << mean << std::endl;

    // l->print();

    // ------------------- search
    list_d *l = new list_d;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000; i++){
        int search_n = rand() % 100001;
        l->search_ord(search_n);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto ms_double = t2 - t1;
    std::cout << "search time = " << ms_double.count() << "ms\n";


    // l->print();
    delete l;
    // }

    input_file.close();

    return 0;
}