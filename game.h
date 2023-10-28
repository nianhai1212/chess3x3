#ifndef __GAME_H__
#define __GAME_H__

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard(char arr[ROW][COL],int row,int col);
void displayBoard(char arr[ROW][COL],int row,int col);
void playerMove(char arr[ROW][COL], int row, int col);
void computerMove(char arr[ROW][COL], int row, int col);

/* 0 not full 
 * 1 full
 */
int isFull(char arr[ROW][COL], int row, int col);

/*
 * '*' player Win
 * '#' computer Win
 * 'Q' balanced
 * 'C' continue
 */
char isWin(char arr[ROW][COL], int row, int col);

#endif
