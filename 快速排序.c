//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//void swap(int* a, int* b) 
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void quick_sort(int q[], int l, int r)
//{
//	if (l >= r)return;
//	int i = l - 1, j = r + 1; int x = q[(l + r) / 2];
//	while (i < j)
//	{
//		do i++; while (q[i] < x);
//		do j--; while (q[j] > x);
//		if (i < j)swap(q + i, q + j);
//	}
//	quick_sort(q, l, j); quick_sort(q, j + 1, r);
//}
//int main() 
//{
//	int arr[100] = { 0 };
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) scanf("%d", arr + i);
//	quick_sort(arr, 0, n-1);
//	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
//	return 0;
//}