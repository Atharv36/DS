#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char post[40],t[30];
int stack[30],i,j,top=-1,op1,op2,n;
int main(){
    printf("Enter Postfix");
    gets(post);
    for(i=0;post[i]!='\0';i++){
        j=0;
        if(post[i]==' '){
        continue;
        }
        if(post[i]=='+' ||post[i]=='-' ||post[i]=='*' ||post[i]=='/' ||post[i]=='%' ||post[i]=='^'){
            op2=stack[top--];
            op1=stack[top--];
            switch(post[i]){
                case '+':  stack[++top]=op1+op2;break;
                case '-':  stack[++top]=op1-op2;break;
                case '*':  stack[++top]=op1*op2;break;
                case '/':  stack[++top]=op1/op2;break;
                case '%':  stack[++top]=op1%op2;break;
                case '^':  stack[++top]=pow(op1,op2);break;
            }
        }
        else{
            while(post[i]==' ' && post[i]!='\0'){
                t[j++]=post[i++];
            }
            t[j]='\0';
            n=atoi(t);
            stack[++top]=n;
        }
    }
    printf("%d",stack[top]);
return 0;
}