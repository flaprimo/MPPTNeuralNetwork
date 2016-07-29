#ifndef MPPTNEURALNETWORK_LIST_H
#define MPPTNEURALNETWORK_LIST_H

typedef struct list_t {
    void *info;

    struct list_t *next;
} List;

void list_addFirst(List **l, void *info);
void list_addLast(List **l, void *info);
void *list_get(List *l, int index);
void list_remove(List **l, int index, void (*freeInfo)(void *));
void list_removeAll(List **l, void (*freeInfo)(void *));

#endif //MPPTNEURALNETWORK_LIST_H
