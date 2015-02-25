#include <stdio.h>
#include <string.h>	// strlen
#include "point.h"

#define XMAX	1024
#define YMAX	768

int main(int argc, char *argv[])
{
	struct rect screen;
	struct point middle;
	struct rect *rp;
	struct point *pp;
	struct point makepoint(int, int);

	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
					(screen.pt1.y + screen.pt2.y)/2);

	/* . -> operator usage */
	pp = &screen.pt1;
	printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
	printf("origin is (%d,%d)\n", pp->x, pp->y);

	pp = &middle;
	printf("middle is (%d,%d)\n", (*pp).x, (*pp).y);
	printf("middle is (%d,%d)\n", pp->x, pp->y);

	/* these four expressions are equivalent. */
	rp = &screen;
	printf("%d %d %d %d\n", screen.pt2.x, rp->pt2.x, (screen.pt2).x, (rp->pt2).x);

	/* p132 */
	{
		struct {
			int len;
			char *str;
		} *p, s[4];

		s[0].str = "Hello, world";
		s[0].len = strlen(s[0].str);
		s[3] = s[2] = s[1] = s[0];
		p = &s[0];

		/* check the notation below. */
		++p->len;
		++(p->len);
		(++p)->len;
		(p++)->len;
		p++->len;

		*p->str;
		*p->str++;
		(*p->str)++;
		*p++->str;
	}

	return 0;
}