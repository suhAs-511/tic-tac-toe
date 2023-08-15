#include <stdio.h>
#include <stdlib.h>
// Define the board size and the symbols for the players and the empty cell
#define N 3
#define X 'X'
#define O 'O'
#define EMPTY ' '
// Declare a global variable to store the board
char board[N][N];
// Initialize the board with empty cells
void init_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = EMPTY;
    }
  }
}
// Display the board on the screen
void print_board() {
  printf("\n");
  for (int i = 0; i < N; i++) {
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if (i < N - 1) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}
// Check if a cell is valid and empty
int is_valid(int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= N) {
    return 0; // out of bounds
  }
  if (board[x][y] != EMPTY) {
    return 0; // already occupied
  }
  return 1; // valid and empty
}
// Check if the board is full
int is_full() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == EMPTY) {
        return 0; // found an empty cell
      }
    }
  }
  return 1; // no empty cells
}
// Check if a player has won by forming a line of their symbol
int is_winner(char symbol) {
  // check rows
  for (int i = 0; i < N; i++) {
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (board[i][j] == symbol) {
        count++;
      }
    }
    if (count == N) {
      return 1; // found a row of symbol
    }
  }
  // check columns
  for (int j = 0; j < N; j++) {
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (board[i][j] == symbol) {
        count++;
      }
    }
    if (count == N) {
      return 1; // found a column of symbol
    }
  }
  // check diagonals
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < N; i++) {
    if (board[i][i] == symbol) {
      count1++;
    }
    if (board[i][N - i - 1] == symbol) {
      count2++;
    }
  }
