#include<stdio.h>
int main(){
int arr[6] = {10, 20, 30, 40, 50, 60};
int *ptr = NULL;
ptr = arr; 
printf("%d %p\n", *ptr, ptr); // 10, 
ptr++;
printf("%d %p\n", *ptr, ptr); // 20
ptr += 3;
printf("%d %p\n", *ptr, ptr); // 50
ptr--;
printf("%d %p\n", *ptr, ptr); // 40
ptr --;
printf("%d %p\n", *ptr, ptr); // 30
	
	return 0;
}
