#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int alloc[n][m],max[n][m],need[n][m];
    int avail[m],f[n],ans[n],index=0;
    for(int i=0;i<n;i++)
    {
        f[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    int y=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(f[j]==0)
            {
                int flag=0;
                for(int k=0;k<m;k++)
                {
                    if(need[j][k]>avail[k])
                    {
                        flag=1;
                        break;

                    }
                }
                if(flag==0)
                {
                    ans[index++]=j;
                    for(y=0;y<m;y++)
                    {
                        avail[y]+=alloc[j][y];
                    }
                    f[j]=1;
                }
            }
        }
    }
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            printf("Not safe");
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        for(int i=0;i<n-1;i++)
        {
            printf("P->%d",ans[i]);
        }
        printf("P->%d",ans[n-1]);
    }
}
//5 3
//0 1 0
//2 0 0
//3 0 2
//2 1 1
//0 0 2
//7 5 3
//3 2 2
//9 0 2
//2 2 2
//4 3 3
//3 3 2
