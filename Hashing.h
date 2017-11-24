#ifndef HASHING_H
#define HASHING_H
char* string;
typedef void (*funcPtr)(char*, int);
int length;
struct element {
    char* key;
    int num;
    struct element* next;
};
struct element ** CreateHashTable (int);
void Clearing (struct element **, int);
int HashFunction (char*, int);
struct element* NewElement(char*, int);
void InsertElement(struct element **, int, char*, int);
void IterateFunction(struct element **, int, funcPtr);
#endif
