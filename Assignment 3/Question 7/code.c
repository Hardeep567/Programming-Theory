#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    float rating;
    int runtime; 
    char encoding[50];
} ContentMetadata;

int main()
{
    int numUsers, numCategories, numDevices, numContents;

    printf("Enter number of users: ");
    scanf("%d", &numUsers);
    printf("Enter number of content categories: ");
    scanf("%d", &numCategories);
    printf("Enter number of devices per user: ");
    scanf("%d", &numDevices);
    printf("Enter number of content pieces per category: ");
    scanf("%d", &numContents);


    double **engagementMatrix = (double **)malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++)
    {
        engagementMatrix[i] = (double *)malloc(numCategories * sizeof(double));
    }


    int **deviceMatrix = (int **)malloc(numUsers * sizeof(int *));
    for (int i = 0; i < numUsers; i++)
    {
        deviceMatrix[i] = (int *)malloc(numDevices * sizeof(int));
    }

    ContentMetadata ***contentMatrix = (ContentMetadata ***)malloc(numCategories * sizeof(ContentMetadata **));
    for (int i = 0; i < numCategories; i++)
    {
        contentMatrix[i] = (ContentMetadata **)malloc(numContents * sizeof(ContentMetadata *));
        for (int j = 0; j < numContents; j++)
        {
            contentMatrix[i][j] = (ContentMetadata *)malloc(sizeof(ContentMetadata));
        }
    }

    printf("\nEnter engagement scores (user x category):\n");
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numCategories; j++)
        {
            printf("User %d, Category %d engagement score: ", i, j);
            scanf("%lf", &engagementMatrix[i][j]);
        }
    }

    printf("\nEnter device preferences (user x device resolution):\n");
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numDevices; j++)
        {
            printf("User %d, Device %d resolution: ", i, j);
            scanf("%d", &deviceMatrix[i][j]);
        }
    }

    printf("\nEnter content metadata (category x content):\n");
    for (int i = 0; i < numCategories; i++)
    {
        for (int j = 0; j < numContents; j++)
        {
            printf("Category %d, Content %d:\n", i, j);
            printf("Title: ");
            getchar();
            fgets(contentMatrix[i][j]->title, 100, stdin);
            contentMatrix[i][j]->title[strcspn(contentMatrix[i][j]->title, "\n")] = '\0'; 
            printf("Rating: ");
            scanf("%f", &contentMatrix[i][j]->rating);
            printf("Runtime (in minutes): ");
            scanf("%d", &contentMatrix[i][j]->runtime);
            printf("Encoding: ");
            getchar();
            fgets(contentMatrix[i][j]->encoding, 50, stdin);
            contentMatrix[i][j]->encoding[strcspn(contentMatrix[i][j]->encoding, "\n")] = '\0';
        }
    }

    printf("\nUser Engagement Scores:\n");
    for (int i = 0; i < numUsers; i++)
    {
        printf("User %d: ", i);
        for (int j = 0; j < numCategories; j++)
        {
            printf("Category %d: %.2f ", j, engagementMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDevice Preferences (Resolution):\n");
    for (int i = 0; i < numUsers; i++)
    {
        printf("User %d: ", i);
        for (int j = 0; j < numDevices; j++)
        {
            printf("Device %d: %d ", j, deviceMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nContent Metadata:\n");
    for (int i = 0; i < numCategories; i++)
    {
        for (int j = 0; j < numContents; j++)
        {
            printf("Category %d, Content %d: Title: %s, Rating: %.1f, Runtime: %d mins, Encoding: %s\n",
                   i, j, contentMatrix[i][j]->title, contentMatrix[i][j]->rating,
                   contentMatrix[i][j]->runtime, contentMatrix[i][j]->encoding);
        }
    }

    for (int i = 0; i < numUsers; i++)
    {
        free(engagementMatrix[i]);
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);

    for (int i = 0; i < numCategories; i++)
    {
        for (int j = 0; j < numContents; j++)
        {
            free(contentMatrix[i][j]);
        }
        free(contentMatrix[i]);
    }
    free(contentMatrix);

    return 0;
}
