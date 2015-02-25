/* quicksort: sort v[left]...v[right] into increasing order */
void quicksort(char *v[], int left, int right,
				int (*comp)(void *, void*))
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last-1, comp);
	quicksort(v, last+1, right, comp);
}