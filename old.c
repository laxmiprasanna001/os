#include<stdio.h>
int ispagefault(int f,int frame[],int pv)
{
  for(int i=0;i<f;i++)
  {
    if(frame[i]==pv)
      return 0;
  }
  return 1;
}
void printframes(int f,int frame[])
{
  for(int i=0;i<f;i++)
     printf("%d",frame[i]);
  printf("\n");
}
int opt(int f,int frame[],int n,int string[],int cur)
{
  int far=cur,res=-1,i,j;
  for(i=0;i<f;i++)
  {
    for(j=cur;j<n;j++)
    {
     if(frame[i]==string[j])
     {
       if(j>far)
       {
         far=j;
         res=i;
       }
       break;
    }
  }
  if(j==n)
    return i;
 }
 return (res==-1)?0:res;
}
void optimal(int f,int frame[],int n,int string[])
{
  int pf=0,i,j;
  for(i=0;i<n;i++)
  {
    if(ispagefault(f,frame,string[i]))
    {
      int e=-1;
      pf++;
      for(j=0;j<n;j++)
      {
        if(frame[j]==-1)
        {
          e=j;
          break;
        }
      }
      if(e!=-1)
        frame[e]=string[i];
      else
      {
        int ri=opt(f,frame,n,string,i+1);
        frame[ri]=string[i];
      }
    }
    printframes(f,frame);
  }
 printf("%d",pf);
}
void main()
{
  int n,f,i;
  printf("Enter length of string:");
  scanf("%d",&n);
  printf("enter reference string:");
  int string[n];
  for(i=0;i<n;i++)
    scanf("%d",&string[i]);
  printf("Enter no.of frames:");
  scanf("%d",&f);
  int frame[f],a[f],b[f];
  for(i=0;i<f;i++)
     frame[i]=-1;
  optimal(f,frame,n,string);
}
