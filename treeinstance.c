#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

/* the node tree structure */
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
main()
{
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) 
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while ((c = getchar()))
		switch (c) {
		case '/*':
			*w = '\0';
		case '#':
			;
		case 'struct': case 'int': case 'char': case 'float': case 'double'
			c++;
		case '{': case '}': case '(': case ')':
			c++;
		default while (isspace(c = getch()))
					;
				if (c != EOF)
					*w++ = c;
				if (!isalpha(c)) {
					*w = '\0';
				return c;
				}
	
		for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}


struct tnode *talloc(void);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) 
{
	int cond;
	
	if (p == NULL) {		/* a new word arrived */
		p = talloc();		/* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word) == 0)
		p->count++;			/* repeated word */
	else if (cond < 0)		/* less than? Into the left subtree */
		p->left = addtree(p->left, w);
	else					/* greater tha? into the right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)		/* make a duplicate of s */
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);	/* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}

