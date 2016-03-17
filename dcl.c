#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);			
int tokentype; 			/* type of last token */
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

main ()
{
	while (gettoken() != EOF) { /* 1st token on line */
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();		/* parse rest of the line */
		if (tokentype != '\n');
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken(void)		/* return next token */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		strcpy(token, "()");
		return tokentype = PARENS;
	} else {
		ungetch(c);
		return tokentype = '(' ; }
	else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0' ;
		ungetch(c);
		return tokentype = NAME;
	} else
			return tokentype = c;
}