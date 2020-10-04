#include<stdio.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main()
{
    int num;
    printf("Enter the no. of processes\n");
    scanf("%d",&num);
    int processes[num],burst_time[num],arrival_time[num],i,j,k,cmpl_time[num],tat[num],wt[num],total_wt=0,total_tat=0;
    float awt,atat;
    for(int k=0;k<num;k++)
    {
	 printf("Enter process id,burst time and arrival time of process %d:",(k+1));
	 scanf("%d",&processes[k]);
     scanf("%d",&burst_time[k]);
     scanf("%d",&arrival_time[k]);
    }
    
    for (i = 0; i < num-1; i++)
    {
       // Last i elements are already in place    
       for (j = 0; j < num-i-1; j++)
       {  
           if (arrival_time[j] > arrival_time[j+1]) 
           {
              swap(&arrival_time[j], &arrival_time[j+1]);
              swap(&processes[j], &processes[j+1]);
              swap(&burst_time[j], &burst_time[j+1]);
           }
       }
    }
    
    cmpl_time[0]=burst_time[0];
    for(i=1;i<num; i++)
    {
       cmpl_time[i]=cmpl_time[i-1]+burst_time[i];
    }
    for(j=0;j<num;j++)
    {
        tat[j]=cmpl_time[j]-arrival_time[j];
        total_tat=total_tat+tat[j];
    }
    for(k=0;k<num;k++)
    {
        wt[k]=tat[k]-burst_time[k];
        total_wt=total_wt+wt[k];
    }
    
    printf("Processes\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
    for(i=0;i<num;i++)
    {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",processes[i],burst_time[i],arrival_time[i],wt[i],tat[i],cmpl_time[i]);
    printf("\n");
    }
    awt = (float)(total_wt /num);
    atat = (float)(total_tat /num);
	printf("\nAverage waiting time = %f",awt);  
    printf("\nAverage turn around time = %f\n",atat);
    return 0;
}
