#include <stdio.h>
#include <stdlib.h>

void addsupplies(char **arr, int numofspecies, int numofsupplies, int isNew) {
    if (isNew == 0) {
        for (int i = 0; i < numofspecies; i++) {
            for (int j = 0; j < numofsupplies; j++) {
                printf("Enter the supply FIRST LETTER (e.g., F for Food) for species %d, supply %d: ", i + 1, j + 1);
                scanf(" %c", &arr[i][j]);
            }
        }
    } else {
        for (int j = 0; j < numofsupplies; j++) {
            printf("Enter the supply FIRST LETTER (e.g., F for Food) for new species, supply %d: ", j + 1);
            scanf(" %c", &arr[numofspecies][j]);
        }
    }
}

void updatesupplies(char **arr, int numofspecies, int numofsupplies, int species) {
    for (int j = 0; j < numofsupplies; j++) {
        printf("Enter the updated supply FIRST LETTER (e.g., F for Food) for species %d, supply %d: ", species + 1, j + 1);
        scanf(" %c", &arr[species][j]);
    }
}

void removethedata(char **arr, int *numofspecies, int species) {
    free(arr[species]);
    for (int i = species; i < *numofspecies - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*numofspecies)--;
}

void display(char **arr, int numofspecies, int numofsupplies) {
    for (int i = 0; i < numofspecies; i++) {
        printf("Species %d supplies: ", i + 1);
        for (int j = 0; j < numofsupplies; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char **arr = NULL;
    int numofspecies = 0, numofsupplies = 0;
    int option, species;

    do {
        printf("\nMenu:\n");
        printf("1. Add supplies\n");
        printf("2. Update supplies\n");
        printf("3. Remove species\n");
        printf("4. Display all supplies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (numofspecies == 0) {
                    printf("Enter the number of species: ");
                    scanf("%d", &numofspecies);
                    printf("Enter the number of supplies per species: ");
                    scanf("%d", &numofsupplies);

                    arr = (char **)malloc(numofspecies * sizeof(char *));
                    for (int i = 0; i < numofspecies; i++) {
                        arr[i] = (char *)malloc(numofsupplies * sizeof(char));
                    }
                    addsupplies(arr, numofspecies, numofsupplies, 0);
                } else {
                    arr = (char **)realloc(arr, (numofspecies + 1) * sizeof(char *));
                    arr[numofspecies] = (char *)malloc(numofsupplies * sizeof(char));
                    addsupplies(arr, numofspecies, numofsupplies, 1);
                    numofspecies++;
                }
                break;

            case 2:
                if (numofspecies == 0) {
                    printf("No species to update. Please add supplies first.\n");
                } else {
                    printf("Enter the species number to update (1 to %d): ", numofspecies);
                    scanf("%d", &species);
                    if (species < 1 || species > numofspecies) {
                        printf("Invalid species number.\n");
                    } else {
                        updatesupplies(arr, numofspecies, numofsupplies, species - 1);
                    }
                }
                break;

            case 3:
                if (numofspecies == 0) {
                    printf("No species to remove. Please add supplies first.\n");
                } else {
                    printf("Enter the species number to remove (1 to %d): ", numofspecies);
                    scanf("%d", &species);
                    if (species < 1 || species > numofspecies) {
                        printf("Invalid species number.\n");
                    } else {
                        removethedata(arr, &numofspecies, species - 1);
                        printf("Species %d removed.\n", species);
                    }
                }
                break;

            case 4:
                if (numofspecies == 0) {
                    printf("No data to display. Please add supplies first.\n");
                } else {
                    display(arr, numofspecies, numofsupplies);
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);


    for (int i = 0; i < numofspecies; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
