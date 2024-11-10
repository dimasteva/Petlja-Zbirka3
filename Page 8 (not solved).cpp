/*
Task: Heirs

In a certain country, a king has taken the throne and started his royal lineage. He has numerous descendants, and each of them wants to know their position in the line of succession to the crown. The rule of succession states that the king is succeeded first by his oldest son. Next in line is the oldest grandson (if any), and so on. If a descendant has no children, then the next in line is his oldest brother, then his descendants, and so forth.  
Write a program that determines the order of succession for certain descendants of the king.

Input: The number \( n \) (1 ≤ \( n \) ≤ 50000), representing the total number of people in the king’s family tree (including him), is read from standard input. After that, pairs in the form "parent child" (each pair on a separate line, separated by a space) are entered, where children of the same parent are listed in descending order of age. Finally, the names of the descendants for whom the succession order is to be determined are entered (each on a separate line).

Output: For each descendant entered after the parent-child relationship description, print their succession position.

Example  
Input  
19  
Elisabeth Charles  
Elisabeth Andrew  
Elisabeth Edward  
Elisabeth Anne  
Charles William  
Charles Harry  
William George  
William Charlotte  
William Louis  
Anne Peter  
Anne Zara  
Andrew Beatrice  
Andrew Eugenie  
Edward James  
Edward Louise  
Peter Savannah  
Peter Isla  
Zara Mia  
Harry  
Charles  
Charlotte  
Louise  
James  
Isla  
Andrew  

Output  
Harry 6  
Charles 1  
Charlotte 4  
Louise 12  
James 11  
Isla 16  
Andrew 7
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

void dfs(map<string, vector<string>>& children, string& king,
		map<string, int>& order)
	{
		int r = 0;
		stack<string> st;
		
		st.push(king);
		while(!st.empty())
		{
			string s = st.top();
			st.pop();
			order[s] = r++;
			
			auto it = children.find(s);
			if (it != children.end())
			{
				vector<string>& s_children = it->second;
				for (auto it = s_children.rbegin(); it != s_children.rend(); it++)
					st.push(*it);
			}
		}
	}

int main() 
{
    map<string, bool> has_parent;
    map<string, vector<string>> children;
    int n; cin >> n;
    forn(i, n-1)
    {
    	string parent, child;
    	cin >> parent >> child;
    	has_parent[child] = true;
    	if (has_parent.find(parent) == has_parent.end())
    		has_parent[parent] = false;
    	
    	children[parent].pb(child);
	}
	for (auto itr : children)
	{
		cout << itr.first << ": ";
		for (auto itr2 : itr.second)
			cout << itr2 << " ";
		cout << endl; 
	}
	string king;
	for (auto itr : has_parent)
		if (!itr.second)
			king = itr.first;
	
	map<string, int> order;
	dfs(children, king, order);
	string q;
	while(cin >> q)
		cout << q << " " << order[q] << endl;
}
