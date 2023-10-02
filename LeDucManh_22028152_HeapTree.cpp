#include <bits/stdc++.h>
using namespace std;
 
//node of heaptree saved in arr
//N is size of arr
//heapify node x 
void heapify(int arr[], int N, int x)
{
	int mx = x, l = x * 2 + 1, r = x * 2 + 2;

	if(l < N && arr[l] > arr[mx]) mx = l;
	if(r < N && arr[r] > arr[mx]) mx = r;

	if(mx != x)
	{
		swap(arr[x], arr[mx]);
		heapify(arr, N, mx);
	}
}

//build heap tree
void build(int arr[], int N)
{
	for(int i = N / 2 - 1; i >= 0; i --)
	{
		heapify(arr, N, i);
	}
}

void remove_max(int arr[], int &N)
{
	N --;
	swap(arr[0], arr[N]);

	heapify(arr, N, 0);
}

int main()
{

	return 0;
}