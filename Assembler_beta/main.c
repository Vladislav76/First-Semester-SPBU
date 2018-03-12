#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

#define RUN 1
#define EXIT 2

int main() {
    int work = 1;
    while (work) {
        printf("\n_ _ _ _ _ _ _ Beta Assembler 1.0 _ _ _ _ _ _ _ \n");
        printf("Choose that you need to do: \n");
        printf("1. Run the program. \n");
        printf("2. Exit. \n");
        char string[255];
        scanf("%s", string);
        long choice = strtol(string, NULL, 10);
        if (choice == RUN) {
            printf("Enter name of the program: \n");
            scanf("%s", string);
            struct Code* myCode = newCode();
            if (loadProgram(string, myCode)) {
                run(myCode);
                printCode(myCode);
            }
            deleteCode(myCode);
        }
        else if (choice == EXIT) {
            work = !work;
        }




    }


    return 0;
}