# Arraylists
The  `arraylist.c` file contains an arraylist implementation- a dynamic array which is automatically resized as needed.

Usage:

    #include <stdio.h>
    #include "arraylist.h"
    
    int main(void) {
    	arraylist* list = list_create();
    
    	list_add(list, 13);
    	list_add(list, 23);
    	list_add(list, 33);
    
    	int result = list_get(list, 1);
    
    	printf("The value with index[1] is %d", result);
    
    }
