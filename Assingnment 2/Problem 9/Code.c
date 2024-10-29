#include <stdio.h>
void print(char grid[5][5], int i,int j){
    int z,k;
    for(z=0;z<5;z++){
    printf("|");
    for(k=0;k<5;k++){
        if(z==i && k==j){
            grid[z][k]='P';
        }
        else if(grid[z][k]=='P')grid[z][k]=' ';
        printf(" %c |", grid[z][k]);
    }
    printf("\n");
}
}
int main() {
   char grid[5][5] = {
{' ', ' ', 'I', 'X', ' '},
{' ', 'X', ' ', ' ', ' '},
{'I', ' ', 'X', 'X', ' '},
{' ', ' ', ' ', 'I', 'X'},
{' ', 'X', ' ', ' ', 'P'}
};
for(int i=0;i<5;i++){
    printf("|");
    for(int j=0;j<5;j++){
        printf(" %c |", grid[i][j]);
    }
    printf("\n");
}
char n;
int i=4,j=4,point=0;
do{
printf("\nMoves for games\nW: up\nS: down\nA: left\nD: right\nQ: quit\n");
scanf(" %c", &n);
switch(n){
    case 'W':
    if(i==0){
        printf("Sorry Not possible");
        break;
    }
    i--;
    if (grid[i][j]=='X'){
        printf("Not Poosible Move");
        i++;
        break;
    }
    if(grid[i][j]=='I')point++;
    print(grid,i,j);

    break;
    case 'S':
    if(i==4){
        printf("sorry not possible:");
        break;
    }
    i++;
    if (grid[i][j]=='X'){
        printf("Not Poosible Move");
        i--;
        break;
    }
    if(grid[i][j]=='I')point++;
    print(grid,i,j);
   
    break;
    case 'D':
    if(j==4){
        printf("sorry not possible:");
        break;
    }
    j++;
    if (grid[i][j]=='X'){
        printf("Not Poosible Move");
        j--;
        break;
    }
    if(grid[i][j]=='I')point++;
    print(grid,i,j);

    break;
    case 'A':
    if(j==0){
        printf("sorry not possible:");
        break;
    }
    j--;
    if (grid[i][j]=='X'){
        printf("Not Poosible Move");
        j++;
        break;
    }
     if(grid[i][j]=='I')point++;
    print(grid,i,j);
    break;
    default:
    if(n=='Q')printf("Thanks For Playing game");
    else printf("Move is not avaible");
    break;
}
}while(n!='Q');
printf("\nYour points: %d", point);

    return 0;
}
