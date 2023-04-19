#include <stdio.h>

/* program to replace blanks by a single blank */
main()
{
	int c = 0, nc;
		
	while ((nc = getchar()) != EOF) {
		if (nc == ' ') {
			if (c != ' ')
				putchar(nc);
		}
		else
			putchar(nc);
		c = nc;
	}
}
