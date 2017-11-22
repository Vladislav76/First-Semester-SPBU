#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashing.h"
int* CreateHashTable (int size) {
    int* h = (int*) calloc(size, sizeof(int*));
    return h;
}
void Clearing (int* hashTable, int size) {
    for (int i = 0; i < size; i++) {
        free(hashTable[i]);
    }
}
int HashFunction (char* key, int size) {
    unsigned int simpleValue = 7121;
    unsigned int sum = 0;
    int i = 0;
    while (key[i] != '\0') {
        sum = (sum + key[i] * simpleValue) % size;
        simpleValue *= simpleValue;
        i++;
    }
    return sum;
}
struct element* NewElement(char* key, int value) {
    struct element* elem = (struct element*) malloc(sizeof(struct element));
    elem -> key = &(string[length]);
    int i = 0;
    while (key[i] != '\0') {
        string[length] = key[i];
        length++;
        i++;
    }
    string[length++] = '\0';
    elem -> num = value;
    elem -> next = NULL;
    return elem;
}
void InsertElement (int* hashTable, int size, char* key, int value) {
    int hash = HashFunction(key, size);
    struct element* current = hashTable[hash];
    if (current) {
        while (current -> next && strcmp(current -> key, key)) {
            current = current->next;
        }
        if (!strcmp(current -> key, key)) {
            current -> num++;
        }
        else {
            current -> next = NewElement(key, value);
        }
    }
    else {
        hashTable[hash] = NewElement(key, value);
    }
}
void IterateFunction(int* hashTable, int size, funcPtr f) {
    struct element* current;
    for(int i = 0; i < size; i++) {
        current = hashTable[i];
        while (current) {
            f(current -> key, current -> num);
            current = current -> next;
        }
    }
}
