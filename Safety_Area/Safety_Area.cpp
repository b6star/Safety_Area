//SAFETY_AREA 백준 안전영역 2468번 문제
//https://www.acmicpc.net/problem/2468
//원형 큐를 이용한 BFS 알고리즘을 사용하여 문제를 해결하였다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int Altitude[100][100];
int N;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void bfs(QueueType Q, int** Altitude_cpy)
{
	while (!is_empty(&Q))
	{
		int y, x;
		dequeue(&Q, &y, &x);
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (Altitude_cpy[ny][nx] != 0)
				{
					enqueue(&Q, ny, nx);
					Altitude_cpy[ny][nx] = 0;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Altitude[i][j]);
		}
	}
	int** Altitude_copy;
	Altitude_copy = (int**)malloc(sizeof(int*)*N);
	Altitude_copy[0] = (int*)malloc(sizeof(int*)*N*N);
	for (int i = 1; i < N; i++) {
		Altitude_copy[i] = Altitude_copy[i-1] + N;
	}
	int height = 0;
	QueueType Q;
	int max_count = 0;
	int count;
	while (1){
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (Altitude[i][j] <= height) {
					Altitude_copy[i][j] = 0;
				}
				else {
					Altitude_copy[i][j] = Altitude[i][j];
				}
			}
		}
		init(&Q);
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Altitude_copy[i][j] != 0) {
					count++;
					enqueue(&Q, i, j);
					Altitude_copy[i][j] = 0;
					bfs(Q, Altitude_copy);
				}
			}
		}
		if (count == 0) {
			break;
		}
		else if (count > max_count) {
			max_count = count;
		}
		height++; 
	}
	printf("%d\n", max_count);
	free(Altitude_copy[0]);
	free(Altitude_copy);
	return 0;
}