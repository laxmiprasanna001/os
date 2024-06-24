#include<stdio.h>
void main()
{
  int n,f,index=0,pf=0,i,j,count;
  printf("Enter length of string:");
  scanf("%d",&n);
  int string[n];
  printf("enter reference string:");
  for(i=0;i<n;i++)
     scanf("%d",&string[i]);
  printf("Enter no.of frames:");
  scanf("%d",&f);
  int frame[f];
  for(i=0;i<f;i++)
     frame[i]=-1;
  for(i=0;i<n;i++)
  {
    count=-1;
    for(j=0;j<f;j++)
    {
      if(string[i]==frame[j])
      {
        count=1;
        break;
      }
    }
    if(count==-1)
    {
      frame[index++]=string[i];
      if(index>f-1)
         index=0;
    }
    if(count==1)
       continue;
    else
    {
      for(j=0;j<f;j++)
      {
        printf("%d ",frame[j]);
      }
      pf++;
    }
    printf("\n");
  }
  printf("%d",pf);
}
    
