#include<stdio.h>
#define MAX 5
void enqueue();
void dequeue();
void display();
int c,queue[MAX],item,front=-1,rear=-1,i,n;

 void main(){
	 do
	{
		 printf("\n1)Insertion\n2)Deletion\n3)Display\n4)Exit\n");
		 scanf("%d",&c);
		 switch(c)
		{
			case 1:
				 enqueue();
	 		     break;
			case 2:
 				dequeue();
 	            break;
			case 3:
 				display();
 				break;
			case 4:
                
                printf("\nExit point\n");
 				break;
			default:
				printf("\ninvalid\n");
		}
	}while(c!=4);
}


void enqueue()
{
	if((rear+1)%MAX==front){
		printf("\nQUEUE IS FULL");
	}
	else
	{
		if(rear==-1)
		front=0;
		printf("\nEnter the element to insert : ");
		scanf("%d",&item);
		rear=(rear+1)%MAX;
		queue[rear]=item;
	}
}


void dequeue(){
 if(front==-1){
 	printf("\nQUEUE IS EMPTY");
 }
 else if(front==rear){
	printf("\nThe deleted element is:%d\n",queue[front]);
	front=rear=-1;
}
else{
	printf("\nThe deleted element is:%d\n",queue[front]);
	front=(front+1)%MAX;
}
}







void display(){
	if(front==-1){
 	printf("\nQUEUE IS EMPTY\n");
 	}
 	else{
 		printf("\n.............................\n");
	int front_pos=front,rear_pos=rear;
	if(front_pos>rear_pos){
		while(front_pos>rear_pos)
			{
				printf(" %d ",queue[front_pos]);
				front_pos=((front_pos+1))%MAX;
			}	
		
	}
	if(front_pos<=rear_pos){
		for(i=front_pos;i<=rear_pos;i++)
		printf(" %d ",queue[i]);
	}
	printf("\nrear:%d \nfront:%d",rear,front);
	printf("\n.............................\n");
	}
	
}