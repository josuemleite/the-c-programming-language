#include <stdio.h>
#define LEN 100
#define TEXT 1000

int getline(char line[], int limit);
void copy(char to[], char from[]);
void reverse(char text[], int size);

int main()
{
	int len, size;
	char line[LEN];
	char text[TEXT];
	char reversed[TEXT];
	
	while ((len = getline(line, LEN)) > 0)
		copy(text, line);
		
	size = length(text);
	
	reverse(text, size);
	
	printf("%s", text);
	
	return 0;	
}

int getline(char s[], int lim)
{
	int i, c;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	
	return i;
}

void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

int length(char text[])
{
	int i;
	
	i = 0;
	while (text[i] != '\0')
		++i;
	
	return i;
}

void reverse(char text[], int size)
{
	int i, s;
	char reversed[size];
	
	s = size;
	for (i=0; i<size; ++i)
		reversed[i] = text[--s];
		
	for (i=0; i<size; ++i)
		text[i] = reversed[i];
}
