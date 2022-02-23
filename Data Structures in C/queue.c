// implementation of a queue data structure in C

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int value;
    struct QueueNode *previousNode;
    struct QueueNode *nextNode;
} QueueNode;

void push(int value, QueueNode **frontNode, QueueNode **endNode)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->value = value;
    if (*endNode == NULL) {
        newNode->nextNode = NULL; 
        newNode->previousNode = NULL;
        *frontNode = newNode;
        *endNode = newNode;
        return;
    }
    newNode->previousNode = *endNode;
    newNode->nextNode = NULL;
    (*endNode)->nextNode = newNode;
    *endNode = newNode;
}

void pop(QueueNode **frontNode, QueueNode **endNode)
{
    if (*frontNode == NULL)
        return;
    if (*frontNode == *endNode) {
        *frontNode = NULL;
        *endNode = NULL;
        return;
    }
    QueueNode *currentFrontNode = (*frontNode)->nextNode;
    currentFrontNode->previousNode = NULL;
    *frontNode = currentFrontNode;
}

int top(QueueNode **frontNode)
{
    if (*frontNode == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return (*frontNode)->value;
}

int main(int argc, const char **argv)
{
    QueueNode *frontNode = NULL, *endNode = NULL;
    push(5, &frontNode, &endNode);
    push(7, &frontNode, &endNode);
    printf("Top of queue = %d\n", top(&frontNode));
    pop(&frontNode, &endNode);
    printf("Top of queue = %d\n", top(&frontNode));
    pop(&frontNode, &endNode);
    printf("Top of queue = %d\n", top(&frontNode));
    return 0;
}
