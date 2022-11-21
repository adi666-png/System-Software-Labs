#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
int ischar(char o){
return ( o == '/' || o == '*' || o == '+' || o == '-' || o =='(' || o == ')');
}
char stack[200];
int top = -1;
 char postStr[200];
 void push(char x)
 {
 stack[++top] = x;
 }

 char pop()
 {
 if (top == -1)
 return -1;
 else
 return stack[top--];
 }

 int priority(char x)
 {
 if (x == '(')
 return 0;
 if (x == '+' || x == '-')
 return 1;
 if (x == '*' || x == '/')
 return 2;
 return 0;
 }

 int main()
 {
 char *exp;
 char *e, x;
 int i = 0;
 // printf("Enter the expression : ");
 // scanf("%s",exp);
 // exp = "((-9.25+4)*5)/2";
 exp = "((((6-(-2+3.5))*(3+(8/2)))-2)+3)";
 e = exp;

 while (*e != '\0')
 {
 if (*e == '-' && isdigit(e[1]) && e[-1]!=')')
 {
 postStr[i++] = '-';
 e++; continue;
 }
 if (isalnum(*e) || *e == '.')
 {
 postStr[i++] = *e;
 if(ischar(e[1])) postStr[i++]=',';
 }

 else if (*e == '(')
 push(*e);
 else if (*e == ')')
 {
 while ((x = pop()) != '(')
 {

 postStr[i++] = x;
 postStr[i++] = ',';
 }
 }
 else
 {
 while (priority(stack[top]) >= priority(*e))
 {
 postStr[i++] = ',';
 postStr[i++] = pop();
 }
 push(*e);
 }
 e++;
 }

 while (top != -1)
 {
 postStr[i++] = ',';
 postStr[i++] = pop();

 }

 postStr[i++] = '$';
 printf("Original infix expression: %s \n",exp);
 printf("Obtained postfix expression: %s \n\n", postStr);
 execl(".\\p2res.exe","p2res.exe",postStr,0);
 return 0;
 }