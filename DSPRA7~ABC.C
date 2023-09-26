#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
void preorder(struct node *temp);
void postorder(struct node *temp);
void inorder(struct node *temp);
int main()
{
int choice,val,count,min,max;
do
{
printf("**** Main Menu ***\n");
printf("1. create a binary search\n");
printf("2. Display the tree \n");
printf("3. EXIT \n");
printf("Enter your choice:");
scanf("%d",&choice);
printf("\n\n");
switch(choice)
{
case 1:root=create(root);
break;
case 2:root=display(root);
break;
case 3:break;
}
}while(choice!=3);
return 0;
}
struct node *create(struct node *root)
{
struct node *newnode=NULL,*temp=NULL,*parent=NULL;
int val;
printf("Enter the data or enter -1 to exit:");
scanf("%d",&val);
while(val!=-1)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
if(root==NULL)
{
root=newnode;
newnode->left=NULL;
newnode->right=NULL;
}
else
{
temp=root;
while(temp!=NULL)
{
parent=temp;
if(val<temp->data)
{
temp=temp->left;
}
else
{
temp=temp->right;
}
}
if(val<parent->data)
{
parent->left=newnode;
newnode->left=NULL;
newnode->right=NULL;
}
else
{
parent->right=newnode;
newnode->left=NULL;
newnode->right=NULL;
}
}
printf("Enter the data or enter -1 to exit:");
scanf("%d",&val);
}
printf("Succesfully created \n");
return root;
}
struct node *display(struct node *root)
{
int choice1;
printf("*** Display Menu***\n");
printf("1.pre-order\n");
printf("2.In-order\n");
printf("3.post-order\n");
printf("4. EXIT\n");
printf("Enter your choice :");
scanf("%d",&choice1);
switch(choice1)
{
case 1:printf("\tThe Pre-order Traveral is:");
preorder(root);
break;
case 2:printf("\tThe in order traversal is:");
inorder(root);
break;
case 3:printf("\tThe post-order traversal is:");
postorder(root);
break;
case 4:break;
}
printf("\n");
return root;
}
void preorder(struct node *temp)
{
if(temp!=NULL)
{
printf("%d",temp->data);
preorder(temp->left);
preorder(temp->right);
}
}
void postorder(struct node *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
printf("%d",temp->data);

}
}
void inorder(struct node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("%d",temp->data);
inorder(temp->right);
}
}
