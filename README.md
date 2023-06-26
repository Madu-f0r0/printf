0x11. C - printf is a peer  project that takes a deep dive into the implentation of the printf function. printf is a C standard library function that prints a formatted string to standard output. Its prototype is contained in the stdio.h header file.

Our implemented printf function is called using the syntax:

	int _printf(const char *format, ...)

It takes a string as mandatory argument, and a number of optional arguments to be printed too. These optional arguments are denoted in the format string using format specifiers which are denoted with a '%' and a character depending on the data type of the argument to be printed. It returns the number of bytes printed.

Collaborators: Daniel Herbert, Oluwatosin Ajayi
