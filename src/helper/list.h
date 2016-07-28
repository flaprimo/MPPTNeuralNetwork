#ifndef MPPTNEURALNETWORK_LIST_H
#define MPPTNEURALNETWORK_LIST_H

typedef struct list_t {
    void *info;

    struct list_t *next;
} List;

void list_addFirst(List **l, void *info);
void list_removeFirst(List **l);
void *list_get(List *l, int index);

#endif //MPPTNEURALNETWORK_LIST_H
