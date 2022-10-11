Class: Operating Systems
Assignment: Project 1
Name: Phat Tran

===============================
Resources Used
===============================
https://austinedger.medium.com/unix-commands-lets-build-cat-59b8a91b9708
	Implementation of cat, used majority of it in ffcat.c, also used the layout of the code for ffwc.c

https://www.programiz.com/c-programming/library-function/ctype.h
	<ctype.h> library information, used to figure out which function would work for ffwc.c
	
https://stackoverflow.com/questions/29772650/counting-words-in-a-file-in-c
	Used the method on how to count characters and whitespaces, also incorporated the state usage

===============================
Implementation of cat: ffcat.c
===============================
How to run:
1. Open up terminal
2. Go to the file's folder destination with cd commands
3. Type: make ffcat, to create the binary file of ffcat
4. With this implementation, ffcat will only read the files that are currently in the same folder
5. The way to run ffcat is to type: ./ffcat [insert file name(s)]
6. The program will return the file into the terminal.

===============================
Implementation of wc: ffwc.c
===============================
How to run:
1. Open up terminal
2. Go to the file's folder destination with cd commands
3. Type: make ffwc, to create the binary file of ffwc
4. With this implementation, ffwc will only read the files that are currently in the same folder
5. I implemented the same return statement as the wc command:
	[lines] [words] [chars] [filename]
	Also, if the program takes in 2 or more file arguments, then it will return the total just as wc.
	[total_lines] [total_words] [total_chars] [total]

	It will also ignore extra whitespaces, or will count just like wc command.
6. The way to run ffwc is to type: ./ffwc [insert file name(s)]
7. The program will return the same output as wc into the terminal

================================
Both
================================
Both programs will be able to accept more than one file arguments:
	Ex. ./ffwc ffcat.c ffwc.c
	
Both programs will return an error if there isn't a file that is contained in the same folder.


	

