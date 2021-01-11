#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked-list.h"
typedef struct _person person;
struct _person {
    int age;
    char* name;
};



/* Linked-List user-function declarations */

void* clone_person (void *elem);
int compare_person (void *a, void *b);
void destroy_person(void *elem);
void print_person (void *elem);
             

int main(int argc, char **argv) {

    struct list *person_list;
    person_list = list_init(clone_person, destroy_person, compare_person, print_person);
    if (!person_list) {
        printf("Error in list init!");
    }
    
    char _name[50];
    for (int i = 0; i < 3; i++) {
        printf("enter name: ");
        scanf("%s",_name);

        person p;
        p.age = i;
        p.name = _name;

        list_push(person_list, (void*)&p);
    }

    print_list(person_list);
    list_destroy(person_list);
}

void* clone_person (void *elem) {
    person *arg = (person*)elem;
    person *out = (person*)malloc(sizeof(person));
    if (!out) {
        printf("Fail!!!\n");
    }
    out->name = (char*)malloc(sizeof(char)*(strlen(arg->name) +1));

    out->age = arg->age;
    strcpy(out->name, arg->name);

    return (void*)out;
}

int compare_person (void *a, void *b) {
    person *one = (person*)a;
    person *two = (person*)b;

    return (one->age == two->age) ? 1 : 0;
}

void destroy_person(void *elem) {
    person *arg = (person*)elem;
    free (arg->name);
    free(arg); 
}

void print_person (void *elem) {
    person *arg = (person*)elem;
    printf("person name: %s, is  %d years old\n",arg->name, arg->age);
}
