#include <stdio.h>
#define LINE 100
#define TEXT 1000

int getline(char[], int);
void copy(char[], char[]);
void format(char[]);

int main()
{
    int len;
    char line[LINE];
    char text[TEXT] = {'\0'};
    
    while ((len = getline(line, LINE)) > 0)
        copy(text, line);
        
    format(text);
    
    printf("%s", text);
    
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    
    for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
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
    int i, j;
    
    i = 0;
    j = 0;
    while (to[i] != '\0')
        ++i;
    while ((to[i++] = from[j++]) != '\0')
        ;
}

void format(char content[])
{
    if (content[0] == '\0') return;

    int i, j;
    char formated[TEXT];

    j = 0;
    for (i=0; i<TEXT && content[i]!='\0'; ++i) {
        if (content[i] == ' ' || content[i] == '\t') {
        	formated[j] = content[i];
        	++j;
        	while (content[i+1] == ' ' || content[i+1] == '\t') {
        		++i;
			}
		} else {
			formated[j] = content[i];
        	++j;
		}
    }
    formated[j] = '\0';

    i = 0;
    while (formated[i] != '\0') {
        content[i] = formated[i];
        ++i;
    }
    content[i] = '\0';
}
