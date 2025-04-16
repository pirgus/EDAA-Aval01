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

    // for (int i = 0; i < 30; i++)
    // {
    //     input_file.clear();
    //     input_file.seekg(0);

    //     list_d *l = new list_d;
    //     auto t1 = std::chrono::high_resolution_clock::now();
    //     while (getline(input_file, buffer))
    //     {
    //         l->add(std::stoi(buffer));
    //     }
    //     auto t2 = std::chrono::high_resolution_clock::now();

    //     std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    //     std::cout << ms_double.count() << "ms\n";
    //     delete l;
    // }

    // restore file pointer to the beginning of the file

    // for (int i = 0; i < 30; i++)
    // {
        // input_file.clear();
        // input_file.seekg(0);
        list_d *l = new list_d;
        auto t1 = std::chrono::high_resolution_clock::now();
        while (getline(input_file, buffer))
        {
            l->add_ordered(std::stoi(buffer));
        }
        auto t2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        std::cout << ms_double.count() << "ms\n";

// ------------------- search

        t1 = std::chrono::high_resolution_clock::now();

        std::cout << "result of search = " << l->search(99999) << std::endl;
        t2 = std::chrono::high_resolution_clock::now();

        ms_double = t2 - t1;
        std::cout << ms_double.count() << "ms\n";

        // l->print();
        delete l;
    // }

    input_file.close();

    return 0;
}