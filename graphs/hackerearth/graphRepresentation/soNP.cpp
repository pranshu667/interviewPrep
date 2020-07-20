#include <bits/stdc++.h>
using namespace std;

void dfs(map<int,vector<int>> m,int i,bool vis[]) {
  stack<int> s;
  s.push(i);

  while(!s.empty()) {
    i=s.top();
    s.pop();

    if(!vis[i]) {
      vis[i]=true;

    }

    for(auto it:m[i]) {
      if(!vis[it]) {
        s.push(it);
      }
    }
  }
}

int main() {
  int n,m,k;
  cin>>n>>m>>k;

  bool *vis=new bool[n+1];
  for(int i=0;i<=n;i++) {
    vis[i]=false;
  }
  map<int,vector<int>> mp;


  for(int i=0;i<m;i++) {
    int u,v;
    cin>>u>>v;
    mp[u].push_back(v);
    mp[v].push_back(u);
  }
  int cnt=0;
  for(int i=1;i<=n;i++) {
    if(!vis[i]) {
      dfs(mp,i,vis);
      cnt++;
    }
  }

  if(cnt>k) {
    cout << "-1" << '\n';
  }
  else {
    cout << m-n+k << '\n';
  }
}
