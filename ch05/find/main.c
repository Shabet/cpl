#include <stdio.h>
#include <string.h>		// strstr()
#define MAXLINE	1000

int getline(char *line, int max);

/* find: print lines that match pattern from 1st arg : use pointer */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				fprintf(stderr, "find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}

	if (argc != 1)
		fprintf(stderr, "Usage: find -x -n pattern\n");
	else
		while (getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}

/* find: print lines that match pattern from 1st arg : use index (it's not good idea, just test) */
/*
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	int i, j;	// here!

	for (i = 1; --argc > 0 && argv[i][0] == '-'; i++)	// here!
		for (j = 1; c = argv[i][j]; j++)	// here!
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				fprintf(stderr, "find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}

	argv = &argv[i];	// here!

	if (argc != 1)
		fprintf(stderr, "Usage: find -x -n pattern\n");
	else
		while (getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}
*/

/* find: print lines that match pattern from 1st arg */
/*
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		fprintf(stderr, "Usage: find pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	return found;
}
*/
