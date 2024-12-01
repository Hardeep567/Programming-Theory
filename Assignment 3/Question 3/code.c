// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int validcheck(char *ptr,int c){
    int found=1;
    int dot=0;
    for(int i=0;i<c;i++){
        if(ptr[i]=='@'){
            found--;
        }
        if(found==0){
            if(ptr[i]=='.'){
                dot++;
            }
        }
    }
    if(found==0 && dot>=1){
        return 1;
    }
    return 0;
}

int main() {
    char str[100];
    fgets(str,100,stdin);
    int c=strlen(str);
    char *ptr=(char *)malloc(sizeof(char)* (c-1));
    
    for(int i=0;i<c-1;i++){
        ptr[i]=str[i];
    }
    
    int check=validcheck(ptr,c-1);
    if(check==1) printf("Valid");
    else printf("In Valid");
    
    free(ptr);

    return 0;
}
