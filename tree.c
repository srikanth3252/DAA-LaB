// Online C compiler to run C program online
# include<stdio.h>
# include<stdlib.h>
struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};
struct node* root=NULL;
struct node* current;
struct node* previous;
struct node* newnode;
struct node* create_node(int);
struct node* insert_bst(int);
struct node* display(struct node*);
struct node* delete_leafnode(int );
struct node* delete_nodewithonenode(int );
int n;
int main()
{  int *a;
    printf("enter the valve to n=");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("enter the elements to the array=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        insert_bst(a[i]);
    }
    printf("\nelements in tree=");
    display(root);
    int key;
    printf("\nenter the delecting valve to key=");
    scanf("%d",&key);
    delete_leafnode(key);
    printf("\nelements in tree after deleting particular node tree=");
    display(root);
        int key1;
    printf("\nenter the delecting valve which have a only one sub node to key=");
    scanf("%d",&key1);
   delete_nodewithonenode(key1 );
    printf("\nelements in tree after deleting particular node tree=");
    display(root);
    return 0;
}

struct node* create_node(int item)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->lchild=NULL;
    newnode->lchild=NULL;
    return newnode;
}

 struct node* insert_bst(int item)
{
    if(root==NULL)
    {
        root=create_node(item);
    }
    else
    {  current=root;
       previous=NULL;
       while(1)
       {
           if((current->data)>item)
           {
               previous=current;
               current=current->lchild;
               if(current==NULL)
               {
                   previous->lchild=create_node(item);
                   return root;
               }
           }
           else
           {
               previous=current;
               current=current->rchild;
               if(current==NULL)
               {
                   previous->rchild=create_node(item);
                   return root;
               }
           }
       }
        
    }
}

struct node* display(struct node* current)
{
    if(current!=NULL)
    {
        display(current->lchild);
        printf("%d ",current->data);
        display(current->rchild);
    }
    return root;
}

struct node* delete_leafnode(int key)
{
    if(root==NULL)
    {
        printf("tree is empty.");
        return root;
    }
    else
    {  
        current =root;
        previous=NULL;
        if(current->data==key)
           {
               if(((current->lchild)==NULL)&&((current->rchild)==NULL))
               {
                   current=NULL;
               }
           }
        while(1)
        {    
            if((current->data)>key)
           {  
               previous=current;
               current=current->lchild;
               if(current->data==key)
              {
                  if(((current->lchild)==NULL)&&((current->rchild)==NULL))
                {
                   previous->lchild=NULL;
                   return root;
                }
              }
           }
           else
           {
               previous=current;
               current=current->rchild;
               if(current->data==key)
              {
                  if(((current->lchild)==NULL)&&((current->rchild)==NULL))
                {
                   previous->rchild=NULL;
                   return root;
                }
              }
           }
        }
        
    }
}

struct node* delete_nodewithonenode(int key1)
{   int c;
    if(root==NULL)
    {
        printf("tree is empty.");
        return root;
    }
    else
    {  
        current =root;
        previous=NULL;
        if(current->data==key1)
           {
               if((((current->lchild)!=NULL)&&((current->rchild)==NULL))||(((current->lchild)==NULL)&&((current->rchild)!=NULL)))
               {
                   if((current->lchild)==NULL)
                   {
                       struct node* current1;
                       current1=current->rchild;
                        if(((current1->lchild)==NULL)&&((current1->rchild)==NULL))
                        {
                             c=current->data;
                       current->data=current1->data;
                       current1->data=c;
                       current->rchild=NULL;
                       return root;
                        }
                   }
                   else
                   {
                       struct node* current1;
                       current1=current->lchild;
                       if(((current1->lchild)==NULL)&&((current1->rchild)==NULL))
                      {
                           c=current->data;
                       current->data=current1->data;
                       current1->data=c;
                       current->lchild=NULL;
                       return root;
                      }
                   }
               }
           }
        while(1)
        {    
            if((current->data)>key1)
           {  
               previous=current;
               current=current->lchild;
               if(current->data==key1)
              {
                     if((((current->lchild)!=NULL)&&((current->rchild)==NULL))||(((current->lchild)==NULL)&&((current->rchild)!=NULL)))
               {
                   if((current->lchild)==NULL)
                   {
                       struct node* current1;
                       current1=current->rchild;
                        if(((current1->lchild)==NULL)&&((current1->rchild)==NULL))
                        {
                             c=current->data;
                       current->data=current1->data;
                       current1->data=c;
                       current->rchild=NULL;
                       return root;
                        }
                   }
                   else
                   {
                       struct node* current1;
                       current1=current->lchild;
                       if(((current1->lchild)==NULL)&&((current1->rchild)==NULL))
                      {
                           c=current->data;
                       current->data=current1->data;
                       current1->data=c;
                       current->lchild=NULL;
                       return root;
                      }
                   }
               }
              }
           }
           else
           {
               previous=current;
               current=current->rchild;
               if(current->data==key1)
              {
                     if((((current->lchild)!=NULL)&&((current->rchild)==NULL))||(((current->lchild)==NULL)&&((current->rchild)!=NULL)))
               {
                   if((current->lchild)==NULL)
                   {
                       struct node* current1;
                       current1=current->rchild;
                        if(((current1->lchild)==NULL)&&((current1->rchild)==NULL))
                        {
                             c=current->data;
                       current->data=current1->data;
                       current1->data=c;
                       current->rchild=NULL;
                        }
                   }
                   else
                   {
                       struct node* current1;
                       current1=current->lchild;
                       if(((current1->lchild)==NULL)&&((current1->rchild)==NULL))
                      {
                           c=current->data;
                       current->data=current1->data;
                       current1->data=c;
                       current->lchild=NULL;
                      }
                   }
               }
              }
           }
        }
        
    }
}