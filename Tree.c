#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 1000
#define MAX_LEN_BUFER 100
struct Node {
	int number;
	int request;
	struct Node *left;
	struct Node *right;
};
void LoadFile(char name[], int a[], int p[], int* n) {
	FILE* f;
	if ((f = fopen(name, "r")) != NULL) {
		int num = 0;
		char bufer[MAX_LEN_BUFER];
		while (!feof(f)) {
			if (fgets(bufer, MAX_LEN_BUFER, f) != NULL) {
				sscanf(bufer, "%d", &a[num]);
				int k = 0;
				while (bufer[k] != '-') {
					k++;
				}
				char* str = &bufer[k + 1];
				sscanf(str, "%d", &p[num]);
				num++;
				if (num == MAX) {
					break;
				}
			}
		}
		*n = num;
		fclose(f);
	}
	else {
		printf("File not found!\n");
	}
}
void QuickSorting(int* a, int* p, int n) {
    void Sort(int l, int r) {
        int i = l;
        int j = r;
        int k = (l + r) / 2;
        int x = a[k];
        do {
            while (a[i] < x) {
                i++;
            }
            while (a[j] > x) {
                j--;
            }
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
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
    Sort(0, n - 1);
}
void Exit() {
	printf("Error! Couldn't allocate memory.\n");
	exit(1);
}
int** CreateMatrix(int size) {
	int **matr = (int**) calloc(size, sizeof(int*));
	if (matr == NULL) {
		Exit();
	}
	matr[0] = (int*) calloc (size * size, sizeof(int));
	if (matr[0] == NULL) {
		Exit();
	}
	for(int i = 1; i < size; i++) {
		matr[i] = matr[0] + size * i;
	}
	return matr;
}
void PrintMatrix(int** matr, int size, char str[]) {
	printf("\n");
	for(int i = 0; i < 3 * size + 1; i++) {
		printf("*");
	}
	printf("%s", str);
	for(int i = 0; i < 3 * size; i++) {
		printf("*");
	}
	printf("\n");
	for(int i = 0; i <= size; i++) {
		for(int j = 0; j <= size; j++) {
			printf("%5d ", matr[i][j]);
		}
		printf("\n");
	}
}
int Min(int i, int j, int** r, int** c) {
	int sum = -1;
	int k;
	int left = r[i][j - 1];
	int right = r[i + 1][j];
	if (left <= i) {
		left = i + 1;
	}
	for(int l = left; l <= right; l++) {
		int currentSum = c[i][l - 1] + c[l][j];
		if (sum == -1 || currentSum < sum) {
			sum = currentSum;
			k = l;
		}
	}
	r[i][j] = k;
	return sum;
}
void SeekOptimalBinTree(int** c, int** w, int** r, int* p, int n) {
	for(int i = 0; i < n; i++) {
		w[i][i + 1] = p[i];
		c[i][i + 1] = p[i];
		r[i][i + 1] = i + 1;
	}
	for(int d = 2; d <= n; d++) {
		for(int j = d; j <= n; j++) {
			int i = j - d;
			w[i][j] = w[i][j - 1] + p[j - 1];
			c[i][j] = w[i][j] + Min(i, j, r, c);
		}
	}	
}
struct Node* CreateTree(int i, int j, int** r, int* a, int* p) {
	if (i != j && r[i][j] != 0) {
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if (node == NULL) {
			Exit();
		}
		node -> number = a[r[i][j] - 1];
		node -> request = p[r[i][j] - 1];
		node -> left = CreateTree(i, r[i][j] - 1, r, a, p);
		node -> right = CreateTree(r[i][j], j, r, a, p);
		return node;	
	}
	else {
		return NULL;
	}
}
void PrintTree(struct Node* node) {
	if (node != NULL) {
		printf("%d(", node -> number);
		PrintTree(node -> left);
		printf(", ");
		PrintTree(node -> right);
		printf(")");
	}
	else {
		printf("x");
	}	
}
void SaveTree(struct Node* node, char name[]) {
	FILE* f = fopen(name, "w");
	int i = 1;
	void Rec(struct Node* current) {
		if (current != NULL) {
			if (current -> left) {
				fprintf(f, "%d->%d\n", current -> number, current -> left -> number);
			}
			else {
				fprintf(f, "%d->null%d\n", current -> number, i++);
				fprintf(f, "null%d [shape=\"point\"]\n", i - 1);
			}
			if (current -> right) {
				fprintf(f, "%d->%d\n", current -> number, current -> right -> number);
			}
			else {
				fprintf(f, "%d->null%d\n", current -> number, i++);
				fprintf(f, "null%d [shape=\"point\"]\n", i - 1);
			}
			Rec(current -> left);
			Rec(current -> right);
		}
	}
	if (f != NULL) {
		fprintf(f, "digraph G {\n");
		Rec(node);
		fprintf(f, "}");
		fclose(f);
	}
	else {
		printf("File isn't created!\n");
	}
}
int main() {
	int a[MAX];
	int p[MAX];
	int n;
	LoadFile("input.txt", a, p, &n);
	QuickSorting(a, p, n);
	int size = MAX + 1;
	int** c = CreateMatrix(size);
	int** w = CreateMatrix(size);
	int** r = CreateMatrix(size);
	SeekOptimalBinTree(c, w, r, p, n);
	struct Node* root = CreateTree(0, n, r, a, p);
	for(int i = 0; i < n; i++) {
		printf("%3d ", a[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++) {
		printf("%3d ", p[i]);
	}
	PrintMatrix(c, n, "Cost");
	PrintMatrix(w, n, "Weight");
	PrintMatrix(r, n, "Root");	
	PrintTree(root);
	SaveTree(root, "output.txt");
	return 0;
}