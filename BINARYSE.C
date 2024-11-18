#include<stdio.h>
#include<conio.h>
struct tree
{
int data;
struct tree *right,*left;
};
typedef struct tree Tree;
int n,data;
Tree *root=NULL,*temp,*nnode,*p,*q;
void create()
{
printf("enter the root element:\n");
scanf("%d",&data);
nnode=(Tree*)malloc(sizeof(Tree));
nnode->data=data;
nnode->right=NULL;
nnode->left=NULL;
root=nnode;
}
void insertion(Tree *temp)
{
if(nnode->data<temp->data)
{
if(temp->left!=NULL)
insertion(temp->left);
else
temp->left=nnode;
}
else
{
if(temp->right!=NULL)
insertion(temp->right);
else
temp->right=nnode;
}
}
void deletion()
{
p=q=root;
printf("enter the element to be deleted:");
scanf("%d",&n);
if(p==NULL)
printf("the tree is empty\n");
if(n==root->data)
root=NULL;
else
{
while(n!=q->data && q!=NULL)
{
p=q;
if(n<p->data)
q=p->left;
else
q=p->right;
}
if(q==NULL)
printf("element not found");
else if(q->right==NULL && q->left==NULL)
{
if(p->right==q)
p->right=NULL;
else
p->left=NULL;
free(q);
}
else if(q->right!=NULL && q->left==NULL)
{
if(p->right==q)
{
p->right=q->right;
q->right=NULL;
}
else
{
p->left=q->right;
q->right=NULL;
}
free(q);
}
else if(q->right==NULL && q->left!=NULL)
{
if(p->right==q)
{
p->right=q->left;
q->left=NULL;
}
else
{
p->left=q->left;
q->left=NULL;
}
free(q);
}
else if(q->right!=NULL && q->left!=NULL)
{
temp=p=q;
q=q->left;
if(q->right ==NULL)
{
temp->data=q->data;
p->left=q->right;
}
else
{
while(p->right!=NULL)
{
p=q;
q=q->right;
}
temp->data=q->data;
p->right=NULL;
}
free(q);
}
}
}
void inorder(Tree *t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d\t",t->data);
inorder(t->right);
}
}
void preorder(Tree *t)
{
if(t!=NULL)
{
printf("%d\t",t->data);
preorder(t->left);
preorder(t->right);
}
}
void postorder(Tree *t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf("%d\t",t->data);
}
}
void find(Tree *t,int n)
{
if(t!=NULL)
{
if(t->data==n)
printf("element found\n");
else if(n<t->data)
find(t->left,n);
else
find(t->right,n);
}
else
printf("element not found");
}
int main(void)
{
int ch,c;
clrscr();
create();
printf("1.insertion  2.deletion  3.display  4.find 5.exit\n");
do
{
printf("enter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter the element to be inserted:");
scanf("%d",&data);
nnode=(Tree *)malloc(sizeof(Tree));
nnode->data=data;
nnode->right=NULL;
nnode->left=NULL;
temp=root;
insertion(temp);
break;
case 2:deletion();
break;
case 3:printf("1.preorder 2.inorder 3.postorder\nEnter the choice");
scanf("%d",&c);
switch(c)
{
case 1:preorder(root);
break;
case 2: inorder(root);
break;
case 3: postorder(root);
break;
default:printf("invalid");
}
break;
case 4:printf("enter the element to be searched:\n");
scanf("%d",&n);
find(root,n);
break;
case 5:printf("exit\n");
break;
default:printf("invalid choice\n");
}
}while(ch!=5);
getch();
return 0;
}