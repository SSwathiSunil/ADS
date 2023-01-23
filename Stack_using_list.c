#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void main(){
    int choice;
    do{
    printf("\nEnter the choice you want:\n");
    printf(" 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
    scanf("%d",&choice);
    if(choice==1)
    push();
    else if (choice==2)
    pop();
    else if(choice==3)
    display();
    else if(choice==4)
    choice=4;
    else
    printf("inavlid!!");
    
    
   
   
    } while(choice!=4);
    }
    struct node
    {
        int data;
        struct node *link;
    };
    struct node*top;
    void push()
    {
        int elem;
        struct node*newnode;
        printf("Enter the element to push:\n");
        scanf("%d",&elem);
        newnode=(struct node*) malloc (sizeof(struct node));
        newnode->data=elem;
        newnode->link=top;
        top=newnode;


    }
    void pop()
    {
        struct node *temp;
        temp=top;
        if(temp==0)
        printf("Underlflow");
        else{
            printf("Popped element is: %d\n",temp->data);
            top=temp->link;
            if(top==0)
            printf("Stack is empty\n");
            free(temp);
            
            
        }
    }
    void display()
    {
        struct node*temp;
        temp=top;
        if(top==0)
        printf("List is empty");
        else{
            printf("Elements are:\n");
            while(temp!=0)
            {
                printf("%d-->",temp->data);
                
                temp=temp->link;
            }
            printf("NULL");

        }
    }