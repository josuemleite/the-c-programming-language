#include <stdio.h>
#define LEN 80
#define MAXLINE 1000
#define MAXTEXT 10000

int getline(char[], int);
void copy(char[], char[], int);
void read(char[], int);

main()
{
	int len;
	int position;
	char line[MAXLINE];
	char longest[MAXTEXT];
	
	position = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LEN) {
			copy(longest, line, position);
			position += len;
		}
	if (position > 0)
		read(longest, position);
	return 0;
}

int getline(char line[], int maxline)
{
	int c, i;
	
	for (i = 0; i<maxline && (c = getchar())!=EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[], int position)
{
	int i;
	
	i = 0;
	while ((to[position] = from[i]) != '\0') {
		++i;
		++position;
	}
}

void read(char text[], int size)
{
	int i;
	
	for (i = 0; i<=size; ++i)
		printf("%c", text[i]);
}
