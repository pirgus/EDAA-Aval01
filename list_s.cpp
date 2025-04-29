#include "list_s.hpp"
#include <fstream>
#include <chrono>
#include <vector>
#include <cstring>

int main(int argc, char **argv)
{
    list_s *l;
    std::string file_name = "inputs/in" + std::string(argv[1]) + ".txt";
    std::ifstream input_file;
    input_file.open(file_name);
    std::string buffer;
    std::vector<long int> values;
    std::string output_filename = "soutput_" + std::string(argv[2]) + std::string(argv[1]) + ".txt";
    std::ofstream output_file;
    output_file.open(output_filename);

    // first read into vector, so the exceution time doesn't count file reading
    while(getline(input_file, buffer)){
        values.push_back(std::stoi(buffer));
    }

    for(int i = 0; i < 10; i++){
        l = new list_s(std::stoi(argv[1]));
        std::chrono::duration<double, std::milli> ms_double;
        if(strcmp(argv[2], "o") == 0){
            auto t1 = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < values.size(); j++)
            {
                l->add_ordered(values[j]);
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            // std::cout << ms_double.count() << "ms\n";
        }
        else{
            auto t1 = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < values.size(); j++)
            {
                l->add(values[j]);
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
        }

        output_file << ms_double.count() << std::endl;

        if(i < 9){
            delete l;
        }
    }

    output_file << "EOI\n";
    std::chrono::duration<double, std::milli> ms_double;

    // l->print();

    // sequential search (worst and random case)
        // worst case
    long int last_value = l->get(std::stoi(argv[1]) - 1);
    for(int i = 0; i < 10; i++){
        auto t1 = std::chrono::high_resolution_clock::now();
        int comp = l->contains(last_value); // last value of array
        auto t2 = std::chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        output_file << ms_double.count() << ";" << comp << std::endl;
    }

    output_file << "EOSW\n";

    for(int i = 0; i < 1000; i++){
        int search_n = rand() % (std::stoi(argv[1]) + 1);
        auto t1 = std::chrono::high_resolution_clock::now();
        int comp = l->contains(search_n);
        auto t2 = std::chrono::high_resolution_clock::now();
        ms_double = t2 - t1;
        output_file << ms_double.count() << ";" << comp << std::endl;
    }

    output_file << "EOSR\n";

    // optmized search (worst and random case)
    if(strcmp(argv[2], "o") == 0){
        // worst case of opt search -> size of array - 2 (penultimate value)
        long int w_value = std::stoi(argv[1]) - 2;
        std::cout << "w_value = " << w_value << std::endl;
        for(int i = 0; i < 10; i++){
            auto t1 = std::chrono::high_resolution_clock::now();
            int comp = l->opt_search(w_value); // last value of array
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            output_file << ms_double.count() << ";" << comp << std::endl;
        }

        output_file << "EOOW\n";

        // random case of opt search
        for(int i = 0; i < 1000; i++){
            int search_n = rand() % (std::stoi(argv[1]) + 1);
            auto t1 = std::chrono::high_resolution_clock::now();
            int comp = l->opt_search(search_n);
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            output_file << ms_double.count() << ";" << comp << std::endl;
        }

        output_file << "EOOR\n";

        // binary search (worst and random case)
        // worst case binary search
        w_value = std::stoi(argv[1]); // worst case for binary search: non existent element 
        for(int i = 0; i < 10; i++){
            auto t1 = std::chrono::high_resolution_clock::now();
            int comp = l->bin_search(w_value);
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            output_file << ms_double.count() << ";" << comp << std::endl;
        }

        output_file << "EOBW\n";

        // random case binary search
        for(int i = 0; i < 1000; i++){
            int search_n = rand() % (std::stoi(argv[1]) + 1);
            auto t1 = std::chrono::high_resolution_clock::now();
            int comp = l->bin_search(search_n);
            auto t2 = std::chrono::high_resolution_clock::now();
            ms_double = t2 - t1;
            output_file << ms_double.count() << ";" << comp << std::endl;
        }
    }

    return 0;
}