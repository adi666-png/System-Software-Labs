#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
int pid;
int arrival_time;
int burst_time;
int start_time;
int finish_time;
int waiting_time;
int turnaround_time;
int remaining_time;
} Process;
int q = 0; // time slice
int flag = 0, rem = 0, time = 0, space=0; //
float avgwt = 0, avgtt = 0; // avg wait time and

void print_table(Process p[], int n);
void print_gantt_chart(Process p[], int n);

int main()
{
Process p[MAX];
int i, j, n;
int sum_waiting_time = 0, sum_turnaround_time = 0;
printf("Enter total number of process: ");
scanf("%d", &n);
rem = n;
printf("Enter arrival time and burst time for each process:\n");
for (i = 0; i < n; i++)
{
p[i].pid = i + 1;
printf("P[%d] : ", i + 1);
scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
p[i].waiting_time = p[i].turnaround_time = 0;
p[i].remaining_time = p[i].burst_time;
}
Process t; // temp var for sorting

// sorting according to the arrival_time
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
if (p[i].arrival_time < p[j].arrival_time)
{
t = p[i];
p[i] = p[j];
p[j] = t;
}
}
}
printf("Enter Time Slice OR Quantum Number : ");
scanf("%d", &q);
printf("\n***************************************\n");
printf(" Gantt Chart\n");
for (time = 0, i = 0; rem != 0;)
{
if (p[i].remaining_time <= q && p[i].remaining_time > 0)
{
time += p[i].remaining_time;
p[i].remaining_time = 0;
flag = 1;
printf("\033[%dC",space);
printf("-------+");
printf("\033[%dC",space);
printf("\033[1B\033[8D\n");
printf("\033[%dC",space);
printf(" P[%d] |", p[i].pid);
printf("\033[%dC",space);
printf("\033[B\033[8D\n");
printf("\033[%dC",space);
space += printf("-------")+2;
printf("%d\033[5A\n", time);
}
else if (p[i].remaining_time > 0)
{
p[i].remaining_time -= q;
time += q;
printf("\033[%dC",space);
printf("-------+");
printf("\033[%dC",space);
printf("\033[1B\033[8D\n");
printf("\033[%dC",space);
printf(" P[%d] |", p[i].pid);
printf("\033[%dC",space);
printf("\033[B\033[8D\n");
printf("\033[%dC",space);
space += printf("-------")+2;
printf("%d\033[5A\n", time);
}
if (p[i].remaining_time == 0 && flag == 1)
{
rem--;
p[i].turnaround_time = time - p[i].arrival_time;
p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
 avgtt += p[i].turnaround_time;
 avgwt += p[i].waiting_time;
 flag = 0;
 }
 if (i == n - 1)
 i = 0;
 else if (p[i + 1].arrival_time <= time)
 i++;
 else
 i = 0;
 }
 printf("\033[7B\n");

 //print table
 puts(""); // Empty line
 print_table(p, n);
 puts(""); // Empty Line
 printf("Total Waiting Time : %-2.0f\n", avgwt);
 printf("Average Waiting Time : %-2.2lf\n", (double)avgwt / (double) n);
 printf("Total Turnaround Time : %-2.0f\n", avgtt);
 printf("Average Turnaround Time : %-2.2lf\n", (double)avgtt / (double) n);

 return 0;
 }

 void print_table(Process p[], int n)
 {
 int i;

 puts("+-----+--------------+------------+--------------+-----------------+");
 puts("| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time |");
 puts("+-----+--------------+------------+--------------+-----------------+");

 for (i = 0; i < n; i++)
 {
 printf("| %2d | %2d | %2d | %2d | %2d |\n",
].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time,
 p[i].turnaround_time);
 puts("+-----+--------------+------------+--------------+-----------------+");
 }
 }
