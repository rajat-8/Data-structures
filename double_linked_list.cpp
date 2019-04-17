// This is a menu driven program for Linear and circular double Linked List 

// This conatins different operations for inserting and deletio of data

#include<iostream>
#include<cstdlib>
using namespace std;

// funtion prototype declaration
//linear linked list functions
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

//circular linked list functions
void ccreate();
void cdisplay();
void cinsert_begin();
void cinsert_end();
void cinsert_pos();
void cdelete_begin();
void cdelete_end();
void cdelete_pos();

struct node
{
        int info;
        struct node *next;
        struct node *prev;
};
struct node *start=NULL;
int main()
{       int choic;
        cout<<"***1. FOR LINEAR DOUBLE LINKED LIST***\n";
        cout<<"***2. FOR CIRCULAR DOUBLE LINKED LIST***\n";
        cin>>choic;
        switch(choic)
        {
          case 1:
              int choice;
              while(1){
                      cout<<"\n***DOUBLE LINKED LIST OPERATIONS:****\n";
                      cout<<"\n                MENU                             \n";
                      cout<<"---------------------------------------\n";
                      cout<<"\n 1.Create     \n";
                      cout<<"\n 2.Display    \n";
                      cout<<"\n 3.Insert at the beginning    \n";
                      cout<<"\n 4.Insert at the end  \n";
                      cout<<"\n 5.Insert at specified position       \n";
                      cout<<"\n 6.Delete from beginning      \n";
                      cout<<"\n 7.Delete from the end        \n";
                      cout<<"\n 8.Delete from specified position     \n";
                      cout<<"\n 9.Exit       \n";
                      cout<<"\n--------------------------------------\n";
                      cout<<"Enter your choice:\t";
                      cin>>choice;
                      switch(choice)
                      {
                              case 1:
                                              create();
                                              break;
                              case 2:
                                              display();
                                              break;
                              case 3:
                                              insert_begin();
                                              break;
                              case 4:
                                              insert_end();
                                              break;
                              case 5:
                                              insert_pos();
                                              break;
                              case 6:
                                              delete_begin();
                                              break;
                              case 7:
                                              delete_end();
                                              break;
                              case 8:
                                              delete_pos();
                                              break;
                              case 9:
                                              exit(0);
                                              break;
                              default:
                                              printf("\n Wrong Choice:\n");
                                              break;
                      }
                    }

          case 2:
          while(1){
                  cout<<"\n***CIRCULAR DOUBLE LINKED LIST OPERATIONS:****\n";
                  cout<<"\n                MENU                             \n";
                  cout<<"---------------------------------------\n";
                  cout<<"\n 1.Create     \n";
                  cout<<"\n 2.Display    \n";
                  cout<<"\n 3.Insert at the beginning    \n";
                  cout<<"\n 4.Insert at the end  \n";
                  cout<<"\n 5.Insert at specified position       \n";
                  cout<<"\n 6.Delete from beginning      \n";
                  cout<<"\n 7.Delete from the end        \n";
                  cout<<"\n 8.Delete from specified position     \n";
                  cout<<"\n 9.Exit       \n";
                  cout<<"\n--------------------------------------\n";
                  cout<<"Enter your choice:\t";
                  cin>>choice;
                  switch(choice)
                  {
                          case 1:
                                          ccreate();
                                          break;
                          case 2:
                                          cdisplay();
                                          break;
                          case 3:
                                          cinsert_begin();
                                          break;
                          case 4:
                                          cinsert_end();
                                          break;
                          case 5:
                                          cinsert_pos();
                                          break;
                          case 6:
                                          cdelete_begin();
                                          break;
                          case 7:
                                          cdelete_end();
                                          break;
                          case 8:
                                          cdelete_pos();
                                          break;
                          case 9:
                                          exit(0);
                                          break;
                          default:
                                          printf("\n Wrong Choice:\n");
                                          break;
                  }
                }

        }

        return 0;
}


///LINEAR LINKED LIST
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the data value for the node:\t";
        cin>>temp->info;
        temp->next=NULL;
        temp->prev=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
                temp->prev=ptr;
        }
}
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                cout<<"\nList is empty:\n";
                return;
        }
        else
        {
                ptr=start;
                cout<<"\nThe List elements are:\n";
                while(ptr!=NULL)
                {
                        cout<<ptr->info ;
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the data value for the node:\t" ;
        cin>>temp->info;
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
                temp->prev=NULL;
        }
        else
        {
                temp->next=start;
                start=temp;
                temp->prev=NULL;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the data value for the node:\t" ;
        cin>>temp->info;
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
                temp->prev=ptr;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the position for the new node to be inserted:\t";
        cin>>pos;
        cout<<"\nEnter the data value of the node:\t";
        cin>>temp->info;
        temp->next=NULL;
        temp->prev=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++)
                {
                        ptr=ptr->next;

                }
                temp->next =ptr->next ;
                temp->prev=ptr;
                ptr->next=temp;

        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                cout<<"\nList is Empty:\n";
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                start->prev=NULL;
                cout<<"\nThe deleted element is : "<<ptr->info;
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                cout<<"\nList is Empty:";
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                cout<<"\nThe deleted element is:\t"<<ptr->info;
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                cout<<"\nThe deleted element is:\t"<<ptr->info;
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                cout<<"\nThe List is Empty:\n";
                exit(0);
        }
        else
        {
                cout<<"\nEnter the position of the node to be deleted:\t";
                cin>>pos;
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        start->prev=NULL;
                        cout<<"\nThe deleted element is:\t"<<ptr->info;
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++)
                        {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        cout<<"\nPosition not Found:\n";
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        ptr->next->prev=temp;
                        cout<<"\nThe deleted element is:\t"<<ptr->info;
                        free(ptr);
                }
        }
}


// CIRCULAR LL

void ccreate()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the data value for the node:\t";
        cin>>temp->info;
        temp->next=NULL;
        temp->prev=NULL;
        if(start==NULL)
        {
                start=temp;
                temp->next=start;
                temp->prev=start;
        }
        else
        {
                ptr=start;
                while(ptr->next!=start)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
                temp->next=start;
                temp->prev=ptr;
                start->prev=temp;
        }
}
void cdisplay()
{
        struct node *ptr;
        if(start==NULL)
        {
                cout<<"\nList is empty:\n";
                return;
        }
        else
        {
                ptr=start;
                cout<<"\nThe List elements are:\n";
                cout<<ptr->info<<"\t";
                ptr=ptr->next ;
                while(ptr!=start)
                {
                        cout<<ptr->info<<"\t" ;
                        ptr=ptr->next ;
                }
        }
}
void cinsert_begin()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the data value for the node:\t" ;
        cin>>temp->info;
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
                temp->next=start;
                temp->prev=start;
        }
        else
        {     ptr=start;
              while(ptr->next!=start)
              {
                  ptr=ptr->next;
              }
                temp->next=start;
                start->prev=temp;
                start=temp;
                start->prev=ptr;
                ptr->next=start;
        }
}
void cinsert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the data value for the node:\t" ;
        cin>>temp->info;
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
                start->next=start;
                start->prev=start;
        }
        else
        {
                ptr=start;
                while(ptr->next !=start)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
                temp->prev=ptr;
                ptr=ptr->next;
                ptr->next=start;
                start->prev=ptr;
        }
}
void cinsert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));

        cout<<"\nEnter the position for the new node to be inserted:\t";
        cin>>pos;
        cout<<"\nEnter the data value of the node:\t";
        cin>>temp->info;

        temp->next=NULL;
        temp->prev=NULL;
        if(pos==0)
        {
          while(ptr->next!=start)
              {
                  ptr=ptr->next;
              }
                temp->next=start;
                start->prev=temp;
                start=temp;
                start->prev=ptr;
                ptr->next=start;
        }
        else
        {       ptr=start;
                for(i=0;i<pos-1;i++)
                {
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                cout<<"\nPosition not found \n";
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next->prev=temp;
                ptr->next=temp;
                temp->prev=ptr;
        }
}
void cdelete_begin()
{
        struct node *ptr,*ptr1;
        if(ptr==NULL)
        {
                cout<<"\nList is Empty:\n";
                return;
        }
        else
        {       while(ptr1->next!=start)
                {
                      ptr1=ptr1->next;
                }
                ptr=start;
                start=start->next ;
                start->prev=ptr1;
                ptr1->next=start;
                cout<<"\nThe deleted element is : "<<ptr->info;
                free(ptr);
        }
}
void cdelete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                cout<<"\nList is Empty:\n";
                exit(0);
        }
        else if(start->next ==start)
        {
                ptr=start;
                start=NULL;
                cout<<"\nThe deleted element is:\t"<<ptr->info;
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=start)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=start;
                start->prev=temp;
                cout<<"\nThe deleted element is:\t"<<ptr->info;
                free(ptr);
        }
}
void cdelete_pos()
{
        int i,pos;
        struct node *temp,*ptr,*ptr1;
        if(start==NULL)
        {
                cout<<"\nThe List is Empty:\n";
                exit(0);
        }
        else
        {
                cout<<"\nEnter the position of the node to be deleted:\t";
                cin>>pos;
                if(pos==0)
                {       while(ptr1->next!=start)
                        {
                              ptr1=ptr1->next;
                        }
                        ptr=start;
                        start=start->next;
                        start->prev=ptr1;
                        ptr1->next=start;
                        cout<<"\nThe deleted element is:\t"<<ptr->info;
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++)
                        {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        cout<<"\nPosition not Found:\n";
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        ptr->next->prev=temp;
                        cout<<"\nThe deleted element is:\t"<<ptr->info;
                        free(ptr);
                }
        }
}
