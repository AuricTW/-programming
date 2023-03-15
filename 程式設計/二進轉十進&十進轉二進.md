#include<stdio.h>
int main(){
	int i,n,a[32];
	printf("輸入10進位數字:");
	scanf("%d",&n);
	
	while(n>0){
		a[i]=n%2;
		i++;
		n=n/2;
	}
	printf("輸出2進位數字:");
	for(i;i>0;i--){
		printf("%d",a[i-1]);
	}
	return 0;
} 


#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    int decimalNumber = 0, i = 0, remainder;

    printf("請輸入二進制數字：");
    scanf("%lld", &n);

    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    printf("十進制數字為：%d", decimalNumber);

    return 0;
}
