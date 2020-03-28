#include<stdio.h>
int main()
{
    int n,break_flag=0;
    printf("Enter the number of process: ");
    scanf("%d",&n);

    int Arrival_time[n],Burst_time[n],original_AT[n],process[n],original_BT[n];
/****************************Number of processes *************************************/

    printf("Enter Process one by one\n");
    for(int i=0;i<n;i++)
    {
        printf("P");
        scanf("%d",&process[i]);
    }
/***********************  Arrival Time *********************************************/

    printf("Enter Arrival time one by one\n");
     for(int i=0;i<n;i++)
    {
       scanf("%d",&Arrival_time[i]);
       original_AT[i]=Arrival_time[i];
    }
/******************** Burst Time ************************************************/

     printf("Enter Burst time one by one\n");
     for(int i=0;i<n;i++)
    {
        scanf("%d",&Burst_time[i]);
        original_BT[i]=Burst_time[i];

    }
/***********************Print question process AT and BT*********************************************/


     printf("\n\n\n Process\tAT\tBT\n");
  for(int i=0;i<n;i++)
     printf("  P%d\t\t%d\t%d\n",process[i],Arrival_time[i],Burst_time[i]);

/*************************** Modified Bubble Sort of arrival time *****************************************/
  for(int i=0;i<n-1;i++)
   {
      for(int j=0;j<n-1-i;j++)
       {
           int temp;
           if(Arrival_time[j]>Arrival_time[j+1])
           {
               temp=Arrival_time[j];
               Arrival_time[j]=Arrival_time[j+1];
               Arrival_time[j+1]=temp;
               break_flag=1;
           }
       }
       if(break_flag==0)
         break;
}

  int New_BT[n],k=0,New_process[n];
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
           if(Arrival_time[i]==original_AT[j])
           {
               New_BT[k]=Burst_time[j];
               New_process[k]=process[j];
               k++;
           }
      }
  }
  int sum=0,final_process[n],P=1,Turn_Around_Time[n],Completion_Time[n];

  for(int i=0;i<n;i++)
  {
      int k=0;
      sum=sum+New_BT[i];

      if(i==0 && k==0)
      {
          final_process[i]=New_process[i];
          Arrival_time[i]=1000;
      }
     int new_process_arrive[n];
      float priority[n];
      for(int j=0;j<n;j++)
      {
          if(sum>=Arrival_time[j])
           {
               new_process_arrive[k]=New_process[j];
               int pri=(sum-Arrival_time[j]);
               priority[k]=1+(float)pri/New_BT[j];
               k++;
           }
      }
/*************************Finding maximum priority of processes *******************************************/
       float max=priority[0];
       int index=0;
       for(int J=0;J<k;J++)
       {
           if(priority[J]>max)
           {
                max=priority[J];
                index=J;
           }
        }
     final_process[P]=new_process_arrive[index];

/********************Final order of process after scheduling ********************************/
     for(int z=0;z<n;z++)
      {
          if(final_process[P]==New_process[z])
           Arrival_time[z]=1000;
       }
      P++;
}
/**************************completion and turnaround time******************************************/
sum=0;
int Avg_tat=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(final_process[i]==process[j])
        {
            sum=sum+Burst_time[j];
            Completion_Time[i]=sum;
            Turn_Around_Time[i]=sum-original_AT[j];
            Avg_tat=Avg_tat+Turn_Around_Time[i];
            break;
        }
    }
}

int new_comp[n],new_tat[n],new_wt[n];
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(final_process[i]==process[j])
        {
           new_comp[j]=Completion_Time[i];
           new_tat[j]=Turn_Around_Time[i];
            break;
        }
    }
}
/************************* Waitinig Time *******************************************/
int waiting[n],avg_wt=0;
for(int i=0;i<n;i++)
{
   waiting[i]=new_tat[i]-Burst_time[i];
   avg_wt=avg_wt+waiting[i];
}

printf("\n\n****************After Scheduling******************");
  printf("\n\n\n Process\tArrival_Time\t\tBurst_Time\t\tWaiting_Time\t\tCompletion_Time\t\t\ Turn_Around_Time\n");

  for(int i=0;i<n;i++)
    printf("   P%d\t\t   %d\t\t\t    %d\t\t\t    %d\t\t\t\t%d\t\t       %d\n",process[i],original_AT[i],Burst_time[i],waiting[i],new_comp[i],new_tat[i]);

  printf("\n\nFinal Order or Gantt Chart:\t\t");
  for(int J=0;J<n;J++)
     printf("P%d\t",final_process[J]);

     printf("\n\nAverage Waiting Time:     %0.3f\t",(float)avg_wt/n);
     printf("\n\nAverage Turn Around Time: %0.3f\t",(float)Avg_tat/n);
}
