#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

bool check(int x)
{
	//检查x是否满足性质
}
int bsearch_1(int l, int r)
{
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	return 1;
}
int besearch_2(int l, int r)
{
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	return 1;
}
int main() 
{

}