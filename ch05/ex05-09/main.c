#include <stdio.h>

char *month[] = { "",
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

int main(void)
{
	int year, day;
	int m, d;
	int day_of_year(int, int, int);
	void month_day(int, int, int *, int *);

	year = 1988, day = 60;
	month_day(year, day, &m, &d);
	printf("%d year %d day -> %s %d\n", year, day, month[m], d);

	day = day_of_year(year, m, d);
	printf("%s %d -> %d year %d day\n", month[m], d, year, day);

	return 0;
}