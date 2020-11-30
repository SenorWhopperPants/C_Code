/***
 * @brief   main.c tests the functionality of linked_list.h
 * 
 * @author  Josh Bussis
 * @date    2020/11/19
 */

#include "linked_list.h"

int main(void)
{
    LINKED_LIST new_list;
    init_list(&new_list);

    add_entry(&new_list, 1);
    add_entry(&new_list, 2);
    add_entry_front(&new_list, 0);
    delete_entry(&new_list, 2);
    print_list(&new_list);

    return 0;
}