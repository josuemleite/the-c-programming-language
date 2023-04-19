#include <stdio.h>

/* program to count blanks, tabs and newlines */
main()
{
	int c, b, t, nl;
	
	b = 0;
	t = 0;
	nl = 0;
	
	while((c = getchar()) != EOF) {
		if (c == ' ')
			++b;
		if (c == '\t')
			++t;
		if (c == '\n')
			++nl;
	}
	printf("%d\n", b);
	printf("%d\n", t);
	printf("%d\n", nl);
}
