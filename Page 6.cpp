/*
Task: Caves

Speleologists are in the entrance hall of the cave, at ground level, with a known altitude. The cave has a total of n halls labeled from 0 to n − 1 (the entrance hall is labeled as 0), and each of them can be reached using n − 1 corridors that connect them. If the two halls connected by each corridor and the altitude difference between them are known, write a program to determine the lowest altitude to which the speleologists in the cave can descend.

Input: The altitude of the ground (an integer) is read from standard input, followed by a natural number n (1 ≤ n ≤ 100) on the next line. In the next n − 1 lines, there are three integers separated by spaces, describing a corridor: the index of the starting hall, the index of the destination hall, and the altitude difference between the starting and destination halls.

Output: Print the required maximum depth to standard output.

Example  
Input  
278  
7  
0 1 -20  
0 2 -10  
1 3 -5  
1 4 10  
2 5 -33  
2 6 7  

Output  
235
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

void dfs(int room, int height, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int& minHeight)
{
	visited[room] = true;
	minHeight = min(minHeight, height);
	for (auto& neighbor : adj[room])
	{
		int nextRoom = neighbor.first;
		int heightDiff = neighbor.second;
		if (!visited[nextRoom])
		{
			dfs(nextRoom, height + heightDiff, adj, visited, minHeight);
		}
	}
}

int main() 
{
    int ground; cin >> ground;
    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    forn(i, n-1)
    {
    	int start, end, height;
    	cin >> start >> end >> height;
    	adj[start].push_back({end, height});
    	adj[end].push_back({start, -height});
	}
	int minHeight = ground;
	vector<bool> visited(n, false);
	dfs(0, ground, adj, visited, minHeight);
	cout << minHeight << endl;
}
