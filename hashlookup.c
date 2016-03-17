/* hash function lookup implementation */

/* hash: form hash value for string s */

static struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

char *strdup(char *s)		/* make a duplicate of s */
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);	/* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];		/* pointer table */

unsigned hash(char *s)
{
	unsigned hashval;
	
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;		/* found */
	return NULL;			/* not found */
}

struct nlist *lookup(char *);
char *strdup(char *);

/* Undef: removes the defined entry. Must be compiled separately */
void undef(char *)
{
	if(*lookup(char *s) = NULL) {
		printf ("%s is not defined", *s);
	}
	else
	{
		struct nlist *np;
		--np->next;
		--s;
		printf ("%s has been erased from lookup table.", *s);
	}
}
