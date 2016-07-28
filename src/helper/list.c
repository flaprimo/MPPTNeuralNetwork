#include <stdlib.h>
#include "list.h"

/**
 * Add first element to the list.
 * @param l list where should be added the new element
 * @param info the new element
 */
void list_addFirst(List **l, void *info)
{
    List *tmp = malloc(sizeof(List));

    tmp->info = info;
    tmp->next = *l;

    *l = tmp;
}

/**
 * Remove first element of the list.
 * @param l list where the first element should be removed
 */
void list_removeFirst(List **l)
{
    if (*l) {
        List *tmp = *l;
        *l = (*l)->next;

        free(tmp->info);
        free(tmp);
    }
}

/**
 * Given a list and an index, it returns the value at the position given, NULL otherwhise.
 * @param l list where to find the element
 * @param index of the element to be found
 * @return
 */
void *list_get(List *l, int index)
{
    void *result = NULL;

    if (l) {
        if (index == 0)
            result = l->info;
        else if (index > 0)
            result = list_get(l->next, --index);
    }

    return result;
}