
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include "1.h"

vector<int> bfs(int v1,int v2,map<int,set<int>> m,vector<bool> &vis,map<int, int> &parent) {
  queue<int> q;
  q.push(v1);
  bool done=false;
  int i;
  while(!q.empty()&&!done) {
    i=q.front();
    q.pop();
    //cout<<i<<" ";

    if(!vis[i]) {
      vis[i]=true;
      if(i==v2) {
        done=true;
      }

    }

    for(auto it:m[i]) {
      if(!vis[it]) {
        q.push(it);
        parent[it]=i;
        if(it==v2) {
          done=true;
        }
      }
    }
  }
  vector<int> out;
  if(done) {
    int cur=v2;
    out.push_back(cur);
    while (cur!=v1) {
      cur=parent[cur];
      out.push_back(cur);
    }
  }
  else {
    out.clear();

  }
  return out;
}




int main()
{
    map<int,set<int>> m;
    m=takeinput();

    map<int,int> parent;
    int v=m.size();

    vector<bool> vis(v+1,false);
    int v1,v2;
    cin>>v1>>v2;

    std::vector<int> vect=bfs(v1,v2,m,vis,parent);
    for(auto it:vect) {
      cout<<it<<' ';
    }
    cout<<endl;






}
