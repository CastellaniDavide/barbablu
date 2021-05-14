#include <bits/stdc++.h>
#define DEBUG

using namespace std;

int N, M, C, K, tmp, tmp2, tmp3;
vector <vector<pair<int, int> > > nodes;
vector <bool> valid;
vector <int> cost;
queue <pair<int,int> > q;

int main()
{
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> N >> M >> C >> K;
    valid.resize(N);
    nodes.resize(N);
    cost.resize(N);

    for (size_t i = 0; i < K; ++i)
    {
        cin >> tmp;
        valid[tmp - 1] = true;
    }

    for (size_t i = 0; i < M; ++i)
    {
        cin >> tmp >> tmp2 >> tmp3;
        nodes[tmp - 1].push_back(make_pair(tmp2 - 1, tmp3));
        nodes[tmp2 - 1].push_back(make_pair(tmp - 1, tmp3));
    }

    for (size_t i = 0; i < N; ++i) {
        cost[i] = INT_MAX;
        /*if(!valid[i]){
            for(size_t j = 0; j < nodes[i].size(); ++j) {
                for(size_t j2 = j + 1; j2 < nodes[i].size(); ++j2) {
                    nodes[nodes[i][j].first].push_back(make_pair(nodes[i][j2].first, nodes[i][j].second + nodes[i][j2].second));
                    nodes[nodes[i][j2].first].push_back(make_pair(nodes[i][j].first, nodes[i][j].second + nodes[i][j2].second));
                }
            }
        }*/
    }

#ifdef DEBUG
    for (size_t i = 0; i < N; ++i)
        cout << valid[i] << "\t";
    cout << endl << endl;

    for (size_t i = 0; i < N; ++i)
    {
        cout << i << endl;
        for (size_t j = 0; j < nodes[i].size(); ++j)
        {
            cout << "\t" << nodes[i][j].first << "\t" << nodes[i][j].second << endl;
        }
    }
#endif // DEBUG

    q.push(make_pair(0, 20));
    cost[0] = 0;

    while(!q.empty()) {
        pair <int, int> elem = q.front();
        q.pop();
        for (size_t i = 0; i < nodes[elem.first].size(); ++i) {
            if(nodes[elem.first][i].second <= elem.second &&
               cost[elem.first] + nodes[elem.first][i].second < cost[nodes[elem.first][i].first]) {
                cost[nodes[elem.first][i].first] = cost[elem.first] + nodes[elem.first][i].second;
                q.push(make_pair(nodes[elem.first][i].first, valid[nodes[elem.first][i].first] ? 20 : elem.second - nodes[elem.first][i].second));
            }
        }
    }

#ifdef DEBUG
    for (size_t i = 0; i < N; ++i)
        cout << cost[i] << "\t";
    cout << endl << endl;
#endif // DEBUG

    if (cost[C - 1] != INT_MAX)
        cout << cost[C - 1] << endl;
    else
        cout << -1 << endl;

    return 0;
}
