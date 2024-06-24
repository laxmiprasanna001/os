#include<stdio.h>
#include<stdlib.h>
void main()
{
  int t,i,j,m,hm=0,hp,k,n;
  printf("enter no.of tracks:");
  scanf("%d",&t);
  m=t+2;
  int track[m];
  printf("enter track values:");
  track[0]=0;
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
  for(i=1;i<m-1;i++)
  {
    if(hp<track[i])
    {
      k=i;
      break;
    }
  }
  printf("enter direction 0-->smaller and 1-->towards larger:");
  scanf("%d",&n);
  switch(n)
  {
     case 0:
            hm+=hp+199+abs(track[m-1]-track[k]);
            printf("%d",hm);
            break;
     case 1:
            hm+=abs(track[m-1]-hp)+199+track[k-1];
            printf("%d",hm);
            break;
  }
}
  
