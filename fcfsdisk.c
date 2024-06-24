#include<stdio.h>
#include<stdlib.h>
void main()
{
  int t,i,m,hm=0,hp;
  printf("enter no.of tracks:");
  scanf("%d",&t);
  m=t+2;
  int track[m];
  track[0]=0;
  for(i=1;i<m-1;i++)
    scanf("%d",&track[i]);
  track[m-1]=199;
  printf("Enter head position:");
  scanf("%d",&hp);
  for(i=1;i<m-1;i++)
  {
    hm+=abs(hp-track[i]);
    hp=track[i];
  }
  for(i=1;i<m-1;i++)
     printf("%d-->",track[i]);
  printf("\n%d",hm);
}
