#include <stdio.h>
#include <stdlib.h>
#include "DinList.h"
#define PRINT 1
#define CREATE 2
#define INBEGIN 3
#define INEND 4
#define INAFTER 5
#define DELETE 6
#define REVERSE 7
#define CREATECYCLE 8
#define ISCYCLE 9
#define CLEAR 10
#define EXIT 11
struct LinkedList list = {-1, NULL};
void Interface(void) {
    printf("------------------------------------------------------------\n");
    printf("%d. Print\n", PRINT);
    printf("%d. Create\n", CREATE);
    printf("%d. Insert in beginning\n", INBEGIN);
    printf("%d. Insert in ending\n", INEND);
    printf("%d. Insert after \n", INAFTER);
    printf("%d. Delete by condition\n", DELETE);
    printf("%d. Reverse\n", REVERSE);
    printf("%d. Create cycle\n", CREATECYCLE);
    printf("%d. Check on cycle\n", ISCYCLE);
    printf("%d. Clear\n", CLEAR);
    printf("%d. Exit\n", EXIT);
    printf("------------------------------------------------------------\n");
}
void AnalyzeKeys(int *key) {
    int temp, temp2;
    printf("Enter number of operation:\n");
    scanf("%d", key);
    switch (*key) {
        case PRINT:
            if (Is_Created(&list)) {
                PrintList(&list);
            }
            break;
        case CREATE:
            CreateList(&list);
            break;
        case INBEGIN:
            if (Is_Created(&list)) {
                printf("Enter value of new element:\n");
                scanf("%d", &temp);
                IntoBeginning(&list, temp);
            }
            break;
        case INEND:
            if (Is_Created(&list)) {
                printf("Enter value of new element:\n");
                scanf("%d", &temp);
                IntoEnding(&list, temp);
            }
            break;
        case INAFTER:
            if (Is_Created(&list)) {
                printf("Enter value of new element:\n");
                scanf("%d", &temp);
                printf("Enter value of element after which to insert new element:\n");
                scanf("%d", &temp2);
                IntoAfter(&list, temp, temp2);
            }
            break;
        case DELETE:
            if (Is_Created(&list)) {
                printf("Enter value for removing:\n");
                scanf("%d", &temp);
                DeleteByCondition(&list, temp);
            }
            break;
        case REVERSE:
            if (Is_Created(&list)) {
                ReverseList(&list);
            }
            break;
        case CREATECYCLE:
            if (Is_Created(&list)) {
                CreateCycle(&list);
            }
            break;
        case ISCYCLE:
            if (Is_Created(&list)) {
                Is_Cycle(&list);
            }
            break;
        case CLEAR:
            if (Is_Created(&list)) {
                Clearing(&list);
            }
            break;
    }
}
void Execute() {
    int key;
    while (1) {
        Interface();
        AnalyzeKeys(&key);
        if (key == EXIT) {
            break;
        }
    }
}
int main() {
    Execute();
    return 0;
}