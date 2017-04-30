/*
ENGGEN131 Project - C Project - 2016
Test program for Task Ten - MakeMove()
This test program allows you to play a game of cave escape while testing
your MakeMove() function.  The MakeMove() function provided below is not
implemented yet, so the caver (denoted by an 'X' in the game) currently
does not move in response to the players commands... you need to change that!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//********************************************************************
//********************************************************************
// You must define the MakeMove() function below.  Refer to the full
// description in the project specification document.  The first input
// to the function is the cave which is represented by a 2-dimensional
// array which is 10 rows by 10 columns.  The second input to the function
// will be one of four characters: 'w', 'a', 's' or 'd' representing the
// move of the player.  You must update the cave array accordingly.
//********************************************************************
//********************************************************************
void Rotate(int cave[10][10],int number)
{
	int original[10][10] = {0};
	int i,j,k;

	for (k = 0; k<number; k++) {
		for (i = 0; i<10; i++){
			for(j = 0; j<10; j++) {
				original[i][j] = cave[i][j];
			}
		}

		for (i = 0; i<10; i++) {
			for(j = 0; j<10; j++) {
				cave[i][j] = original[9-j][i];
			}
		}
	}
}

int MakeMove(int cave[10][10], char move)
{
	int i,j;
	int row = 0;
	int col = 0;
	int hole_row = 0;
	int hole_col = 0;
	int left = 0;
	int right = 0;
	int down = 0;
	int obstacle = 0;
	int obstacle_row = 0;
	int returnNumber = 0;

	if (move == 'a') {
		left = 1;
		Rotate(cave,1);
	}

	if (move == 's') {
		down = 1;
		Rotate(cave,2);
	}

	if (move == 'd') {
		right = 1;
		Rotate(cave,3);
	}

	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			if (cave[i][j] == 3){
				row = i;
				col = j;
			}

			if (cave[i][j] == 4) {
				hole_row = i;
				hole_col = j;
			}
		}
	}

	if (cave[row-1][col] == 0) {
		cave[row-1][col] = 3;
		cave[row][col] = 0;
	}
	else if (cave[row-1][col] == 4) {
		cave[row][col] = 0;
		returnNumber = 1;
	}
	else if (cave[row-1][col] == 5) {
		cave[row][col] = 0;
		cave[row-1][col] = 3;
		returnNumber = 2;
	}
	else if (cave[row-1][col] == 2) {
		if (cave[row-2][col] != 1 && cave[row-2][col] != 2) {
			cave[row-1][col] = 3;
			cave[row][col] = 0;

			for (i = 0; i<row-1; i++) {
				if (cave[i][col] != 0) {
					obstacle = cave[i][col];
					obstacle_row = i;
				}
			}

			if (obstacle == 4) {
				cave[hole_row][hole_col] = 0;
			}
			if (obstacle == 2 || obstacle == 1) {
				cave[obstacle_row+1][col] = 2;
			}
		}
	}

	if (left) {
		Rotate(cave,3);
	}
	if (down) {
		Rotate(cave,2);
	}

	if (right) {
		Rotate(cave,1);
	}

	return returnNumber;
}


//********************************************************************
//********************************************************************
// YOU SHOULD NOT MAKE ANY CHANGES TO THE PROGRAM BELOW.  REMEMBER
// YOU ARE ONLY SUBMITTING THE MakeMove() FUNCTION ABOVE (AND ANY)
// HELPER FUNCTIONS THAT YOU HAVE DEFINED.  REMEMBER TO PLACE THE
// MakeMove() FUNCTION INTO THE project.c FILE BEFORE SUBMISSION.
//********************************************************************
//********************************************************************

/* Function prototype declarations */
void PrintCave(int cave[10][10]);
char GetMove(void);

// Print a welcome message, and enter the main game loop.
int main(void)
{
	printf("ENGGEN131 2016 - C Project - Task Ten\n");
	printf("                     ... presents ...\n");
	printf("   ______                    ______                          \n");
	printf("  / ____/___ __   _____     / ____/_____________ _____  ___  \n");
	printf(" / /   / __ `/ | / / _ \\   / __/ / ___/ ___/ __ `/ __ \\/ _ \\ \n");
	printf("/ /___/ /_/ /| |/ /  __/  / /___(__  ) /__/ /_/ / /_/ /  __/ \n");
	printf("\\____/\\__,_/ |___/\\___/  /_____/____/\\___/\\__,_/ .___/\\___/  \n");
	printf("                                              /_/            \n");
	printf("Use the keys 'w', 'a', 's', 'd' to move the caver (X)\n");
	printf("Push the boulders (O) into the hole (*) and then escape!\n");
	printf("Good luck!\n\n\n");

	/* A couple of basic caves are provided to test with */
	/*int cave[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 2, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 3, 0, 0, 4, 5},
		{1, 0, 0, 1, 0, 0, 2, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	}; */
	  int cave[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 5, 1, 1},
		{1, 0, 0, 0, 0, 0, 2, 4, 0, 1},
		{1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 2, 0, 0, 1, 1},
		{1, 1, 0, 3, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	// The main game loop - continue to make moves until the game is over
	int gameOver = 0;
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nGAME OVER!! \nCongratulations - you escaped!\n\n");
		}
	}
	return 0;
}

/* A simple function for displaying the cave. */
void PrintCave(int cave[10][10])
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (cave[i][j] == 0) {
				printf(" ");
			} else if (cave[i][j] == 1) {
				printf("#");
			} else if (cave[i][j] == 2) {
				printf("O");
			} else if (cave[i][j] == 3) {
				printf("X");
			} else if (cave[i][j] == 4) {
				printf("*");
			} else if (cave[i][j] == 5) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

/* The GetMove() function returns the entered character.  Invalid
   characters are ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	// Ignore any characters that are invalid
	scanf("%c", &move);
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}
