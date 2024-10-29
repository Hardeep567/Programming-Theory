#include<stdio.h>
#include<string.h>
#include<math.h>

int BinaryToDecimal(int n){
	
    int i=0,j;
    int sum=0,c[100];
    while(n>0){
        c[i] = n%10;
        n /= 10;
        i++;
    }
    for(j=0;j<i;j++){
        c[j]=pow(2,j)*c[j];
        sum+=c[j];
    }
    return sum;
}
int DecimalToBinary(int n){
	int rev=0,c=0;
    while(n>0){
        c=n%2;
        n=n/2;
        if(c==0) c=2;
        rev=c+rev*10;
    }
    while(rev>0){
        c=rev%10;
        rev/=10;
        if(c==2) c=0;
        n=c+n*10;
    }
    return n;
}
void HexadecimalToDecimal(char str[]){
	int n=strlen(str);
	int i=0,j,sum=0,z;
    int ch='A';
    for(j=n-2;j>=0;j--){
        int v;
        if(str[j]>='A' && str[j]<='F' ) {
            v=str[j];
            v=v-ch+10;
        }
        else if(str[j]>='0' && str[j]<='9'){
            v=str[j]-'0';
        }
        z=pow(16,i)*v;
        sum+=z;
        i++;
        z=0;
    }
    printf("%d", sum);	
}
void DecimalToHexadecimal(int n){
	int i=0,j;
    char ch='A';
    int sum=0,c[100];
    while(n>0){
        c[i]=n%16;
        n/=16;
        i++;
    }
    for(j=i-1;j>=0;j--){
        if(c[j]>9){
            c[j]=c[j]-10;
            printf("%c",(ch+c[j]));
        }
        else{
            printf("%d", c[j]);
        }
    }
}
void BinaryToHexadecimal(int number){
	int c=BinaryToDecimal(number);
	DecimalToHexadecimal(c);
}
void HexadecimalToBinary(char str[]){
	int n=strlen(str);
	int i=0,j,sum=0,z;
    int ch='A';
    for(j=n-2;j>=0;j--){
        int v;
        if(str[j]>='A' &&str[j]<='F' ) {
            v=str[j];
            v=v-ch+10;
        }
        else if(str[j]>='0' && str[j]<='9'){
            v=str[j]-'0';
        }
        z=pow(16,i)*v;
        sum+=z;
        i++;
        z=0;
    }
    int p=DecimalToBinary(sum);
    printf("%d", p);
}
int main(){
	int ch,n;
	char str[100];
	printf("Enter the option\n1.Binary To Decimal\n2.Decimal To Binary\n3.Decimal To Hexadecimal\n4.Hexadecimal To Decimal\n5.Binary To Hexadecimal\n6.Hexadecimal To Binary\n7.Quit");
	scanf("%d", &ch);
	if(ch==1){
		printf("Enter the number:");
		scanf("%d", &n);
		int ans=BinaryToDecimal(n);
		printf("%d", &ans);
	}
	else if(ch==2){
		printf("Enter the number:");
		scanf("%d", &n);
		int ans=DecimalToBinary(n);
		printf("%d", ans);
	}
	else if(ch==4){
		scanf(" %s", &str);
		HexadecimalToDecimal(str);
	}
	else if(ch==3){
		printf("Enter the number:");
		scanf("%d", &n);
		DecimalToHexadecimal(n);
	}
	else if(ch==5){
		printf("Enter the number:");
		scanf("%d", &n);
		BinaryToHexadecimal(n);
	}
	else if(ch==6){
		scanf(" %s", &str);
		HexadecimalToBinary(str);
	}
	else {
		return 0;
	}
	return 0;
}
