#include<stdio.h>
int arrivalTime1[40],arrivalTime2[40],arrivalTime3[40];
int burstTime1[40],burstTime2[40],burstTime3[40];
int main()
{
	int n,i,ar[40],brst[40],p[40],j=0,k=0,l=0;
	printf("enter number of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Detail Of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",ar+i);
		printf("Burst Time:");
		scanf("%d",brst+i);
		printf("Priority(1 to 15):");
		scanf("%d",p+i);
	}
	for(i=0;i<n;i++)
	{
		if(p[i]>=1&&p[i]<=5)
		{
			printf("Process[%d] is in Queue 1\n",i+1);
			arrivallTime1[j]=ar[i];
			burstTime1[j]=brst[i];
			j++;
		}
		
		else if(p[i]>=6&&p[i]<=10)
		{
			printf("Process[%d] is in Queue 2\n",i+1);
			arrivalTime2[k]=ar[i];
			burstTime2[k]=brst[i];
			k++;
		}
		
		else if(p[i]>=11&&p[i]<=15)
		{
			printf("Process[%d] is in Queue 3\n",i+1);
			arrivalTime3[l]=ar[i];
			burstTime3[l]=brst[i];
			l++;
		}
	}
	return 0;
}
