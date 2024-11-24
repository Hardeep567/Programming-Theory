#include<stdio.h>
#include<stdlib.h>

void addsupplies(char **arr,int numofspecies,int numofsupplies,int a){
if(a==0){
  for(int i=0;i<numofspecies;i++){
    for(int j=0;j<numofsupplies;j++){
      printf("Enter the supplies FIRST LETTER eg:F of Food");
      scanf(" %c", &arr[i][j]);
  }
    }
      }
else{
for(int j=0;j<numofsupplies;j++){
  printf("Enter the supplies FIRST LETTER eg:F of Food");
  scanf(" %c", &arr[numofspecies][j]);
  }
    }
  return ;
}

void updatesupplies(char **arr,int numofspecies,int numofsupplies,int speices){
  for(int j=0;j<numofsupplies;j++){
    printf("Enter the supplies FIRST LETTER eg:F of Food");
    scanf(" %c", &arr[speices][j]);
  }

return ;
}

void removethedata(char **arr,int numofspecies,int numofsupplies,int speices){
   
    free(arr[speices]);
    return ;  
}

void display(char **arr,int numofspecies,int numofsupplies){
    for(int i=0;i<numofspecies;i++){
      for(int j=0;j<numofsupplies;j++){
   if(arr[i][j]!=NULL && arr[i][j]>='A'  && arr[i][j]<='Z'){
        printf(" %c", arr[i][j]);
       }
    }
  }
return ;
}

int main(){
char **arr;
int numofspecies;
int numofsupplies;
int species;
int i,j=0;

do{
printf("\nEnter the \n 1. Add supplies\n 2. Update supplies \n 3. Remove The Data\n 4. Display");
scanf("%d", &i);
if(i==1){
if(j==0){
printf("Enter the number of species");
scanf("%d", &numofspecies);

printf("Enter the number of species");
scanf("%d", &numofsupplies);

arr=(char **)malloc(sizeof(char *)*numofspecies);

for(int i=0;i<numofspecies;i++)
{
  arr[i]=(char *)malloc(sizeof(char)*numofsupplies);
}
  addsupplies(arr,numofspecies,numofsupplies,0);
}
if(j>=1){
arr = (char **)realloc(arr, sizeof(char *) * (numofspecies+1));
        arr[numofspecies] = (char *)malloc(sizeof(char) * numofsupplies);

  addsupplies(arr,numofspecies,numofsupplies,1);
  numofspecies++;
  }
  j++;
}
else if(i==2){
  if(j==0){
    printf("First Add something");
  }
  else {
    printf("Enter the species");
    scanf("%d", &species);
    updatesupplies(arr,numofspecies,numofsupplies,species-1);
  }
}
else if(i==3){
  if(j==0){
    printf("First Add something");
  }  
  else {
    printf("Enter the species");
    scanf("%d", &species);
    removethedata(arr,numofspecies,numofsupplies,species-1);
  }
}
else if(i==4){
  if(j==0){
    printf("First ADD something");
  }
  else{
    display(arr,numofspecies,numofsupplies);
    }
}

  }while(i>=1 || i<=4);
  return 0;
}
