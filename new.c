#include<stdio.h>
void main()
{
  int n,f,i,j,index=0,k,r,pf=0,count;
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
  frame[index]=string[index];
  printf("%d\n",frame[index]);
  index++;
  pf++;
  for(i=1;i<n;i++)
  {
    count=0;
    for(j=0;j<f;j++)
    {
     if(frame[j]!=string[i])
       count++;
    }
    if(count==f)
    {
     pf++;
     if(index<f)
     {
     frame[index]=string[i];
     index++;
     for(k=0;k<index;k++)
       printf("%d ",frame[k]);
     printf("\n");
    }
    else
    {
       for(r=0;r<index;r++)
       {
         a[r]=0;
         for(j=i-1;j>=0;j--)
         {
           if(frame[r]!=string[j])
           {
             a[r]++;
           }
           else
            break;
         }
       }
       for(r=0;r<f;r++)
         b[r]=a[r];
       for(r=0;r<f;r++)
       {
         for(j=0;j<f-r-1;j++)
         {
           if(b[j]<b[j+1])
           {
            int temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;
           }
         }
      }
      for(r=0;r<f;r++)
      {
        if(a[r]==b[0])
          frame[r]=string[i];
        printf("%d ",frame[r]);
      }
      printf("\n");
    }
  }
  }
  printf("%d",pf);
 }
          
