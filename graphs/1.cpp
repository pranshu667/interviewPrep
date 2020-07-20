#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include "1.h"

void printVector(vector<int> vect)
{
    for (auto it : vect)
    {
        cout << it << " ";
    }
    cout << endl;
}

bool hasPathUtil(int i, int v2, map<int, vector<int>> m, vector<bool> &visited)
{

    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        if (!visited[i])
        {
            if (i == v2)
            {
                return true;
            }
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
    return false;
}

bool hasPath(int v1, int v2, map<int, vector<int>> m)
{
    int v = m.size();
    vector<bool> visited(v + 1, false);

    return hasPathUtil(v1, v2, m, visited);
}

int main()
{
    map<int, vector<int>> m;
    m = takeinput();

    //vector<int> dfsArray = dfs(m);
    //vector<int> bfsArray = bfs(m);

    int v1, v2;
    cin >> v1 >> v2;
    //printVector(dfsArray);

    bool ans = hasPath(v1, v2, m);
    cout << ans << endl;
}
