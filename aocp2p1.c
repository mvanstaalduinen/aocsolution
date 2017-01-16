/*
 * Melissa vanStaalduinen
 *
 * Solution to advent of code puzzle 2 part 1
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

	 const int numpad[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	 int current[2] = {1,1}; // set current location to 5;
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
			if (current[0] != 0)
				current[0] -= 1;
		} else if (c == 'D') {
			if (current[0] != 2)
				current[0] += 1;
		} else if (c == 'L') {
			if (current[1] != 0)
				current[1] -= 1;
		} else if (c == 'R') {
			if (current[1] != 2)
				current[1] += 1;
		} else {
			// new line char means a number in the code has been found.
			*(code + count) = numpad[current[0]][current[1]];
			count++;
		}
	}
	// because of EOF
	*(code + count) = numpad[current[0]][current[1]];
	count++;

	printf("The code for the washroom is: ");
	for (int i = 0; i < count; i++) {
		printf("%d", *(code + i));
	}
	printf("\n");

	fclose(fp);
	free(code);
	return 1;
 }
