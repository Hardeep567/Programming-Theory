#include<stdio.h>

int main() {
    int num, i, j;

    printf("Enter any number: ");
    scanf("%d", &num);
    for (i = 1; i <= num-1; i++) {
        for (j= 1;  j<= (num-i) * 2; j++) {
            printf(" ");
        }
        printf("*");
        if (i> 1) {
            for (j= 1; j<= (i-1) * 2 - 1; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    for (j= 1; j<= num; j++){
        printf("*");
    }
    for (j= 1; j<= (num-1) * 2 - 1; j++){
        printf(" ");
    }
    for (j= 1; j<= num; j++){
        printf("*");
    }
    printf("\n");
    for (i= num - 1; i>= 1; i--) {
        for (j= 1; j<= (num-i); j++) {
            printf("  ");
        }
        printf("*");
        for (j= 1; j<= (i-1) * 2 - 1; j++) {
            printf(" ");
        }
        if (i> 1) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
