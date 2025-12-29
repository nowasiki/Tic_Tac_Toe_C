#include "game.h"
int step;
void menu(void) {
	printf("=== Tic Tac Toe ===\n");
	printf("1. Start Game\n");
	printf("2. Exit\n");
	printf("Select an option>");
	step = 1;
}
void start_game(int num) {
	int state_code = -1;
	char board[ROW][COL] = {0};
	printf("Game started! \n");
	init_board(board, ROW, COL);
	display_board(board, ROW, COL);
	while (1) {
		player_move(board, ROW, COL);
		display_board(board, ROW, COL);
		state_code = Judge(board, ROW, COL, num);
		if(state_code) break;
		computer_move(board, ROW, COL);
		display_board(board, ROW, COL);
		state_code = Judge(board, ROW, COL, num);
		if (state_code) break;
	}
	if (state_code == 1) printf("*********************************\nYOU WIN!!!");
	else if(state_code == 2) printf("*********************************\nYOU LOSE!!!");
	else printf("*********************************\nDRAW!!");
	display_board(board, ROW, COL);
	printf("*********************************\n");
}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0, num;
	do {
		menu();
		if(scanf_s("%d", &input) != 1){
			while (getchar() != '\n'); // Clear the input buffer
			printf("\nInvalid input. Please enter a number.\n\n"); 
			continue;
		}
		switch (input) {
			case 1:
				printf("WIN CONDITION(HOW MANY PIECES?)>"); 
				if (scanf_s("%d", &num) != 1 || num > ROW) {
					while (getchar() != '\n'); // Clear the input buffer
					printf("\nInvalid input. Please enter a number.\n\n"); 
					continue;
				}
				start_game(num);
				break;
			case 2:
				printf("Exiting the game. Goodbye!\n");
				break;
			default:
				printf("Invalid option. Please try again.\n");
				break;
		}
	} while (input != 2);
}