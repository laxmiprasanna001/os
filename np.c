#include<stdio.h>
typedef struct np
{
  int id,a,b,c,t,w,pr;
}np;
void main()
{
  int n,i,j,c=0,cmp=0,index=0;
  float atat=0,awt=0;
  printf("Enter no.of processes:");
  scanf("%d",&n);
  np p[n];
 int is[n];
  printf("priority,at,bt respectively:\n");
  for(i=0;i<n;i++)
  {
    p[i].id=i+1;
    scanf(" %d %d %d",&p[i].pr,&p[i].a,&p[i].b);
    is[i]=0;
  }
  while(c!=n)
  {
    int k=-1,min=1000000;
    for(i=0;i<n;i++)
    {
      if(p[i].a<=cmp && is[i]==0)
      {
        if(p[i].pr<min)
        {
          min=p[i].pr;
          k=i;
        }
        if(p[i].pr==min && p[i].a<p[k].a)
        {
          min=p[i].pr;
          k=i;
        }
      }
    }
    if(k!=-1)
    {
      p[k].c=cmp+p[k].b;
      p[k].t=p[k].c-p[k].a;
      atat+=p[k].t;
      p[k].w=p[k].t-p[k].b;
      awt+=p[k].w;
      cmp=p[k].c;
      c++;
      is[k]=1;
      printf("P%d ",p[k].id);
      
   }
   else
     cmp++;
 }
 printf("p.no \t AT \t BT \t CT \t TAT \t WT\n");
 for(i=0;i<n;i++)
 {
   printf("\n%d\t%d\t%d\t\%d\t%d\t%d\n",p[i].id,p[i].a,p[i].b,p[i].c,p[i].t,p[i].w);
 }
 printf("ATAT is : %f\n",atat/n);
 printf("AWT is : %f\n",awt/n);
}
