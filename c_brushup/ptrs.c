#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dyncamically change a string and reallocate its memory.
char* change_str_and_resize(char *str, char new_str[]){
    void *tmp = realloc(str, strlen(new_str) + 1); // New pointer assigned to tmp, NULL on failure.
    if (!tmp){
        printf("Error reallocating memory");
    } else {
        str = tmp;
    }
    strcpy(str, new_str);

    return str;
}

int main(){
    printf("INTS:\n");
    int *num = malloc(sizeof(int));
    printf("int1, %d (%p)\n", *num, num);
    *num = 500;
    printf("int1, %d (%p)\n", *num, num);

    free(num);

    int num2 = 0;
    int *num2_ptr = &num2;
    printf("int2, %d (%p)\n", num2, &num2);
    num2 = 500;
    printf("int2, %d (%p)\n\n", *num2_ptr, num2_ptr);


    printf("STRINGS:\n");
    char *str = calloc(20, 1); // Like malloc but also initialize memory allocated.
    char *str_ptr = str; // == &str[0] // We don't point to the entire array like so: char (*)[8]ptr
    strcpy(str, "Before change");
    printf("Value: %s (%p - %lu)\n", str, str_ptr, strlen(str));

    change_str_and_resize(str, "CHANGED! NEW DATA NEW DATA");
    str_ptr = str;

    printf("New value: %s (%p - %lu)\n\n", str_ptr, str_ptr, strlen(str_ptr));

    free(str);


    printf("NESTED POINTERS:\n");

    int num3 = 10;
    int *num3_ptr = &num3;
    int **num3_ptr_ptr = &num3_ptr;

    printf("(%p)\n", &num3);
    printf("(%p)\n", &num3_ptr);
    printf("(%p)\n", &num3_ptr_ptr);
    printf("Nested - %d (%p)", **num3_ptr_ptr, num3_ptr_ptr);
}
