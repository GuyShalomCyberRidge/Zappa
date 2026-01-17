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
    char *str = calloc(20, 1); // Like malloc but also initialize memory allocated.
    strcpy(str, "Before change");

    char *str_ptr = str; // == &str[0] // We don't point to the entire array like so: char (*)[8]ptr
    printf("Value: %s (%p - %lu)\n", str, str_ptr, strlen(str));

    change_str_and_resize(str, "CHANGED! NEW DATA NEW DATA");
    str_ptr = str;

    printf("New value: %s (%p - %lu)\n", str_ptr, str_ptr, strlen(str_ptr));

    free(str);
}
