/*
Task: Flight Connections
An airline, along with its partners, operates flights between well-known global airports. Write a program that determines whether it is possible to reach one given airport from another using these flights, and if so, how many minimum flights are required.

Input: The standard input provides the number m (1 ≤ m ≤ 100) of flights operated by the company, followed by m lines describing these flights (departure and arrival airport codes separated by a space). Then, the number k (1 ≤ k ≤ 100) of passengers interested in the company's flights is entered, followed by k lines describing the routes they wish to travel on (departure and arrival airport codes separated by a space).

Output: For each of the k passengers, output the minimum number of flights required to complete the desired journey or the word "no" if such a journey cannot be completed using the flights provided by the company.

Example
Input
7
BEG FRA
FRA MUC
FRA JFK
BEG MUC
MUC LAX
LAX JFK
LAX ORD
3
BEG JFK
MUC BEG
BEG ORD

Output
2
no
3

Explanation
It is possible to travel from Belgrade (BEG) to New York (JFK) via Frankfurt (FRA). Traveling from Munich (MUC) to Belgrade (BEG) is not possible. Traveling from Belgrade (BEG) to Chicago (ORD) is possible via Munich (MUC) and Los Angeles (LAX).
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

int find(map<string, vector<string>>& adj, string start, string& end)
{
	if (start == end)
		return 0;
	
	map<string, int> visited;
	queue<pair<string, int>> q;
	q.push({start, 0});
	
	while(!q.empty())
	{
		auto [airport, flights] = q.front();
		q.pop();
		visited[airport] = 1;
		for (auto& next : adj[airport])
		{
			if (next == end)
				return flights + 1;
			if (!visited[next])
				q.push({next, flights+1});
		}
	}
	return -1;
}

int main() 
{
	FIO
    int n; cin >> n;
    map<string, vector<string>> adj;
    forn(i, n)
    {
    	string a, b; cin >> a >> b;
    	adj[a].pb(b);
	}
	int q; cin >> q;
	while(q--)
	{
		string a, b; cin >> a >> b;
		int num = find(adj, a, b);
		cout << (num == -1? "ne" : to_string(num)) << endl;
	}
}
