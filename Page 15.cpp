/*
Task: Strange Network
In a computer lab, an unusual computer network needs to be set up. Computers must be placed on `n` tables, where some tables can host regular computers (which are available in unlimited quantities), while others must host special servers (which need to be purchased separately at a cost of `cs` dinars). Some tables can be connected directly with network cables, while others cannot. The cost of setting up a network cable between any two tables is `ck` dinars. Write a program to determine the minimum cost required so that each computer or server is either a server or is connected by a network cable to at least one server (not necessarily directly).

Input: From standard input, the first line contains the numbers `cs` (0 ≤ `cs` ≤ 1000) and `ck` (0 ≤ `ck` ≤ 1000), separated by a space. The next line contains the number of computers `n` (2 ≤ `n` ≤ 50000) and `m`, the number of pairs of computers between which a network cable can be placed \(2 ≤ m ≤ \frac{n(n-1)}{2}\), separated by a space. The next `m` lines contain pairs of numbers between `0` and `n−1`, separated by a space, which indicate the computers between which a cable can be installed.

Output: Print the required minimum cost to standard output.

Example  
Input  
850 350  
7 6  
0 1  
0 4  
4 2  
1 4  
3 5  
6 5  

Output  
3450
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

void dfs(int current, map<int, vector<int>>& adj, vector<bool>& visited, int& cnt)
{
	cnt++;
	visited[current] = true;
	for (auto itr : adj[current])
		if (!visited[itr])
			dfs(itr, adj, visited, cnt);
}

int main() 
{
	FIO
    int cs, ck; cin >> cs >> ck;
    int n, m; cin >> n >> m;
    map<int, vector<int>> adj;
    forn(i, m)
    {
    	int a, b; cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
	}
	vector<bool> visited(n, false);
	ll sum = 0;
	forn(i, n)
		if (!visited[i])
		{
			int cnt = 0;
			dfs(i, adj, visited, cnt);
			sum += min(cs  + (cnt-1) * ck, cnt * cs);
		}
	cout << sum << endl;
}
