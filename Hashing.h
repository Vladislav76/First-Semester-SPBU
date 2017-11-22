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
int* CreateHashTable (int);
void Clearing (int*, int);
int HashFunction (char*, int);
struct element* NewElement(char*, int);
void InsertElement(int*, int, char*, int);
void IterateFunction(int*, int, funcPtr);
#endif
