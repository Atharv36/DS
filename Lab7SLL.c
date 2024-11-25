

#include<stdio.h>
#include<stdlib.h>
int i,ch;
void insertionatfront();
void display();
void insertionatend();
void deletionatend();
void deletionatfront();
struct node{
  char usn[10],name[10],prog[10];
  int sem,phno;
  struct node *next;
} *ptr, *header, *new, *ptr1, *ptr2;
int main(){
  header = NULL;
  while(1){
    printf("\nThe menu is 1.Front Insertion.\t2.Display the status and count.\t3.Insertion at end.\t4.deletion at end.\t5.Stack operation\t6.Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1:insertionatfront();
             break;
      case 2:display();
             break;
      case 3:insertionatend();
             break;
      case 4:deletionatend();
             break;
      case 5:printf("\noperation related to stack\n");
             insertionatfront();
             display();
             deletionatfront();
             display();
             break;
      case 6:exit(0);
    }
  }
  return 0;
}
void insertionatfront(){
  new=malloc(sizeof(struct node));
  printf("Enter the Usn: ");
  scanf("%s",new->usn);
  printf("\nEnter name: ");
  scanf("%s",new->name);
  printf("\nEnter programme: ");
  scanf("%s",new->prog);
  printf("\nEnter semester: ");
  scanf("%d",&new->sem);
  printf("\nEnter phone number: ");
  scanf("%d",&new->phno);
  if(header==NULL){
     new->next=NULL;
     header=new;
   }else{
     new->next=header;
     header=new;
   }
}
void display(){
  int count=0;
  ptr=header;
  if(header==NULL){
    printf("\nlist is empty!\n");
    printf("Count is %d", count);
  }else{
    printf("Now the list elements are: ");
    while(ptr!=NULL){
      printf("USN:%s\tName:%s\tProgramme%s\tSemester%d\tPhone number%d \n",ptr->usn, ptr->name, ptr->prog, ptr->sem, ptr->phno);
      ptr=ptr->next;
      count++;
    }
      printf("\nCount is %d", count);
  }
}
void insertionatend(){
  new=malloc(sizeof(struct node));
  printf("Enter the Usn: ");
  scanf("%s",new->usn);
  printf("Enter name: ");
  scanf("%s",new->name);
  printf("Enter programme: ");
  scanf("%s",new->prog);
  printf("Enter semester: ");
  scanf("%d",&new->sem);
  printf("Enter phone number: ");
  scanf("%d",&new->phno);
  ptr=header;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next =new;
  new->next = NULL;
}
void deletionatend(){
  ptr=header;
  while(ptr->next!=NULL){
    ptr1=ptr;
    ptr=ptr->next;
  }printf("\nThe deleted element is USN:%s\tName:%s\tProgramme%s\tSemester%d\tPhone number%d \n ",ptr->usn, ptr->name, ptr->prog, ptr->sem, ptr->phno);
  ptr1->next=NULL;
}
void deletionatfront(){
  ptr=header;
  printf("\nThe deleted element is USN:%s\tName:%s\tProgramme%s\tSemester%d\tPhone number%d \n ",ptr->usn, ptr->name, ptr->prog, ptr->sem, ptr->phno);
  header = ptr->next;
}

