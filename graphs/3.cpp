#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void bfs(map<int,set<int>> m,int i,vector<bool> &vis){
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

int main()
{
    int v,e;
    cin>>v>>e;

    map<int,set<int>> m;
    for(int i=0;i<e;i++) {
      int a,b;
      cin>>a>>b;
      m[a].insert(b);
      m[b].insert(a);
    }

    vector<bool> vis(v,false);

    bfs(m,0,vis);

    bool flag=true;
    
    for(auto it:vis) {
      if(!it) {
        flag=false;
        break;
      }
    }


    if(flag) {
      cout<<"true";
    }
    else {
      cout<<"false";
    }
    cout<<endl;

}
