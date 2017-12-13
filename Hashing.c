#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashing.h"
struct element ** CreateHashTable (int size) {
    struct element ** h = (struct element **) calloc(size, sizeof(struct element *));
    if (h == NULL) {
        printf("Error. Couldn't allocate memory!\n");
        exit(1);
    }
    return h;
}
void Clearing (struct element ** hashTable, int size) {
    for (int i = 0; i < size; i++) {
        struct element *current = hashTable[i];
        struct element *temp;
        while (current) {
            temp = current->next;
            free(current);
            current = temp;
        }
    }
    free(hashTable);
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
    if (elem == NULL) {
        printf("Error. Couldn't allocate memory!\n");
        exit(1);
    }
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
void InsertElement (struct element ** hashTable, int size, char* key, int value) {
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
void IterateFunction(struct element ** hashTable, int size, funcPtr f) {
    struct element* current;
    for(int i = 0; i < size; i++) {
        current = hashTable[i];
        while (current) {
            f(current -> key, current -> num);
            current = current -> next;
        }
    }
}
