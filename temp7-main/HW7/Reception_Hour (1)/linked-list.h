#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* typename of list user functions */
typedef void*(*clone_func_t)(void*); 			/* Clones the element */
typedef int(*compare_func_t)(void *a, void *b); /* Returns 1 iff (*a)==(*b) */
typedef void(*destroy_func_t)(void*); 			/* Deallocate all memory of element */
typedef void(*print_func_t)(void*); 			/* Prints the element*/

struct list; /* Opaque pointer */

struct list* list_init(clone_func_t clone,
                       destroy_func_t destroy,
                       compare_func_t compare,
                       print_func_t print);

void list_destroy(struct list *list);

/* Returns the element (by-pointer) if found, otherwise returns NULL */
void* list_search(struct list *list, void *elem); 

void list_push(struct list *list, void *elem);

void print_list(struct list *list);

#endif 