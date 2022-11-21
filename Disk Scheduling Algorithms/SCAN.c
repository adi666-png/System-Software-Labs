#include <stdio.h>
#include <limits.h>

int last=0;
int first=0;
int loc,count, i, j, temp,seek, head_indice, least_indice, Cylinder;
int seek1=0;

void merge(int arr[], int l, int m, int r)
 {
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 int L[n1], R[n2];
 for (i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];

 i = 0; j = 0; k = l;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) { arr[k] = L[i++]; }
 else { arr[k] = R[j++]; }k++;
 }
 while (i < n1) { arr[k++] = L[i++]; }
 while (j < n2) { arr[k++] = R[j++]; }
 }

 void mergeSort(int arr[], int l, int r)
 {
 if (l < r) {
 int m = l + (r - l) / 2;
 mergeSort(arr, l, m);
 mergeSort(arr, m + 1, r);
 merge(arr, l, m, r);
 }
 }
 int SCAN(int arr[], int n, int head){
 int arr1[8];
 arr1[0]=0;
 int distance=0;
 arr1[6]=head;
 arr1[7]=199;
 for(i=0; i<n; i++){
 arr1[i+1]=arr[i];
 }
 mergeSort(arr1,0,8);
 for(int i=0; i<8; i++){
 if(arr1[i]==head){
 head_indice=i;
 }
 if(arr[i]==0){
 least_indice=i;
 }
 }
 //Going outside the track
 for(i=head_indice+1; i<8; i++){
 distance=arr1[i]-head;
 seek=seek+distance;
 head=arr1[i];
 printf("%d ",head);
 }
 //Going inside the track
 for( i=head_indice-1; i>0; i--){
 distance=head-arr1[i];
 seek=seek+distance;
 head=arr1[i];
 printf("%d ",head);
 }

 /*Calculating the distance by measuring the distance between last track present
 and head, last track present and minimum request present.
 Summing them up to find the final distance. */

 seek1=(arr1[7]-arr1[1])+(arr1[7]-arr1[head_indice]);
 return seek1;
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
 Cylinder=SCAN(Request, n, ini); //Initially head is at ini
 printf("\n Total no of seeks %d",Cylinder);
 return 0;
 }
