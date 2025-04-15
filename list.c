// implementacao de lista em C
// com alocacao de dados estática

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10

typedef struct Lista{
    int data[N];
    int size;
} Lista;

Lista *create_list(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL){
        printf("Error creating list...\n");
        return -1;
    }

    l->size = 0;
    return l;
}

int list_size(Lista *l){
    if(l != NULL){
        return l->size;
    }
    else{
        return -1;
    }
}

int add_to_list(int el, Lista *l){
    if(l != NULL && l->size < N){
        l->data[l->size] = el;
        l->size++;
        return l->size-1;
    }
    else{
        printf("Uncreated list OR full list!\n");
    }
}

void print_list(Lista *l){
    if(l != NULL){
        printf("[ ");
        for(int i = 0; i < l->size; i ++){
            if(i < l->size - 1){
                printf("%d, ", l->data[i]);
            }
            else{
                printf("%d", l->data[i]);
            }
        }
        printf(" ]\n");
    }
}

int get_element(Lista lista, int pos){
    return lista.data[pos];
}

int add_in_pos(Lista *l, int el, int pos){
    if(l != NULL && pos <= l->size && l->size < N){
        int aux = el;
        while(pos < l->size+1){
            int obj = aux;
            aux = l->data[pos];
            l->data[pos] = obj;
            pos++;
        }
        l->size++;
        return el;
    }
    else{
        printf("Full or unallocated list.\n");
        return -1;
    }
}

int add_ordered(Lista *l, int el){
    if(l->size < N){
        int i;
        for(i = l->size - 1; i >= 0 && l->data[i] > el; i--){
            l->data[i + 1] = l->data[i];
        }
        l->data[i + 1] = el;
        l->size++;
        return i + 1;
    }
    return -1;
}

int set_el(Lista *l, int el, int pos){
    if(l != NULL && pos < l->size){
        l->data[pos] = el;
        return el;
    }
    else{
        printf("Unallocated list or invalid index.\n");
        return -1;
    }
}

int contains_el(Lista* l, int el){
    if(l != NULL){
        for(int i = 0; i < l->size; i++){
            if(l->data[i] == el){
                return i;
            }
        }
    }

    return -1; // if element not found
}

int remove_el(Lista *l, int el){
    int position = contains_el(l, el);
    if(position > -1){
        if(position < l->size - 1){
            int count = position;
            while(count < l->size){
                l->data[count] = l->data[count + 1];
                count++;
            }
            l->size--;
            return position;
        }
        else{
            l->data[position] = -1;
            l->size--;
            return position;
        }
    }
    else{
        printf("Element not found\n");
        return -1;
    }
}

int remove_at_pos(Lista *l, int pos){
    if(l != NULL && pos < l->size && pos >= 0){
        int element_removed = l->data[pos];
        while(pos < l->size){
            l->data[pos] = l->data[pos + 1];
            pos++;
        }
        l->size--;
        return element_removed;
    }
    else{
        printf("Unallocated list or invalid index.\n");
        return -1;
    }
}

int binary_search(Lista *l, int value){
    int first_i = 0;
    int last_i = l->size - 1;

    while(last_i - first_i + 1 >= 1){
        int middle_i = (first_i + last_i) / 2;

        if(l->data[middle_i] == value){
            return middle_i;
        }

        if(l->data[middle_i] < value){
            first_i = middle_i + 1;
        }

        if(l->data[middle_i] > value){
            last_i = middle_i - 1;
        }
    }

    return -1;
}

void clear_list(Lista *l){
    if(l != NULL){
        l->size = 0;
        free(l);
        l = NULL;   
        printf("assigned null\n");
    }
}

int main(){
    Lista *lista = NULL;
    lista = create_list();
    int element, remove, position, new_el, search;
    
    char opc = 'C';
    while(opc != 'K'){
        printf("Choose what you'd like to do:\n");
        printf("A - Add to list\n");
        printf("B - Add to specific position\n");
        printf("C - Print list size\n");
        printf("D - Print list\n");
        printf("E - Get element at position\n");
        printf("F - Set element at position\n");
        printf("G - Search for element\n");
        printf("H - Binary search for element (ordered list)\n");
        printf("I - Remove element\n");
        printf("J - Remove element at position\n");
        printf("K - Clear list and Exit program\n");
        printf("L - Add ordered\n");
    
        scanf("%c", &opc);
        switch(opc){
            case 'A':
                printf("Insert element: \n");
                scanf("%d", &element);
                printf("New size after added el. = %d\n", add_to_list(element, lista));
                // getchar();
            break;

            case 'B':
                printf("Insert element and position: \n");
                scanf("%d", &element);
                scanf("%d", &position);
                printf("Added element = %d\n", add_in_pos(lista, element, position));
                getchar();

            break;

            case 'C':
                printf("List size = %d\n", lista->size);
                getchar();
            break;

            case 'D':
                print_list(lista);
                getchar();
            break;

            case 'E':
                printf("Insert position: \n");
                scanf("%d", &position);
                printf("Element at position = %d\n", get_element(*lista, position));
                getchar();

            break;

            case 'F':
                printf("Insert new value and position: \n");
                scanf("%d", &new_el);
                scanf("%d", &position);
                printf("New element = %d\n", set_el(lista, new_el, position));
                getchar();

            break;

            case 'G':
                printf("Insert value to search: \n");
                scanf("%d", &search);
                printf("Result of search - %d\n", contains_el(lista, search));
                getchar();

            break;

            case 'H':
                printf("Insert value to search: \n");
                scanf("%d", &search);
                printf("Result of binary search - %d\n", binary_search(lista, search));
                getchar();
            break;

            case 'I':
                printf("Choose value to remove: \n");
                scanf("%d", &remove);
                printf("Result of remove = %d\n", remove_el(lista, remove));
                getchar();

            break;

            case 'J':
                printf("Choose position to remove: \n");
                scanf("%d", &position);
                printf("Result of remove = %d\n", remove_at_pos(lista, position));
                getchar();

            break;

            case 'K':
                printf("Clearing list\n");
                clear_list(lista);
                printf("lista = %d ; lista size = %d\n", sizeof(lista), lista->size);
                getchar();
            break;

            case 'L':
                printf("Insert element: \n");
                scanf("%d", &element);
                printf("Result of ordered add: %d\n", add_ordered(lista, element));
            break;
        }
        getchar();
        system("clear");
    }

    // printf("%p\n", lista);
    // if(lista != NULL){
    //     printf("List's pointer wasn't unallocated.\n");
    //     clear_list(lista);
    // }

    return 0;
}