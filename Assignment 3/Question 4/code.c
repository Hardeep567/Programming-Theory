#include <stdio.h>
#include<stdlib.h>

void input(int**arr,int numofemployee,int numofperiod){
   
    for(int i=0;i<numofemployee;i++){
        for(int j=0;j<numofperiod;j++){
            printf("\nEnter the Rating of employee %d in Period %d between 1 and 2\n",i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    return;
}

void displayperformance(int** arr, int numofemployee,int numofperiod){
    for(int i=0;i<numofemployee;i++){
        for(int j=0;j<numofperiod;j++){
          printf("%d  ", arr[i][j]);  
        }
        printf("\n");
    }
}

int employeeofyear(int** arr, int numofemployee,int numofperiod){
    int average=0.0,s=0.0;
    int index;
    for(int i=0;i<numofemployee;i++){
        for(int j=0;j<numofperiod;j++){
          s+=arr[i][j];
        }
        if(i==0 || average<s){
            average=s;
            s=0;
            index=i;
        }
    }
    return index;
}

int periodoftime(int** arr, int numofemployee,int numofperiod){
    float average=0.0,s=0.0;
    int index;
    for(int i=0;i<numofperiod;i++){
        for(int j=0;j<numofemployee;j++){
          s+=arr[i][j];
        }
        if(i==0 || average<s){
            average=s;
            s=0;
            index=i;
        }
    }
    return index;
}

int worstemployeeofyear(int** arr, int numofemployee,int numofperiod){
    float average=0.0,s=0;
    int index;
    for(int i=0;i<numofemployee;i++){
        for(int j=0;j<numofperiod;j++){
          s+=arr[i][j];
        }
        if(i==0 || average>s){
            average=s;
            s=0;
            index=i;
        }
    }

    return index;
}

int main() {
    int **arr;
    int numofemployee;
    int numofperiod;
    printf("Enter the Number of employees ");
    scanf("%d", &numofemployee);
    printf("Enter the Evalution of time period");
    scanf("%d", &numofperiod);
   
    arr=(int **)malloc(sizeof(int *)*numofemployee);
    for(int i=0;i<numofemployee;i++){
        arr[i]=(int *)malloc(sizeof(int)*numofperiod);
    }
   
    input(arr,numofemployee,numofperiod);
   
    displayperformance(arr,numofemployee,numofperiod);
   
    int c=employeeofyear(arr,numofemployee,numofperiod);
    printf("The Employee of year is %d\n",c+1);
   
    int d=periodoftime(arr,numofemployee,numofperiod);
    printf("The Period of time is %d\n",d+1);
   
    int e=worstemployeeofyear(arr,numofemployee,numofperiod);
    printf("The Worst employee is %d",e+1);
   
    for(int i=0;i<numofemployee;i++){
    free(arr[i]);
}
    free(arr);
    return 0;
}
