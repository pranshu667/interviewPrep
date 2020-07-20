#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(map<int,vector<int>> m,int i,vector<bool> &vis,int parent) {
  vis[i]=true;
  for(auto it:m[i]) {
    if(vis[it]&&it!=parent) {
      return true;
    }
    if(!vis[it]) {
      return isCyclicUtil(m,it,vis,i);
    }

  }
  return false;
}

bool isCyclicBfs(map<int,vector<int>> m,int i,vector<bool> &vis) {
  queue<int> q;
  q.push(i);
  map<int,int> parent;
  parent[i]=-1;

  while(!q.empty()) {
    i=q.front();
    q.pop();

    vis[i]=true;

    for(auto it:m[i]) {
      if(vis[it]&&it!=parent[i]) {

      }
    }
  }
}

bool isCyclic(map<int,vector<int>> m,int v) {
  vector<bool> vis(v,false);
  for(int i=0;i<v;i++) {
    if(!vis[i]) {
      if(isCyclicBfs(m,i,vis)) {
        return true;
      }
    }
  }
  return false;
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

  bool res=isCyclic(m,v);

  cout<<res<<endl;
}
