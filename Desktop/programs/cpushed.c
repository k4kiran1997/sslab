//program for cpu scheduling

#include<sstdio.h>

void fcfs()
{

	int p[20],bt[20],wt[20],tat[20],totat,towt;
	float avgtat,avgwt;
	printf("\nenter the no of processes: ");
	scanf("%d",&n);

