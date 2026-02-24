#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, j;
    struct Process p[20], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);

        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &p[i].priority);
    }
    
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting_time = 0;
    for(i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for(i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    printf("\nPID\tBurst\tPriority\tWaiting\tTurnaround\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].burst_time,
               p[i].priority,
               p[i].waiting_time,
               p[i].turnaround_time);

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
