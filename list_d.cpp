#include "list_d.hpp"
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <cstring>

int main(int argc, char **argv)
{
    std::string file_name = "inputs/in" + std::string(argv[1]) + ".txt";
    std::ifstream input_file;
    input_file.open(file_name);
    std::string buffer;
    std::vector<long int> values;
    std::ofstream output_file;
    std::string o_file_name = "output_" + std::string(argv[2]) + std::string(argv[1]) + ".txt";
    output_file.open(o_file_name);

    double mean = 0;
    // first read into vector, so the exceution time doesn't count file reading
    while(getline(input_file, buffer)){
        values.push_back(std::stoi(buffer));
    }

    list_d *l;
    for(int i = 0; i < 10; i++){
        l = new list_d;
        std::chrono::duration<double, std::milli> ms_double;
        if(strcmp("o", argv[2]) == 0){ // ordered insertion
            auto t1 = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < values.size(); j++){
                l->add_ordered(values[j]);
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            // std::cout << ms_double.count() << "ms\n";
        }
        else{ // unordered insertion
            auto t1 = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < values.size(); j++){
                l->add(values[j]);
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            // std::cout << ms_double.count() << "ms\n";
        }

        output_file << ms_double.count() << std::endl;
        
        if(i < 9){
            delete l; // if it isn't the last test case, delete the list
                      // otherwise, we keep the list to use it for the search tests
        };
    }


    output_file << "EOI\n";
    std::chrono::duration<double, std::milli> ms_double;

    // ------------------- search

    // worst case scenario - 10 tests
    int search_v = std::stoi(argv[1]) + 1;
        // worst case for ordered linked list -> in this case, the penultimate value since we keep track of the tail
    if(strcmp("o", argv[2]) == 0){
        search_v = std::stoi(argv[1]) - 2;
    }

    std::cout << "search v = " << search_v << std::endl;

    for(int i = 0; i < 10; i++){
        auto t1 = std::chrono::high_resolution_clock::now();
        int n_comp = l->search(search_v);
        auto t2 = std::chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        output_file << ms_double.count() << ";" << n_comp << std::endl;
    }

    output_file << "EOWC\n";

    // random scenarios - 1000 scenarios
    for(int i = 0; i < 1000; i++){
        auto t1 = std::chrono::high_resolution_clock::now();
        int search_n = rand() % (std::stoi(argv[1]) + 1);
        int n_comp = l->search(search_n);
        auto t2 = std::chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        output_file << ms_double.count() << ";" << n_comp << std::endl;
        // std::cout << "search time = " << ms_double.count() << "ms\n";
    }

    delete l;

    input_file.close();
    output_file.close();

    return 0;
}