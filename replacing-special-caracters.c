#include <stdio.h>

/* program to replace tab by \t,
 * space by \b
 * and backslash by \\ */
main()
{
	int c;
	
	while((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == ' ') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
}
