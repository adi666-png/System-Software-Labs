include <stdio.h>
char input[100];

int i, l;
int E();
int EP();
int TP();
int T();
int F();

int E()
{
printf("%s(",__func__);
if (T())
{
if (EP())
{printf(")");return 1;}
else
{printf(")");return 0;}
}
else
{printf(")");return 0;}
}

int EP()
{
printf("%s(",__func__);
if (input[i] == '+')
{
i++; printf(" + ");
if (T())
{
if (EP())
{printf(")");return 1;}
else
{printf(")");return 0;}
}
else
{printf(")");return 0;}
}
else
{printf(")");return 1;}
}

int T()
{
printf("%s(",__func__);
if (F())
{
if (TP())
{printf(")");return 1;}
else
{printf(")");return 0;}
}
else
{printf(")");return 0;}
}

int TP()
{
printf("%s(",__func__);
if (input[i] == '*')
{
i++; printf(" * ");
if (F())
{
if (TP())
{printf(")");return 1;}
else
{printf(")");return 0;}
}
else
{printf(")");return 0;}
}
else
{printf(")");return 1;}
}

int F()
{
printf("%s(",__func__);
if (input[i] == '(')
{
i++;
if (E())
{
if (input[i] == ')')
{
i++; printf(")"); return 1;
}
else
{printf(")");return 0;}
}
else
{printf(")");return 0;}
}
else if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
{
i++;
 {printf(")");return 1;}
 }
 else
 {printf(")");return 0;}
 }

 void main()
 {
 printf("Recursive descent parsing for the following grammar\n");
 printf("\nE->TE'\nE'->+TE'/$\nT->FT'\nT'->*FT'/$\nF->(E)/ID\n");
 printf("\nEnter the string to be checked:");
 gets(input);
 // sprintf(input,"%s","a+b*c");
 printf("%s : ",input);
 if (E())
 {
 if (input[i + 1] == '\0')
 printf("\nString is accepted");
 else
 printf("\nString is not accepted");
 }
 else
 printf("\nString not accepted");
 }