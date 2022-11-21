#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum STATE { A,B,C,D,E };
enum STATE state = A;
enum STATE sA(int c);
enum STATE sB(int c);
enum STATE sC(int c);
enum STATE sD(int c);
enum STATE sE(int c);

int main()

{
char *s[5] = {"456abba5bb6abbaabbababababb",
"abc",
"4abb",
"bbahfy9830bbab",
"jbc/*a8503-bba"};
// enter the test string here
int cnt = 0;
char c;
int i = 0;
for (int itr = 0; itr < 5; itr++)
{
printf("\n Checking string \"%s\" :\t", s[itr]);
cnt = 0; i = 0;
state = A;
printf("\n intial state=%d; state transition sequence is ", state);
do
{
c = s[itr][i++];
if (state == A)
{
state = sA(c);
printf("%d", state);
}
else if (state == B)
{
state = sB(c);
printf("%d", state);
}

else if (state == C)
{
state = sC(c);
printf("%d", state);
}

else if (state == D)
{
state = sD(c);
printf("%d", state);
}

else if (state == E)
{
cnt++;
state = sE(c);
printf("%d", state);
}
} while ((char)c != '\0'); printf("\b");
if (cnt)
{
if (cnt == 1)
printf(";\t%d match found\n", cnt);
else if (cnt > 1)
printf(";\t%d matches found\n", cnt);
}
else
printf(";\tMatch not found\n");
}
exit(0);
}

enum STATE sA(int c)
{
enum STATE t;
if ((char)c == 'a')
t = B;
else if ((char)c == 'b')
t = C;
else
t = A;
return t;
}

enum STATE sB(int c)
{
enum STATE t;
if ((char)c == 'a')
t = B;
else if ((char)c == 'b')
t = D;
else
t = A;
return t;
}

 enum STATE sC(int c)
 {
 enum STATE t;
 if ((char)c == 'a')
 t = B;
 else if ((char)c == 'b')
 t = C;
 else
 t = A;
 return t;
 }

 enum STATE sD(int c)
 {
 enum STATE t;
 if ((char)c == 'a')
 t = B;
 else if ((char)c == 'b')
 t = E;
 else
 t = A;
 return t;
 }

 enum STATE sE(int c)
 {
 enum STATE t;
 if ((char)c == 'a')
 t = B;
 else if ((char)c == 'b')
 t = C;
 else
 t = A;
 return t;
 }
