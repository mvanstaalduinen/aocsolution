/*
 * Melissa vanStaalduinen
 *
 * Solution to advent of code puzzle 2 part 2
 * http://adventofcode.com/2016/day/2
 */

 # include <stdio.h>
 # include <stdlib.h>
 # include <ctype.h>

 int main(int argc, char *argv[])
 {
	 if (argc != 2) {
		 printf("Please give Filename.\n");
		 exit(EXIT_FAILURE);
	 }

	 const char numpad[5][5] = {{'0','0','1','0','0'}, {'0','2','3','4','0'},
	 							{'5','6','7','8','9'}, {'0','A','B','C','0'},
								{'0','0','D','0','0'}};
	 int row = 3; // set current location to 5;
	 int col = 0;
	 int *code;
	 int count = 0;
	 char c;
	 code = malloc(50*sizeof(int));

	 FILE *fp;
	 fp = fopen(argv[1], "r");
	 if (fp == NULL) {
		 printf("Cannot open file %s.\n", argv[1]);
		 exit(EXIT_FAILURE);
	 }

	// get char
	while ((c = fgetc(fp)) != EOF) {
		if (c == 'U') {
			if ((row != 0) && (numpad[row-1][col] != '0'))
				row -= 1;
		} else if (c == 'D') {
			if ((row != 4) && (numpad[row+1][col] != '0'))
				row += 1;
		} else if (c == 'L') {
			if ((col != 0) && (numpad[row][col-1] != '0'))
				col -= 1;
		} else if (c == 'R') {
			if ((col != 4) && (numpad[row][col+1] != '0'))
				col += 1;
		} else {
			// new line char means a number in the code has been found.
			*(code + count) = numpad[row][col];
			count++;
		}
	}
	// because of EOF
	*(code + count) = numpad[row][col];
	count++;

	printf("The code for the washroom is: ");
	for (int i = 0; i < count; i++) {
		printf("%c", *(code + i));
	}
	printf("\n");

	fclose(fp);
	free(code);
	return 1;
 }
