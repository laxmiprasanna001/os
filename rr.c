#include<stdio.h>
struct process
{
  int id,a,b,c,t,w,d;
};
struct process queue[100];
int front=-1,rear=-1;
void enque(struct process p)
{
  if(front==-1 && rear==-1)
  {
    front=rear=0;
    queue[rear]=p;
  }
  else
  {
   rear++;
   queue[rear]=p;
  }
}
int deque()
{
  int res;
  if(front==rear)
  {
    res=queue[front].id;
    front=rear=-1;
  }
  else
  {
    res=queue[front].id;
    front++;
  }
  return res;
}
void sort(struct process p[],int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(p[j].a>p[j+1].a)
      {
        struct process temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
   }
  }
}
void solve(struct process p[],int n,int ideal,int tq)
{
  printf("ganttchart ");
  if(ideal!=0)
    printf("- ");
  int sum=ideal;
  int j=1;
  enque(p[0]);-*+
  while(front!=-1 && rear!=-1)
  {
    for(int i=0;i<n;i++)
    {
      if(p[i].id==queue[front].id)
      {
        if(p[i].b<=tq)
        {
          sum+=p[i].b;
          p[i].c=sum;
        }
        else
        {
          sum+=tq;
          p[i].b-=tq;
          while(p[j].a<=sum && j<n)
          {
            enque(p[j]);
            j++;
          }
          enque(p[i]);
        }
        break;
     }
    }
    int res=deque();
    printf("%d",res);
  }
}
int main()
{
  int n,i;
  printf("enter no.of processes:");
  scanf("%d",&n);
  struct process p[n];
  printf("enter at and bt respectively:");
  for(i=0;i<n;i++)
  {
    p[i].id=i+1;
    scanf("%d %d",&p[i].a,&p[i].b);
    p[i].d=p[i].b;
  }
  int tq;
  printf("Enter time quantum:");
  scanf("%d",&tq);
  sort(p,n);
  int ideal=0;
  if(p[0].a==0)
     solve(p,n,ideal,tq);
  else
  {
     ideal=ideal+p[0].a;
     solve(p,n,ideal,tq);
  }
  float atat=0,awt=0;
  for(i=0;i<n;i++)
  {
    p[i].t=p[i].c-p[i].a;
    atat+=p[i].t;
    p[i].w=p[i].t-p[i].d;
    awt+=p[i].w;
  }
  printf("\np.no \t AT \t BT \t CT \t TAT \t WT\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t%d\t%d\t\%d\t%d\t%d\n",p[i].id,p[i].a,p[i].d,p[i].c,p[i].t,p[i].w);
 }
 printf("ATAT is : %f\n",atat/n);
 printf("AWT is : %f\n",awt/n);
}
