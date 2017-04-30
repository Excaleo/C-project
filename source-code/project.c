#include "project.h"

/*
This source file is the one that you will submit for marking.
Currently, all of the function implementations below are incorrect.

***** PLEASE NOTE *****
IF YOU CHOOSE NOT TO IMPLEMENT A FUNCTION, DO NOT DELETE IT FROM
THIS SOURCE FILE.  WHEN YOU SUBMIT THIS SOURCE FILE FOR MARKING,
ALL TEN FUNCTIONS MUST BE PRESENT.

You may define as many additional "helper" functions as you like.

Good luck!
*/

/* --------------------------HELPER FUNCTIONS----------------------------------

 		Task 9: SumOfDigits
		This function was used in task 9 in order to calculate the sum of the
		digits given any input number.
		The function first finds the correct order of the number eg is it in the
		thousands or hundreds. This is done using a while loop and the remainder
		operator. If the remainder is smaller than the integer itself then
		exponent is exponent*10 and the process repeats until the remainder is
		itself. Then the exponent is then divided by 10 and the while loop ends
		because right_factor is now true. The following while loop computes the
		sum of the digits. This is done by dividing the number by the exponent
		adding that to sum and subtracting the number by (number/exponent)*exponent.
		This only works because type int rounds down. This repeats until exponent =0
		because 1/10 = 0. i.e. This while loop retrieves every digit in the number
		and adds it to the sum. */
int SumOfDigits(int number)
{
	int sum = 0;
	int exponent= 1;
	int right_factor = 0;

	while(!right_factor) {
		if (number%exponent != number) {
			exponent = 10*exponent;
		}
		else {
			exponent = exponent/10;
			right_factor = 1;
		}
	}

	while(exponent!=0) {
		sum += number/exponent;
		number = number - (number/exponent)*exponent;
		exponent = exponent/10;
	}

	return sum;
}

/* Task 10: Rotate
	 The Rotate function takes two inputs, a 10x10 integer array and the number of
	 of rotations and rotates and array clockwise by a number of times.
	 For each rotation a copy of the input array is made in
	 the original array using a nested for loop. The input array is then
	 rotated using the formual I derived for rotation:
	 cave[i][j] = original[9-j][i]; which I figured out after doing handworked
	 examples. After this the array is effectively rotated clockwise. This
	 process repeats for the number of times of the input number. */
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

/* The Perimeter functions takes two integer inputs, the width and the height of
	 a field and returns the perimeter of the field as an integer.
	 If either of the inputs are negative integers the function returns 0.

	 My algorithm first uses an if conditional statement to check that the
	 height and width are both positive (greater than or equal to 0). If both
	 are positive then the function returns the perimeter using 2xwidth + 2xheight.
	 Otherwise the function will return 0.*/
int Perimeter(int width, int height)
{
	if (width >= 0 && height >= 0) {
		return (2*width + 2*height);
	}
	else {
		return 0;
	}
}

/* The Volume function computes the Volume of a sphere using the general formula
   4/3 *(PI*radius^3) and takes the radius of the sphere as an integer input.The
	 output is the Volume as a double. If the input radius is negative, the function
	 returns 0.0.

	 My algorithm first checks if the input radius is positive or 0 using an if
	 conditional. If the radius is positive or 0 then the volume is computed
	 using the volume formula stated above and returned. Otherwise (if the
   the input radius is negative) the function returns 0.0*/
double Volume(int radius)
{
	double PI = 3.141592654;

	if (radius >= 0) {
		return (4*PI*radius*radius*radius)/3;
	}
	else {
		return 0.0;
	}
}

/* The PrimeBelow function takes an integer, uppers, as input and returns the
	 largest prime number that comes before the input. If the integer is 2 or
	 less then the function returns -1 as there are no prime numbers below 2.

	 My algorithm uses a nested for loop and a prime_indicator boolean variable.
	 first the function checks to see if the input (upper) is greater than 2. If
	 not, -1 is returned. If the input is greater than 2 then a nested for loop
	 runs to find the highest prime number before the upper integer. The outside
	 or first for loop variable i represents the integer of which we are trying to
	 determine if it is primal. The second for loop finds the remainder of i
	 divided by every positive integer below it that is not 0 or 1. If any of these
	 remainders are 0 then that means the number can be divided by a number other
	 than itselve and 1. Hence it is not a prime number and the prime_indicator
	 becomes 0 and the nested for loop continues for the next lower number. If
	 the remainder never equals 0 for a given value, then i is prime and the
	 prime_indicator remains as true/1.
	 This will cause the last if conditional to execute which returns the number.*/
int PrimeBelow(int upper)
{
	int prime;
	int prime_indicator = 1;

	if (upper > 2) {
		for (int i = upper - 1; i >= 2; i--) {
			prime_indicator = 1;

			for (int j = i - 1 ; j >= 2; j--) {
				if (i%j == 0) {
					prime_indicator = 0;
				}
			}

			if (prime_indicator) {
				prime = i;
				return prime;
			}
		}
	}

	return -1;
}

/* The Abbreviate function takes a string or array of characters, word, as input
	 and modifies the string so that all the vowels (a,e,i,o,u) are removed from
	 string.

	 Within the function, the length of the string is stored in string_length
	 using strlen(word), in order to take into account the '\0' at the end of
	 every string, my string_length variable is strlen(word) plus 1. A for loop
	 is then used to scan the input string character by character for the
	 prescence of characters that are not vowels. If the character is not a vowel,
	 it is copied into the new_word character array. Otherwise it is not copied.
	 The variable j represents the position of the new_word so that no character
	 overwrites existing characters. At the end of the loop the new_word array
	 should contain the input string without vowels. This is then copied to the
	 original word using the strcpy function so the input is replaced with the
	 new word without vowels. */
void Abbreviate(char* word)
{
	char new_word[MAX_ARRAY_SIZE];
	int j = 0;
	int string_length = strlen(word) + 1;

	for (int i = 0; i<string_length; i++) {
		if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
			new_word[j] = word[i];
			j++;
		}
	}
	strcpy(word,new_word);
}

/* The Strikeout function takes two strings as input, hide and phrase, and
	 replaces all instances of the hide string within the phrase string with
	 asteriks' '*' to effectively strike-out the hide word within the phrase.
	 The result is a modified phease with no instances of the hide word.

	 In order to achieve this with the function, I first scanned the prescence
	 of the first character of the hide word and stored all their positions in
	 array in the occurence integer array. If the character isn't detected the
	 function ends. Otherwise I use a while loop nested in a for loop in order
	 to scan every occurence of the first character in the string to see if it
	 matches the hide word by comparing it to the hide word. If it is not the same
	 word the boolean same_word will become 0 and nothing will be changed. However
	 if the word is the same then a for loop replaces the positions of the word
	 with '*', blurring it out. */
void Strikeout(char *hide, char *phrase)
{
	int i,j;
	int length_word = strlen(hide);
	int length_phrase = strlen(phrase);
	int Occurence[MAX_ARRAY_SIZE];
	int count = 0;
	int same_word;

	for (i = 0; i<length_phrase; i++) {
		if (phrase[i] == hide[0]) {
			Occurence[count] = i;
			count++;
		}
	}

	if(count>=1) {
		for (i = 0; i<count; i++) {
			j= 0;
			same_word = 1;

			while (same_word && j<length_word) {
				if (phrase[(Occurence[i]+j)] != hide[j]) {
					same_word = 0;
				}
				j++;
			}

			if (same_word) {
				for (j = Occurence[i]; j< (Occurence[i]+length_word); j++) {
					phrase[j] = '*';
				}
			}
		}
	}
}

/* The KthLargest function takes 3 inputs, an array of integers(values), the
	 number of values within the array (numValues)mthe kth largest value we
	 want to find(k), and returns the kth largest value within the array. If
	 there is no Kth largest value e.g. k > numValues, -1 is returned.

	 My function first checks is k is greater than numValues, if yes then -1 is
	 returned as K cannot be larger than numValues. Otherwise, an array of -1s
	 is created called kthlargest array. All values within the array less than
	 the position index of numValues are set to -1 (this is to account for
   duplicate integers in the array). A for loop is then used with 2 if
	 statements to determine the largest and the lowest value within the array,
	 highest and lowest. Highest is stored in the first position of the kth
	 largest array and also stored in the max_compare function. A nested for loop
	 is then used to find the consequent largest numbers. The nested for loop
	 scans the array for (numValues) number of times and stores the number that
	 is less than max_compare but greater than or equal to the lowest. i.e.
	 the next highest number that's less than the largest. If this value does not
	 equal the max_compare value then the value is stored in the next position
	 of the kth largest array and the max_compare is updated with the 2nd lowest
	 number. This process then repeats for the next lowest number and so on.
	 When the max_compare is equal to the minimum of the array, values are no
	 longer stored in the kth largest array as the if statement doesn't execute.
	 At the end the value from the K-1 position in the kth largest array is
	 returned.*/
int KthLargest(int k, int *values, int numValues)
{
	if (k>numValues) {
		return -1;
	}
	else {
		int kthlargestarray[MAX_ARRAY_SIZE];
		int highest = values[0];
		int max_compare = 0;
		int lowest = values[0];

		for (int i = 0; i<numValues; i++) {
			kthlargestarray[i] = -1;
		}

		for (int i = 1; i<numValues; i++) {
			if (values[i]> highest)
			highest = values[i];  //stores largest value in highest
			if (values[i]< lowest)
			lowest = values[i];  //stores lowest value in array to lowest
		}

		kthlargestarray[0] = highest;
		max_compare = highest;
		highest = lowest;

		for (int i = 1; i<numValues; i++) {
			for (int j = 0; j<numValues; j++) {
				if (values[j] >= highest && values[j] < max_compare ) {
					highest = values[j];
				}
			}

			if (max_compare!=highest) {
				max_compare = highest;
				kthlargestarray[i] = highest;
				highest = lowest;
			}
		}

		return kthlargestarray[k-1];
	}
}

/* The BoundingRectangle function takes two rectangle inputs, r1 and r2, and
	 outputs the minimum area rectangle that can entirely bound both of the
	 rectangules. The inputs and output are of type rectangle which has 4
	 components, row, column, height and width.

	 In order to find the row and column components of the bounding rectangle,
	 if and else conditionals were used. The row and column component should be
 	 the minimum of the row and col of the two input rectangles, so the if else
	 statements set result.col and result.row to the minimum of the two inputs.
	 To find the width and height components of the bounding rectangle the maximum
	 row and column for each rectangle is calculated by adding the height and row
	 and adding the col and width respectively. The max_row and max_col is set to
	 the largest value out of the two through the use of if conditionals. The
	 width and height of the bounding rectangle are then calculated by subtracting
	 the max width and max column by the col and row of the bounding rectangle
	 respectively (these were calculated in the first 2 if else statements).
	 After this the minimum bounding rectangle is returned as all 4 components
	 have been determined. */
Rectangle BoundingRectangle(Rectangle r1, Rectangle r2)
{
	Rectangle result;
	int max_col;
	int max_row;

	if (r1.row <= r2.row) {
		result.row = r1.row;
	}
	else {
		result.row = r2.row;
	}

	if (r1.col <= r2.col) {
		result.col = r1.col;
	}
	else {
		result.col = r2.col;
	}

	max_row = r1.height + r1.row;

	if ((r2.height + r2.row ) > max_row) {
		max_row  = r2.height + r2.row;
	}

	max_col = r1.width + r1.col;

	if ((r2.width + r2.col ) > max_col) {
		max_col  = r2.width + r2.col;
	}

	result.width = max_col - result.col;
	result.height = max_row - result.row;

	return result;
}

/* The Codeword function takes an array of characters as input and modifies
	 the string/character array to the word of choice. strcpy is used to copy
	 the word decoded from the NZ flag BMP to the input string.

	 To decode the word from the BMP image, a for loop was used to scan each pixel
	 in the first row of the picture to determine the RGB intensity of each pixel
	 using the function GetPixelValue. The remainder of each intensity divided by
	 2 was then printed in chronological order(these were the bits).
	 This then gave a binary sequence in the first 32 intensity values which
	 I used to decode my string length via binary to decimal conversion of the 32
	 bit sequence in reverse. Then the next 8 bits were used to decode a decimal
	 value which corresponds to an asci character. Then the process was repeated
	 for the next 8 bits and up until a word was obtained.  */
void Codeword(char *result)
{
	strcpy(result, "staphylococcus");
}

/* The function TallestVine takes 2 input seeds, A and B, and the number
 	 of growing days as input and outputs/returns the tallest point that
	 the vines will go to after the period of days.
	 The seeds grow by the sum of their digits each day and if at any points any
	 two length values of the vines are the same (even on different days) the
	 vines stop growing and that common value becomes the tallest value.

	 For this function I used the helper function SumOfDigits which is used to sum
	 the digits of an integer. It's algorithm is explained at the top in the
	 helper section function.

	 My algorithm grows the two vines separately using a while loop and the number
	 of days each vine is grown is stored in daysA and daysB respectively. The
	 loop only executes when both daysA and daysB are below days i.e. when growth
	 is still possible for any vine. First it checks is any of daysA or daysB is
	 the number of days, because in those scenarios only the opposite vine can
	 be grown. During each growth daysB or daysA is incremented depending on which
	 one grows. If neither days A or B are equal to days, then the smallest vine is
	 grown. If at any point the two seeds have the same value then the loop ends
	 and seedA is returned because the vines stop growing when they're the same
	 and join together. At the end of the while loop where growth has finished,
	 and the larger of the 2 seeds is returned */
int TallestVine(int seedA, int seedB, int days)
{
	int daysA = 0;
	int daysB = 0;

	while (daysA < days || daysB < days) {
		if (daysA == days) {
			seedB += SumOfDigits(seedB);
			daysB++;
		}

		else if (daysB == days) {
			seedA += SumOfDigits(seedA);
			daysA++;
		}

		else {

			if (seedA > seedB) {
				seedB += SumOfDigits(seedB);
				daysB++;
			}
			else {
				seedA += SumOfDigits(seedA);
				daysA++;
			}
		}

		if (seedA == seedB) {
			return seedA;
		}
	}

	if (seedA > seedB) {
		return seedA;
	}

	else {
		return seedB;
	}
}

/* The MakeMove function takes two inputs, an array of integers representing
	 the cave escape game and a character input called move. If move is w or a
	 or s or d then the caver within the cave array will move and an integer is
	 returned based on whether the game cave escape game was completed/finished
	 or not. If the game is not finished then the function returns 0.If the game
	 is finished because the player fell into a hole then the function returns 1
	 and if the game is finished because the player reached the exit then the
	 function returns 2.
	 The players movement is represented by 3 and it's movement is dependent on the
	 input character and the array position it is moving into. w moves the player
	 up, d for right, s for down, a for left.
	 The integers representing the various components of the cave_escape game are:
   0: Empty space
	 1: Wall obstacle
	 2: Boulder
	 3: Player
	 4: Hole
	 5: Exit

	 The algorithm I used makes use of the Rotate helper function which rotates
	 an array a number of times clockwise based on the input. I coded for the
	 scenario of an up player movement ('w' input for move) and rotated the array
	 for the rest of the movements to make the move so that the move is the
	 same as if it were an up movement and then the array is rotated back into
	 it's original configuration after the move.
	 The first if statements rotate the array accordingly based on the input.
	 The nested for loop then scans for the position of the hole and the player
	 and stores them in hole_row,hole_col and row,col respectively.

	 The scenarios of the cave escape game are then coded for.
	 The if statements check the value of [row-1][col] of the array as that's
	 what the player moves into when 'w' is the user input. If it's 0 (empty space)
	 then the player moves into then the two values are swapped and 0 is returned.
	 If the player moves into a hole(4) then 1 is returned and the player
	 disappears. If the player moves into 1 then the player does not move and 0
	 is returned. If the player moves into the exit (5) then the player is swapped
	 with the 5 square and 2 is returned to indicate the end of the game.
	 If the players moves into a boulder then a loop scans the column for an
	 obstacle and stores it's index in obstacle row. The Boulder would then move
	 just below the obstacle if it is not already blocked by an
	 obstacle([row-2][col] is not 2 and 1) and 0 is returned. If the boulder is
	 pushed into a hole then both disappear. These scenarios are all coded for
	 using if statements.
	 */
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
