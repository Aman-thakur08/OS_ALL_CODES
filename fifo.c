#include<stdio.h>
int find(int x,int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            return 1;
    }
    return 0;
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t",a[i]);
    }
    printf("\n");
}
int main()
{
    int n,m,h=0,c=0,f=0;
    scanf("%d%d",&n,&m);
    int a[m],s[n];
    for(int i=0;i<m;i++)
    {
        a[i]=-1;
    }
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<n;i++)
    {
        if(find(s[i],a,c)==1)
        {
            h++;
            print(a,m);
        }
        else
        {
            a[(c++)%m]=s[i];
            f++;
            print(a,m);
        }
        printf("\n");
    }
    printf("%d %d",h,f);
}
