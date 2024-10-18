#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
struct node 
{ 
int info; 
struct node *ref; 
}; 
typedef struct node Node; 
Node *nnode,*temp=NULL,*head=NULL,*t1; 
int n,ch,data,i,pos; 
 
void create() 
{ 
printf("Enter Limit:"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
nnode=(Node*)malloc(sizeof(Node)); 
printf("Enter Data:"); 
scanf("%d",&data); 
nnode->info=data; 
nnode->ref=NULL; 
if(head==NULL) 
temp=head=nnode; 
else 
{ 
temp->ref=nnode; 
temp=nnode; 
} 
} 
} 
 
void display() 
{ 
printf("Linked List:"); 
t1=head; 
while(t1!=NULL) 
{ 
printf("%d->",t1->info); 
t1=t1->ref; 
} 
printf("NULL"); 
} 
 
 
void insertbegin() 
{ 
nnode=(Node*)malloc(sizeof(Node)); 
printf("Enter Data:"); 
scanf("%d",&data); 
nnode->info=data; 
nnode->ref=head; 
head=nnode; 
n++; 
} 
 
void insertend() 
{ 
int data; 
nnode=(Node*)malloc(sizeof(Node)); 
printf("Enter Data:"); 
scanf("%d",&data); 
nnode->info=data; 
nnode->ref=NULL; 
t1=head; 
while(t1->ref!=NULL) 
{ 
t1=t1->ref; 
} 
t1->ref=nnode; 
} 
 
void insertpos() 
{ 
int c=0; 
nnode=(Node*)malloc(sizeof(Node)); 
printf("Enter Data:"); 
scanf("%d",&data); 
nnode->info=data; 
nnode->ref=NULL; 
printf("Enter Position to insert:"); 
scanf("%d",&pos); 
if(pos==1) 
{ 
head->ref=nnode; 
head=nnode; 
} 
t1=head; 
while(c<pos-1) 
{ 
temp=t1; 
t1=t1->ref; 
c++; 
} 
nnode->ref=t1; 
temp->ref=nnode; 
n++; 
} 
 
void deletefirst() 
{ 
if(head==NULL) 
printf("Empty List"); 
temp=head; 
head=head->ref; 
free(temp); 
printf("Deleted"); 
n--; 
} 
 
void deleteend() 
{ 
int c=0; 
t1=head; 
while(c<n-1) 
{ 
temp=t1; 
t1=t1->ref; 
c++; 
} 
temp->ref=NULL; 
free(t1); 
n--; 
} 
 
void deletefrompos() 
{ 
int c=0; 
printf("Enter pos"); 
scanf("%d",&pos); 
if(pos==1) 
{ 
if(head==NULL) 
printf("Empty List"); 
temp=head; 
head=head->ref; 
free(temp); 
printf("Deleted"); 
n--; 
} 
else 
{ 
t1=head; 
while(c<pos-1) 
{ 
temp=t1; 
t1=t1->ref; 
c++; 
} 
temp->ref=t1->ref; 
n--; 
} 
} 
 
int main() 
{ 
int ch,subCh; 
clrscr(); 
do { 
 printf("\n1) Create\n2) Display\n3) Insertion\n4) Deletion\n9) Exit\n"); 
 printf("Enter Choice: "); 
 scanf("%d", &ch); 
 
 switch (ch) { 
     case 1: 
  create(); 
  break; 
     case 2: 
  display(); 
  break; 
     case 3: 
  printf("\nSubmenu for Insertion:\n1) Insert at Beginning\n2) Insert at End\n3) Insert at Position\n"); 
  printf("Enter Sub Choice: "); 
  scanf("%d", &subCh); 
  switch (subCh) { 
      case 1: insertbegin(); break; 
      case 2: insertend(); break; 
      case 3: insertpos(); break; 
      default: printf("Invalid choice\n"); 
  } 
  break; 
     case 4: 
  printf("\nSubmenu for Deletion:\n1) Delete from Beginning\n2) Delete from End\n3) Delete from Position\n"); 
  printf("Enter Sub Choice: "); 
  scanf("%d", &subCh); 
  switch (subCh) { 
      case 1: deletefirst(); break; 
      case 2: deleteend(); break; 
      case 3: deletefrompos(); break; 
      default: printf("Invalid choice\n"); 
  } 
  break; 
     case 9: 
  printf("Exit\n"); 
  break; 
     default: 
  printf("Invalid choice\n"); 
 } 
    } while (ch != 9); 
getch(); 
return 0; 
}