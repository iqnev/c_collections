#undef Boolean
#define Boolean short unsigned int

typedef struct arraylist arraylist; 

void list_add(arraylist* list, void* item);
void* list_get(arraylist* list, unsigned int index);
void list_clear(arraylist* list);
arraylist* list_create();
void list_allocate(arraylist* list, unsigned int size);
inline unsigned int arraylist_size(arraylist* list);
Boolean list_is_empty(arraylist* list);


