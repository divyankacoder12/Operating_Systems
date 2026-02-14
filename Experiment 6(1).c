#include <stdio.h>
#define MAX_PROCESSES 10

void findWaitingTime(int processes[], int n, int bt[], int wt[],
                     int ct[], int rt[]) {

    int remaining_bt[MAX_PROCESSES];
    int is_started[MAX_PROCESSES] = {0};

    for (int i = 0; i < n; i++)
        remaining_bt[i] = bt[i];

    int current_time = 0;

    while (1) {
        int min_bt = 9999;
        int shortest = -1;
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                shortest = i;
                done = 0;
            }
        }

        if (done)
            break;

        // Response Time (first time CPU allocation)
        if (is_started[shortest] == 0) {
            rt[shortest] = current_time;
            is_started[shortest] = 1;
        }

        remaining_bt[shortest]--;
        current_time++;

        // Completion Time
        if (remaining_bt[shortest] == 0) {
            ct[shortest] = current_time;
            wt[shortest] = ct[shortest] - bt[shortest];
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[],
                        int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void calculateAverageTimes(int processes[], int n, int bt[]) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int ct[MAX_PROCESSES], rt[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, ct, rt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Process\tBT\tCT\tWT\tTAT\tRT\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i], bt[i], ct[i], wt[i], tat[i], rt[i]);
    }

    printf("\nAverage Waiting Time: %.2f",
           (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n",
           (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {6, 8, 7, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, n, burst_time);
    return 0;
}
