#include <stdio.h>
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

 int seek1,count, i, j, temp,seek, head_indice, Cylinder;

 int CLOOK(int arr[], int n, int head){
 int arr1[6];
 int distance=0;
 for(i=0; i<n; i++){
 arr1[i]=arr[i];
 }
 arr1[5]=head;
 mergeSort(arr1,0,6);
 for(int i=0; i<6; i++){
 if(arr1[i]==head){
 head_indice=i;
 }
 }

 //Going inside the track
 for( i=head_indice-1; i>=0; i--){
 distance=head-arr1[i];
 seek=seek+distance;
 head=arr1[i];
 printf("%d ",head);
 }

 //Going outside the track
 for(i=5; i>head_indice;i--){
 distance=arr1[i]-head;
 seek=seek+distance;
 head=arr1[i];
 printf("%d ",head);
 }
 seek1=(arr1[5]-arr1[head_indice])+(arr1[5]-arr1[0])+(arr1[head_indice-1]-arr1[0]);
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
 Cylinder=CLOOK(Request, n, ini); //Initially head is at ini


 printf("\n Total no of seeks %d",Cylinder);
 return 0;
 }