/* evaluating expr 2 3 4 + *; each operator or operand is *++argv[]. 
argc = count of arguments
argv stores these arguments.
argv[1] is the first optional argument. With a command called, argc[1] is always there. There has to be sorting
of the arguments in numbers and operators. The sorting generates a stream which is then calculated with 
precedence which is set. The expression generates one value. So, there can be a pointer which simply goes on changing
with the last term being \0 */


#include <stdio.h>
#include <string.h>

#define MAXARG 100

int sort(int argc, char *argv) 
{
	int *argf;
	while (argc > 1) {
		for (k = 0; k < argc; ++k) {
			int *argf = *argv[1+k];			/* pick the first optional argument */
			*argf += ' ';					/* append space */
			*argf += *argv[(argc-1)-k];		/* since last character in argc count is \0, the useful is argc-1 */
		}
		printf("%s", *argf)
	}
	return *argf;
}

int main (int argc, char *argv)
{
	static char *operators[] = {
		"invalid operation", "*", "-", "+", "/"		/* this is one implementation; but case with mapping symbols to */
													/* operation may be required */
	};
	while (argc =< MAXARG) {
		sort (int, char) = *order;
		int i;
		for (argc =< MAXARG; argc > 1; --argc) {
			while (*order = *operators[i] && *order != ' ') {
				
			}
			
			
		}
	}
}
