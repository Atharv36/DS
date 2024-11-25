#include<stdio.h>
#include<ctype.h>
char stack[30],in[30],post[30],ch;
int i,j,top=-1;
void push(char c);
char pop();
int priority(char c);

int main(){
printf("Enter Infix Expression:");
gets(in);
for(i=0,j=0;in[i]!='\0';i++){
    if(isalpha(in[i])){
        post[j++]=in[i];
    }
    else{
        if(in[i]=='('){
            push(in[i]);
        }
        else if(in[i]==')'){
            while((ch=pop())!='('){
                post[j++]=ch;
            }
        }
        else{
            while(priority(in[i])<=priority(stack[top])){
                post[j++]=pop();
            }
            push(in[i]);
        }
    }
}
while(top!=-1){
    post[j++]=pop();    
}
post[j]='\0';
printf("%s",post);
return 0;
}

void push(char c){
    stack[++top]=c;
}
int priority(char c){
    switch(c){
        case '+':
        case '-':return 1;
        case '*':
        case '/':
        case '%':return 2;
        case '^':return 3;
        default:return 0;

    }
}
char pop(){
    return stack[top--];
}