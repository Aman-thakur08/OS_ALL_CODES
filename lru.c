#include<stdio.h>
#include<limits.h>
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
    int n,m,c=0,f=0;
    scanf("%d%d",&n,&m);
    int s[n],d[n],q[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    printf("Process\t\tFrame1\t\tFrame2\t\tFrame3\n");
    for(int i=0;i<n;i++)
    {
        printf("%d    \t\t",s[i]);
        if(find(s[i],q,c)==1)
        {
            print(q,c);
        }
        else if(c<m)
        {
            q[c++]=s[i];
            print(q,c);
            f++;
        }
        else
        {
            int max=INT_MIN,index;
            for(int j=0;j<m;j++)
            {
                d[j]=0;
                for(int k=i-1;k>=0;k--)
                {
                    ++d[j];
                    if(q[j]==s[k])
                        break;
                }
                if(d[j]>max)
                {
                    max=d[j];
                    index=j;
                }
            }
            q[index]=s[i];
            f++;
            print(q,c);
        }
        printf("\n");
    }
    printf("%d",f);
}
