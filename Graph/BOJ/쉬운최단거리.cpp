#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef struct point{
    ll x;
    ll y;
}point;

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

void print(vector<vector<ll> >&graph, ll n, ll m){
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isPromise(point p, vector<vector<ll> >&graph){
    if(p.x < 0 || p.x >= graph[0].size())
        return false;
    if(p.y < 0 || p.y >= graph.size())
        return false;
    if(graph[p.y][p.x] == 0)
        return false;
    return true;
}



ll bfs(vector<vector<ll> >&graph, vector<vector<ll> >&visit, queue<point>&q)
{
    vector<vector<ll> >trace(graph.size(), vector<ll>(graph[0].size(), 0));
    while(!q.empty()){
        point new_point;
        point old_point = q.front();
        q.pop();
        for(ll i=0; i<4; i++){
            new_point.x = old_point.x + dx[i];
            new_point.y = old_point.y + dy[i];
            if(isPromise(new_point, graph) == true){
                visit[new_point.y][new_point.x] = visit[old_point.y][old_point.x] + 1;
                q.push(new_point);
                if(graph[new_point.y][new_point.x] == 2)
                    return visit[new_point.y][new_point.x];
            }
        } 

    }
    return 0;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll n = 0;
    ll m = 0;
    cin >> n >> m;

    vector<vector<ll> >graph(n, vector<ll>(m, 0));
    vector<vector<ll> >dis(n, vector<ll>(m, 0));
    point p;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++)
            cin >> graph[i][j];
    }
    

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            vector<vector<ll> >visit(n, vector<ll>(m, 0));
            queue<point>q;
            if(graph[i][j] == 2)
                continue;
            p.y = i;
            p.x = j;
            q.push(p);
            dis[i][j] = bfs(graph, visit, q);
        }
    }
    // print(graph, n, m);
    print(dis, n, m);

    return 0;
}