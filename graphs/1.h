
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


    map<int, set<int>> takeinput()
    {
        map<int, set<int>> ans;

        int u, v;
        while (cin >> u && cin >> v && (u != -1) && (v != -1))
        {
            ans[u].insert(v);
            ans[v].insert(u);
        }
        return ans;
    }

vector<int> dfsIterative(map<int, vector<int>> m, int i, vector<bool> &visited)
{
    vector<int> ans;
    stack<int> s;
    s.push(i);

    while (!s.empty())
    {
        i = s.top();
        s.pop();

        if (!visited[i])
        {
            ans.push_back(i);
            visited[i] = true;
        }

        for (auto it : m[i])
        {
            if (!visited[it])
            {
                s.push(it);
            }
        }
    }

    return ans;
}

vector<int> dfs(map<int, vector<int>> m)
{
    int v = m.size();
    vector<bool> visited(v + 1, false);
    vector<int> iterativeAnswer;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            vector<int> vect = dfsIterative(m, i, visited);
            iterativeAnswer.insert(iterativeAnswer.end(), vect.begin(), vect.end());
        }
    }
    return iterativeAnswer;
}

vector<int> bfsUtil(map<int, vector<int>> m, int i, vector<bool> &visited)
{

    int v = m.size();
    vector<int> ans;
    queue<int> q;

    q.push(i);

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        if (!visited[i])
        {
            ans.push_back(i);
            visited[i] = true;
        }

        for (auto it : m[i])
        {
            if (!visited[it])
            {
                q.push(it);
            }
        }
    }
    return ans;
}

void printGraph(map<int,vector<int>> m) {
  for(auto it:m) {
    cout<<it.first<<": ";
    for(auto itr:it.second) {
      cout<<itr<<" ";
    }
    cout<<endl;
  }
}

vector<int> bfs(map<int, vector<int>> m)
{
    int v = m.size();
    vector<bool> visited(v + 1, false);
    vector<int> ans;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            vector<int> vect = bfsUtil(m, i, visited);
            ans.insert(ans.end(), vect.begin(), vect.end());
        }
    }
    return ans;
}
