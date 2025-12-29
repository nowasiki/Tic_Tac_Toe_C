#pragma once // Ensure the header file is included only once

#define _CRT_SECURE_NO_WARNINGS // Disable security warnings for functions like scanf
#define ROW 4 // Define the number of rows
#define COL 4 // Define the number of colums

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

/**
* @brief Display the game board
* @param board The game board
* @param row Number of rows
* @param col Number of columns
* @return void
**/
void display_board(char board[ROW][COL], int row, int col);

/**
* @brief Initialize the game board
* @param board The game board
* @param row Number of rows
* @param col Number of columns
* @return void
**/
void init_board(char board[ROW][COL], int row, int col);

/**
* @brief Handle player's move
* @param board The game board
* @param row Number of rows
* @param col Number of columns
* @return void
**/
void player_move(char board[ROW][COL], int row, int col);

/**
* @brief Handle computer's move
* @param board The game board
* @param row Number of rows
* @param col Number of columns
* @return void
**/
void computer_move(char board[ROW][COL], int row, int col);

/**
* @brief Judge the game state
* @param board The game board
* @param row Number of rows
* @param col Number of columns
* @param num Number of pieces needed to win
* @return int Game state code 0:continue 1:player win 2:computer win 3:draw
* 
**/
int Judge(char board[ROW][COL], int row, int col, int num);