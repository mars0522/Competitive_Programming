
#include<bits/stdc++.h>
using namespace std;

long long arr[100001];
long long prefix[100001] = {0};
long long query_no[100001] = {0};
int query[100001][3];

int main()
{

	// for fast input output
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif

	int n, k, m;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= m; i++)
	{
		cin >> query[i][0] >> query[i][1] >> query[i][2];
	}

	for (int i = 1; i <= k; i++)
	{
		int x, y; cin >> x >> y;

		query_no[x]++;
		query_no[y + 1]--;
	}

	// there are m no of queries and we want to find out which query is repeate how many
	// times
	for (int i = 2; i <= m; i++)
		query_no[i] += query_no[i - 1];

	// Now doing prefix sum
	for (int i = 1; i <= m; i++)
	{
		int l = query[i][0];
		int r = query[i][1];
		int d = query[i][2];

		prefix[l] += query_no[i] * d;
		prefix[r + 1] -= query_no[i] * d;
	}

	for (int i = 2; i <= n; i++)
		prefix[i] += prefix[i - 1];

	for (int i = 1; i <= n; i++)
		arr[i] += prefix[i];


	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";

	cout << endl;





}