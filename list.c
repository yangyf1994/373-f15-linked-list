#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t * prev = NULL;
	list_t * current = head;

	while(current && new_element->index>current->index){
		prev = current;
		current = current->next;
	}
	//if we are inserting in front
	if (prev==NULL){
		new_element->next = head;
		head = new_element;
	}
	else {
		prev->next = new_element;
		new_element->next = current;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t * prev = NULL;
	list_t * current = head;
	list_t * next = head->next;

	while(current){
		current->next = prev;
		prev = current;
		current = next;
		if(next) next = next->next;
	}

	return prev;
}

