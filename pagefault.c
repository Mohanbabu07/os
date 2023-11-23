#include <stdio.h>
int pageFaultsFIFO(int pages[], int n, int capacity) {
 int frame[capacity];
 for (int i = 0; i < capacity; i++) {
 frame[i] = -1;
 }
 int page_faults = 0;
 int currentIndex = 0; // Current index in the frame
 for (int i = 0; i < n; i++) {
 int page = pages[i];
 int isInFrame = 0;
 for (int j = 0; j < capacity; j++) {
 if (frame[j] == page) {
 isInFrame = 1;
 break;
 }
 }
 if (!isInFrame) {
 page_faults++;
 frame[currentIndex] = page;
 currentIndex = (currentIndex + 1) % capacity;
 } return page_faults;
}int pageFaultsLRU(int pages[], int n, int capacity) {
 int frame[capacity];
 for (int i = 0; i < capacity; i++) {
 frame[i] = -1;
 }
 int page_faults = 0;
 int lru[capacity];
 for (int i = 0; i < capacity; i++) {
 lru[i] = 0;
 }for (int i = 0; i < n; i++) {
 int page = pages[i];
 int isInFrame = 0;
 for (int j = 0; j < capacity; j++) {
 if (frame[j] == page) {
 isInFrame = 1;
 lru[j] = i;
 break;
 }
 }if (!isInFrame) {
 page_faults++;
 int lruIndex = 0;
 int minLRU = lru[0];
 for (int j = 1; j < capacity; j++) {
 if (lru[j] < minLRU) {
 minLRU = lru[j];
 lruIndex = j;
 }
 }
 frame[lruIndex] = page;
 lru[lruIndex] = i;
 }
 }return page_faults;
}int pageFaultsOptimal(int pages[], int n, int capacity) {
 int frame[capacity];
 for (int i = 0; i < capacity; i++) {
 frame[i] = -1;
 }
 int page_faults = 0;
 for (int i = 0; i < n; i++) {
 int page = pages[i];
 int isInFrame = 0;
 for (int j = 0; j < capacity; j++) {
 if (frame[j] == page) {
 isInFrame = 1;
 break;
 }
 }
 if (!isInFrame) {
 page_faults++;
 int farthestIndex = -1;
 int maxDistance = -1;
 for (int j = 0; j < capacity; j++) {
 int nextPageIndex = -1;
 for (int k = i + 1; k < n; k++) {
 if (pages[k] == frame[j]) {
 nextPageIndex = k;
 break;
 }
 }
 if (nextPageIndex == -1) {
 farthestIndex = j;
 break;
 } else if (nextPageIndex > maxDistance) {
 maxDistance = nextPageIndex;
 farthestIndex = j;
 }
 }
 frame[farthestIndex] = page;
 }
 }
 return page_faults;
}
int main() {
 int n, capacity;
 printf("Enter the number of pages: ");
 scanf("%d", &n);
 int pages[n];
 printf("Enter the page references: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &pages[i]);
 }
 printf("Enter the number of frames: ");
 scanf("%d", &capacity);
 printf("Page Faults for FIFO: %d\n", pageFaultsFIFO(pages, n, capacity));
 printf("Page Faults for LRU: %d\n", pageFaultsLRU(pages, n, capacity));
 printf("Page Faults for Optimal: %d\n", pageFaultsOptimal(pages, n, capacity));
 return 0;
}