#include<stdio.h>
int main()
{
int n,i;
int bt[20],wt[20],tat[20];
float avg_wt=0,avg_tat=0;
printf("Enter Number of Processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Burst Time for P%d: ",i+1);
scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
wt[i]=wt[i-1]+bt[i-1];
for(i=0;i<n;i++)
{


tat[i]=wt[i]+bt[i];
avg_wt+=wt[i];
avg_tat+=tat[i];
}
printf("\nProcess\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time = %.2f",avg_wt/n);
printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);
return 0;
}
====================================
  Enter Number of Processes: 5
Enter Burst Time for P1: 53
Enter Burst Time for P2: 43
Enter Burst Time for P3: 243
Enter Burst Time for P4: 345
Enter Burst Time for P5: 2112

Process	BT	WT	TAT
P1	53	0	53
P2	43	53	96
P3	243	96	339
P4	345	339	684
P5	2112	684	2796

Average Waiting Time = 234.40
Average Turnaround Time = 793.60
=====================================

2. Shortest Job First (SJF)


#include<stdio.h>
int main()
{
int n,i,j,temp;
int bt[20],wt[20],tat[20];
float avg_wt=0, avg_tat=0;
printf("Enter Number of Processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Burst Time for P%d: ",i+1);
scanf("%d",&bt[i]);
}
// Sorting burst times in ascending order
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i] > bt[j])
{
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
}
}


}
wt[0] = 0;
for(i=1;i<n;i++)
wt[i] = wt[i-1] + bt[i-1];
printf("\nProcess\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
tat[i] = wt[i] + bt[i];
avg_wt += wt[i];
avg_tat += tat[i];
printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
}
avg_wt = avg_wt / n;
avg_tat = avg_tat / n;
printf("\nAverage Waiting Time = %.2f", avg_wt);
printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
return 0;
}
=============================================
  Enter Number of Processes: 3
Enter Burst Time for P1: 12
Enter Burst Time for P2: 23
Enter Burst Time for P3: 43

Process	BT	WT	TAT
P1	12	0	12
P2	23	12	35
P3	43	35	78

Average Waiting Time = 15.67
Average Turnaround Time = 41.67
==============================================
3. Priority Scheduling

#include<stdio.h>
int main() {
int n,i,j,temp;
int bt[20],pr[20],wt[20],tat[20];
float avg_wt=0, avg_tat=0;
printf("Enter Number of Processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("

\nEnter Burst Time for P%d: ",i+1);

scanf("%d",&bt[i]);
printf("Enter Priority for P%d: ",i+1);
scanf("%d",&pr[i]);
}
/* Sort according to priority */
for(i=0;i<n
-1;i++)
{
for(j=i+1;j<n;j++)
{
if(pr[i] > pr[j])
{
temp = pr[i];
pr[i] = pr[j];
pr[j] = temp;
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
}
}
}
wt[0] = 0;
for(i=1;i<n;i++)
wt[i] = wt[i
-1] + bt[i
-1];

printf("
\nProcess
\tPriority
\tBT
\tWT
\tTAT
\n");

for(i=0;i<n;i++)
{
tat[i] = wt[i] + bt[i];
avg_wt += wt[i];

34

avg_tat += tat[i];
printf("P%d\t%d\t\t%d\t%d\t%d\n",
i+1, pr[i], bt[i], wt[i], tat[i]);
}
avg_wt /= n;
avg_tat /= n;
printf("\nAverage Waiting Time = %.2f", avg_wt);
printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
return 0;
}
==============================================
  Enter Number of Processes: 3

Enter Burst Time for P1: 23
Enter Priority for P1: 43

Enter Burst Time for P2: 23
Enter Priority for P2: 45

Enter Burst Time for P3: 67
Enter Priority for P3: 55

Process	Priority	BT	WT	TAT
P1	43		23	0	23
P2	45		23	23	46
P3	55		67	46	113

Average Waiting Time = 23.00
Average Turnaround Time = 60.67
=====================================================

4. Round Robin Scheduling
#include<stdio.h>
int main()
{
int n, tq, i;
int bt[20], rem_bt[20];
int wt[20] = {0}, tat[20];
int time = 0, done;
float avg_wt = 0, avg_tat = 0;
printf("Enter Number of Processes: ");
scanf("%d", &n);
for(i = 0; i < n; i++)
{
printf("Enter Burst Time for P%d: ", i + 1);
scanf("%d", &bt[i]);
rem_bt[i] = bt[i];
}
printf("Enter Time Quantum: ");
scanf("%d", &tq);
do
{
done = 1;
for(i = 0; i < n; i++)
{
if(rem_bt[i] > 0)
{
done = 0;
if(rem_bt[i] > tq)
{
time += tq;
rem_bt[i]-= tq;

}
else
{
time += rem_bt[i];
wt[i] = time- bt[i];
rem_bt[i] = 0;
}
}
}
} while(!done);
printf("\nProcess\tBT\tWT\tTAT\n");

for(i = 0; i < n; i++)
{
tat[i] = bt[i] + wt[i];
avg_wt += wt[i];
avg_tat += tat[i];
printf("P%d\t%d\t%d\t%d\n",
i + 1, bt[i], wt[i], tat[i]);
}
avg_wt /= n;
avg_tat /= n;
printf("\nAverage Waiting Time = %.2f", avg_wt);
printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
return 0;
}
========================================
  Enter Number of Processes: 3
Enter Burst Time for P1: 234
Enter Burst Time for P2: 657
Enter Burst Time for P3: 456
Enter Time Quantum: 87

Process	BT	WT	TAT
P1	234	348	582
P2	657	690	1347
P3	456	756	1212

Average Waiting Time = 598.00
Average Turnaround Time = 1047.00
===========================================

