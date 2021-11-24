#include<stdio.h>
#include<string.h>
void example(char acWelcome[]){
    printf("%d",sizeof(acWelcome));
 
}
int main(){
    char acWelcome[]="Hello";
    printf("%d", sizeof(acWelcome));
    printf("%d", strlen(acWelcome));
    //example(acWelcome);
    return 0;
}