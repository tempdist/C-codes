/* the set of programs that focus on using pointers */

/* A: strcat: copies the string t to the end of string s */

#include <stdio.h>
#include <ctype.h>

int s, t;
int strcat(int *s, int *t) 
{
	while(*s == '\0')		/* this here is an idiom */
	{
		*s++ = *t++;
	}
	return 1;
}

int check(int)
{
	while(strcat)
	{
		return 1;
	}
	return printf("it worked");
}

/* code to sort between lines of characters */

#include <stdio.h>
#include <string.h>

#define MAXLINE 5000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
	int nlines;		/* number of input lines read */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		prinf("error: input too long to sort\n");
		return 1;
	}
}

#define MAXLEN 1000		/* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len-1] = '\0';		/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;
	
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* converting day of the month to day of year */

static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/* day_of_year: set the day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i=1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;		/* this will have a binary value */
	for (i = 1; yearday > daytab[leap][i]; i++)		/* here the binariness of leap is made a subscript out of */
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

/* Expr: calculates the reverse polish expression with each operator/operand \ 
/* being a character. */

#include <stdio.h>
#include <string.h>

#define LONGEST 50 

static char command = "expr ";

/* function to take care of arguments */

while(command)
{
	char *args[];
	if()
}