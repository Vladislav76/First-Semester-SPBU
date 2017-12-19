#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Hashing.h"
#define MAX_LEN 10000
#define MAX_LEN_WORD 100
struct Statistics {
    int allWords;
    int diffWords;
    int maxLength;
    int minLength;
    char* mostPopularWord;
    int numMostPopularWord;
    int numChains;
    int maxChain;
    int middleLenChain;
    double times;
    char* maxWord;
    char* minWord;
} state;
void PrintElement(char* key, int value) {
    printf("%s:%d\n", key, value);
}
void CountingSum(char* key, int value) {
    state.allWords += value;
}
void CountingDiff(char* key, int value) {
    state.diffWords++;
}
void SeekLongestWord(char* key, int value) {
    int len = strlen(key);
    if (len > state.maxLength) {
        state.maxLength = len;
        state.maxWord = key;
    }
    else if (len < state.minLength) {
        state.minLength = len;
        state.minWord = key;
    }
}
void SeekMostPopularWord(char *key, int value) {
    if (value > state.numMostPopularWord) {
        state.numMostPopularWord = value;
        state.mostPopularWord = key;
    }
}
void CountingNumOfChains(struct element ** hashTable, int size) {
    struct element* current;
    for(int i = 0; i < size; i++) {
        if (hashTable[i]) {
            state.numChains++;
        }
    }
}
void CountingMaxChain(struct element ** hashTable, int size) {
    struct element* current;
    for(int i = 0; i < size; i++) {
        current = hashTable[i];
        int k = 0;
        while (current) {
            k++;
            current = current -> next;
        }
        if (k > state.maxChain) {
            state.maxChain = k;
        }
    }
}
/*void PrintTable (int* hashTable, int size, FILE* output) {
    for (int i = 0; i < size; i++) {
        struct element* temp = hashTable[i];
        if (temp) {
            fprintf(output, "%d. ", i);
            while (temp) {
                fprintf(output, "\"%s\": %d | ", temp->key, temp->num);
                temp = temp->next;
            }
            fprintf(output, "\n");
        }
    }
}*/
void AnalyzeOfStatistics(struct element ** hashTable, int size) {
    state.maxWord = NULL;
    state.minLength = 999;
    IterateFunction(hashTable, size, &CountingSum);
    IterateFunction(hashTable, size, &CountingDiff);
    IterateFunction(hashTable, size, &SeekLongestWord);
    IterateFunction(hashTable, size, &SeekMostPopularWord);
    IterateFunction(hashTable, size, &PrintElement);
    CountingNumOfChains(hashTable, size);
    CountingMaxChain(hashTable, size);
    state.middleLenChain = state.diffWords / state.numChains;
    printf("--------------------------------------------------------\n");
    printf("Size of table: %d\n", size);
    printf("Number of keys: %d\n", state.diffWords);
    printf("All words: %d\n", state.allWords);
    printf("Number of chains: %d\n", state.numChains);
    printf("Max length of chain: %d\n", state.maxChain);
    printf("Middle length of chain: %d\n", state.middleLenChain);
    printf("Most popular word: %s\n", state.mostPopularWord);
    printf("Was used: %d\n", state.numMostPopularWord);
    printf("Longest word: %s\n", state.maxWord);
    printf("Shortest word: %s\n", state.minWord);
    printf("Time of working: %lf\n", state.times);
}
void Execute(FILE* input, int sizeTable) {
    double startTime = (double) clock();
    string = (char*) calloc(1000000, sizeof(char));
    if (string == NULL) {
        printf("Error. Couldn't allocate memory!\n");
        exit(1);
    }
    int size = sizeTable;
    struct element ** hashTable = CreateHashTable(size);
    char bufer[MAX_LEN];
    char word[MAX_LEN_WORD];
    while (!feof(input)) {
        if (fgets(bufer, MAX_LEN, input) != NULL) {
            int i = 0;
            while (bufer[i] != '\n') {
                int len = 0;
                while (bufer[i] >= 'A' && bufer[i] <= 'Z' || bufer[i] >= 'a' && bufer[i] <= 'z') {
                    word[len] = bufer[i];
                    len++;
                    i++;
                }
                if (len > 0) {
                    word[len] = '\0';
                    InsertElement(hashTable, size, word, 1);
                }
                else {
                    i++;
                }
            }
        }
    }
    double finishTime = (double) clock();
    state.times = (finishTime - startTime) / CLOCKS_PER_SEC;
    AnalyzeOfStatistics(hashTable, size);
    //PrintTable(hashTable, size, output);
    free(string);
    Clearing(hashTable, size);
}
int main() {
    FILE* input;
    char name[] = "War and Peace.txt";
    if ((input = fopen(name, "r")) != NULL) {
        Execute(input, 100000000);
        fclose(input);
    }
    else {
        printf("File not found!\n");
    }
    return 0;
}