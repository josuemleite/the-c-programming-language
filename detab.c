/**
 * This program replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop.
 *
 * For example, if you consider the tab size to be 4
 * ----|----|----|----
 * and type
 * hi--|----|----|----
 * when you press the tab key, the cursor will move to the next tab stop.
 * hi-->|<----|----|----
 *
 * reference: https://stackoverflow.com/questions/23583252/exercise-1-20-of-the-book-c-the-programming-language-2nd-edition
 */
#include <stdio.h>

#define MAX_BUFFER 1024
#define SPACE	   ' '
#define TAB        '\t'
#define TAB_SIZE   4

int getline(char s[], int lim);
int calculateNumberOfSpaces(int offset, int tabSize);

int main()
{
	int i, j, k, l;
	char buffer[MAX_BUFFER];

	while (getline(buffer, MAX_BUFFER) > 0) {
		for (i=0, l=0; buffer[i]!='\0'; ++i) {
			if (buffer[i] == TAB) {
				j = calculateNumberOfSpaces(l, TAB_SIZE);
				for (k=0; k<j; ++k) {
					putchar(SPACE);
					++l;
				}
			} else {
				putchar(buffer[i]);
				++l;
			}
		}
	}

	return 0;	
}

int getline(char s[], int lim)
{
	int c, i;
	
	for (i=0; i<lim && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	
	return i;
}

int calculateNumberOfSpaces(int offset, int tabSize)
{
	return tabSize - (offset % tabSize);
}
