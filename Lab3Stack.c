#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int stack[MAX];
int top=-1; 
void push();
void pop();
void display();
void palin();

int main(){
while(1){
    char ch;
    printf("1.Push 2.Pop 3.Display 4.Exit\n");
    printf("Enter choice");
    scanf("%d",&ch);
    switch(ch){
        case 1:push();break;
        case 2:pop();break;
        case 3:display();palin();break;
        case 4:exit(0);break;
    }
}
return 0;
}
void push(){
    int item;
    if(top>=MAX-1){
        printf("Overflow");
    }else{
    printf("Enter the item:");
    scanf("%d",&item);
    stack[++top]=item;
    }
}
void pop(){
    if(top==-1){
        printf("Underflow");
    }else{
    printf("The deleted item is %d",stack[top--]);
}}

void display(){
    if(top==-1){
        printf("Underflow");
    }
    else{
    for(int i=top;i>=0;i++){
        printf("%d ",stack[i]);
    }}
}
void palin(){
    int start=0;
    int end=top;
    while(start<=end){
        if(stack[start]==stack[end]){
        start++;end--;
    }
    else{
        printf("Not palin");break;
    }
    }
    if(start>end){
        printf("Palindrome");
    }
    
}