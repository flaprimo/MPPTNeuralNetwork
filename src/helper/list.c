#include <stdlib.h>
#include "list.h"

/**
 * Given a list and an element, the element is added as the first of the list.
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
 * Given a list and an element, the element is added at the end of the list.
 * @param l
 * @param info
 */
void list_addLast(List **l, void *info)
{
    List *tmp = malloc(sizeof(List));

    tmp->info = info;
    tmp->next = NULL;

    if (*l == NULL)
        *l = tmp;
    else {
        List *tmp2 = *l;
        while (tmp2->next != NULL)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
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

/**
 * Given an list, an index and a destructor function for l->info, it remove the corresponding element of the list.
 * @param l list where the first element should be removed
 */
void list_remove(List **l, int index, void (*freeInfo)(void *))
{
    if (*l) {
        if (index == 0) {
            List *tmp = *l;
            *l = (*l)->next;

            freeInfo(tmp->info);
            free(tmp);
        }
        else {
            list_remove(&(*l)->next, --index, freeInfo);
        }
    }
}

/**
 * Given an list and a destructor function for l->info, it remove every element of the list.
 * @param l
 * @param freeInfo
 */
void list_removeAll(List **l, void (*freeInfo)(void *))
{
    if (*l) {
        list_remove(l, 0, freeInfo);
        list_removeAll(l, freeInfo);
    }
}