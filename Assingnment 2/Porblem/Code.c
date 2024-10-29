/*
Name:Hardeep Naresh
Roll NO: 24K-0653
Desc:Second minimum number
*/

#include<stdio.h>
int main(){
	int i,n,min,smin;
	printf("Enter the size or array");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	min=arr[0];
	smin=arr[1];
	for(i=n-1;i>=0;i--){
		if(min>arr[i]){
			smin=min;
			min=arr[i];
		}
		else if(smin>arr[i] && arr[i]!=min){
			smin=arr[i];
		}
	}
	printf("Second minimun is :%d", smin);
	
}
