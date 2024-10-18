#include<stdio.h>
int queue[30],front=-1,rear=-1,i,data,c,n;
void enqueue(int n)
{
 if(((front==0)&&(rear==n-1))||(rear==front-1)) 
 {
     printf("queue overflow!\n");
     return;
 }
 
 else if(front==-1&&rear==-1)
 {
 printf("enter the element:\n");
 scanf("%d",&data);
     front=rear=0;
     queue[rear]=data;
 }
 else if(rear==n-1)
 {
     printf("enter the element:\n");
     scanf("%d",&data);
     rear=0;
     queue[rear]=data;
 }
 else
 {
     printf("enter the element:\n");
     scanf("%d",&data);
     rear+=1;
     queue[rear]=data;
 }
}
void dequeue(int n)
{
    if(front==-1 && rear==-1)
    {
    printf("queue underflow\n");
    return;
    }
    data=queue[front];
    printf("%d is popped\n",data );
    if(front==rear)
    front=rear=-1;
    else if(front == n-1)
    front=0;
    else
    front+=1;

}
void display(int n)
{
    if(front==-1)
    {
    printf("queue is empty");
    return;
    }
    int f=front,r=rear,j=0;
    if(f<=r)
    {
        while(f<=r)
        {
        printf("%d\t",queue[f]);
        f++;
        }
        printf("\n");
    }
    else
    {
     while(f<n)
     {
         printf("%d\t",queue[f]);
         f++;
     }
     while(j<=rear)
     {
         printf("%d\t",queue[j]);
         j++;
     }
     printf("\n");
    }
}
void main()
{
    
    
    printf("enter the limit:\n");
    scanf("%d",&n);
    printf("1.Insertion 2.deletion 3.display 4.exit\n");
    do
    {
        printf("enter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:enqueue(n);
        break;
        case 2:dequeue(n);
        break;
        case 3:display(n);
        break;
        case 4:printf("exit");
        break;
        default:printf("invalid choice\n");
        }
    } while(c!=4);
        
   return ;
}