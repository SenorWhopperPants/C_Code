/***
 * @breif   linked_list.h contains a linked list data structure
 *          and accompanying functions
 * 
 * @author  Josh Bussis
 * @date    2020/11/19
 */


#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

#include <stdlib.h>
#include <stdio.h>

/* CONSTANTS */


/* STRUCTURES AND TYPES */
typedef struct entry_t {
    int value;              /* value for the entry */
    struct entry_t* next;   /* pointer to next entry */
} ENTRY;

typedef struct list_t {
    struct entry_t* first;  /* pointer to first entry in list */
    int size;               /* store how many entries are in it */
} LINKED_LIST;


/* FUNCTION DECLARATIONS */
void init_list(LINKED_LIST* list); 
void add_entry(LINKED_LIST* list, int value);
void add_entry_front(LINKED_LIST* list, int value);
void delete_entry(LINKED_LIST* list, int value);
void delete_list(LINKED_LIST* list);
void print_list(LINKED_LIST* list);

/* FUNCTION DEFINITIONS */


void init_list(LINKED_LIST* list)
{
    list->first = NULL; /* set first to NULL */
    list->size = 0;     /* set size to zero */
}


/**
 * @brief   add_entry() adds a new entry to the end of the list provided
 * 
 * @param   list (LINKED_LIST*)
 * @param   value (int) 
 */
void add_entry(LINKED_LIST* list, int value)
{
    ENTRY* current;     /* make an ENTRY pointer for current entry in list */
    ENTRY* new_entry;   /* make an ENTRY pointer for the new entry */

    new_entry = malloc(sizeof(ENTRY));  /* allocate memory for the new_entry */
    new_entry->value = value;           /* set value of new_entry */
    new_entry->next = NULL;             /* make sure next points to nothing */

    if (list->first == NULL) {          /* check for entries in list */
        list->first = new_entry;        /* set first entry to new_entry */
        list->size++;                   /* increment size */
        return;
    }

    current = list->first;  /* set current pointer to first entry in list */

    while(current->next != NULL) {  /* keep going until at the end of list */
        current = current->next;    /* make sure to keep incrementing */
    }

    current->next = new_entry;      /* point the last entry to the new_entry */
    list->size++;                   /* increment size */
}


/**
 * @brief   add_entry_front() takes value and puts it at the front of the list
 * 
 * @param   list (LINKED_LIST*)
 * @param   value (int)
 */
void add_entry_front(LINKED_LIST* list, int value)
{
    ENTRY* new_entry;                   /* make ENTRY pointer for new entry */

    new_entry = malloc(sizeof(ENTRY));  /* allocate space for the new entry */
    new_entry->value = value;           /* set entry value to desired value */
    new_entry->next = NULL;             /* start with next pointer to NULL */

    if (list->first == NULL) {          /* if there's no entries */
        list->first = new_entry;        /* add new entry to front */
        list->size++;                   /* increment size */
        return;                         /* we are done here */
    }

    new_entry->next = list->first;      /* point next to first entry in list */
    list->first = new_entry;            /* make new entry the first entry */
    list->size++;                       /* increment size */
}



void delete_entry(LINKED_LIST* list, int value)
{

    /* TODO: make sure we can delete the first entry */
    ENTRY* current;
    ENTRY* next;

    if (list->size == 0) {
        return;                 /* there's nothing to delete */
    }
    else if (list->size == 1) {
        if (list->first->value == value)
        {
            free(list->first);      /* there's only one entry to delete */
            list->first = NULL;     /* make sure first points to nothing */
            list->size = 0;         /* reset size */
        }
        return;
    }

    current = list->first;
    next = list->first->next;

    if (current->value == value) {
        list->first = next;
        free(current);
        list->size--;
    }

    do {
        if (next->value == value) {
            current->next = next->next;
            free(next);
            list->size--;
            break;
        }

        current = next;
        next = next->next;

    } while (current->next != NULL);
}





/**
 * @brief   print_list() prints out values of given list
 * 
 * @param   list (LINKED_LIST*) 
 */
void print_list(LINKED_LIST* list)
{
    ENTRY* current = list->first;       /* ENTRY pointer for current entry */
    do {
        printf("%d\n", current->value); /* print current value */
        current = current->next;        /* increment to the next entry */
    } while (current != NULL);          /* make sure there are more entries */
}


#endif  /* end of linked_list.h */