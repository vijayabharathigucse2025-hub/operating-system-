#include <stdio.h>
int main()
{
int pageTable[20];
int pageSize;
int numPages;
int logicalAddress;
int pageNumber;
int offset;
int frameNumber;
int physicalAddress;
int i;
printf("Enter Page Size: ");
scanf("%d", &pageSize);
printf("Enter Number of Pages: ");
scanf("%d", &numPages);
printf("Enter Frame Numbers for Each Page:\n");
for(i = 0; i < numPages; i++)
{
printf("Page %d -> Frame: ", i);
scanf("%d", &pageTable[i]);
}
printf("Enter Logical Address: ");
scanf("%d", &logicalAddress);
pageNumber = logicalAddress / pageSize;
offset = logicalAddress % pageSize;
if(pageNumber >= numPages)
{
printf("Invalid Logical Address\n");
return 0;
}
frameNumber = pageTable[pageNumber];
physicalAddress = (frameNumber * pageSize) + offset;
printf("\nPage Number : %d", pageNumber);
printf("\nOffset : %d", offset);
printf("\nFrame Number : %d", frameNumber);
printf("\nPhysical Address : %d\n", physicalAddress);
return 0;
}
==========================================
Enter Page Size: 100
Enter Number of Pages: 3
Enter Frame Numbers for Each Page:
Page 0 -> Frame: 5
Page 1 -> Frame: 2
Page 2 -> Frame: 7
Enter Logical Address: 250

Page Number : 2
Offset : 50
Frame Number : 7
Physical Address : 750
=========================================================
