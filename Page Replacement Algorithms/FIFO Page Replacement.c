include <stdio.h>
int main()
{ printf("\n First In First Out Simulation");
int reference_string[12]={5,1,2,3,5,1,4,5,1,2,3,4};
int page_faults = 0;
int m, n, s, pages=12, frames=4;

int temp[frames];
for(m = 0; m < frames; m++)
 {
 temp[m] = -1;
 }
 for(m = 0; m < pages; m++)
 {
 s = 0;
 for(n = 0; n < frames; n++)
 {
 if(reference_string[m] == temp[n])
 {
 s++;
 page_faults--;
 }
 }
 page_faults++;
 if((page_faults <= frames) && (s == 0))
 { temp[m] = reference_string[m]; }
 else if(s == 0)
 {
 temp[(page_faults - 1) % frames] = reference_string[m];
 }
 printf("\n");
 for(n = 0; n < frames; n++)
 {
 printf("\t\t%d", temp[n]);
 }
 }
 printf("\n Total Number of Page Faults %d",page_faults);
 printf("\n Total number of Page Hits %d",pages-page_faults);
 return 0;
 }
