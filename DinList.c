#include <stdio.h>
#include <stdlib.h>
#include "DinList.h"
struct Node* CreateNode(int value) {
    struct Node *newNode = calloc(1, sizeof(struct Node));
    newNode -> value = value;
    return newNode;
}
void CreateList(struct LinkedList *list) {
    if (list -> length <= 0) {
        printf("Enter number of elements in the list:\n");
        list -> length = 0;
        int n, x;
        scanf("%d", &n);
        if (n > 0) {
            printf("Enter %d values:\n", n);
            scanf("%d", &x);
            struct Node *curNode = CreateNode(x);
            list -> head = curNode;
            list -> length++;
            for (int i = 1; i < n; i++) {
                scanf("%d", &x);
                curNode->next = CreateNode(x);
                curNode = curNode -> next;
                list -> length++;
            }
            curNode -> next = NULL;
            printf("The list is created.\n");
        } else {
            printf("The list is empty.\n");
        }
    }
    else {
        printf("Error: The list isn't empty! First clean the current list.\n");
    }
}
void IntoBeginning(struct LinkedList *list, int value) {
    struct Node *newNode = CreateNode(value);
    newNode -> next = list -> head;
    list -> head = newNode;
    list -> length++;
}
void IntoEnding(struct LinkedList *list, int value) {
    struct Node *newNode = CreateNode(value);
    struct Node *curNode = list -> head;
    if (curNode) {
        while (curNode -> next) {
            curNode = curNode -> next;
        }
        curNode -> next = newNode;
    }
    else {
        list -> head = newNode;
    }
    newNode->next = NULL;
    list -> length++;
}
void IntoAfter(struct LinkedList *list, int value, int where) {
    struct Node *curNode = list -> head;
    if (curNode) {
        while (curNode && curNode -> value != where) {
            curNode = curNode -> next;
        }
        if (curNode) {
            struct Node *newNode = CreateNode(value);
            newNode -> next = curNode -> next;
            curNode -> next = newNode;
            list -> length++;
        }
        else {
            printf("Error: Element not found!\n");
        }
    }
    else {
        printf("Error: List is empty!\n");
    }
}
void DeleteByCondition(struct LinkedList *list, int value) {
    struct Node *curNode = list -> head;
    struct Node *preNode = list -> head;
    int num = 0;
    while (curNode) {
        if (curNode -> value == value) {
            if (curNode == list -> head) {
                list -> head = curNode -> next;
                free(curNode);
                curNode = list -> head;
                preNode = curNode;
            }
            else {
                preNode->next = curNode->next;
                free(curNode);
                curNode = preNode->next;
            }
            num++;
        }
        else {
            preNode = curNode;
            curNode = curNode -> next;
        }
    }
    if (num == 1) {
        printf("One element is deleted.\n");
    }
    else if (num > 0) {
        printf("%d elements are deleted.\n", num);
    }
    else {
        printf("Error: elements not found!\n");
    }
}
void PrintList(struct LinkedList *list) {
    struct Node *curNode = list -> head;
    if (curNode) {
        while (curNode) {
            printf("%d ", curNode -> value);
            curNode = curNode -> next;
        }
        printf("\n");
    }
    else {
        printf("Error: The list is empty! Printing isn't possible.\n");
    }
}
void ReverseList(struct LinkedList *list) {
    if (list -> length > 1) {
        struct Node *preNode = list -> head;
        struct Node *curNode = list -> head -> next;
        struct Node *sucNode = curNode -> next;
        preNode -> next = NULL;
        while (sucNode) {
            curNode -> next = preNode;
            preNode = curNode;
            curNode = sucNode;
            sucNode = sucNode -> next;
        }
        curNode -> next = preNode;
        list -> head = curNode;
    }
}
void CreateCycle(struct LinkedList *list) {
    if (list -> length > 0) {
        printf("Enter number of element for creating cycle (from 1 to %d).\n", list -> length);
        int i, n;
        scanf("%d", &n);
        if (n <= list -> length) {
            struct Node *curNode = list -> head;
            i = 1;
            while (i < n) {
                curNode = curNode -> next;
                i++;
            }
            struct Node *tmpNode = curNode;
            while (tmpNode -> next) {
                tmpNode = tmpNode -> next;
            }
            tmpNode -> next = curNode;
            printf("Cycle is created.\n");
        }
        else {
            printf("Error: There isn't such element!\n");
        }
    }
    else {
        printf("Error: The list is empty!\n");
    }
}
int Is_Cycle(struct LinkedList *list) {
    if (list -> length > 0) {
        struct Node *pNode1 = list -> head;
        struct Node *pNode2 = list -> head -> next;
        while (pNode1 && pNode2 && pNode2 -> next && pNode1 != pNode2) {
            pNode1 = pNode1 -> next;
            pNode2 = pNode2 -> next -> next;
        }
        if (pNode1 != pNode2) {
            printf("The list hasn't a cycle.\n");
            return 0;
        }
        else {
            printf("The list has a cycle.\n");
            return 1;
        }
    }
    else {
        printf("Error: The list is empty!\n");
        return 0;
    }
}
void Clearing(struct LinkedList *list) {
    struct Node *curNode = list -> head;
    while (curNode) {
        struct Node *tmpNode = curNode -> next;
        free(curNode);
        curNode = tmpNode;
    }
    list -> head = NULL;
    list -> length = 0;
    printf("The list is cleaned.\n");
}
int Is_Created (struct LinkedList *list) {
    if (list -> length < 0) {
        printf("Error: The list isn't created!\n");
    }
    return (list -> length >= 0);
}

