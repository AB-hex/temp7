#include <stdlib.h>
#include <stdio.h>
#include "linked-list.h"

struct node {
	struct node *next;
	void *element;
};

struct list {
	struct node *head;
	struct node *tail;
	clone_func_t clone;
	destroy_func_t destroy;
	compare_func_t compare;
    print_func_t print;
};

struct list* list_init(clone_func_t clone,
                       destroy_func_t destroy,
                       compare_func_t compare,
                       print_func_t print) {
    struct list *list;
    list = (struct list*)malloc(sizeof(*list));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->clone = clone;
    list->destroy = destroy;
    list->compare = compare;
    list->print = print;
    return list;
}

void list_destroy(struct list *list) {
    if (!list) {
        return;
    }
    struct node *cursor;
    struct node *tmp;

    cursor=list->head;
    while(cursor) {
        tmp=cursor;
        cursor=cursor->next;
        list->destroy(tmp->element);
        free(tmp);
    }
    free(list);
}

/* Returns the element if found, otherwise returns NULL */
void* list_search(struct list *list, void *elem) {
    if (!list || !elem) {
        return NULL;
    }
    struct node *cursor;
    for (cursor=list->head; cursor; cursor=cursor->next) {
        if (list->compare(elem, cursor->element)) {
            return cursor->element;
        }
    }
    return NULL;
} 

void list_push(struct list *list, void *elem) {
    if (!list || !elem) {
        return;
    }
    struct node *node;
    void *clone;

    node=(struct node*)malloc(sizeof(*node));
    clone=list->clone(elem);
    if (!node || !clone) {
        /* No memory... */
        list->destroy(clone);
        free(node);
        return;
    }
    node->next=NULL;
    node->element = clone;
    if (list->tail) {
        list->tail->next=node;
    }
    list->tail=node;
    if (!list->head) {
        list->head = node;
    }
}


void print_list(struct list *list) {
    if (!list) {
        return ;
    }
    struct node *cursor;
    for (cursor=list->head; cursor; cursor=cursor->next) {
        list->print(cursor->element);
    }
}