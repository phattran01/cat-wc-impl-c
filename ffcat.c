#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ) {

	/*
	Initializes buffer variable that allows temporary space for reading file data.
	currentFile points to specific argument in the command line, starts at 1.
	*/
	FILE *file;
	const int bufferSize = 4096;
	char buffer[bufferSize];
	int currentFile = (argc > 1 ? 1 : 0);
	
	while (currentFile < argc) {
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
		Uses fgets to load the file line by line into the buffer.
		Prints out the buffer, which is the output of the file, line by line with while loop.
		*/
		while (fgets(buffer, bufferSize, (file == NULL ? stdin : file))) {
			int length = strlen(buffer);
			buffer[length - 1] = '\0';
			
			fprintf(stdout, "%s\n", buffer);
		}
		
		/*
		Closes the file and then increase currentFile to move onto the next file if NOT 0.
		*/
		fclose(file);
		currentFile++;
	}
	
	
	return 0;
}
