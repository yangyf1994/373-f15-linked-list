#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct list_t {
	uint32_t index;
	struct list_t *next;
} list_t;

list_t* insert_sorted(list_t* head, list_t* new_element);
list_t* reverse(list_t* head);

#endif // LIST_H
