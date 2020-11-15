#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int MAX(int num1, int num2) {	// 더 큰 값을 반환
	if (num1 > num2)
		return num1;
	else
		return num2;
}

// LCS Length Top-down Memoization function
int LCS_LENGTH(const char* X, const char* Y, int i, int j)
{
	if (c[i][j] != -1)
		return c[i][j];
	else 
	{
		if (X[i - 1] == Y[j - 1])
			c[i][j] = LCS_LENGTH(X, Y, i - 1, j - 1) + 1;
		else
			c[i][j] = MAX(LCS_LENGTH(X, Y, i, j - 1), LCS_LENGTH(X, Y, i - 1, j));
	
		return c[i][j];
	}
}


int** c;

int main(void)
{
	int n = 10;
	char* X = (char*)malloc(sizeof(char) * n);
	char* Y = (char*)malloc(sizeof(char) * n);

	srand((unsigned int)time(NULL));

	// 랜덤한 대문자 문자열 X, Y 생성
	for (int idx = 0; idx < n; idx++)
	{
		int rand1 = rand() % 26 + 65;	// 65~90 (-> A~Z)
		int rand2 = rand() % 26 + 65;	// 65~90 (-> A~Z)
		X[idx] = (char)rand1;
		Y[idx] = (char)rand2;
	}

	// X와 Y 출력
	printf("X : ");
	for (int idx = 0; idx < n; idx++)
		printf("%c", X[idx]);
	printf("\nY : ");
	for (int idx = 0; idx < n; idx++)
		printf("%c", Y[idx]);
	printf("\n\n");
	

	// 배열 c 크기 : (n+1)x(n+1)
	c = (int**)malloc(sizeof(int*) * (n + 1));	
	for (int idx = 0; idx < n + 1; idx++) {
		c[idx] = (int*)malloc(sizeof(int) * (n + 1));
	}

	// 0번째 row 또는 col에서는 배열 값이 0, 그 외에는 배열 값이 -1 
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			c[i][j] = -1;
	for (int i = 0; i < n + 1; i++)
		c[i][0] = 0;
	for (int j = 1; j < n + 1; j++)
		c[0][j] = 0;



	//clock_t start, end;
	//float exec_time;
	//start = clock();	// 시작 시간 측정

	LCS_LENGTH(X, Y, n, n);

	//end = clock();	// 완료 시간 측정
	//exec_time = (float)(end - start) / CLOCKS_PER_SEC;
	//printf("%f\n", exec_time);



	printf("Length of LCS : %d\n\n", c[n][n]);


	// print c
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
			printf("%d\t", c[i][j]);
		printf("\n");
	}
}
