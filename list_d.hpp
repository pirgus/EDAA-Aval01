#include <iostream>

// NODE CLASS DEFINITION --------------------------------------------------------------------
class node{
    private:
        long int value;
        node *next;
    
    public:
        node(long int value);
        node();
        ~node();
        node *get_next() const;
        void set_next(node *new_next);
        long int get_value() const;
        void set_value(int new_value);
};

node::node(long int v){
    value = v;
    next = nullptr;
}

node::node(){
    value = 0;
    next = nullptr;
}

node::~node(){

}

node *node::get_next() const{
    return next;
}

void node::set_next(node *new_next){
    next = new_next;
}

long int node::get_value() const{
    return value;
}

void node::set_value(int new_value){
    value = new_value;
}


// LINKED LIST CLASS DEFINITION -----------------------------------------------------------------
class list_d
{

private:
    node *head;
    node *tail;
    int size;

public:
    list_d();
    ~list_d();
    int get_size();
    long int get_value(int position);
    void add(long int value);
    void print();
    int remove_v(long int value);
    int add_at_end(long int value);
    int search(long int value);
    int search_ord(long int value);
    int add_ordered(long int value);
};

list_d::list_d(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}   

list_d::~list_d(){
    node *aux = head;
    while(aux != nullptr){
        head = head->get_next();
        delete(aux);
        aux = head;
    }
}

int list_d::get_size(){
    return size;
}

long int list_d::get_value(int position){
    if(position > size || position < 0){
        std::cout << "Invalid index\n";
        return -1;
    }
    node *aux;
    int count = 0;
    aux = head;
    while(aux != nullptr){
        if(count == position){
            return aux->get_value();
        }
        aux = aux->get_next();
        count++;
    }

    std::cout << "Element not found\n";
    return -1;
}

void list_d::add(long int value){
    node *aux;
    aux = head;
    head = new node(value);
    head->set_next(aux);
    if(size == 0){
        tail = head;
    }
    size++;
}

int list_d::add_at_end(long int value){
    node *aux = tail;
    if(aux == nullptr){
        add(value);
        return 0;
    }

    node *new_node = new node(value);
    aux->set_next(new_node);
    tail = new_node;
    return ++size;
}

void list_d::print(){
    node *aux;
    aux = head;
    int count = 0;
    std::cout << "[ ";
    while(aux != nullptr){
        if(count < size - 1){
            std::cout << aux->get_value() << ", ";
        }
        else{
            std::cout << aux->get_value() << " ";
        }

        aux = aux->get_next();
        count++;
    }
    std::cout << " ]" << std::endl;

    std::cout << "tail = " << tail->get_value() << std::endl;
}

// linear search: works for any kind of list: unordered or ordered, whatever!
int list_d::search(long int value){
    int count = 0;
    node *aux = head;
    while(aux != nullptr){
        if(aux->get_value() == value){
            return count;
        }
        aux = aux->get_next();
        count++;
    }

    return count;
}

// search in an ordered list (ONLY WORKS IF LIST IS ORDERED!!!!!!)
int list_d::search_ord(long int value){
    int count = 0;
    node *aux = head;
    while(aux != nullptr){
        if(aux->get_value() > value || tail->get_value() < value){
            // current element is greater than the value being searched, which in a ordered list means
            // that this value doesn't exist
            // also, if the last value of the ordered list is lesser than the value being search,
            // it also means that the value is not present on the ordered list
            return -1;
        }
        else if(aux->get_value() == value){
            return count;
        }

        aux = aux->get_next();
        count++;
    }

    return -1;
}

int list_d::remove_v(long int value){
    node *aux = head;
    node *earlier;
    int count = 0;
    while(aux != nullptr){
        if(aux->get_value() == value){
            if(count == 0){
                head = aux->get_next();
                delete aux;
                if(size == 1){
                    // the element removed was the first and only element of the list
                    tail = head;
                }
                size--;
                return count;
            }
            else{
                earlier->set_next(aux->get_next());
                if(count == size - 1){
                    // if the el. to be removed is the last el. of the list
                    tail = earlier;
                }
                delete aux;
                size--;
                return count;
            }
        }
        earlier = aux;
        aux = aux->get_next();
        count++;
    }

    std::cout << "Element not found on list.\n";
    return -1;
}

int list_d::add_ordered(long int value){
    node *aux = head;
    // if the list is empty OR it is lesser than the first value, add at beginning
    if(aux == nullptr || aux->get_value() > value){
        add(value);
        return 0;
    }

    // otherwise, if the value is greater than the tail's value, add at end
    if(value > tail->get_value()){
        add_at_end(value);
        return size;
    }

    // on the last case, go through the list and find the correct position to add the value
    int count = 0;
    while(aux->get_next() != nullptr && aux->get_next()->get_value() < value){
        aux = aux->get_next();
        count++;
    }

    node *new_node = new node(value);
    new_node->set_next(aux->get_next());
    aux->set_next(new_node);
    size++;
    return count;
}
