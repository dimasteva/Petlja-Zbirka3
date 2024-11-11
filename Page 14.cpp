/*
Task: Connected Components  
Write a program that determines the connected components in an undirected graph. A connected component is a set of vertices such that there is a path between every pair of vertices within the component, and there is no path to any vertex outside the component.  

Input: The first line of input contains the number of vertices (1 ≤ v ≤ 100) and the number of edges (0 ≤ e ≤ v(v−1)/2) of an undirected graph. The next e lines describe the edges (a pair of vertices separated by a space, where the vertices are numbered from 0 to v − 1).  

Output: For each vertex, print the component number it belongs to (components are numbered starting from 1). The order of components is determined by the order of their smallest elements (for example, if vertex 3 and vertex 7 are not in the same component, the component containing vertex 3 should have a smaller number than the component containing vertex 7).  

Example:  
Input:  
6 3  
1 3  
2 4  
5 0  

Output:  
1 2 3 2 3 1
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

int s = 1;

void rec(int edge, map<int, vector<int>>& m, vector<bool>& visited, map<int, int>& sol)
{
	visited[edge] = true;
	sol[edge] = s;
	for (auto itr : m[edge])
	{
		if (!visited[itr])
			rec(itr, m, visited, sol);
	}
}

int main() 
{
    int n, k; cin >> n >> k;
    map<int, vector<int>> m;
    forn(i, k)
    {
    	int a, b; cin >> a >> b;
    	m[a].pb(b);
    	m[b].pb(a);
	}
	vector<bool> visited(n, false);
	map<int, int> sol;
	forn(i, n)
		if (!visited[i])
		{
			rec(i, m, visited, sol);
			s++;
		}
			
	forn(i, n)
		cout << sol[i] << " ";
}
