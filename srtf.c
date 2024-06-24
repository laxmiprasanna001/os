#include<stdio.h>
typedef struct srtf
{
  int id,a,b,c,t,w;
}srtf;
void main()
{
  int n,i,j;
  printf("Enter no.of processes:");
  scanf("%d",&n);
  srtf p[n];
  int is[n],bs[n];
  printf("Enter pno,AT,bt respectively:");
  for(i=0;i<n;i++)
 {
   p[i].id=i+1;
   scanf("%d %d",&p[i].a,&p[i].b);
   is[i]=0;
   bs[i]=p[i].b;
 }
 int c=0,cmp=0,index=0;
 float atat,awt;
 while(c!=n)
 {
   int k=-1,min=1000000;
   for(i=0;i<n;i++)
   {
     if(p[i].a<=cmp && is[i]==0)
     {
       if(p[i].b<min)
       {
         min=p[i].b;
         k=i;
       }
       if(p[i].b==min && p[i].a<p[k].a)
       {
         min=p[i].b;
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
     printf("P%d ",p[k].id);
     
  }
  else
    cmp++;
 }
  printf("\np.no \t AT \t BT \t CT \t TAT \t WT\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t%d\t%d\t\%d\t%d\t%d\n",p[i].id,p[i].a,bs[i],p[i].c,p[i].t,p[i].w);
 }
 printf("ATAT is : %f\n",atat/n);
 printf("AWT is : %f\n",awt/n);
}
    

