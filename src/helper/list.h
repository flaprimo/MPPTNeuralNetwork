#ifndef MPPTNEURALNETWORK_LIST_H
#define MPPTNEURALNETWORK_LIST_H

typedef struct list {
    void *info;

    struct list *next;
} list;

void list_addFirst(list **l, void *info);
void list_removeFirst(list **l);
void *list_get(list *l, int index);
void list_map(list **l, void *(*func)(void *));

#endif //MPPTNEURALNETWORK_LIST_H
