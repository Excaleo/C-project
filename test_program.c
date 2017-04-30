/* Test program for ENGGEN 131 Project Two - 2016 */
/* Prepared by Paul Denny, September 2016 */

#include "project.h"
#include <stdlib.h>
#include <time.h>

/* You are encouraged to add additional tests to the testing functions */
/* defined in this program.  There are ten test functions, one for each */
/* of the functions you are required to define for this project */


void Test_Perimeter(void);
void Test_Volume(void);
void Test_PrimeBelow(void);
void Test_Abbreviate(void);
void Test_Strikeout(void);
void Test_KthLargest(void);
void Test_BoundingRectangle(void);
void Test_Codeword(void);
void Test_TallestVine(void);
void Test_MakeMove(void);

/* You do not need to modify the main() function - it simply calls each of */
/* the test functions */
int main(void)
{
	srand((unsigned int)time(NULL));
	// Print welcome message
	//printf("\nWelcome to the minimal test program for Project Two.\n\n");
	//printf("This test program provides an absolute minimal set of test cases\n");
	//printf("that you can use to automatically test the functions you have defined\n");
	//printf("for the project.  Failing any of these tests is an indication that there\n");
	//printf("is an error in your implementation.  However, because this is a minimal\n");
	//printf("set of tests, passing all of them is no guarantee that your functions\n");
	//printf("are defined correctly.  It is up to you to test your code more thoroughly,\n");
	//printf("but hopefully this template will be a useful guide for you.\n\n");
	//printf("Good luck!\n");

	// Automated testing of each function
	Test_Perimeter();
	Test_Volume();
	Test_PrimeBelow();
	Test_Abbreviate();
	Test_Strikeout();
	Test_KthLargest();
	Test_BoundingRectangle();
	Test_Codeword();
	Test_TallestVine();
	Test_MakeMove();

	return 0;
}

void Test_Perimeter(void)
{
	printf("\nTesting Perimeter()...\n");
	int i = 0;
	if (Perimeter(10, 25) != 70) {
		printf("  - FAIL (10, 25)\n");
	}
	else {
		i++;
	}
	if (Perimeter(20, -1) != 0) {
		printf("  - FAIL (20, -1)\n");
	}
	else {
		i++;
	}
	if (Perimeter(50, -5) != 0) {
		printf("  - FAIL (50, -5)\n");
	}
	else {
		i++;
	}
	if (Perimeter(-1, -5) != 0) {
		printf("  - FAIL (-1, -5)\n");
	}
	else {
		i++;
	}
	if (Perimeter(1000, 1001) != 4002) {
		printf("  - FAIL (1000, 1001)\n");
	}
	else {
		i++;
	}
	if (Perimeter(0, 100) != 200) {
		printf("  - FAIL (0, 100)\n");
	}
	else {
		i++;
	}
	printf("You passed %d out of 6 tests\n", i);
}

void Test_Volume(void)
{
	printf("\nTesting Volume()...\n");
	int i = 0;
	if ((Volume(10) < 4188.78) || (Volume(10) > 4188.80)) {
		printf("  - FAIL (10)\n");
	}
	else {
		i++;
	}
	if ((Volume(-5) < -0.001) || (Volume(-5) > 0.001)) {
		printf("  - FAIL (-5)\n");
	}
	else {
		i++;
	}
	if ((Volume(0) < -0.001) || (Volume(0) > 0.001)) {
		printf("  - FAIL (0)\n");
	}
	else {
		i++;
	}
	if ((Volume(1) < 4.18) || (Volume(1) > 4.20)) {
		printf("  - FAIL (1)\n");
	}
	else {
		i++;
	}
	printf("You passed %d out of 4 tests\n", i);
}

void Test_PrimeBelow(void)
{
	int i = 0;
	printf("\nTesting PrimeBelow()...\n");
	if (PrimeBelow(-100) != -1) {
		printf("  - FAIL (-100)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(-1) != -1) {
		printf("  - FAIL (-1)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(0) != -1) {
		printf("  - FAIL (0)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(1) != -1) {
		printf("  - FAIL (1)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(2) != -1) {
		printf("  - FAIL (2)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(3) != 2) {
		printf("  - FAIL (3)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(10) != 7) {
		printf("  - FAIL (10)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(47) != 43) {
		printf("  - FAIL (47)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(100) != 97) {
		printf("  - FAIL (100)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(150) != 149) {
		printf("  - FAIL (150)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(1000) != 997) {
		printf("  - FAIL (1000)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(7919) != 7907) {
		printf("  - FAIL (7919)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow(104729) != 104723) {
		printf("  - FAIL (104729)\n");
	}
	else {
		i++;
	}
	if (PrimeBelow((int)0x80000000) != -1) {
		printf("  - FAIL ((int)0x80000000)\n");
	}
	else {
		i++;
	}
	printf("You passed %d out of 14 tests\n", i);
}

void Test_Abbreviate(void)
{
	char wordA[MAX_ARRAY_SIZE] = "facetiously";
	char wordB[MAX_ARRAY_SIZE] = "meet you at the movies tonight";
	char wordC[MAX_ARRAY_SIZE] = "sequoia";
	char wordD[MAX_ARRAY_SIZE] = "wry";
	char wordE[MAX_ARRAY_SIZE] = "12345678a90";
	char wordH[MAX_ARRAY_SIZE] = "aeiou";
	char wordI[MAX_ARRAY_SIZE] = "onomatopoeia";
	char wordJ[MAX_ARRAY_SIZE] = "aaia rencheck";
	char wordK[MAX_ARRAY_SIZE] = " ;;;rt-0102:\"";

	printf("\nTesting Abbreviate()...\n");

	int i = 0;

	Abbreviate(wordA);
	Abbreviate(wordB);
	Abbreviate(wordC);
	Abbreviate(wordD);
	Abbreviate(wordE);
	Abbreviate(wordH);
	Abbreviate(wordI);
	Abbreviate(wordJ);
	Abbreviate(wordK);

	if (strcmp(wordA, "fctsly") != 0) {
		printf("  - FAIL (wordA)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordB, "mt y t th mvs tnght") != 0) {
		printf("  - FAIL (wordB)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordC, "sq") != 0) {
		printf("  - FAIL (wordC)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordD, "wry") != 0) {
		printf("  - FAIL (wordD)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordE, "1234567890") != 0) {
		printf("  - FAIL (wordE)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordH, "") != 0) {
		printf("  - FAIL (wordH)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordI, "nmtp") != 0) {
		printf("  - FAIL (wordI)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordJ, " rnchck") != 0) {
		printf("  - FAIL (wordJ)\n");
	}
	else {
		i++;
	}
	if (strcmp(wordK, " ;;;rt-0102:\"") != 0) {
		printf("  - FAIL (wordK)\n");
	}
	else {
		i++;
	}
	printf("You passed %d out of 9 tests\n", i);
}

void Test_Strikeout(void)
{
	char wordA[MAX_ARRAY_SIZE] = "nail";
	char phraseA[MAX_ARRAY_SIZE] = "get the nail out";

	char wordB[MAX_ARRAY_SIZE] = "hello";
	char phraseB[MAX_ARRAY_SIZE] = "hello world";

	char wordC[MAX_ARRAY_SIZE] = "cat";
	char phraseC[MAX_ARRAY_SIZE] = "cat dog cat cat ant cat";

	char wordD[MAX_ARRAY_SIZE] = "finish";
	char phraseD[MAX_ARRAY_SIZE] = "finish";

	char wordE[MAX_ARRAY_SIZE] = "i";
	char phraseE[MAX_ARRAY_SIZE] = "informative interrogation";

	char wordF[MAX_ARRAY_SIZE] = "";
	char phraseF[MAX_ARRAY_SIZE] = "hello";

	char wordG[MAX_ARRAY_SIZE] = "cat";
	char phraseG[MAX_ARRAY_SIZE] = "cat dog cat cat gattacat";

	char wordH[MAX_ARRAY_SIZE] = "fuck";
	char phraseH[MAX_ARRAY_SIZE] = "fuck, please strike that out";

	char wordI[MAX_ARRAY_SIZE] = "be";
	char phraseI[MAX_ARRAY_SIZE] = "bye";

	char wordJ[MAX_ARRAY_SIZE] = "bye";
	char phraseJ[MAX_ARRAY_SIZE] = "byebyebyebyebyebyebyebyeby";
	printf("\nTesting Strikeout()...\n");

	Strikeout(wordA, phraseA);
	Strikeout(wordB, phraseB);
	Strikeout(wordC, phraseC);
	Strikeout(wordD, phraseD);
	Strikeout(wordE, phraseE);
	Strikeout(wordF, phraseF);
	Strikeout(wordG, phraseG);
	Strikeout(wordH, phraseH);
	Strikeout(wordI, phraseI);
	Strikeout(wordJ, phraseJ);

	int i = 0;

	if (strcmp(phraseA, "get the **** out") != 0) {
		printf("  - FAIL (wordA)\n");
		printf("    - error \"%s\"\n", phraseA);
	}
	else {
		i++;
	}
	if (strcmp(phraseB, "***** world") != 0) {
		printf("  - FAIL (wordB)\n");
		printf("    - error \"%s\"\n", phraseB);
	}
	else {
		i++;
	}
	if (strcmp(phraseC, "*** dog *** *** ant ***") != 0) {
		printf("  - FAIL (wordC)\n");
		printf("    - error \"%s\"\n", phraseC);
	}
	else {
		i++;
	}
	if (strcmp(phraseD, "******") != 0) {
		printf("  - FAIL (wordD)\n");
		printf("    - error \"%s\"\n", phraseD);
	}
	else {
		i++;
	}
	if (strcmp(phraseE, "*nformat*ve *nterrogat*on") != 0) {
		printf("  - FAIL (wordE)\n");
		printf("    - error \"%s\"\n", phraseE);
	}
	else {
		i++;
	}
	if (strcmp(phraseF, "hello") != 0) {
		printf("  - FAIL (wordF)\n");
		printf("    - error \"%s\"\n", phraseF);
	}
	else {
		i++;
	}
	if (strcmp(phraseG, "*** dog *** *** gatta***") != 0) {
		printf("  - FAIL (wordG)\n");
		printf("    - error \"%s\"\n", phraseG);
	}
	else {
		i++;
	}
	if (strcmp(phraseH, "****, please strike that out") != 0) {
		printf("  - FAIL (wordH)\n");
		printf("    - error \"%s\"\n", phraseH);
	}
	else {
		i++;
	}
	if (strcmp(phraseI, "bye") != 0) {
		printf("  - FAIL (wordI)\n");
		printf("    - error \"%s\"\n", phraseI);
	}
	else {
		i++;
	}
	if (strcmp(phraseJ, "************************by") != 0) {
		printf("  - FAIL (wordJ)\n");
		printf("    - error \"%s\"\n", phraseJ);
	}
	else {
		i++;
	}

	printf("You passed %d out of 10 tests\n", i);
}

void PrintArray(int array[],int arraysize) {

	int i;
	printf("{");
	for (i = 0;i < arraysize;i++) {
		printf(" %d ", array[i]);
		if (((i+1) % 10 == 0)){
			printf("\n ");
		}
	}
	printf("}");
}

void Test_KthLargest(void)
{
	int valuesA[12] = { 4, 3, 7, 6, 3, 1, 4, 2, 6, 7, 6, 7 };
	int valuesB[5] = { 3, 3, 999, 3, 3 };
	int valuesC[7] = { 5, 1, 2, 5, 4, 1, 2 };
	int valuesD[6] = { 0, 0, 0, 0, 0, 0 };
	int valuesE[7] = {-1,-2,-3, 0, 1, 2, 3 };
	int valuesF[1] = {0};
	int valuesG[1] = { 1 };
	int valuesH[1] = { -1 };
	int valuesI[MAX_ARRAY_SIZE] = { 0,2,4,6,8,10,12,14,16,18,20,999,1000,50000,5000,1000000,700,200,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,4,4,45};
	int valuesJ[13] = { -69,69,2,0,-1,-2,-1,0,-3,-4,-4,-4,0 };
	int i = 0;
	/*
	int lengthofarray, k, m, n;
	int randomarray[MAX_ARRAY_SIZE] = { 0 };

	/*for (n = 0;n < 10;n++) {
		lengthofarray = (rand() % 200) + 1;
		for (k = 0;k < lengthofarray;k++) {
			randomarray[k] = rand();
		}
		m = (rand() % (lengthofarray+1)) + 1;

		printf("\n\n");
		PrintArray(randomarray, lengthofarray);
		printf("\nThe %dth value of array: ", m);
		printf("\n is %d \n array size %d \n", (KthLargest(m, randomarray, lengthofarray)), lengthofarray);
		PrintArray(randomarray, lengthofarray);
	}
	*/

	printf("\nTesting KthLargest()...\n");

	if (KthLargest(7, valuesJ, 13) != -4) {
		printf("  - FAIL (valuesJ)\n");
	}
	else {
		i++;
	}if (KthLargest(1, valuesA, 12) != 7) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesA, 12) != 6) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(3, valuesA, 12) != 4) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(4, valuesA, 12) != 3) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(5, valuesA, 12) != 2) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(6, valuesA, 12) != 1) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(7, valuesA, 12) != -1) {
		printf("  - FAIL (valuesA)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesB, 5) != 999) {
		printf("  - FAIL (valuesB)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesB, 5) != 3) {
		printf("  - FAIL (valuesB)\n");
	}
	else {
		i++;
	}
	if (KthLargest(3, valuesB, 5) != -1) {
		printf("  - FAIL (valuesB)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesC, 7) != 5) {
		printf("  - FAIL (valuesC)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesC, 7) != 4) {
		printf("  - FAIL (valuesC)\n");
	}
	else {
		i++;
	}
	if (KthLargest(3, valuesC, 7) != 2) {
		printf("  - FAIL (valuesC)\n");
	}
	else {
		i++;
	}
	if (KthLargest(4, valuesC, 7) != 1) {
		printf("  - FAIL (valuesC)\n");
	}
	else {
		i++;
	}
	if (KthLargest(5, valuesC, 7) != -1) {
		printf("  - FAIL (valuesC)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesD, 6) != 0) {
		printf("  - FAIL (valuesD)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesD, 6) != -1) {
		printf("  - FAIL (valuesD)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesE, 7) != 3) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesE, 7) != 2) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(3, valuesE, 7) != 1) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(4, valuesE, 7) != 0) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(5, valuesE, 7) != -1) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(6, valuesE, 7) != -2) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(7, valuesE, 7) != -3) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(8, valuesE, 7) != -1) {
		printf("  - FAIL (valuesE)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesF, 1) != 0) {
		printf("  - FAIL (valuesF)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesF, 1) != -1) {
		printf("  - FAIL (valuesF)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesG, 1) != 1) {
		printf("  - FAIL (valuesG)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesG, 1) != -1) {
		printf("  - FAIL (valuesG)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesH, 1) != -1) {
		printf("  - FAIL (valuesH)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesH, 1) != -1) {
		printf("  - FAIL (valuesH)\n");
	}
	else {
		i++;
	}
	if (KthLargest(1, valuesI, 200) != 1000000) {
		printf("  - FAIL (valuesI)\n");
	}
	else {
		i++;
	}
	if (KthLargest(2, valuesI, 200) != 50000) {
		printf("  - FAIL (valuesI)\n");
	}
	else {
		i++;
	}
	if (KthLargest(3, valuesI, 200) != 5000) {
		printf("  - FAIL (valuesI)\n");
	}
	else {
		i++;
	}
	if (KthLargest(24, valuesI, 200) != 0) {
		printf("  - FAIL (valuesI)\n");
	}
	else {
		i++;
	}

	printf("You passed %d out of 36 tests\n", i);

}

void Test_BoundingRectangle(void)
{
	printf("\nTesting BoundingRectangle()...\n");

	Rectangle a, b, c1, c2,c3, tiny;
	a.row = 35;
	a.col = 20;
	a.width = 110;
	a.height = 50;
	b.row = 70;
	b.col = 10;
	b.width = 35;
	b.height = 55;
	tiny.row = 45;
	tiny.col = 45;
	tiny.width = 5;
	tiny.height = 5;
	c1 = BoundingRectangle(a, b);
	int i = 0;
	if (c1.row != 35 || c1.col != 10 || c1.width != 120 || c1.height != 90) {
		printf("  - FAIL (c1)\n");
		printf("%d its supposed to be 35\n", c1.row);
		printf("%d its supposed to be 10\n", c1.col);
		printf("%d its supposed to be 120\n", c1.width);
		printf("%d its supposed to be 90\n", c1.height);
	}
	else {
		i++;
	}
	c2 = BoundingRectangle(a, tiny);
	if (c2.row != 35 || c2.col != 20 || c2.width != 110 || c2.height != 50) {
		printf("  - FAIL (c2)\n");
		printf("%d its supposed to be 35\n", c2.row);
		printf("%d its supposed to be 20\n", c2.col);
		printf("%d its supposed to be 110\n", c2.width);
		printf("%d its supposed to be 50\n", c2.height);
	}
	else {
		i++;
	}
	c3 = BoundingRectangle(b, tiny);
	if (c3.row != 45 || c3.col != 10 || c3.width != 40 || c3.height != 80) {
		printf("  - FAIL (c3), this is a test for two rectangles that do not overlap at all\n");
		printf("%d its supposed to be 45\n", c2.row);
		printf("%d its supposed to be 10\n", c2.col);
		printf("%d its supposed to be 40\n", c2.width);
		printf("%d its supposed to be 80\n", c2.height);
	}
	else {
		i++;
	}
	printf("You passed %d out of 3 tests\n", i);

}

void Test_Codeword(void)
{
	//printf("\nTesting Codeword()...\n");
	//printf("  - This function cannot be tested automatically\n");
}

void Test_TallestVine(void)
{
	printf("\nTesting TallestVine()...\n");
	int i = 0;
	if (TallestVine(501, 491, 8) != 609) {
		printf("  - FAIL (501, 491, 8)\n");
		printf("You got : %d, its supposed to be 609\n", TallestVine(501, 491, 8));
	}
	else {
		i++;
	}
	if (TallestVine(429, 501, 8) != 519) {
		printf("  - FAIL (429, 501, 8)\n");
		printf("You got : %d, its supposed to be 519\n", TallestVine(429, 501, 8));
	}
	else {
		i++;
	}
	if (TallestVine(501, 399, 7) != 588) {
		printf("  - FAIL (501, 399, 7)\n");
		printf("You got : %d, its supposed to be 588\n", TallestVine(501, 399, 7));
	}
	else {
		i++;
	}
	if (TallestVine(501, 399, 8) != 507) {
		printf("  - FAIL (501, 399, 7)\n");
		printf("You got : %d, its supposed to be 507\n", TallestVine(501, 399, 8));
	}
	else {
		i++;
	}
	if (TallestVine(20, 1000, 72) != 1972) {
		printf("  - FAIL (20, 1000, 72)\n");
		printf("You got : %d, its supposed to be 1972\n", TallestVine(20, 1000, 72));
	}
	else {
		i++;
	}
	if (TallestVine(20, 1000, 73) != 1003) {
		printf("  - FAIL (20, 1000, 73)\n");
		printf("You got : %d, its supposed to be 1003\n", TallestVine(20, 1000, 73));
	}
	else {
		i++;
	}
	if (TallestVine(480, 481, 5000) != 107598) {
		printf("  - FAIL (480, 481, 5000)\n");
		printf("You got : %d, its supposed to be 107598\n", TallestVine(480, 481, 5000));
	}
	else {
		i++;
	}
	if (TallestVine(480, 481, 500) != 9120) {
		printf("  - FAIL (480, 481, 500)\n");
		printf("You got : %d, its supposed to be 9120\n", TallestVine(480, 481, 500));
	}
	else {
		i++;
	}
	if (TallestVine(480, 481, 100) != 1893) {
		printf("  - FAIL (480, 481, 100)\n");
		printf("You got : %d, its supposed to be 1893\n", TallestVine(480, 481, 100));
	}
	else {
		i++;
	}
	if (TallestVine(1, 2, 100) != 2) {
		printf("  - FAIL (480, 481, 100)\n");
		printf("You got : %d, its supposed to be 1893\n", TallestVine(480, 481, 100));
	}
	else {
		i++;
	}
	printf("You passed %d out of 10 tests\n", i);
}

void Test_MakeMove(void)
{
	int i, j, k = 0;
	int result;
	int correct = 1;

	printf("\nTesting MakeMove()...\n");

	int in_cave[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 2, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 3, 0, 4, 5},
		{1, 0, 0, 1, 0, 0, 2, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	int out_cave[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 2, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 4, 5},
		{1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 0, 2, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	int in_cave1[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 2, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 3, 4, 5 },
		{ 1, 0, 0, 1, 0, 0, 2, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	int out_cave1[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 2, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 4, 5 },
		{ 1, 0, 0, 1, 0, 0, 2, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	int in_cave2[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 2, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 3, 2, 4, 5 },
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	int out_cave2[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 2, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 3, 0, 5 },
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	int in_cave3[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 2, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 3, 5 },
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	int out_cave3[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 2, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	result = MakeMove(in_cave, 's');
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (out_cave[i][j] != in_cave[i][j]) {
				correct = 0;
			}
		}
	}
	if ((correct)&&(result==0)) {
		k++;
	}
	else {
		printf("  - FAIL (MakeMove)\n");
	}


	result = MakeMove(in_cave1, 'd');
	correct = 1;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (out_cave1[i][j] != in_cave1[i][j]) {
				correct = 0;
			}
		}
	}
	if ((correct)&&(result)) {
		k++;
	}
	else {
		printf("  - FAIL (MakeMove)\n");
	}

	result = MakeMove(in_cave2, 'd');
	correct = 1;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (out_cave2[i][j] != in_cave2[i][j]) {
				correct = 0;
			}
		}
	}
	if ((correct)&&(result==0)) {
		k++;
	}
	else {
		printf("  - FAIL (MakeMove)\n");
	}

	result = MakeMove(in_cave3, 'd');
	correct = 1;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (out_cave3[i][j] != in_cave3[i][j]) {
				correct = 0;
			}
		}
	}
	if ((correct) && (result == 2)) {
		k++;
	}
	else {
		printf("  - FAIL (MakeMove)\n");
	}

	printf("You passed %d out of 4 tests\n\n", k);
}
