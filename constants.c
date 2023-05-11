#include <stdio.h>

#define OCTAL_VTAB '\013' /* ASCII vertical tab in octal */
#define OCTAL_BELL '\007' /* ASCII bell character in octal */
#define HEX_VTAB '\xb' /* ASCII vertical tab in hexadecimal */
#define HEX_BELL '\x7' /* ASCII bell character in hexadecimal */

#define MAXLINE 1000
char line[MAXLINE+1];
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];

enum boolean { NO, YES };
enum escapes { BELL  = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; /* FEB is 2, MAR is 3, etc. */

/* A string constant, or string literal, is a sequence of zero or more characters
 * surrounded by double quotes, as in
 * "I am a string" or "" (the empty string)
 * A single character: 'x' is not the same as "x".
 * The former is an integer, used to produce the numeric value of the letter x in
 * the machine's character set. The latter is an array of characters that contains
 * one character (the letter x) and a '\0' (equals to 0).
 */

void main() {
	
	printf("The complete set of escape sequence:\n");
	printf("\\a\n"); // alert (bell) character
	printf("\\b\n"); // backspace
	printf("\\f\n"); // formfeed
	printf("\\n\n"); // newline
	printf("\\r\n"); // carriage return
	printf("\\t\n"); // horizontal tab
	printf("\\v\n"); // vertical tab
	printf("\\\\\n"); // backslash
	printf("\\?\n"); // question mark
	printf("\\'\n"); // single quote
	printf("\\\"\n"); // double quote
	printf("\\000\n"); // octal number
	printf("\\xa9\n"); // hexadecimal number
	
	printf("\n");
	printf("hello, " "world");
	printf("\n\n");
	
	enum boolean value;
	value = NO;
	printf("NO: %d ", value);
	value = YES;
	printf("YES: %d", value);
	
	enum escapes nl;
	nl = NEWLINE;
	printf("%c", nl);
	printf("%c", nl);
	
	enum months month;
	month = OCT;
	printf("OCTOBER: %d", month);
}
