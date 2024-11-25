#include<stdio.h>

int main(){
    int i=0,j=0,found=0,k;
    char str[50],pat[50],rep[50],res[50];
    printf("Enter original string:");
    gets(str);
    printf("\nEnter patter string:");
    gets(pat);
    printf("\nEnter replacement string:");
    gets(rep);

    while(str[i]!='\0'){
        k=0;
        while(pat[k]!='\0' && str[i+k]==pat[k]){
            k++;
        }
        if(pat[k]=='\0'){
            found=1;
            for(k=0;rep[k]!='\0';k++){
                res[j++]=rep[k];
            }
            i+=k;
        }
        else{
            res[j++]=str[i++];
        }
    }
res[j]='\0';
if(found){
    printf("%s",res);
}
else{
    printf("pattern not found");
}
return 0;
}
