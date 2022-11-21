#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// declaring a struct called Node for the dynamic allocation of the stack
struct Node {
double data;
struct Node *next;
};

/*****************
* STACK FUNCTIONS
******************/

// function to show the contents of the stack
void Display(struct Node **top) {
struct Node *p;
if (top == NULL) {
printf("Stack is Empty\n\n");
return;
}
printf("[ ");
p = *top;
while (p != NULL) {
printf("%lf ", p->data);
p = p->next;
}
free(p);
printf("]\n");
return;
}

// function to push data into a stack
void push(struct Node **top, double x) {
struct Node *t = (struct Node *)malloc(sizeof(struct Node));
t->data = x;
t->next = *top;
*top = t;
Display(top);
return;
}

// function to pop data from a stack
double pop(struct Node **top) {
double x = -1;
if (*top == NULL)
printf("Stack is Empty\n\n");
else {
struct Node *t;
t = *top;
*top = (*top)->next;
x = t->data;
}
Display(top);
return x;
}

/*****************
* POSTFIX EVALUATION FUNCTIONS
******************/

// function to determine if a symbol is an operand
int isDigit(char c) { return (c >= '0' && c <= '9'); }

// function to determine if a symbol is an operator
int isOperator(char ch) {
return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^');
}
// function to evaluate the postfix expression
void PostEval(struct Node **sp, char *postfix) {
int i = 0, decimal = 0, neg = 0;
// i -> string index ; decimal -> decimal flag ; neg -> negative flag

double j = 0, d1 = 0, d2 = 0, m = 0.1;
// j -> accumulator ; m -> scaling factor for decimal ; d1,d2 can be optimised

char ch; // store the character to reduce the number of accesses to array

while ((ch = postfix[i++]) != '$') {
if (ch == '-' && isDigit(postfix[i])) {
neg = 1; // to detect a negative number and set the "neg" flag
continue;
}
if (ch == '.') {
decimal = 1; // to detect a decimal and set the "decimal" flag
continue;
}
if (isDigit(ch)) {
if (decimal) {
j += (double)(ch - '0') * m;
m = m * 0.1;
} else {
j = j * 10 + (ch - '0');
}
if (postfix[i] == ',') {
j = (neg) ? -j : j; // set the sign of the number in the accumulator
push(sp, j); // push the content of the accumulator
j = 0; // resetting the accumulator,
m = 0.1; // scaling
 neg = 0; // and
 decimal = 0; // the flags
 }
 } else if (isOperator(ch)) {
 d1 = pop(sp);
 d2 = pop(sp);
 switch (ch) {
 case '+':
 push(sp, d2 + d1);
 break;
 case '-':
 push(sp, d2 - d1);
 break;
 case '*':
 push(sp, d2 * d1);
 break;
 case '/':
 if (d1)
 push(sp, d2 / d1);
 else {
 printf("Zero Division Error");
 exit(1);
 }
 break;
 case '^':
 push(sp, pow(d2, d1));
 break;
 }
 }
 }
 printf("\nResult of postfix = %lf", (*sp)->data);
 return;
 }
 int main(int argc, char *argv[]) {
 struct Node *sp = NULL;
 // declared a stack pointer "sp" and initialised to NULL
 // printf("Enter a balanced postfix expression to calculate: ");
 char ch, s[100];
 int i = 0;
 do {
 // ch = getchar();
 s[i] = argv[1][i];
 } while (argv[1][i++] != '$');
 s[i] = '\0'; // getting user input for the postfix expression
 /* we assume that the input is a valid postfix expression
 the program just exits without thrwoing any error if
 only '£' is entered.*/
 // printf("\n%s\n",s);
 PostEval(&sp, s);
 free(sp);
 return 0;
 }
