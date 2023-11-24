#include <stdio.h>
#include <limits.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
  
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
  
    for (int i = 0; i < n; i++) {
        int worstFitIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstFitIdx == -1 || blockSize[j] > blockSize[worstFitIdx])
                    worstFitIdx = j;
            }
        }
  
        if (worstFitIdx != -1) {
            allocation[i] = worstFitIdx;
            blockSize[worstFitIdx] -= processSize[i];
        }
    }
  
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d \t\t%d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    int blockSize[m];
    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n];
    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    worstFit(blockSize, m, processSize, n);
    return 0;
}
