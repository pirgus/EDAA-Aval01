#include <iostream>

class list_s
{
private:
    long int *data;
    int max_size;
    int size;
public:
    list_s(int max_size);
    ~list_s();
    int get_size();
    void set_size(int n);
    int add(long int value);
    void print();
    long int get(int position);
    int add_at(long int value, int position);
    int add_ordered(long int value);
    int set(long int value, int position);
    int contains(long int value);
    int remove(long int value);
    int remove_at(int position);
    int bin_search(long int value);
    int opt_search(long int value);
};

list_s::list_s(int m_size)
{
    data = new long int[m_size];
    max_size = m_size;
    size = 0;
}

list_s::~list_s()
{
    delete[] data;
    max_size = -1;
    size = -1;
}

int list_s::get_size(){
    return size;
}

void list_s::set_size(int n){
    size = n;
}

int list_s::add(long int value){
    if(size < max_size){
        data[size] = value;
        size++;
        return size;
    }
    else{
        std::cout << "Full list\n";
        return -1;
    }
}


void list_s::print(){
    std::cout << "[ ";
    for(int i = 0; i < size; i++){
        if(i < size - 1){
            std::cout << data[i] << " ";
        }
        else{
            std::cout << data[i];
        }
    }
    std::cout << " ]\n";
}

long int list_s::get(int position){
    return data[position];
}

int list_s::add_at(long int value, int position){
    if(position <= size && size < max_size){
        int aux = value;
        while(position < size+1){
            int obj = aux;
            aux = data[position];
            data[position] = obj;
            position++;
        }
        size++;
        return value;
    }
    else{
        std::cout << "Full list\n";
        return -1;
    }
}

int list_s::add_ordered(long int value){
    if(size < max_size){
        int i;
        for(i = size - 1; i >= 0 && data[i] > value; i--){
            data[i + 1] = data[i];
        }
        data[i + 1] = value;
        size++;
        return i + 1;
    }

    return -1;
}

int list_s::set(long int value, int position){
    if(position < size){
        data[position] = value;
        return value;
    }
    else{
        std::cout << "Invalid index\n";
        return -1;
    }
}

int list_s::contains(long int value){
    for(int i = 0; i < size; i++){
        if(data[i] == value){
            return i;
        }
    }

    return -1;
}

int list_s::remove(long int value){
    int position = contains(value);
    if(position > -1){
        if(position < size - 1){
            int count = position;
            while(count < size){
                data[count] = data[count + 1];
                count++;
            }
            size--;
            return position;
        }
        else{
            data[position] = -1;
            size--;
            return position;
        }
    }
    else{
        std::cout << "Element not found\n";
        return -1;
    }
}

int list_s::remove_at(int position){
    if(position < size && position >= 0){
        int element_removed = data[position];
        while(position < size){
            data[position] = data[position + 1];
            position++;
        }
        size--;
        return element_removed;
    }
    else{
        std::cout << "Invalid index\n";
        return -1;
    }
}

int list_s::bin_search(long int value){
    int first_i = 0;
    int last_i = size - 1;
    int count = 0;

    while(last_i - first_i + 1 >= 1){
        int middle_i = (first_i + last_i) / 2;

        if(data[middle_i] == value){
            return count;
        }
        
        if(data[middle_i] < value){
            first_i = middle_i + 1;
        }

        if(data[middle_i] > value){
            last_i = middle_i - 1;
        }
        count++;
    }

    return count;
}

int list_s::opt_search(long int value){
    // for ordered lists only
    if(data[0] > value || data[size - 1] < value){
        return -1;
    }
    else{
        for(int i = 0; i < size; i++){
            if(data[i] == value){
                return i;
            }
            else if(data[i] > value){
                return -1;
            }
        }
    }

    return -1;
}