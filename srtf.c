#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct fcfs
{
    int pid,at,bt,rbt,tat,ct,wt,rt,st;
}ps[100];
int findmax(int a,int b) 
{
    return (a>b)? a:b;
}

int findmin(int a,int b){ return (a<b)? a:b;}

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
        ps[i].rbt=ps[i].bt;
    }
    int sum_tat=0,sum_wt=0,sum_rt=0,length_cycle=0,total_idle_time=0,prev=0;
    float throughput,cpu;
    int completed=0,current_time=0;
    int max_ct=INT_MIN,min_at=INT_MAX;
    bool is_completed[100]={false},is_first_process=true;
    while(completed!=n)
    {
        int index=-1;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(ps[i].at<=current_time&&is_completed[i]==false)
            {
                if(ps[i].rbt<minimum)
                {
                    minimum=ps[i].rbt;
                    index=i;
                }
                if(ps[i].rbt==minimum)
                {
                    if(ps[i].at<ps[index].at)
                    {
                        minimum=ps[i].rbt;
                        index=i;
                    }
                }
            }
        }
        if(index==-1) current_time++;
        else
        {
            if(ps[index].rbt==ps[index].bt)
            {
                ps[index].st=current_time;
                total_idle_time+=(is_first_process==true)? 0:(ps[index].st-prev);
                is_first_process=false;
            }
            ps[index].rbt--;
            current_time++;
            prev=current_time;
            if(ps[index].rbt==0)
            {
                ps[index].ct=current_time;
                ps[index].tat=ps[index].ct-ps[index].at;
                ps[index].wt=ps[index].tat-ps[index].bt;
                ps[index].rt=ps[index].ct-ps[index].st;
                sum_rt+=ps[index].rt;
                sum_wt+=ps[index].wt;
                sum_tat+=ps[index].tat;
                is_completed[index]=true;
                completed++;
            }
        }
    }
    printf("Process\t\tAT\t\tBT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].tat,ps[i].wt,ps[i].rt);
    }
    for(int i=0;i<n;i++)
    {
        max_ct=findmax(max_ct,ps[i].ct);
        min_at=findmin(min_at,ps[i].at);
    }

    length_cycle=max_ct-min_at;
    printf("avg_tat :%f\n",sum_tat/(float)n);
    printf("avg_wt :%f\n",sum_wt/(float)n);
    printf("avg_rt :%f\n",sum_rt/(float)n);
    printf("length_cycle :%d\n",length_cycle);
    
    printf("tit :%d\n",total_idle_time);
    printf("cpu :%f\n",(length_cycle-total_idle_time)/(float)length_cycle);
    printf("throughput :%f\n",n/(float)length_cycle);
}