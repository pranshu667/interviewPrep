#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(map<int,vector<int>> m,int i,vector<bool> &vis) {

  queue<int> q;
  q.push(i);
  vector<int> ans;

  while(!q.empty()) {
    i=q.front();
    q.pop();

    if(!vis[i]) {
      ans.push_back(i);
      vis[i]=true;
    }

    for(auto it:m[i]) {
      if(!vis[it]) {
        q.push(it);
      }
    }
  }
  return ans;
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

  vector<bool> vis(v,false);

  for(int i=0;i<v;i++) {
    if(!vis[i]) {
      vector<int> vect=bfs(m,i,vis);
      sort(vect.begin(),vect.end());
      for(auto it:vect) {
        cout<<it<<" ";
      }
      cout<<endl;
    }
  }
}
