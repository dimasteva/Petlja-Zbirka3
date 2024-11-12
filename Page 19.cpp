/*
Task: Job Order
To build a car, a sequence of tasks needs to be completed. Some tasks depend on others (for example, before installing the wheels, the axles must be installed). Write a program that determines a possible order of completing these tasks, where all dependencies are satisfied.

Input: The standard input contains the integer n (1 ≤ n ≤ 50000), followed by the integer m (1 ≤ m ≤ 10n), and then m pairs of integers xi, yi (0 ≤ xi, yi < n), separated by a space, indicating that the task yi must be completed before task xi.

Output: Print n integers representing the order of tasks in which they can be completed, each number on a new line. Such an order is guaranteed to exist.

Example
Input
6  
6  
3 1  
3 2  
4 2  
4 5  
1 0  
0 5  

Output
2  
5  
0  
1  
3  
4
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define MOD 1000000007 // 998244353
#define FIO                \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main() 
{
	FIO
	int n; cin >> n;
	vector<int> out_degree(n);
	vector<vector<int>> anc(n);
	int m; cin >> m;
	forn(i, m)
	{
		int a, b; cin >> a >> b;
		anc[b].push_back(a);
		out_degree[a]++;
	}
	queue<int> independent;
	for (int edge = 0; edge < n; edge++)
		if (out_degree[edge] == 0)
			independent.push(edge);
	
	while(!independent.empty())
	{
		int edge = independent.front();
		independent.pop();
		cout << edge << endl;
		for (auto itr : anc[edge])
			if (--out_degree[itr] == 0)
				independent.push(itr);
	}
}
