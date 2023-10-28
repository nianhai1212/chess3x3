#include "game.h"

char arr[ROW][COL] = {};

void manu() {
	printf("*****************************\n");
	printf("*****1. play 0.exit**********\n");
	printf("*****************************\n");
};

void test() {

	int input = 0;

	char ret = 0;

	srand((unsigned int)time(NULL));
	
	manu();
	do {
		printf("Please input the option->\n");
		scanf("%d",&input);

		switch(input) {
			case 0:
				printf("Quit Game!\n");
				break;
			case 1:
				printf("Enjoy!\n");
				initBoard(arr,ROW,COL);
				displayBoard(arr,ROW,COL);
				while(1) {
					playerMove(arr,ROW,COL);
					displayBoard(arr,ROW,COL);
					ret = isWin(arr,ROW,COL);
					printf("player isWin is %c\n",ret);
					if(ret != 'C') {
						break;
					}
					computerMove(arr,ROW,COL);
					displayBoard(arr,ROW,COL);
					ret = isWin(arr,ROW,COL);
					printf("computer isWin is %c\n",ret);
					if(ret != 'C') {
						break;
					}
				}
				break;
			default:
				printf("Option Error Please input 0 or 1\n");
				break;
		}
		if(ret == '*') {
			printf("player Win\n");
		} else if (ret == '#') {
			printf("Computer Win\n");
		} else {
			printf("Balanced\n");
		}

	}while(input);
}

int main()
{

	test();

	return 0;
}
