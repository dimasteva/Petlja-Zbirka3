/*
Zadatak: Najkraći put između dva grada  
Gradovi su povezani putevima i za svaki put je poznato vreme potrebno da se pređe njime (vreme za prolazak u jednom i drugom smeru ne mora biti isto). Napiši program koji određuje najkraći put između dva data grada.  

Ulaz: Sa standardnog ulaza se unosi broj gradova **n** (1 ≤ n ≤ 1000), u narednom redu broj puteva **m** (1 ≤ m ≤ n² − n), a zatim u narednih **m** redova opisi puteva (dva cela broja koja predstavljaju redne brojeve gradova, koji se broje od nule, i nakon toga pozitivan realan broj koji predstavlja vreme da se put pređe). U poslednja dva reda nalaze se redni broj početnog i redni broj ciljnog grada.  

Izlaz: Na standardni izlaz ispisati minimalno vreme potrebno da se stigne od startnog do ciljnog grada, zaokruženo na pet decimala, a zatim, u narednom redu, redne brojeve gradova na putu od starta do cilja. Ako se od starta do cilja ne može stići učitanim putevima, samo ispisati "ne".  

Primer:  
Ulaz:  
4  
6  
0 1 1.2  
1 2 1.3  
0 2 2.0  
0 3 5.7  
1 3 4.6  
2 3 2.1  
0  
3  

Izlaz:  
4.10000  
0 2 3  
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
    
const double INF = numeric_limits<double>::infinity();

int main()
{
	FIO
	int n, m; cin >> n >> m;
	vector<vector<pair<int, double>>> v(n);
	forn(i, m)
	{
		int a, b; double x;
		cin >> a >> b >> x;
		v[a].emplace_back(b, x);
	}
	int start, end; cin >> start >> end;
	vector<double> bestpath(n, INF);
	vector<bool> solved(n, false);
	vector<int> parents(n, -1);
	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>,
		greater<tuple<double, int, int>>> pq;
	
	pq.emplace(0.0, start, -1);
	
	while(!pq.empty())
	{
		int mn, parent;
		double len;
		tie(len, mn, parent) = pq.top(); pq.pop();
		
		if (solved[mn])
			continue;
		
		solved[mn] = true;
		parents[mn] = parent;
		
		if (mn == end)
			break;
		
		for (auto itr : v[mn])
		{
			if (!solved[itr.first] && len + itr.second < bestpath[itr.first])
			{
				bestpath[itr.first] = len + itr.second;
				pq.emplace(bestpath[itr.first], itr.first, mn);
			}
		}
	}
	
	if (bestpath[end] == INF)
	{
		cout << "ne" << endl;
		return 0;
	}
	cout << setprecision(5) << fixed << showpoint << bestpath[end] << endl;
	stack<int> s;
	s.push(end);
	while(parents[end] != -1)
	{
		end = parents[end];
		s.push(end);
	}
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
