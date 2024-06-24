#include<stdio.h>
typedef struct fcfs
{
  int id,a,b,c,t,w;
}fcfs;
void main()
{
  int n,i,j;
  printf("Enter no.of processes:");
  scanf("%d",&n);
  fcfs p[n];
  printf("Enter pno,arrival time and burst time respectively:");
  for(i=0;i<n;i++)
  {
    scanf("%d %d %d",&p[i].id,&p[i].a,&p[i].b);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(p[j].a>p[j+1].a)
      {
        int temp=p[j].a;
        int temp1=p[j].b;
        p[j].a=p[j+1].a;
        p[j].b=p[j+1].b;
        p[j+1].a=temp;
        p[j+1].b=temp1;
      }
   }
 }
 p[0].c=p[0].a+p[0].b;
 int time=p[0].c;
 for(i=1;i<n;i++)
 {
   if(p[i].a<=time)
   {
     p[i].c=time+p[i].b;
     time=p[i].c;
   }
   else
   {
     p[i].c=p[i].a+p[i].b;
     time=p[i].c;
   }
 }
 float atat=0,awt=0;
 for(i=0;i<n;i++)
 {
   p[i].t=p[i].c-p[i].a;
   atat+=p[i].t;
   p[i].w=p[i].t-p[i].b;
   awt+=p[i].w;
 }
 printf("p.no \t AT \t BT \t CT \t TAT \t WT\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t%d\t%d\t\%d\t%d\t%d\n",p[i].id,p[i].a,p[i].b,p[i].c,p[i].t,p[i].w);
 }
 printf("ATAT : %f",atat/n);
 printf("AWT is : %f",awt/n);
}
