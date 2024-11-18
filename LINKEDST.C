#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack
{
int data;
struct stack *next;
};
struct stack *top=NULL,*nnode,*temp;
int n,data,ch,c=0;
void push()
{
printf("enter the data:\n");
scanf("%d",&data);
nnode=(struct stack*)malloc(sizeof(struct stack));
nnode->data=data;
nnode->next=top;
top=nnode;
}
void pop()
{
if(top==NULL)
printf("stack is empty\n");
else
{
printf("%d is popped\n",top->data);
top=top->next;
}
}
void display()
{
temp=top;
if(temp==NULL)
printf("stack is empty");
else
{
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}
}
void count()
{
if(top==NULL)
printf("count=%d\n",c);
else
{
while(top!=NULL)
{
c=c+1;
top=top->next;
}
printf("Count=%d",c);
}
}
int main(void)
{
int i;
clrscr();
printf("enter the limit:\n");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
{
nnode=(struct stack*)malloc(sizeof(struct stack));
scanf("%d",&data);
nnode->data=data,nnode->next=NULL;
if(top==NULL)
top=nnode;
else
{
nnode->next=top;
top=nnode;
}
}
printf("1.push  2.pop  3.display 4.count 5.exit \n");
do
{
printf("enter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:count();
break;
case 5:printf("exit");
break;
default:printf("invalid choice!");
}
}while(ch!=4);
getch();
return 0;
}

