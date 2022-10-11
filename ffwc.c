#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char *argv[] ) {

	/*
	currentFile points to specific argument in the command line, starts at 1.
	*/
	FILE *file;
	int currentFile = (argc > 1 ? 1 : 0);
	
	int total_lines = 0;
	int total_words = 0;
	int total_chars = 0;
	
	while (currentFile < argc) {
		/*
		Variable initialization
			int ch: used as an argument to check certain requirements in the while loop
			int state: used as a boolean type, 0 if it is a space, 1 if its not a space
			int words, lines, chars: used to store data and print out into the terminal
		*/
		int ch;
		int state;
		int words = 0;
		int lines = 0;
		int chars = 0;
		
		/*
		Checks if currentFile is a true condition with fopen() exits if file argument returns NULL
		*/
		if (argc > 1) {
			file = fopen(argv[currentFile], "rb");
			if (file == NULL) {
				fprintf(stderr, "%s: %s: No such file or directory \n",
					argv[0], argv[currentFile]);
				exit(1);
			}
		}
		
		/*
		Set state as 0 so once the while loop starts reading, it doesn't register the state being
		a word before it began reading the file with fgetc()
		*/
		state = 0;
		
		while ((ch = fgetc(file)) != EOF) {
			if (ch == '\n') {
				++lines;
			}
			/*
			isspace(), isalnum(), and ispunct() are functions provided in <ctype.h>
			Allows us to read ch if it is a space, alphabet or number, and or a punctuation.
			*/
			if (isspace(ch)) {
				state = 0;
			}
			
			else if (state == 0 && isalnum(ch) || state == 0 && ispunct(ch)) {
				state = 1;
				++words;
			}
			
			/*
			Since the while loop is going through every character in the file, chars is
			incremented at the end.
			*/
			++chars;
		}
		
		/*
		Prints out wc data to terminal, almost formatted like the actual wc but ran into spacing
		problems.
		*/
		fprintf(stdout, "%3d %3d %3d %s\n", lines, words, chars, argv[currentFile]);
		
		/*
		Closes the file and then increase currentFile to move onto the next file if NOT 0.
		Adds currentFile's variables to global variables.
		*/
		total_lines += lines;
		total_words += words;
		total_chars += chars;
		fclose(file);
		currentFile++;
	}
	
	/*
	If arguments are greater than 2 (this somehow works for this case rather than > 1) it will
	print out the global variables for the total of the two or more files.
	*/
	if (argc > 2) {
		fprintf(stdout, "%3d %3d %3d %s\n", total_lines, total_words, total_chars, "total");
	}
	return 0;
}
