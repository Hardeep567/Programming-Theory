#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[]) {
    int count[26] = {0}; 


    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i] - 'a']++; 
        
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i] - 'a']--;  
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return 0;
    }
    
    return 1; 
}

void groupAnagrams(char transactions[1000][100], int size) {
    int used[1000] = {0}; 
    
    for (int i = 0; i < size; i++) {
        if (used[i]) continue;
        
        printf("[");
        for (int j = i; j < size; j++) {
            if (!used[j] && areAnagrams(transactions[i], transactions[j])) { //eat
                printf(" %s", transactions[j]);
                used[j] = 1; 
            }
        }
        printf(" ]\n");
    }
}

int main() {
    char transactions[1000][100];
    int size;

    printf("Enter number of transactions: ");
    scanf("%d", &size);
    
    printf("Enter the transactions:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s", transactions[i]);
    }

    printf("Grouped anagrams:\n");
    groupAnagrams(transactions, size); 
    return 0;
}
