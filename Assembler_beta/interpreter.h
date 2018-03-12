#ifndef ASSEMBLER_BETA_INTERPRETER_H
#define ASSEMBLER_BETA_INTERPRETER_H

#endif

#define NUM_COMMANDS 9
#define LD 0
#define ST 1
#define LDC 2
#define ADD 3
#define SUB 4
#define CMP 5
#define JMP 6
#define BR 7
#define RET 8

void run(struct Code*);
int loadProgram(char*, struct Code*);