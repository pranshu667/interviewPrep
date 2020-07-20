#include<bits/stdc++.h>
using namespace std;

void bfs(map<int,vector<int>> m,int i,vector<bool> &vis) {
  queue<int> q;
  q.push(i);

  while(!q.empty()) {
    int n=q.size();
    while(n--) {
      i=q.front();
      q.pop();
      if(!vis[i]) {
        cout<<i<<" ";
        vis[i]=true;
        
      }
      for(auto it:m[i]) {
        if(!vis[it]) {
          q.push(it);

        }
      }
    }
    cout<<endl;
  }
}

int main() {
  int v,e;
  cin>>v>>e;

  map<int,vector<int>> m;
  for(int i=0;i<e;i++) {
    int a,b;
    cin>>a>>b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  int l;
  cin>>l;

  vector<bool> vis(v,false);

  bfs(m,0,vis);





}
