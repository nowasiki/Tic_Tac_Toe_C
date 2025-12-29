#include "game.h"
extern int step;
void display_board(char board[ROW][COL], int row, int col) {
	int i, j;
	printf("\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (j != 0) printf("|");
			printf(" %c ", board[i][j]);
		}
		printf("\n");
		if (i != row - 1) {
			for (j = 0; j < col; j++) {
				if (j == 0) printf("---");
				else printf("|---");
			}
			printf("\n"); 
		}
	}
	printf("\n");
}
void init_board(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' '; // Initialize each cell to a space character
		}
	}
}
void player_move(char board[ROW][COL], int row, int col) {
	int x, y;
	printf("<%d>", step); // Display the current step number
	printf("YOUR TURN!PLEASE INPUT THE COORDINATES(x y):");
	if ((scanf("%d %d", &x, &y) == 2) && (x <=row && y <= col && x > 0 && y > 0)) {
		if (board[x - 1][y - 1] == ' ') {
			printf("\nIPPUT SUCCESSFULLY!\n");
			board[x - 1][y - 1] = '*'; // Player's move
			step++;
		}
		else {
			printf("\nYou cannot place it there.\n");
			display_board(board, row, col); // Show the board again
			player_move(board, row, col); // Prompt the player to move again
		}
	}
	else {
		while (getchar() != '\n'); // Clear the input buffer
		printf("\nINVALID INPUT!PLEASE TRY AGAIN!\n");
		display_board(board, row, col);
		player_move(board, row, col);
	}
}
void computer_move(char board[ROW][COL], int row, int col){
	printf("\n<%d>", step);
	step++;
	printf("COMPUTER IS PLACING!\n");
	int x = rand() % row;
	int y = rand() % col;
	while (board[x][y] != ' ') {
		x = rand() % row;
		y = rand() % col;
	}
	board[x][y] = '$';
	Sleep(2000); // Pause for 2 seconds to simulate thinking time
	printf("\nYOUR TIME NOW!\n");
}

// 0:continue 1:player win 2:computer win 3:draw
int Judge(char board[ROW][COL], int row, int col, int num) {
	int i = 0, j = 0, n = 0, id = 1; //id = 0:COMPUTER, id = 1:USER
	char m[2] = { '$', '*' }; //m[0]:COMPUTER, m[1]:USER

	for (i = 0; i < row; i++) {
		n = 0;
		//check row
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') n = 0;
			else if (n == 0) {
				if(board[i][j] == '$') id = 0;
				else id = 1;
				n++;
			}
			else if (board[i][j] == m[id]) {
				n++;
				if (n == num) {
					if (board[i][j] == '*') return 1; //player win
					else return 2; //computer win
					}
			}
			else{
				n = 1;
				if (board[i][j] == '$') id = 0;
				else id = 1;
			}
		}
	}
	//check col
	for (j = 0; j < row; j++) {
		n = 0;
		for (i = 0; i < col; i++) {
			if (board[i][j] == ' ') n = 0;
			else if (n == 0) {
				if (board[i][j] == '$') id = 0;
				else id = 1;
				n++;
			}
			else if (board[i][j] == m[id]) {
				n++;
				if (n == num) {
					if (board[i][j] == '*') return 1; //player win
					else return 2; //computer win
				}
			}
			else {
				n = 1;
				if (board[i][j] == '$') id = 0;
				else id = 1;
			}
		}
	}
	//check diagonal-1
	for (i = 0; i < row; i++) {
		j = 0, n = 0;
		for (; i < row && j < col; i++, j++) {
			if (board[i][j] == ' ') {
				n = 0;
			}
			else if (n == 0) {
				if (board[i][j] == '$') id = 0;
				else id = 1;
				n++;
			}
			else if (board[i][j] == m[id]) {
				n++;
				if (n == num) {
					if (board[i][j] == '*') return 1; //player win
					else return 2; //computer win
				}
			}
			else {
				n = 1;
				if (board[i][j] == '$') id = 0;
				else id = 1;
			}
		}
	}
	//check diagonal-2
	for (j = 0; j < col; j++) {
		i = 0, n = 0;
		for (; i < row && j < col; i++, j++) {
			if (board[i][j] == ' ') {
				n = 0;
			}
			else if (n == 0) {
				if (board[i][j] == '$') id = 0;
				else id = 1;
				n++;
			}
			else if (board[i][j] == m[id]) {
				n++;
				if (n == num) {
					if (board[i][j] == '*') return 1; //player win
					else return 2; //computer win
				}
			}
			else {
				n = 1;
				if (board[i][j] == '$') id = 0;
				else id = 1;
			}
		}
	}
	//check full board
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') return 0; //continue
		}
	}
	//draw
	return 3;
}