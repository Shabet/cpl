#include <stdio.h>
#include <string.h>

/* echo command-line arguments: 1st version */
/*
int main(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc -1) ? " " : "");
	printf("\n");
	return 0;
}
*/

/* echo command-line arguments: 2nd version */
/*
int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");	// tip! argv[i] <-> *(argv + i) -> *(++argv) -> *++argv
	printf("\n");

	return 0;
}
*/

/* echo command-line arguments: 3rd version */
int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf(argc > 1 ? "%s " : "%s", *++argv);	// NOTE. > operator is higher than ?: operator.
	printf("\n");

	return 0;
}