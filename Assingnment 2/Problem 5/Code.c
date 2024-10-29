#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array");
    scanf("%d", &n);
    int arr[n],an[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        printf("The value %d    ", i+1);
        for(int j=0;j<arr[i];j++){
            printf("*");
        }
        an[i]=arr[i];
        printf("\n");
    }
    for(int i=max;i>0;i--){
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                arr[j]--;
                printf(" *");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        printf(" %d",an[i]);
    }
}
