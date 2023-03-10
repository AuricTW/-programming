//記憶體位置
#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
int main(){
	int arr[]={3,4,5,6,7};
	int sz=sizeof(arr)/sizeof(int);
	printf("%d\n",sz);
	
	printf("arr: \t%p\n",sz);
	printf("arr[0]: \t%p\n",&arr[0]);
	printf("arr[1]: \t%p\n",&arr[1]);
	printf("arr[2]: \t%p\n",&arr[2]);
	printf("arr[3]: \t%p\n",&arr[3]);

	return 0;
	}
	
	

//兩未知大小矩陣運算
//rows:列(橫向)  columns:行(縱向) 
#include <stdio.h>

int main() {
    int rows1, cols1, rows2, cols2, i, j, k;
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // 檢查矩陣是否可以運算
    if (cols1 != rows2) {
        printf("Matrices cannot be multiplied!");
        return 0;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // 輸入矩陣1元素
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // 輸入矩陣2元素
    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // 計算兩矩陣相乘並儲存
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // 輸出結果
    printf("Resultant matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
