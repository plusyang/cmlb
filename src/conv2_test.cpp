//
//
//
#include <stdio.h>
#define N1 5      //信号1的行
#define M1 5    //信号1的列
#define N2 3       //信号2的行
#define M2 3      //信号2的列

//conv2 test
void conv2(int x[N1][M1], int y[N2][M2], int z[N1 + N2 - 1][M1 + M2 - 1]) {
	int i, j;
	int n, m;
	for (i = 0; i < N1 + N2 - 1; i++)
		for (j = 0; j < M1 + M2 - 1; j++) {
			int temp = 0;
			for (m = 0; m < N1; m++) {
				for (n = 0; n < M1; n++) {
					if ((i - m) >= 0&&(i-m)<N2&&(j-n)>=0&&(j-n)<M2) {
						temp += x[m][n] * y[i - m][j - n];
					}
				}
			}
			z[i][j] = temp;
		}
}

void print(int ** x ,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d,",*((int *)x+i*n+j));
		printf("\n");
	}
}

int xxmain() {
	int x[N1][M1] = {{1,5,7,3,3},{3,4,5,1,1},{2,1,2,1,2},{2,2,2,2,2},{8,8,8,7,8}};
	int y[N2][M2] = { { 1, 1, 1 }, { 1, 1, 1 },{2,2,2} };
	int z[N1 + N2 - 1][M1 + M2 - 1] = { 0 };
	conv2(x, y, z);

	print((int **)x,5,5);printf("\n");
	print((int **)y,3,3);printf("\n");
	print((int **)z,7,7);printf("\n");
}
