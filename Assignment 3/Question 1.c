#include<stdio.h>

typedef struct employees
{
    int employeecode;
    char employeeName[60];
    int dateofjoining[3];
} employees;

int main(){
	int i;
    employees arr[4];
    
    for (i = 0; i < 4; i++)
    {
        
        printf("Enter the Name of employee %d\n",i+1);
        getchar();
        fgets(arr[i].employeeName,60,stdin);
        printf("Enter the Code of employee %d\n",i+1);
        scanf("%d", &arr[i].employeecode);
        printf("Enter the data of joining employee %d\n",i+1);
        scanf("%d %d %d", &arr[i].dateofjoining[0], &arr[i].dateofjoining[1], &arr[i].dateofjoining[2]);
    }
    int currentdate[3],count=0;
    printf("Enter the current date");
    scanf("%d %d %d",&currentdate[0],&currentdate[1],&currentdate[2]);
    for(i = 0; i < 4; i++)
    {
    	if(currentdate[2]-arr[i].dateofjoining[2]>3){
    		if(currentdate[1]-arr[i].dateofjoining[1]>=0){
    			if(currentdate[0]-arr[i].dateofjoining[0]>=0){
    				printf("%s \n %d \n %d-%d-%d\n",arr[i].employeeName,arr[i].employeecode,arr[i].dateofjoining[0],arr[i].dateofjoining[1],arr[i].dateofjoining[2]);
    				count++;
				}
			}
		}
	}
	printf("Number of employees tenure of more than three years : %d", count);
    
}
