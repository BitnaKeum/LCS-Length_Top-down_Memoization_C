#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int MAX(int num1, int num2) {	// �� ū ���� ��ȯ
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

	// ������ �빮�� ���ڿ� X, Y ����
	for (int idx = 0; idx < n; idx++)
	{
		int rand1 = rand() % 26 + 65;	// 65~90 (-> A~Z)
		int rand2 = rand() % 26 + 65;	// 65~90 (-> A~Z)
		X[idx] = (char)rand1;
		Y[idx] = (char)rand2;
	}

	// X�� Y ���
	printf("X : ");
	for (int idx = 0; idx < n; idx++)
		printf("%c", X[idx]);
	printf("\nY : ");
	for (int idx = 0; idx < n; idx++)
		printf("%c", Y[idx]);
	printf("\n\n");
	

	// �迭 c ũ�� : (n+1)x(n+1)
	c = (int**)malloc(sizeof(int*) * (n + 1));	
	for (int idx = 0; idx < n + 1; idx++) {
		c[idx] = (int*)malloc(sizeof(int) * (n + 1));
	}

	// 0��° row �Ǵ� col������ �迭 ���� 0, �� �ܿ��� �迭 ���� -1 
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			c[i][j] = -1;
	for (int i = 0; i < n + 1; i++)
		c[i][0] = 0;
	for (int j = 1; j < n + 1; j++)
		c[0][j] = 0;



	//clock_t start, end;
	//float exec_time;
	//start = clock();	// ���� �ð� ����

	LCS_LENGTH(X, Y, n, n);

	//end = clock();	// �Ϸ� �ð� ����
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
