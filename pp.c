#include<stdio.h>
typedef struct pp
{
  int id,a,b,c,t,w,pr;
}pp;
void main()
{
  int n,i,index=0,c=0,cmp=0;
  printf("Enter no.of processes:");
  scanf("%d",&n);
  pp p[n];
  int is[n],bs[n];
  printf("enter pno,priority,at,bt respectively;");
  for(i=0;i<n;i++)
  {
    scanf("%d %d %d %d",&p[i].id,&p[i].pr,&p[i].a,&p[i].b);
    is[i]=0;
    bs[i]=p[i].b;
  }
  float atat=0,awt=0;
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
      p[k].b-=1;
      cmp++;
      if(p[k].b==0)
      {
        p[k].c=cmp;
        p[k].t=p[k].c-p[k].a;
        atat+=p[k].t;
        p[k].w=p[k].t-bs[k];
        awt+=p[k].w;
        is[k]=1;
        c++;
      }
    }
    else
      cmp++;
  }
  printf("p.no \t AT \t BT \t CT \t TAT \t WT\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t%d\t%d\t\%d\t%d\t%d\n",p[i].id,p[i].a,bs[i],p[i].c,p[i].t,p[i].w);
 }
 printf("ATAT is : %f\n",atat/n);
 printf("AWT is : %f\n",awt/n);
}
