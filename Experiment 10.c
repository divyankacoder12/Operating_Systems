#include<stdio.h>
int main() {
int n, i;
printf("Enter number of processes: ");
scanf("%d",&n);
int alloc[n],max[n],need[n];
printf("Enter allocation:\n");
for(i=0;i<n;i++) {
scanf("%d",&alloc[i]);
}
printf("Enter max:\n");
for(i=0;i<n;i++) {
scanf("%d",&max[i]);
}
int avail;
printf("Enter available:");
scanf("%d",&avail);
for(i=0;i<n;i++) {
need[i] = max[i]-alloc[i];
}
int finish[n], seq[n];
for(i=0;i<n;i++) {
finish[i]=0;
}
int count = 0;
while(count<n) {
for(i=0;i<n;i++){
if(finish[i]==0 && need[i] <= avail) {
avail = avail + alloc[i];
seq[count]=i;
count++;
finish[i] = 1;
}
}
}
printf("Sequence :");
for(i=0;i<n;i++) {
printf("P%d ",seq[i]);
}
return 0;
}
