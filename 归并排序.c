#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void merge_sort(int q[], int l, int r)
{
	if (l >= r)return;
	int mid = (l + r) / 2;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	int temp[100];
	while (i <= mid && j <= r)
		if (q[i] <= q[j])temp[k++] = q[i++];
		else temp[k++] = q[j++];
	while (i <= mid)temp[k++] = q[i++];
	while (j <= r)temp[k++] = q[j++];
	for (i = l, j = 0; i <= r; i++, j++)q[i] = temp[j];
}
int main()
{
	int arr[100] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	merge_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	return 0;
}