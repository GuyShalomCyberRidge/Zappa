#include <stdio.h>
#include <stdlib.h>
#include 

int main(){
    char singleChar = 's';
    char singleChar2 = 't';
    printf("%c\n", singleChar);
    
    char stringConst[4] = "stri"; // This overrides null termination delimiter
    printf("%s\n", stringConst);

    char stringDynamic[] = "stringDynamic";
    printf("%s\n", stringDynamic);

    return 0;
}