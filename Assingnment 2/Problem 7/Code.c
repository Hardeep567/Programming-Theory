#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int horizontal(int, int, char[6][5], char[7], int, int);
int vertical(int, int, char[6][5], char[7], int, int);

int main()
{
    srand(time(NULL));
    char mat[6][5];
    char guess[7];
    char Quit[4];
    int found = 1;
    int score = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char x = 'A' + (rand() % 26);
            mat[i][j] = x;
        }
    }

    mat[5][0] = '0';
    mat[5][1] = '6';
    mat[5][2] = '5';
    mat[5][3] = '3';


    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("     %c ", mat[i][j]);
        }
        printf("\n\n");
    }

    do
    {
        printf("Search String: ");
        scanf("%s", guess);
        int len = strlen(guess);
        found = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (mat[i][j] == guess[0])
                {
                    found = horizontal(i, j, mat, guess, found, len);
                    if (found == 1)
                    {
                        score++;
                        printf("%s is present\n", guess);
                        printf("Score: %d", score);
                        break;
                        found = 0;
                    }
                    found = vertical(i, j, mat, guess, found, len);
                    if (found == 1)
                    {
                        score++;
                        printf("%s is present\n", guess);
                        printf("Score: %d", score);
                        break;
                        found = 0;
                    }
                }
            }

            if (found == 1)
            {
                break;
            }
        }

        if (found == 0)
        {
            score--;
            printf("%s is not present\n", guess);
            printf("Score: %d", score);
        }

        printf("\nplay: for keep going, end: for ending  ");
        scanf("%s", Quit);
        if(strcmp(Quit,"Play") !=0 && strcmp(Quit,"PLAY") !=0 && strcmp(Quit,"play") !=0 && strcmp(Quit, "end") != 0 && strcmp(Quit, "END") != 0 && strcmp(Quit, "End") != 0){
            printf("Invalid input...");
            return 1; 
        }
    } while (strcmp(Quit, "end") != 0 && strcmp(Quit, "END") != 0 && strcmp(Quit, "End") != 0);

    return 0;
}

int horizontal(int i, int j, char mat[6][5], char guess[7], int found, int len)
{
    for (int h = 0; h < len; h++)
    {
        if (j + h < 5)
        {
            if (mat[i][j + h] != guess[h])
            {
                found = 0;
                return found;
            }
            
        }
        else{
            found = 0;
            return found;
        }
    }
    found = 1;
    return found;
}
int vertical(int i, int j, char mat[6][5], char guess[7], int found, int len)
{
    for (int h = 0; h < len; h++)
    {
        if (i + h < 6)
        {
            if (mat[i + h][j] != guess[h])
            {
                found = 0;
                return found;
            }
        }else{
            found = 0;
            return found;
        }
    }
    
    found = 1;
    return found;
}
