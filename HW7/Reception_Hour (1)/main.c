#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked-list.h"

/* Linked-List user-function declarations */

void* clone_int (void* elem);            
int compare_int (void *a, void *b); 
void destroy_int (void* elem);           
void print_int (void* elem); 
             

int main(int argc, char **argv) {

    struct list *int_list;
    int_list = list_init(clone_int, destroy_int, compare_int, print_int);
    if (!int_list) {
        printf("Error in list init!");
    }
    
    for (int i = 0; i < 3; i++) {
        printf("Elem with val %d is pushed to the list:\n", i);
        list_push(int_list, (void*)&i);
    }

    print_list(int_list);
    list_destroy(int_list);
}

void* clone_int (void* elem) {
    int *arg = (int*)elem;
    int *out = (int*)malloc(sizeof(int));
    if (!out) {
        printf("Error !\n");
        return NULL;
    }
    *out = (*arg);
    return (void*)out;
}

int compare_int (void *a, void *b) {
    int *first = (int*)a;
    int *second = (int*)b;
    return (*first == *second) ? 1 : 0;
}

void destroy_int (void* elem) {
    free(elem);
} 

void print_int(void* elem) {
    int *tmp = (int*)elem;
    printf("- %d\n", *tmp); 
}  