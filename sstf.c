#include<stdio.h>
#include<math.h>
int main()
{
    int n,h,m=0,c=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&h);
    while(c!=n)
    {
        int min=1000,d,index;
        for(int i=0;i<n;i++)
        {
            if(a[i]==-1) continue;
            d=fabs(a[i]-h);
            if(d<min)
            {
                min=d;
                index=i;
            }

        }
        m+=min;
        h=a[index];
        a[index]=-1;
        c++;
    }
    printf("%d",m);
}
