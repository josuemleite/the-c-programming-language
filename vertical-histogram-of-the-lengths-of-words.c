#include <stdio.h>
#include <windows.h>

/* vertical histogram of the lenghts of words */
main()
{
	int c, i, j, max = 0;
	int ndigit[10];

	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
		
	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0 | 0xf);
	for (i = 0; i < 10; ++i) {
		printf("%d ", i);
		if (ndigit[i] > max)
			max = ndigit[i];
	}
	putchar('\n');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (i = 0; i < max; ++i) {
		for (j = 0; j < 10; ++j) {
			if (ndigit[j]) {
				putchar('|');
				putchar(' ');
				--ndigit[j];
			}
			else {
				putchar(' ');
				putchar(' ');
			}
		}
		putchar('\n');
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0 | 0xf);
}
