#include<stdio.h>
void main()
{
 int n,t,j;
 printf("enter string length:");
 scanf("%d",&n);
 int f;
 scanf("%d",&f);
 int s[n],p[f];
 for(int i=0;i<n;i++)
 {
  scanf("%d",&s[i]);
 }
 for(int i=0;i<f;i++)
   p[i]=-1;
 for(int i=0;i<n;i++)
 {
   int c=-1;
   for(j=0;j<f;j++)
   {
    if(s[i]==p[j])
    {
     c=1;
     break;
    }
   }
   if(c==-1)
   {
    for(int j=i-1;j>=0;j--)
    {
    t=0;
     for(int k=0;k<f;k++)
     {
      if(s[j]==p[k])
       t=1;
     }
     if(t==0)
     
      break;
    }
    for(int r=0;r<f;r++)
    {
     if(p[r]==p[j+1])
      p[r]=s[i];
    }
   }
   if(c==1)
    continue;
   else
   {
    for(int r=0;r<f;r++)
    {
     printf("%d	",p[r]);
    }
   
   printf("\n");
   }
 }
}
