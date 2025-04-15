#include "list_d.hpp"

int main(){
    list_d *l = new list_d;

    l->add_ordered(5);
    l->print();
    l->add_ordered(1);
    l->print();
    l->add_ordered(7);
    l->print();
    l->add_ordered(10);
    l->print();
    l->add_ordered(8);
    l->print();
    l->add_ordered(45);
    l->print();
    l->add_ordered(0);

    l->print();

    delete l;

}