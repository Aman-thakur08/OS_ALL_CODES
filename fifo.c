#include<stdio.h>
int search(int a[],int m,int x)
{
    for(int i=0;i<m;i++)
    {
        if(a[i]==x)
            return 1;
    }
    return -1;
}
int main()
{
    int n,m,c=0,h=0;
    scanf("%d%d",&n,&m);
    int a[m],str[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&str[i]);
    }
    for(int i=0;i<m;i++)
    {
        a[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(search(a,m,str[i])==1) h++;
        else
        {
            a[(c++)%m]=str[i];
            for(int j=0;j<m;j++)
            {
                printf("%d ",a[j]);
            }
            printf("\n");
        }
    }
    printf("miss=%d\n",n-h);
    float x=h/(n*1.0);
    float y=(n-h)/(n*1.0);
    printf("miss r=%f\n",y);
    printf("miss p=%f\n",y*100);
}
