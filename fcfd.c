#include<stdio.h>
#include<math.h>
int main()
{
    int n,h,m=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&h);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
        m+=fabs(a[i]-h);
        h=a[i];
    }
    printf("%d s",m);
}
