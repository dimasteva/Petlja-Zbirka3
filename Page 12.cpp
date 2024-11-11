/*
Task: Caves with Tunnels  
Speleologists are located in the entrance hall of a cave, at ground level, with a known altitude above sea level. The cave has a total of \( n \) halls numbered from 0 to \( n - 1 \) (the entrance hall is numbered 0), and each can be reached by using one of the many tunnels connecting them. All tunnels are bidirectional. For each tunnel, if we know which two halls it connects and the altitude difference between them, write a program that determines the lowest altitude within the cave that the speleologists can descend to.  
Input: The input consists of an integer representing the ground level altitude (a whole number), followed by a natural number \( n \) (1 ≤ \( n \) ≤ 100) representing the number of halls, and then a natural number \( m \) (1 ≤ \( m \) ≤ \( n \cdot (n - 1)/2 \)) representing the number of tunnels. In the next \( m \) lines, there are three integers separated by spaces, describing each tunnel: the index of the starting hall, the index of the destination hall, and the altitude difference between the starting and destination halls.  
Output: The output should be an integer representing the lowest altitude of any hall in the cave.  
Example  
Input  
696  
5  
7  
0 1 -7  
0 4 4  
0 3 -6  
1 2 -10  
1 3 1  
1 4 11  
3 4 10  
Output  
679
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

void dfs(int room, vector<vector<pair<int, int>>>& v, vector<bool>& visited, int currentHeight, int& minHeight)
{
    visited[room] = true;
    minHeight = min(minHeight, currentHeight);
    for (auto itr : v[room])
    {
        if (!visited[itr.first])
            dfs(itr.first, v, visited, currentHeight + itr.second, minHeight);
    }
}

int main() 
{
    int ground; cin >> ground;
    int n, q; cin >> n >> q;
    vector<vector<pair<int, int>>> v(n);
    forn(i, q)
    {
        int a, b, h; cin >> a >> b >> h;
        v[a].push_back({b, h});
        v[b].push_back({a, -h});
    }
    int minHeight = ground;
    vector<bool> visited(n, false);
    dfs(0, v, visited, ground, minHeight);
    cout << minHeight << endl;
}
