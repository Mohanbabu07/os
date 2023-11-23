import java.util.Scanner;
class Main {
static int[][] allocation;
static int[][] max;
static int[][] need;
static int[] available;
static int processes;
static int resources;
static void requestResources(int process, int[] request) {
for (int i = 0; i < resources; i++) {
if (request[i] > need[process][i] || request[i] > available[i]) {
System.out.println("Deadlock occurs.");
return;
}
}
for (int i = 0; i < resources; i++) {
available[i] -= request[i];
allocation[process][i] += request[i];
need[process][i] -= request[i];
}
if (isSafeState()) {
System.out.println("Resource request granted.");
} else {
for (int i = 0; i < resources; i++) {
available[i] += request[i];
allocation[process][i] -= request[i];
need[process][i] += request[i];
}
System.out.println("Resource request denied.");
}
}
static boolean isSafeState() {
int[] work = new int[resources];
int[] finish = new int[processes];
for (int i = 0; i < resources; i++) {
work[i] = available[i];
}
for (int i = 0; i < processes; i++) {
finish[i] = 0;
}
for (int i = 0; i < processes; i++) {
if (finish[i] == 0) {
boolean canAllocate = true;
for (int j = 0; j < resources; j++) {
if (need[i][j] > work[j]) {
canAllocate = false;
break;
}
}
if (canAllocate) {
finish[i] = 1;
for (int j = 0; j < resources; j++) {
work[j] += allocation[i][j];
}
i = -1; // Start from the beginning
}
}
}
for (int i = 0; i < processes; i++) {
if (finish[i] == 0) {
return false;
}
}
return true;
}
static void printState() {
System.out.println("\nCurrent State:");
System.out.println("Processes: " + processes);
System.out.println("Resources: " + resources);
System.out.println("Allocation:");
printMatrix(allocation);
System.out.println("Max:");
printMatrix(max);
System.out.println("Need:");
printMatrix(need);
System.out.println("Available:");
printArray(available);
}
static void printMatrix(int[][] matrix) {
for (int i = 0; i < processes; i++) {
for (int j = 0; j < resources; j++) {
System.out.print(matrix[i][j] + " ");
}
System.out.println();
}
}
static void printArray(int[] array) {
for (int i = 0; i < resources; i++) {
System.out.print(array[i] + " ");
}
System.out.println();
} public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the number of processes: ");
processes = scanner.nextInt();
System.out.print("Enter the number of resources: ");
resources = scanner.nextInt();
allocation = new int[processes][resources];
max = new int[processes][resources];
need = new int[processes][resources];
available = new int[resources];
System.out.println("Enter allocation matrix:");
for (int i = 0; i < processes; i++) {
for (int j = 0; j < resources; j++) {
allocation[i][j] = scanner.nextInt();
}
}
System.out.println("Enter max matrix:");
for (int i = 0; i < processes; i++) {
for (int j = 0; j < resources; j++) {
max[i][j] = scanner.nextInt();
} System.out.print("Enter available resources: ");
for (int i = 0; i < resources; i++) {
available[i] = scanner.nextInt();
}
for (int i = 0; i < processes; i++) {
for (int j = 0; j < resources; j++) {
need[i][j] = max[i][j] - allocation[i][j];
}
} while (true) {
System.out.println("\nMenu:");
System.out.println("1. Check for Safe Sequence");
System.out.println("2. Request Resources");
System.out.println("3. Exit");
int choice = scanner.nextInt();
switch (choice) {
case 1:
if (isSafeState()) {
System.out.println("System is in a safe state.");
System.out.print("Safe sequence: ");
for (int i = 0; i < processes; i++) {
if (i > 0) System.out.print(" -> ");
System.out.print(i);
}
System.out.println();
} else {
System.out.println("System is not in a safe state.");
}break;
case 2:
System.out.print("Enter process making the request: ");
int process = scanner.nextInt();
int[] request = new int[resources];
System.out.print("Enter resource request: ");
for (int i = 0; i < resources; i++) {
request[i] = scanner.nextInt();
}
requestResources(process, request);
break;
case 3:
scanner.close();
return;
default:
System.out.println("Invalid choice. Please try again.");
}
}
}
}