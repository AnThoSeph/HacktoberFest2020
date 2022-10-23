#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next,*  prev;
};



struct node* takeInput(){
    
    struct node* head=NULL;
    struct node* temp=NULL;
    int check=1;
    while(check!=0){
        int data;
        scanf("%d",&data);
        struct node* newNode= (struct node*)malloc(sizeof(struct node));
        newNode->value=data;
        newNode->next=NULL;
        newNode->prev=NULL;
        
        if(head==NULL){
            temp=head=newNode;
            
        }
        else{
            temp->next=newNode;
            newNode->prev=temp;
            temp=newNode;
        }
        printf("Do you want to take input again!! : ");
        scanf("%d",&check);
          
    }
    return head;
}
void printLinkedList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->value);
        temp=temp->next;
    }
    printf("\n");

}
struct node* insertAB(struct node* head,int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=head;
    head->prev=newNode;
    return newNode;
}

// void insertAE(struct node* head,int data){
//     struct node *temp=head;
//     struct node* newNode=(struct node*)malloc(sizeof(struct node));
//     newNode->data=data;
//     newNode->prev=NULL;
//     newNode->next=NULL;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=newNode;
//     newNode->prev=temp;
// }

void insertATPoint(struct node* head,int data,int pos){
    struct node* temp1=head;
    int count=0;
    while(temp1!=NULL){
        temp1=temp1->next;
        count++;
    }
    if(pos>count){
        printf("Invalid position for inserting the node!!");
    }
    else{

    
    struct node* temp=head;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    newNode->prev=temp;
    temp->next=newNode;
}
int main(){
	struct node* head= takeInput();
	printLinkedList(head);
    // struct node* head1=insertAB(head,100);
    // printLinkedList(head1);
    // insertAE(head,100);
    // printLinkedList(head);
    // insertATPoint(head,100,3);
    // printLinkedList(head);
	return 0;
}