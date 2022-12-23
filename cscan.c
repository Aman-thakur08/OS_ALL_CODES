#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int comp(const void *a,const void *b)
{
    int x=*(int *)a;
    int y=*(int *)b;
    return x-y;
}
int main()
{
    int n,h,m=0,x,ch;
    int c=1,d=0;
    scanf("%d%d",&n,&h);
    int left[10],right[10];
    left[0]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x<h)
        {
            left[c++]=x;
        }
        else if(x>h)
        {
            right[d++]=x;
        }
    }
    right[d++]=199;
    qsort(left,c,sizeof(int),comp);
    qsort(right,d,sizeof(int),comp);
    scanf("%d",&ch);
    int run=2;
    while(run--)
    {
        if(ch==0)
        {
            for(int i=0;i<c;i++)
            {
                printf("%d\n",left[i]);
                m+=fabs(left[i]-h);
                h=left[i];
            }
            ch=1;
        }
        else if(ch==1)
        {
            for(int i=0;i<d;i++)
            {
                printf("%d\n",right[i]);
                m+=fabs(right[i]-h);
                h=right[i];
            }
            ch=0;
        }
    }
    printf("%d",m);
}

