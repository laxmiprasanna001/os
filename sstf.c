#include<stdio.h>
#include<stdlib.h>
void main()
{
  int t,i,m,hm=0,k,hp,j,d;
  printf("Enter no.of tracks:");
  scanf("%d",&t);
  m=t+2;
  int track[m];
  track[0]=0;
  printf("Enter track values:");
  for(i=1;i<m-1;i++)
     scanf("%d",&track[i]);
  track[m-1]=199;
  printf("enter head position:");
  scanf("%d",&hp);
  for(i=1;i<m-1;i++)
  {
    int min=10000000;
    for(j=1;j<m-1;j++)
    {
      k=abs(hp-track[j]);
      if(k<min)
      {
        min=k;
        d=j;
      }
    }
    hm+=min;
    hp=track[d];
    printf("%d--> ",track[d]);
    track[d]=10000000;
  }
  printf("\n%d",hm);      
 } 
