#include <stdio.h>

#define MAX_BUFFER 1024
#define SPACE	   ' '
#define TAB        '\t'
#define TAB_SIZE   5

int getline(char s[], int lim);
int calculateNumberOfSpaces(int offset, int tabSize);

int main()
{
	int i, j, k, l, m;
	char buffer[MAX_BUFFER];

	while (getline(buffer, MAX_BUFFER) > 0) {
		for (i=0, l=0, m=0; buffer[i]!='\0'; ++i) {
			if (buffer[i] == SPACE) {
				++m;
				if (m == TAB_SIZE) {
					putchar(TAB);
					i+=TAB_SIZE;
					m=0;
				} else {
					++l;
				}
			} else {
				while (m > 0) {
					putchar(SPACE);
					--m;
				}
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
