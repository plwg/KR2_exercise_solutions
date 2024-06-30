#define MAXOP 100
#define NUMBER '0'

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);
void print_stack(void);
