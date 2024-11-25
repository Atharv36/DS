#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct day{
    int date;
    char *dayname;
    char *activity;
};
struct day create(){
    struct day newday;
    newday.dayname=(char *)malloc(7*sizeof(char));
    newday.activity=(char *)malloc(50*sizeof(char));
    printf("\nEnter day name\n");
    scanf("%s",newday.dayname);
    printf("\nEnter date:");
    scanf("%d",&newday.date);
    getchar();
    printf("\nEnter activity\n");
    gets(newday.activity);
    return newday;
}
void read(struct day calendar[],int newdays){
    for(int i=0;i<newdays;i++){
        printf("\nEnter details for day %d\n",i+1);
        calendar[i]=create();
    }
}
void display(struct day calendar[],int numdays){
    printf("\nWeeks activity\n");
    for(int i=0;i<numdays;i++){
        printf("Day: %s ,Date: %d , Activity: %s\n",calendar[i].dayname,calendar[i].date,calendar[i].activity);
    }
}
int main(){
    int numDays=7;
    struct day calendar[7];
    read(calendar,numDays);
    display(calendar,numDays);
    
    for(int i=0;i<numDays;i++){
        free(calendar[i].dayname);
        free(calendar[i].activity);
    }
return 0;
}

