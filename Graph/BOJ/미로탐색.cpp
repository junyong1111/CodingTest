// https://jypark1111.tistory.com/115
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct point{
    ll x;
    ll y;
}point;

ll dx[4] = {0, 0, 1, -1}; // 상, 하, 좌, 우
ll dy[4] = {1, -1, 0, 0}; // 상, 하, 좌, 우

bool indexCheck(vector<vector<ll> >&maze, point p){ // 미로 범위 밖을 벗어나지는 확인
    if(p.x < 0 or p.x >= maze[0].size())
        return false;
    if(p.y < 0 or p.y >= maze.size())
        return false;
    return true;
}

bool visitCheck(vector<vector<ll> >&dis, point p) // 미로에 해당 좌표를 방문한적이 있는지 확인
{
    if(dis[p.y][p.x] == 0 )
        return false;
    return true;
}

bool isWall(ll n){ // 벽인지 아닌지 확인
    if (n == 1)
        return false;
    return true;
}

void bfs(vector<vector<ll> >&maze, vector<vector<ll> >&dis, vector<point>&q)
{
    while(!q.empty()){
        point newPoint;
        point oldPoint;
        oldPoint = q.front(); // 현재 큐에 있는 원소를 뺀 후 oldpoint에 저장
        q.erase(q.begin()); // queue pop

        for(ll i=0; i<4; i++){ // 4방향 탐색
            newPoint.x = oldPoint.x + dx[i];
            newPoint.y = oldPoint.y + dy[i];
            // 미로범위내에 있으며 방문한적이 없고 벽이 아닌경우
            if(indexCheck(maze, newPoint) == true and visitCheck(dis, newPoint) == false and
                isWall(maze[newPoint.y][newPoint.x] == false)){
                    // 최단거리를 확인하기 위해 이전에 움직였던 oldPoint distanse에서 1을 증가 후 queue에 새롭게 삽입
                    dis[newPoint.y][newPoint.x] = dis[oldPoint.y][oldPoint.x] + 1; 
                    q.push_back(newPoint);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll N, M;
    string str;
    cin >> N >> M;
    vector<vector<ll> >maze(N, vector<ll>(M, 0)); 
    vector<vector<ll> >dis(N, vector<ll>(M, 0)); // 최단경로를 저장할 distance 2차원 배열
    dis[0][0] = 1; // start point

    for(ll i=0; i<N; i++){
        cin >> str;
        for(ll j=0; j<M; j++){
            maze[i][j] = str[j] - 48;
        }
    }

    vector<point>q;
    point p;
    p.x = 0; p.y = 0; 
    q.push_back(p); // 최초 start point 삽입
    bfs(maze, dis, q);

    cout << dis[N-1][M-1] << "\n";
    // index 시작은 0부터 이므로 -1

    return 0;
}