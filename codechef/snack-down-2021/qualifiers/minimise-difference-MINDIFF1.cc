#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define endl '\n';

void dfs(int node, 
  vector<bool>& visited, 
  vector<vector<int>>& graph, 
  vector<pair<int, int>>& degrees
  ) {

    visited[node] = true;
    degrees.push_back({graph[node].size(), node});
    for ( auto& next: graph[node] ) {
      if ( !visited[next] ) {
        dfs(next, visited, graph, degrees);
      }
    }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, n, m, u, v;
  cin >> t;
  while ( t-- ) {
    cin >> n >> m;
    vector<set<int>> auxiliar(n);
    vector<vector<int>> graph(n);
    vector<int> assignment(n);
    vector<int> differences(n);
    vector<bool> visited(n);
    
    for ( int i = 0; i < m; ++i ) {
      cin >> u >> v;
      u--; v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
      auxiliar[u].insert(v);
      auxiliar[v].insert(u);
    }

    int cur_assigned = 1;

    for ( int i = 0; i < n; ++i ) {
      if ( !visited[i] ) {
        vector<pair<int, int>> degrees;
        dfs(i, visited, graph, degrees);
        sort(degrees.rbegin(), degrees.rend());
        for ( auto degree: degrees) {
          int node = degree.second;
          assignment[node] = cur_assigned++;
          for ( auto& next : auxiliar[node] ) {
            differences[next]++;
            auxiliar[next].erase(node);
          }
        }
      }
    }

    int min_difference = *max_element(differences.begin(), differences.end());
    min_difference -= *min_element(differences.begin(), differences.end());
    cout << min_difference << endl;
    for ( auto x: differences ) cout << x << " "; cout << endl;
    for ( auto x: assignment ) cout << x << " "; cout << endl;
  }
  return 0;
}
