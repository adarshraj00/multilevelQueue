	#include<stdio.h>
	int arrivalTime1[30],arrivalTime2[30],priority2[30],process2[30],arrivalTime3[30];
	int burstTime1[30],burstTime2[30],burstTime3[30];
	int Total=0,t1=0,t2=0,t3=0;
	int n,i,ar[30],brst[30],pr[30],j=0,k=0,l=0;
	int total,x,temp[30],counter=0;
	float avgWaitTime1=0.0,avgTurnaroundTime1=0.0;
	int p,waitingTime3[30],turnaroundTime3[30];
	float avgWaitTime3=0.0,avgTurnaroundTime3=0.0;
	int position,q,temp1,sum=0,waitingTime2[30],turnaroundTime2[30];
	float avgWaitTime2,avgTurnaroundTime2;
	void roundRobin()
	{
		printf("Time Quantum for Queue1 is 4\n");
		for(i=0;i<j;i++)
		{
			temp[i]=burstTime1[i];
		} 
		printf("\nProcess \tBurst Time\t Turnaround Time\t Waiting Time\n");
		x=j;
	    for(i=0,total=0;x!=0;) 
	    { 
	    	if(temp[i]<=4&&temp[i]>0) 
	        {
				printf("\nProcess[%d] of Queue1 is running for %d units of time",i+1,temp[i]); 
	            total=total+temp[i]; 
	            temp[i]=0; 
	            counter=1; 
	        } 
	        else if(temp[i]>0) 
	        {
				printf("\nProcess[%d] of Queue1 is running for 4 units of time",i+1); 
	            temp[i]=temp[i]-4; 
	            total=total+4; 
	        } 
	        if(temp[i]==0&&counter==1) 
	        { 
	            x--; 
	            printf("\nProcess[%d]\t%d\t%d\t%d",i+1,burstTime1[i],total-arrivalTime1[i],total-arrivalTime1[i]-burstTime1[i]);
	            avgWaitTime1=avgWaitTime1+total-arrivalTime1[i]-burstTime1[i]; 
	            avgTurnaroundTime1=avgTurnaroundTime1+total-arrivalTime1[i]; 
	            counter = 0; 
	        } 
	        if(i==j-1) 
	        {
	            i=0; 
	        }
	        else if(arrivalTime1[i+1]<=total) 
	        {
	            i++;
	        }
	        else 
	        {
	            i=0;
	        }
	    } 
	    avgWaitTime1=avgWaitTime1/j;
	    avgTurnaroundTime1=avgTurnaroundTime1/j;
	    printf("\nAverage Waiting Time:%f",avgWaitTime1); 
	    printf("\nAverage Turnaround Time:%f\n",avgTurnaroundTime1); 
	}
	void priority()
	{
		for(i=0;i<k;i++)
	    {
	        position=i;
	        for(q=i+1;q<k;q++)
	        {
	            if(priority2[q]<priority2[position])
	            {
	                position=q;
	            }
	        }
	        temp1=priority2[i];
	        priority2[i]=priority2[position];
	        priority2[position]=temp1; 
	        
	        temp1=burstTime2[i];
	        burstTime2[i]=burstTime2[position];
	        burstTime2[position]=temp1;
	        
	        temp1=process2[i];
	        process2[i]=process2[position];
	        process2[position]=temp1;
	    }
	    waitingTime2[0]=0;
	    for(i=1;i<k;i++)
	    {
	        waitingTime2[i]=0;
	        for(q=0;q<i;q++)
	        {
	            waitingTime2[i]=waitingTime2[i]+burstTime2[j];
	        }
	        sum=sum+waitingTime2[i];
	    }
	    avgWaitTime2=sum/k;
	    sum=0;
	    printf("\nProcess \t\tBurst Time\t Waiting Time\t Turnaround Time\n");
	    for(i=0;i<k;i++)
	    {
	    	turnaroundTime2[i]=burstTime2[i]+waitingTime2[i];
	        sum=sum+turnaroundTime2[i];
	        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",process2[i],burstTime2[i],waitingTime2[i],turnaroundTime2[i]);
	    }
	    avgTurnaroundTime2=sum/k;
	    printf("\nAverage Waiting Time:\t%f",avgWaitTime2);
	    printf("\nAverage Turnaround Time:\t%f\n",avgTurnaroundTime2);   
	    for(i=0;i<k;i++)
	    {
	    	while(burstTime2[i]!=0)
	    	{
	    		if(burstTime2[i]>10)
	    		{
					printf("\nProcess[%d] of Queue2 is running for 10 units of time",i+1);
					burstTime2[i]=burstTime2[i]-10;
				}
				else if(burstTime2[i]<=10)
				{
					printf("\nProcess[%d] of Queue2 is running for %d units of time",i+1,burstTime2[i]);
					burstTime2[i]=0;
				}
			}
		}
	}
	void fcfs()
	{
		waitingTime3[0] = 0;   
	    for(i=1;i<l;i++)
	    {
	        waitingTime3[i] = 0;
	        for(p=0;p<l;p++)
	        {
	            waitingTime3[i]=waitingTime3[i]+burstTime3[p];
	        }
	    }
	    printf("\nProcess \t\tBurst Time\tWaiting Time\tTurnaround Time\n");
	    for(i=0;i<l;i++)
	    {
	        turnaroundTime3[i]=burstTime3[i]+waitingTime3[i];
	        avgWaitTime3=avgWaitTime3+waitingTime3[i];
	        avgTurnaroundTime3=avgTurnaroundTime3+turnaroundTime3[i];
	        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,burstTime3[i],waitingTime3[i],turnaroundTime3[i]);
	    }
	    avgWaitTime3=avgWaitTime3/l;
	    avgTurnaroundTime3=avgTurnaroundTime3/l;
	    printf("\nAverage Waiting Time=%f",avgWaitTime3);
	    printf("\nAverage Turnaround Time=%f",avgTurnaroundTime3);
	    for(i=0;i<l;i++)
	    {
	    	while(burstTime3[i]!=0)
	    	{
	    		if(burstTime3[i]>10)
	    		{
					printf("\nProcess[%d] of Queue3 is running for 10 units of time",i+1);
					burstTime3[i]=burstTime3[i]-10;
				}
				else if(burstTime3[i]<=10)
				{
					printf("\nProcess[%d] of Queue2 is running for %d units of time",i+1,burstTime3[i]);
					burstTime3[i]=0;
				}
			}
		}
	}
	void roundRobin1()
	{
		printf("Time Quantum between the 3 queues is 10\n");
		for(i=1;i<Total;i=i+10)
		{
			if(t1>10)
			{
				printf("Queue1 is running for 10 units of time\n");
				t1=t1-10;
			}
			else if(t1<=10&&t1!=0)
			{
				printf("Queue1 is running for %d units of time\n",t1);
				t1=0;
			}
			if(t2>10)
			{
				printf("Queue2 is running for 10 units of time\n");
				t2=t2-10;
			}
			else if(t2<=10&&t2!=0)
			{
				printf("Queue2 is running for %d units of time\n",t2);
				t2=0;
			}
			if(t3>10)
			{
				printf("Queue3 is running for 10 units of time\n");
				t3=t3-10;
			}
			else if(t3<=10&&t3!=0)
			{
				printf("Queue3 is running for %d units of time\n",t3);
				t3=0;
			}
		}
	}
	int main()
	{
		printf("Enter the no. of processes\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("Enter details of process[%d]\n",i+1);
			printf("Arrival Time:");
			scanf("%d",ar+i);
			printf("Burst Time:");
			scanf("%d",brst+i);
			printf("Priority(1 to 15):");
			scanf("%d",pr+i);
			Total=Total+brst[i];
		}
		for(i=0;i<n;i++)
		{
			if(pr[i]>=1&&pr[i]<=5)
			{
				printf("\n\nProcess[%d] belongs to Queue 1\n",i+1);
				arrivalTime1[j]=ar[i];
				burstTime1[j]=brst[i];
				j++;
				t1=t1+brst[i];
			}
			
			else if(pr[i]>=6&&pr[i]<=10)
			{
				printf("Process[%d] belongs to Queue 2\n",i+1);
				arrivalTime2[k]=ar[i];
				burstTime2[k]=brst[i];
				priority2[k]=pr[i];
				process2[k]=k+1;
				k++;
				t2=t2+brst[i];
			}
			
			else if(pr[i]>=11&&pr[i]<=15)
			{
				printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1);
				arrivalTime3[l]=ar[i];
				burstTime3[l]=brst[i];
				l++;
				t3=t3+brst[i];
			}
		}	
		roundRobin1();
		roundRobin();
		fcfs();
		priority();
		
		return 0;
	}
//11812708 Adarsh raj
