#include "game.h"

void initBoard(char arr[ROW][COL],int row,int col) {
	int i = 0;
	int j = 0;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			arr[i][j] = ' ';
		}
	}
}


void displayBoard(char arr[ROW][COL],int row,int col) {
	int i = 0;
	int j = 0;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) { 
			if(j < col -1) {
				printf(" %c |",arr[i][j]);
			} else {
				printf(" %c ",arr[i][j]);
			}
		}
		printf("\n");
		
		if(i < row - 1) {
			for(j = 0; j < col; j++) {
				if(j < col - 1) {
					printf("---|");
				} else {
					printf("---");
				}
			}
			printf("\n");
		}
	}
}

void playerMove(char arr[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;

	printf("Player Move:>\n");

	while(1) {
		printf("Please Input the Pos:");
		scanf("%d%d",&i,&j);
		if( i >= 1 && i <= row && j >= 1 && j <= col) {
			if(arr[i-1][j-1] == ' ') {
				arr[i-1][j-1] = '*';
				break;
			} else {
				printf("Pos Conflict!\n");
			}
		} else {
			printf("Out of the chese board range\n");
		}
	}
}

void computerMove(char arr[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	
	printf("Computer Move:>\n");

	while(1) {
		x = rand() % row;
		y = rand() % col;
	
		if(arr[x][y] == ' ') {
			arr[x][y] = '#';
			break;
		}
	}
}

/* 0 not full 
 * 1 full
 */
int isFull(char arr[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			if(arr[i][j] == ' ') {
				return 0;
			}
		}
	}

	return 1;
}

/*
 * '*' player Win
 * '#' computer Win
 * 'Q' balanced
 * 'C' continue
 */
char isWin(char arr[ROW][COL], int row, int col) {
	int i = 0;

	for(i = 0; i < row; i++) {
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
			return arr[i][1];
	}

	for(i = 0; i < row; i++) {
		if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
			return arr[1][i];
	}

	if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];

	if(arr[0][2] == arr[1][1] && arr[1][1] == arr[3][0] && arr[1][1] != ' ')
		return arr[1][1];

	if(1 == isFull(arr,ROW,COL)) {
		return 'Q';
	} else { 
		return 'C';
	}

}
