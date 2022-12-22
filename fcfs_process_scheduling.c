#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
    int pid,st,at,bt,wt,tat,ct,rt;
}ps[100];

int findmax(int a,int b)
{
    return a>b? a:b;
}

int comparator_AT(const void *a,const void *b)
{
    int x=((struct fcfs*)a)->at;
    int y=((struct fcfs*)b)->at;
    return x<y? -1:1;
}

int comparator_PID(const void *a,const void *b)
{
    int x=((struct fcfs*)a)->pid;
    int y=((struct fcfs*)b)->pid;
    return x<y? -1:1;
}

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
    qsort((void *)ps,n,sizeof(struct fcfs),comparator_AT);
    for(int i=0;i<n;i++)
    {
        ps[i].st=(i==0)? ps[i].at:findmax(ps[i].at,ps[i-1].ct);
        ps[i].ct=ps[i].st+ps[i].bt;
        ps[i].tat=ps[i].ct-ps[i].at;
        ps[i].wt=ps[i].tat-ps[i].bt;
        ps[i].rt=ps[i].wt;
        sum_tat+=ps[i].tat;
        sum_wt+=ps[i].wt;
        sum_rt+=ps[i].rt;
        total_idle_time+=(i==0)? 0:(ps[i].st-ps[i-1].ct);
    }
    length_cycle=ps[n-1].ct-ps[0].st;
    cpu=(float)(length_cycle-total_idle_time)/length_cycle;
    throughput=n/(float)length_cycle;
    qsort((void*)ps,n,sizeof(struct fcfs),comparator_PID);

    printf("Process\t\tAT\t\tBT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].tat,ps[i].wt,ps[i].rt);
    }
    printf("Avg_tat = %f\n",sum_tat/(float)n);
    printf("Avg_wt = %f\n",sum_wt/(float)n);
    printf("Avg_rt = %f\n",sum_rt/(float)n);
    printf("Cpu utilisation  = %f\n",cpu);
    printf("Throughput = %f\n",throughput);
    return 0;

}