#include<stdio.h>
#include<stdlib.h>
void create();
void insert_Head();
void insert_End();
void insert_Pos();
void delete_Head();
void delete_End();
void delete_Pos();
void display();
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct  node *head,*newNode,*tail;
struct node *temp;
 static int size=0;

void main()
{
    int a,choice;
    do{
        printf("\n 1.create\n 2.display\n 3.insert at head\n 4.insert at end\n 5.insert at a particular position\n 6.delete at head\n 7.delete at end\n 8.delete at a particular position\n 9.exit\n");
        scanf("%d",&a);
        if(a==1)
        create();
        else if(a==2)
        display();
        else if(a==3)
        insert_Head();
        else if(a==4)
        insert_End();
        else if(a==5)
        insert_Pos();
        else if(a==6)
        delete_Head();
        else if(a==7)
        delete_End();
        else if(a==8)
        delete_Pos();
        else if(a==9)
        printf("\nExit point\n");
        else printf("invalid");
        
        
        
    }while(a!=9);
}

void create(){
    
    
    
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newNode->data);
        newNode->next = 0;
        newNode->prev = 0;
        if (head == 0)
            {
                head = tail = newNode;
            }
        else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

        
    
    size++;
}

void insert_Head(){
    
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&newNode->data);
    newNode->next=0;
    newNode->prev=0;
    if(head==0)
    {
        head=tail=newNode;
    }
    else{
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
    }
    size++;

}
void insert_End(){
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&newNode->data);
    newNode->next=0;
    newNode->prev=0;
    if(tail==0)
    {
        head=newNode;
        tail=newNode;
    }
    else{
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
    }
    size++;

}
void insert_Pos(){
    int i=1,pos;
    
    

        printf("Enter a position to insert new node.\nHead:0,Tail=%d\n",size);
        
        scanf("%d",&pos);
        if(pos<0|| pos>size)
        printf("Invalid\n");
        if(pos==0)
            insert_Head();
        else if(pos==size)
        insert_End();    
        else{
            temp=head;
            newNode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the data\n");
            scanf("%d",&newNode->data);
            

        while(i<pos-1)
        {
            temp=temp->next;
            i++;

        }
       
        newNode->next=temp->next;
        temp->next=newNode;
        (temp->next)->prev=newNode;
        newNode->prev=temp;
        size++;

    }

}
void delete_Head(){
    
    if(head==0)
    printf("Linked List is empty");
    else{
        printf("\nDeleted Node is: %d\n",head->data);
        temp=head;
        head=head->next;
        if(head!=0)
        head->prev=0;
        else
        tail=0;
        free(temp);
        size--;
    }    
}
void delete_End(){
    if(tail==0)
    printf("Linked list is empty");
    else{
        temp=tail;
        printf("Deleted node is: %d",temp->data);
        
        tail=tail->prev;
        if(tail==0)
        head==0;
        else
        tail->next=0;
        free(temp);
        size--;

    }
}
void delete_Pos(){
    int pos,i=1;
    

    
        printf("Enter the position to delete a node.\nHead:0,Tail=%d\n",size-1);
    
        scanf("%d",&pos);
        
        if(pos<0||pos>size)
        printf("\nInvalid\n");
        else if(pos==0)
        delete_Head();
        else if(pos==size-1)
        delete_End();
        else{
            temp=head;
            while(i<pos){
                temp=temp->next;
                i++;
            }
            printf("Deleted node is: %d",temp->data);
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
            free (temp);
            size--;
        }
    
}


void display(){
    if(head==0)
    printf("\nLinked List is Empty\n");
    else{
        printf("\n.................\n");
        printf("\nLinked List is:\n");
    temp = head;
    while (temp != 0)
        {
                printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n.................\n");
    }
}
