#include<stdio.h>
void main()
{
  int b,p,i,j;
  printf("Enter no.of blocks:");
  scanf("%d",&b);
  int block[b];
  printf("Enter block size and also enter -1 if its filled:");
  for(i=0;i<b;i++)
    scanf("%d",&block[i]);
  printf("Enter no.of processes:");
  scanf("%d",&p);
  int pro[p],alloc[p];
  printf("enter size of each processes:");
  for(i=0;i<p;i++)
  {
    scanf("%d",&pro[i]);
    alloc[i]=-1;
  }
  for(i=0;i<p;i++)
  {
    for(j=0;j<b;j++)
    {
      if(pro[i]<=block[j] && block[j]!=-1)
      {
        block[j]=block[j]-pro[i];
        alloc[i]=j;
        if(block[j]==0)
           block[j]=-1;
        break;
      }
    }
  }
  printf("pno\tprocess size\tallocated block\n");
  for(i=0;i<p;i++)
  {
    if(alloc[i]!=-1)
       printf("%d\t\t%d\t\t%d",i,pro[i],alloc[i]);
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
   if(ext>=pro[i])
     printf("%d",ext);
   else
     printf("no");
 }
}

  
