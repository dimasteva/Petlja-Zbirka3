/*
Task: Reachable Nodes  
For each router in a computer network, a list of connected routers is provided. Write a program that checks if it is possible to send a message from one given router to another.  
Input: The input from standard input includes the number of routers `n` (1 ≤ n ≤ 100), followed by the number of connections `m` between routers (0 ≤ m ≤ n(n − 1)), and then in the next `m` lines, pairs of two different numbers between 1 and `n` separated by a space, which represent routers between which a connection is established (the first router can send a message to the second). Each connection is listed only once. After that, the number of pairs `p` (1 ≤ p ≤ 100) of routers whose connectivity needs to be checked is entered. Each pair is described by two different numbers `start` and `goal` between 1 and `n`.  
Output: For each pair of routers to be checked, output "yes" if it is possible to send a message from router `start` to router `goal`, or "no" otherwise.  

Example 1  
Input  
4  
4  
1 2  
1 3  
3 2  
2 4  
2  
2 3  
1 4  
Output  
no  
yes  

Example 2  
Input  
4  
4  
1 2  
2 3  
2 4  
3 4  
1  
1 4  
Output  
yes
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
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n+1, vector<int>(n+1, 0));
	forn(i, m)
	{
		int x, y; cin >> x >> y;
		a[x][y] = 1;
	}
	int p; cin >> p;
	while(p--)
	{
		int x, y; cin >> x >> y;
		stack<int> s;
		s.push(x);
		vector<vector<int>> visited(n+1, vector<int>(n+1, 0));
		bool found = false;
		while(!s.empty())
		{
			int x1 = s.top();
			if (x1 == y)
			{
				found = true;
				break;
			}
			s.pop();
			forn(i, n+1)
				if (a[x1][i] == 1 && visited[x1][i] == 0)
				{
					visited[x1][i] = 1;
					s.push(i);
				}
		}
		cout << (found ? "da" : "ne") << endl;
	}
}
