#include<stdio.h>

int main() {
    int num, i, j;

    printf("Enter any number: ");
    scanf("%d", &num);// Input From user
    
    /*
    Printing the Upper part of star
    */
    for (i = 1; i <= num-1; i++) {
        for (j= 1;  j<= (num-i) * 2; j++) {
            printf(" ");//Space print
        }
        printf("*");// Star print
        if (i> 1) {
            for (j= 1; j<= (i-1) * 2 - 1; j++) {
                printf(" ");//Innerspace print
            }
            printf("*");// Star print
        }
        printf("\n");
    }
    /*
    Printing the middle line of star
    */
    for (j= 1; j<= num; j++){
        printf("*");// Star print
    }
    for (j= 1; j<= (num-1) * 2 - 1; j++){
        printf(" ");//Inner space print 
    }
    for (j= 1; j<= num; j++){
        printf("*");//star print
    }
    printf("\n");
    /*
    Printing the lower part of star
    */
    for (i= num - 1; i>= 1; i--) {
        for (j= 1; j<= (num-i); j++) {
            printf("  ");//Outer Space
        }
        printf("*");// Star print
        for (j= 1; j<= (i-1) * 2 - 1; j++) {
            printf(" ");//Inner Space
        }
        if (i> 1) {
            printf("*");// Star print
        }
        printf("\n");
    }
    return 0;
}
