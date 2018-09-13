#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BST* insert(struct BST *,int);
void inorder(struct BST *);
void preorder(struct BST *);
void postorder(struct BST *);

struct BST
{
   int data;
   struct BST *left;
   struct BST *right;
};

int main()
{
   struct BST *root;
   int ch,data;
   root=NULL;
   while(1)
   {
	//clrscr();
	printf("1) INSERT\n2) INORDER\n3) PREORDER\n4) POSTORDER\n5) EXIT\n\n");
	printf("Enter your choice ");
	scanf("%d",&ch);
	switch(ch)
	{

	     case 1: printf("Enter data:");
		     scanf("%d",&data);
		     root=insert(root,data);
		     break;
	     case 2: inorder(root);
		     getch();
		     break;
	     case 3: preorder(root);
		     getch();
		     break;
	     case 4: postorder(root);
		     getch();
		     break;
	     case 5: exit(0);
	     default: printf("wrong input!!!");
	}
   }
   return 0;
}


struct BST* insert(struct BST *root,int data)
{
    struct BST *temp,*ptr,*p;
    temp=(struct BST*)malloc(sizeof(struct BST));
    if(temp==NULL)
    {
	  printf("Memory not available");
    }
    else
    {
	  temp->data=data;
	  temp->left=NULL;
	  temp->right=NULL;
	  if(root==NULL)
	  {
		 root=temp;
	  }
	  else
	  {
		 ptr=root;
		 while(ptr!=NULL)
		 {
		       if(ptr->data==data)
		       {
			      printf("%d is already in the tree",data);
			      return root;
		       }
		       else if(ptr->data<data)
		       {
			     p=ptr;
			     ptr=ptr->right;
		       }
		       else
		       {
			     p=ptr;
			     ptr=ptr->left;
		       }
		 }
		 if(p->data>data)
		 {
		      p->left=temp;
		 }
		 else
		 {
		      p->right=temp;
		 }
	    }
      }
   return root;
}


void inorder(struct BST *root)
{
     if(root!=NULL)
     {
	  inorder(root->left);
	  printf("%d ",root->data);
	  inorder(root->right);
     }
}

void preorder(struct BST *root)
{
     if(root!=NULL)
     {
	  printf("%d ",root->data);
	  preorder(root->left);
	  preorder(root->right);
     }
}

void postorder(struct BST *root)
{
     if(root!=NULL)
     {
	  preorder(root->left);
	  preorder(root->right);
	  printf("%d ",root->data);
     }
}

