#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 32768
#define COUNTING 1
#define QUICK 2 
#define BUBBLE 3
typedef void (*funcptr) (int*, int);
void CountingSorting(int *m, int size) {
    int *TempArray = calloc(MAX_VALUE, sizeof(int));
    for (int i = 0; i < size; i++) {
        TempArray[m[i]]++;
    }
    int num = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < TempArray[i]; j++) {
            m[num] = i;
            num++;
        }
    }
}
void BubbleSorting(int *m, int size) {
    for (int k = 0; k < size; k++) {
        for (int i = size - 1; i > k; i--) {
            if (m[i - 1] > m[i]) {
                int temp = m[i - 1];
                m[i - 1] = m[i];
                m[i] = temp;
            }
        }
    }
}
void QuickSorting(int *m, int size) {
    void Sort(int l, int r) {
        int i = l;
        int j = r;
        int k = (l + r) / 2;
        int x = m[k];
        do {
            while (m[i] < x) {
                i++;
            }
            while (m[j] > x) {
                j--;
            }
            if (i <= j) {
                int temp = m[i];
                m[i] = m[j];
                m[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        if (i < r) {
            Sort(i, r);
        }
        if (j > l) {
            Sort(l, j);
        }
    }
    Sort(0, size - 1);
}
void InputArray(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }
}
void PrintResult(int *m, int size, clock_t time) {
   /* for (int i = 0; i < size; i++) {
        printf("%d ", m[i]);
    }*/
    double sec = ((double)time) / CLOCKS_PER_SEC;
    int min = sec / 60;
    sec = sec - min * 60;
    printf("Время выполнения: %d минут, %.6f секунд(а) для %d чисел\n", min, sec, size);
}
void Execution(funcptr fptr) {
    int num[] = {5, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int n = 9;
    for (int k = 0; k < n; k++) {
        int *m = (int*) calloc(num[k], sizeof(int));
        if (m == NULL) {
            printf("Error! Сould not allocate memory.\n");
            exit(1);
        }
        InputArray(m, num[k]);
        clock_t startTime = clock();
        fptr(m, num[k]);
        clock_t finishTime = clock();
        PrintResult(m, num[k], finishTime - startTime);
        free(m);
    }
}
int main() {
    printf("Counting Sorting:\n");
    Execution(&CountingSorting);
    printf("Quick Sorting:\n");
    Execution(&QuickSorting);
    printf("Bubble Sorting:\n");
    Execution(&BubbleSorting);
    return 0;
}