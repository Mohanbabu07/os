#include <stdio.h>

struct Process
{
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int finish_time;
    int started;
    int priority;
    int response_time; // Added field for response time
};

void calculateResponseTime(struct Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].response_time = processes[i].start_time - processes[i].arrival_time;
    }
}

int fcfs(int n, struct Process processes[])
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].start_time = -1;
    }

    int total_time = 0;
    int process_completed = 0;

    printf("Gantt Chart:\n");

    while (process_completed < n)
    {
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= total_time)
            {
                flag = 1;
                printf("| P%d ", i + 1);
                if (processes[i].start_time == -1)
                {
                    processes[i].start_time = total_time; // - processes[i].burst_time;
                }
                total_time += processes[i].remaining_time;
                process_completed++;
                processes[i].remaining_time = 0;
                processes[i].finish_time = total_time;
            }
        }

        if (flag == 0)
        {
            printf("| Idle ");
            total_time++;
        }
    }

    printf("|\n");

    calculateResponseTime(processes, n); // Calculate response time

    float avg_turnaround = 0.0, avg_waiting = 0.0, avg_response = 0.0;

    for (int i = 0; i < n; i++)
    {
        int turnaround = processes[i].finish_time - processes[i].arrival_time;
        int waiting = turnaround - processes[i].burst_time;
        avg_turnaround += turnaround;
        avg_waiting += waiting;
        avg_response += processes[i].response_time;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    avg_response /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Response Time: %.2f\n", avg_response);

    return 0;
}

int sjf(int n, struct Process processes[])
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].start_time = -1;
    }

    int total_time = 0;
    int process_completed = 0;

    printf("Gantt Chart:\n");

    while (process_completed < n)
    {
        int flag = 0;
        int min_time = -1;
        int min_process = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= total_time && processes[i].remaining_time > 0)
            {
                if (min_time == -1 || processes[i].burst_time < min_time)
                {
                    min_time = processes[i].burst_time;
                    min_process = i;
                }
            }
        }

        if (min_process != -1)
        {
            flag = 1;
            printf("| P%d ", min_process + 1);
            if (processes[min_process].start_time == -1)
            {
                processes[min_process].start_time = total_time; // - processes[min_process].burst_time;
            }
            total_time += processes[min_process].remaining_time;
            process_completed++;
            processes[min_process].remaining_time = 0;
            processes[min_process].finish_time = total_time;
        }
        else
        {
            printf("| Idle ");
            total_time++;
        }
    }

    printf("|\n");

    calculateResponseTime(processes, n); // Calculate response time

    float avg_turnaround = 0.0, avg_waiting = 0.0, avg_response = 0.0;

    for (int i = 0; i < n; i++)
    {
        int turnaround = processes[i].finish_time - processes[i].arrival_time;
        int waiting = turnaround - processes[i].burst_time;
        avg_turnaround += turnaround;
        avg_waiting += waiting;
        avg_response += processes[i].response_time;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    avg_response /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Response Time: %.2f\n", avg_response);

    return 0;
}

int srtf(int n, struct Process processes[])
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].start_time = -1;
    }

    int total_time = 0;
    int process_completed = 0;

    printf("Gantt Chart:\n");

    while (process_completed < n)
    {
        int min_time = 999999;
        int min_process = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= total_time && processes[i].remaining_time > 0)
            {
                if (processes[i].remaining_time < min_time)
                {
                    min_time = processes[i].remaining_time;
                    min_process = i;
                }
            }
        }

        if (min_process != -1)
        {
            printf("| P%d ", min_process + 1);
            processes[min_process].remaining_time--;
            if (processes[min_process].start_time == -1)
            {
                processes[min_process].start_time = total_time; // - processes[min_process].burst_time;
            }
            total_time++;

            if (processes[min_process].remaining_time == 0)
            {
                processes[min_process].finish_time = total_time;
                process_completed++;
            }
        }
        else
        {
            printf("| Idle ");
            total_time++;
        }
    }

    printf("|\n");

    calculateResponseTime(processes, n);

    float avg_turnaround = 0.0, avg_waiting = 0.0, avg_response = 0.0;

    for (int i = 0; i < n; i++)
    {
        int turnaround = processes[i].finish_time - processes[i].arrival_time;
        int waiting = turnaround - processes[i].burst_time;
        avg_turnaround += turnaround;
        avg_waiting += waiting;
        avg_response += processes[i].response_time;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    avg_response /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Response Time: %.2f\n", avg_response);

    return 0;
}

int round_robin(int n, struct Process processes[])
{
    int quantum;
    printf("Enter the Quantum");
    scanf("%d",&quantum);
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].start_time = -1;
    }

    int total_time = 0;
    int process_completed = 0;

    printf("Gantt Chart:\n");

    while (process_completed < n)
    {
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= total_time)
            {
                flag = 1;

                if (processes[i].start_time == -1)
                {
                    processes[i].start_time = total_time; // - processes[i].burst_time;
                }

                if (processes[i].remaining_time > quantum)
                {
                    printf("| P%d ", i + 1);
                    total_time += quantum;
                    processes[i].remaining_time -= quantum;
                }
                else
                {
                    printf("| P%d ", i + 1);
                    total_time += processes[i].remaining_time;
                    process_completed++;
                    processes[i].remaining_time = 0;
                    processes[i].finish_time = total_time;
                }
            }
        }

        if (flag == 0)
        {
            printf("| Idle ");
            total_time++;
        }
    }

    printf("|\n");

    calculateResponseTime(processes, n); // Calculate response time

    float avg_turnaround = 0.0, avg_waiting = 0.0, avg_response = 0.0;

    for (int i = 0; i < n; i++)
    {
        int turnaround = processes[i].finish_time - processes[i].arrival_time;
        int waiting = turnaround - processes[i].burst_time;
        avg_turnaround += turnaround;
        avg_waiting += waiting;
        avg_response += processes[i].response_time;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    avg_response /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Response Time: %.2f\n", avg_response);

    return 0;
}

int non_pre_emptive_priority(int n, struct Process processes[])
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].start_time = -1;
    }

    int current_time = 0;
    int completed_processes = 0;

    printf("Gantt Chart:\n");
    printf("| ");

    while (completed_processes < n)
    {
        int highest_priority = 999999;
        int selected_process = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
            {
                if (processes[i].priority < highest_priority)
                {
                    highest_priority = processes[i].priority;
                    selected_process = i;
                }
            }
        }

        if (selected_process != -1)
        {
            if (processes[selected_process].start_time == -1)
            {
                processes[selected_process].start_time = current_time;
            }

            printf("P%d | ", selected_process + 1);
            current_time += processes[selected_process].burst_time;
            processes[selected_process].remaining_time = 0;
            processes[selected_process].finish_time = current_time;
            completed_processes++;
        }
        else
        {
            printf("Idle | ");
            current_time++;
        }
    }

    printf("\n");

    calculateResponseTime(processes, n); // Calculate response time

    float avg_turnaround = 0.0, avg_waiting = 0.0, avg_response = 0.0;

    for (int i = 0; i < n; i++)
    {
        int turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        avg_turnaround += turnaround_time;
        avg_waiting += waiting_time;
        avg_response += processes[i].response_time;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    avg_response /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Response Time: %.2f\n", avg_response);

    return 0;
}

int pre_emptive_priority(int n, struct Process processes[])
{
    
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].finish_time = 0;
        processes[i].response_time = -1;
        processes[i].start_time = -1;
    }

    int current_time = 0;
    int completed_processes = 0;

    printf("Gantt Chart:\n");

    while (completed_processes < n)
    {
        int highest_priority = 999999;
        int selected_process = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
            {
                if (processes[i].priority < highest_priority)
                {
                    highest_priority = processes[i].priority;
                    selected_process = i;
                }
            }
        }

        if (selected_process != -1)
        {
            if (processes[selected_process].start_time == -1)
            {
                processes[selected_process].start_time = current_time;
                processes[selected_process].response_time = current_time - processes[selected_process].arrival_time; // Calculate response time
            }

            printf("| P%d ", selected_process + 1);
            processes[selected_process].remaining_time--;
            current_time++;

            if (processes[selected_process].remaining_time == 0)
            {
                processes[selected_process].finish_time = current_time;
                completed_processes++;
            }
        }
        else
        {
            printf("| Idle ");
            current_time++;
        }
    }

    printf("|\n");

    float avg_turnaround = 0.0;
    float avg_waiting = 0.0;
    float avg_response = 0.0;

    for (int i = 0; i < n; i++)
    {
        int turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        avg_turnaround += turnaround_time;
        avg_waiting += waiting_time;
        avg_response += processes[i].response_time;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    avg_response /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Response Time: %.2f\n", avg_response);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);

        processes[i].remaining_time = processes[i].burst_time;
        processes[i].finish_time = 0;
        processes[i].response_time = -1;
        processes[i].start_time = -1;
    }

    // Call all scheduling algorithms and display their output
    printf("\nFCFS Scheduling:\n");
    fcfs(n, processes);

    printf("\nSJF Scheduling:\n");
    sjf(n, processes);

    printf("\nSRTF Scheduling:\n");
    srtf(n, processes);

    printf("\nRound Robin Scheduling:\n");
    round_robin(n, processes);

    printf("\nNon-Preemptive Priority Scheduling:\n");
    non_pre_emptive_priority(n, processes);

    printf("\nPreemptive Priority Scheduling:\n");
    pre_emptive_priority(n, processes);

    return 0;
}

