#include <bits/stdc++.h>
using namespace std;

void bfs(map<int,vector<int>> m,int i,vector<bool> &vis) {
  queue<int> q;
  q.push(i);

  while(!q.empty()) {
    i=q.front();
    q.pop();

    if(!vis[i]) {
      vis[i]=true;
    }

    for(auto it:m[i]) {
      if(!vis[it]) {
        q.push(it);
      }
    }
  }
}

int main() {

  int n,m;
  cin>>n>>m;

  int *u=new int[m];
  int *v=new int[m];

  for(int i=0;i<m;i++) {
    cin>>u[i];
  }

  for(int i=0;i<m;i++) {
    cin>>v[i];
  }

  map<int,vector<int>> mp;
  for(int i=0;i<m;i++) {
    mp[u[i]].push_back(v[i]);
    mp[v[i]].push_back(u[i]);
  }

  vector<bool> vis(n+1,false);

  int cnt=0;
  for(int i=1;i<=n;i++) {
    if(!vis[i]) {
      bfs(mp,i,vis);
      cnt++;
    }
  }

  cout<<cnt<<endl;


}
