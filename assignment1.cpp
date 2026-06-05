#include<iostream>
int p1()
{
    int x=3;
    if(x%2==0)
        printf("Even");
    else
        printf("Odd");
}
int p2()
{
    int x,i,fac=1;
    printf("Enter a number:\n");
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        fac=fac*i;
    }
    printf("%d",fac);
}
int p3()
{
    int x,y,t;
    scanf("%d %d",&x,&y);
    t=y;
    y=x;
    x=t;
    printf("%d %d",x,y);
}
int lcm(int x,int y)
{
    int l;
    for(int l=x>y?x:y;l<=x*y;l++)
    {
        if(l%x==0&&l%y==0)
            return l;
    }
}
int prime(int x)
{
    int i;
    for(i=2;i<x;i++)
    {
        if(x%i==0)
            return 0;
        return 1;
    }
}
int main()
{
    int x;
    x=prime(4);
    if(x==0)
        printf("not prime");
    else
        printf("prime");    
    return 0;
}
