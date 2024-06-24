#include<stdio.h>
#include<stdlib.h>
void main()
{
  int t,hp,hm=0,i,m,j,n;
  printf("Enter no.of tracks:");
  scanf("%d",&t);
  m=t+2;
  int track[m];
  track[0]=0;
  printf("enter track values:");
  for(i=1;i<m-1;i++)
    scanf("%d",&track[i]);
  track[m-1]=199;
  printf("Enter head position:");
  scanf("%d",&hp);
  for(i=1;i<m-1;i++)
  {
    for(j=1;j<m-i-1;j++)
    {
      if(track[j]>track[j+1])
      {
        int temp1=track[j];
        track[j]=track[j+1];
        track[j+1]=temp1;
      }
    }
  }
  printf("Enter direction 0-->towards smaller and 1-->towards larger:");
  scanf("%d",&n);
  switch(n)
  {
    case 0:
           hm+=hp+track[m-2];
           printf("%d ",hm);
           break;
    case 1:
           hm+=abs(hp-track[m-1])+abs(track[m-1]-track[1]);
           printf("%d",hm);
           break;
  }
}
