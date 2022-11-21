#include <stdio.h>

int seek=0; int i=0; int Cylinder=0;

int FCFS(int request[], int n, int head){
int distance=0; int current_track;

 for(i=0; i<n; i++){
 current_track=request[i];
 //Setting current track to the request to be serviced
 if(current_track-head >0){
 distance=current_track-head;
 //Current difference between head and current request
 }
 else{
 distance=head-current_track;
 }
 seek=seek+distance;
 //Summing the distance covered by read-write head
 head=current_track; //Accessed track = New head
 }

 //Seek records will be in the same order as given request
 for(i=0; i<n; i++){
 printf(" %d ",request[i]);
 }

 return seek;
 }

 int main() {
 int n,ini;
 printf("Enter the initial position: ");
 scanf("%d",&ini);
 printf("Enter the size of request array: ");
 scanf("%d",&n);
 int Request[n]; //Request Array
 printf("Enter the request array: ");
 for(int i=0;i<5;) scanf("%d",&Request[i++]);
 printf("The seek order is : ");
 Cylinder=FCFS(Request, n, ini); //Initially head is at ini
 printf("\n Total no of seeks %d",Cylinder);
 return 0;
 }