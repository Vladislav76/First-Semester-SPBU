#ifndef DINLIST_H
#define DINLIST_H
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node *next;
};
struct LinkedList {
    int length;
    struct Node *head;
};
struct Node* CreateNode(int);
void CreateList(struct LinkedList*);
void IntoBeginning(struct LinkedList*, int);
void IntoEnding(struct LinkedList*, int);
void IntoAfter(struct LinkedList*, int, int);
void DeleteByCondition(struct LinkedList*, int);
void PrintList(struct LinkedList*);
void ReverseList(struct LinkedList*);
void CreateCycle(struct LinkedList*);
void Clearing(struct LinkedList*);
int Is_Cycle(struct LinkedList*);
int Is_Created (struct LinkedList*);
#endif
