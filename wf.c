#include<stdio.h>
void main()
{
  int p,b,i,j;
  printf("Enter no.of processes:");
  scanf("%d",&p);
  int pro[p],alloc[p];
  printf("Enter size of processes:");
  for(i=0;i<p;i++)
  {
    scanf("%d",&pro[i]);
    alloc[i]=-1;
  }
  printf("Enter no.of blocks:");
  scanf("%d",&b);
  int block[b];
  printf("Enter block size and enter -1 if it is already filled:");
  for(i=0;i<b;i++)
    scanf("%d",&block[i]);
  for(i=0;i<p;i++)
  {
    int max=0,k,flag=0;
    for(j=0;j<b;j++)
    {
      if(pro[i]<=block[j] && block[j]!=-1 && block[j]>max)
      {
        max=block[j];
        k=j;
        flag=1;
      }
    }
    if(flag==1)
    {
      block[k]=block[k]-pro[i];
      alloc[i]=k;
      if(block[k]==0)
         block[k]=-1;
    }
  }
  printf("p.no \t process size \t allocated block\n");
  for(i=0;i<p;i++)
  {
    if(alloc[i]!=-1)
    {
      printf("%d\t\t%d\t\t%d",i,pro[i],alloc[i]);
    }
    else
    {
      printf("%d\t\t%d\t\t",i,pro[i]);
      printf("not allocated");
    }
    printf("\n");
  }
  int ext=0;
  for(i=0;i<b;i++)
  {
    if(block[i]!=-1)
     {
      printf("%d ",block[i]);
      ext+=block[i];
    }
  }
  for(i=0;i<p;i++)
  {
    if(alloc[i]==-1)
    {
      if(ext>=pro[i])
        printf("\n%d",ext);
      else
        printf("NO");
    }
  }
}
