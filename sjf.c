#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct sjf
{
    int pid,at,bt,ct,wt,tat,rt,st;
}ps[100];
int main()
{
    int n;
    printf("Enter no of process:");
    scanf("%d",&n);
    printf("Enter process Arrival Time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ps[i].at);
        ps[i].pid=i;
    }
    printf("Enter process Burst Time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ps[i].bt);
    }
    int sum_tat=0,sum_wt=0,sum_rt=0,length_cycle=0,total_idle_time=0;
    float throughput,cpu;
    int completed=0,current_time=0;
    bool is_completed[100]={false};
    while(completed!=n)
    {
        int index=-1;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(ps[i].at<=current_time&&is_completed[i]==false)
            {
                if(ps[i].bt<minimum)
                {
                    minimum=ps[i].bt;
                    index=i;
                }
                if(ps[i].bt==minimum)
                {
                    if(ps[i].at<ps[index].at)
                    {
                        minimum=ps[i].bt;
                        index=i;
                    }
                }
            }
        }
        if(index==-1) current_time++;
        else
        {
            ps[index].st=current_time;
            ps[index].ct=ps[index].st+ps[index].bt;
            ps[index].tat=ps[index].ct-ps[index].at;
            ps[index].wt=ps[index].tat-ps[index].bt;
            ps[index].rt=ps[index].wt;
            sum_tat+=ps[index].tat;
            sum_wt+=ps[index].wt;
            sum_rt+=ps[index].rt;
            completed++;
            current_time=ps[index].ct;
            is_completed[index]=true;
        }
    }
    printf("Avg_tat : %f\n",sum_tat/(float)n);
    printf("Avg_wt : %f\n",sum_wt/(float)n);
    printf("Avg_rt : %f\n",sum_rt/(float)n);
}