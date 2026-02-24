#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int at;     // Arrival Time
    int bt;     // Burst Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
    bool done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].done = false;
    }

    int completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;

    while(completed < n) {
        int idx = -1;
        int max_bt = -1;

        // Find longest job among arrived processes
        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].done == false) {
                if(p[i].bt > max_bt) {
                    max_bt = p[i].bt;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            // Calculate waiting time
            p[idx].wt = time - p[idx].at;
            if(p[idx].wt < 0)
                p[idx].wt = 0;

            // Execute process
            time += p[idx].bt;

            // Calculate turnaround time
            p[idx].tat = p[idx].wt + p[idx].bt;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;

            p[idx].done = true;
            completed++;
        } else {
            time++; // CPU idle
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
