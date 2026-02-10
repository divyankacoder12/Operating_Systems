#include<stdio.h>
#define MAX_PROCESSES 10
void findWaitingTime(int process[],int n,int bt[],int wt[]){
int remaining_bt[MAX_PROCESSES];
for(int i = 0; i < n; i++){
  remaining_bt[i] = bt[i];
}
int current_time = 0;
while(1){
  int min_bt = 9999;
  int shortest = -1;
  int done = 1;
  for(int i = 0; i < n; i++){
  if (remaining_bt[i]>0 && remaining_bt[i]<min_bt){
   min_bt = remaining_bt[i];
   shortest=i;
   done = 0;
  }
}
if(done){
 break;
}
wt[shortest] = current_time;
current_time++;
remaining_bt[shortest]--;
}
}
void findTurnaroundTime(int processes[],int n, int bt[],int wt[],int tat[]){
for(int i = 0; i < 0; i++){
tat[i] = bt[i] + wt[i];
}
}
void calculateAverageTimes(int processes[],int n, int bt[]){
int wt[MAX_PROCESSES],tat[MAX_PROCESSES];
int total_wt = 0, total_tat = 0;

findWaitingTime(processes,n,bt,wt);
findTurnaroundTime(processes,n,bt,wt,tat);

for(int i=0; i < n; i++){
 total_wt+=wt[i];
 total_tat+=tat[i];
}

printf("Process\tBurst Time\tWaiting Time\tTurnaound Time\n");
for(int i = 0; i < n;i++){
  printf("%d\t\t%d\t\t%d\t\t%d\n",processes[i],bt[i],wt[i],tat[i]);
}
printf("\nAverage Waiting Time: %.2f\n",(float)total_wt / n);
printf("\nAverage Turnaround Time: %.2f\n",(float)total_tat / n);
}
int main(){
int processes[] = {1,2,3,4};
int burst_time[] = {6,8,7,3};
int n = sizeof(processes)/sizeof(processes[0]);
calculateAverageTimes(processes,n,burst_time);
return 0;
} 

