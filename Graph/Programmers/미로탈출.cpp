// https://jypark1111.tistory.com/manage/posts/
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define MAX_SZ 100

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

vector<string>MAP(MAX_SZ);

pi START;
void init(vector<string>&maps){
    for(ll i=0; i<maps.size(); i++){
        MAP[i] = maps[i];
    }
}

pi find_point(char ch, vector<string>&maps){
    pi p;
    for(ll i=0; i<maps.size(); i++){
        for(ll j=0; j<maps[i].size(); j++){
            if(maps[i][j] == ch){
                return make_pair(i, j);
            }
        }
    }
    return p;
}

bool is_possible(ll ny, ll nx, ll n, ll m){
    if(ny < 0 || ny >= n)
        return false;
    if(nx < 0 || nx >= m)
        return false;
    return true;
}

ll bfs(pi s , ll n, ll m, char target){
    ll dx[4] = {0, 0, 1, -1};
    ll dy[4] = {1, -1, 0, 0};
    vector<vector<ll> >dis(n, vector<ll>(m, 0));
    queue<pi>q;
    q.push(s);
    dis[s.first][s.second] = 0;
    ll cnt = 0;
    
    while(!q.empty()){
        pi oldp = q.front(); q.pop();
        for(ll i=0; i<4; i++){
            ll ny = dy[i] + oldp.first;
            ll nx = dx[i] + oldp.second;
            if(is_possible(ny, nx, n, m) == true and MAP[ny][nx] != 'X' and dis[ny][nx] == 0){
                // 인덱스 범위 내에 있으면서 벽이 아니고 최초 방문인 경우
                dis[ny][nx] = dis[oldp.first][oldp.second] + 1;
                q.push(make_pair(ny, nx));
            }
            
        }
    } // while
    pi t = find_point(target, MAP);
    if(dis[t.first][t.second] != 0){
        cnt = dis[t.first][t.second];
        START = t;
    }
    return cnt;
}

int solution(vector<string> maps) {
    // TO DO
    init(maps);
    START = find_point('S', maps);
    ll l = 0; ll e = 0;
    l = bfs(START, maps.size(), maps[0].size(), 'L');
    if(l == 0)
        return -1;
    e = bfs(START, maps.size(), maps[0].size(), 'E');
    if(e == 0) return -1;
    return l+e;
}