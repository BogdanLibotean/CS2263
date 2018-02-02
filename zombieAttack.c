#include <stdlib.h>
#include <stdio.h>

void set_zombies(int n, char fred[n][n]);
void print_zombies(int n, char fred[n][n]);
void block_zombies(int n, char fred[n][n]);

void main() {
	int n;
	scanf("%d", &n);
	char fred[n][n];
	set_zombies(n, fred);
	print_zombies(n, fred);
	block_zombies(n, fred);
	print_zombies(n, fred);
}

void print_zombies(int n, char fred[n][n]) {
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			printf("%d ", fred[i][j]);
		}
		printf("\n");
	}
}

void set_zombies(int n, char fred[n][n]) {
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			fred[i][j] = '.';
		}
	}
	int zombies[n*n];
	int i = 0;
	while(getchar() != EOF) {
		scanf("%d", &zombies[i]);
		i ++;
	}
	for(int m = 0; m < i; m = m + 2) {
		fred[zombies[m]][zombies[m+1]] = 'Z';
	}
}

void block_zombies(int n, char fred[n][n]) {
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			if(fred[i][j] == 'Z') {
				if((j < n-1) || (fred[i][j+1] != 'B') || (fred[i][j+1] != 'Z')) {
					fred[i][j+1] = 'B';
				}
				if((j > 0) || (fred[i][j-1] != 'B') || (fred[i][j-1] != 'Z')) {
					fred[i][j-1] = 'B';
				}
				if((i < n-1) || (fred[i+1][j] != 'B') || (fred[i+1][j] != 'Z')) {
					fred[i+1][j] = 'B';
				}
				if((i < 0) || (fred[i-1][j] != 'B') || (fred[i-1][j] != 'Z')) {
					fred[i-1][j] = 'B';
				}
			}
		}
	}
}
