#include<bits/stdc++.h>
using namespace std;


int main(){
    int k, n, m, i;
    cin >> k >> n >> m;
    vector<int> adj[n+1];
    for(i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    queue<int> q;
    bool visited[n+1];
    int distance[n+1];
    for(i=0;i<=n;i++){
        distance[i]=-1;
        visited[i]=0;
    }
    visited[1] = true;
    distance[1] = 0;
    q.push(1);
    while (!q.empty()) {
       int s = q.front(); q.pop();
       // process node s
       for (auto u : adj[s]) {
           if (visited[u]) continue;
           visited[u] = true;
           distance[u] = distance[s]+1;
           q.push(u);
        }
    }
    int ans=0;
    for(i=1;i<=n;i++){
        //cout << distance[i] << " ";
        if(distance[i]<=k && distance[i]!=-1){
            //cout << distance[i] << " " << k << endl;
            ans=max(ans,i);
        }
    }
    cout << ans;
}/* 2 6 5 1 2 1 3 2 5 3 4 5 6 */