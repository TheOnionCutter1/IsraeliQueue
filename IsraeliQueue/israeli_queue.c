#include "israeli_queue.h"
#include <stdlib.h>

typedef struct
{
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct
{
    int groupID;
    Node* groupHead;
    Node* groupTail;
    struct GroupNode* nextGroup;
} GroupNode;

struct IsraeliQueue
{
    GroupNode* head;
    GroupNode* tail;
};

IsraeliQueue* israeliQueue_create()
{
    IsraeliQueue* q = malloc(sizeof(IsraeliQueue));

    q->head = NULL;
    q->tail = NULL;

    return q;
}
