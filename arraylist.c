#include <stdio.h>
#include "arraylist.h"

#define ARRAYLIST_INITIAL_CAPACITY 4


struct arraylist
{
	unsigned int size;
	unsigned int capacity;
	void** data;
};


arraylist* list_create() {
	/* Allocate Memory */
	arraylist* new_list = malloc(sizeof(arraylist));
	if (new_list == NULL) {
		return NULL;
	}
	new_list->size = 0;
	new_list->capacity = ARRAYLIST_INITIAL_CAPACITY;
	new_list->data = malloc(sizeof(void*) * ARRAYLIST_INITIAL_CAPACITY);
	if (new_list->data == NULL) {
		free(new_list);
		return NULL;
	}

	return new_list;
}

void list_add(arraylist* list, void* item) {
	list_allocate(list, list->size);
	list->data[list->size++] = item;
}

void list_allocate(arraylist* list, unsigned int size) {
	if (size > list->capacity) {
		unsigned int new_capacity = list->capacity;

		while (new_capacity < size) {
			new_capacity *= 2;
		}

		list->data = realloc(list->data, sizeof(void*) * new_capacity);
		list->capacity = new_capacity;
	}
}

void* list_get(arraylist* list, unsigned int index) {
	return list->data[index];
}

void list_clear(arraylist* list) {
	list->size = 0;
}

Boolean list_is_empty(arraylist* list) {
	return (0 == arraylist_size(list));
}

extern inline unsigned int arraylist_size(arraylist* list) {
	return list->size;
}


