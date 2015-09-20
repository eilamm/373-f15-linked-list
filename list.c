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

	
	if (new_element->index < head->index) {
		new_element->next = head;
		head = new_element;
		return head;
	}

	list_t* list_ptr = head->next;
	list_t* prev_ptr = head;
	while (list_ptr != NULL) {
		if (new_element->index < list_ptr->index) {
			prev_ptr->next = new_element;
			new_element->next = list_ptr;
			return head;
		}
		else {
			prev_ptr = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
	//New element is largest element
	prev_ptr->next = new_element;
	new_element->next = NULL;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* temp_trail = NULL;
	list_t* temp = head;
	list_t* temp_fw = head->next;
	while (temp_fw != NULL) {
		temp->next = temp_trail;
		temp_trail = temp;
		temp = temp_fw;
		temp_fw = temp_fw->next;
	}
	temp->next = temp_trail;
	head = temp;
	return head;
}

