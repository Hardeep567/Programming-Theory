#include <stdio.h>

int main() {
    int nis;
    

    printf("Enter a non-negative integer: ");
    scanf("%d", &nis);
    
    if (nis < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    int first;
    int n;
    
    n = nis % 4; 
    nis = nis - n; 
    first = nis / 4; 

    if (first % 2 != 0) {
        if (n == 2) {
            printf("Keep the one only\n");
        } else if (n == 3) {
            printf("Keep the two only\n");
        } else if (n == 0) {
            printf("Keep the four only\n");
        } else {
            printf("You cannot ever win\n");
        }
    } else {
        if (n == 1) {
            printf("Keep the four only\n");
        } else if (n == 2) {
            printf("Keep the three only\n");
        } else if (n == 3) {
            printf("Keep the two only\n");
        } else if (n == 0) { 
            printf("Keep the one only\n");
        } else {
            printf("You cannot ever win\n");
        }
    }

    return 0;
}
