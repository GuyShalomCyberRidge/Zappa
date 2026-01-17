#include <stdio.h>
#include <stdlib.h>

void draw_tri(int num){
    for (int i = 1; i <= num; i++){
        for (int j = 0; j < num - i; j++){
            printf(" ");
        }
        for (int j = 0; j < i+(i-1); j++){
            printf("*");
        }

        printf("\n");
    }
}


int main(){
    int height;
    printf("How tall should the triangle be (int):");
    scanf("%d", &height);

    draw_tri(height);

    return 0;
}