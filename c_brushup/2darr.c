#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[2][2] = {
        {1, 2},
        {3, 4}
    };

    printf("%lu\n", sizeof(num));
    return 0;
}