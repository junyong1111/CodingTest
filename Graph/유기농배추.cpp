// https://jypark1111.tistory.com/114 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef struct point{
    ll x;
    ll y;
}point;

ll dx[4] = {0, 0, 1, -1}; //상, 하, 좌, 우
ll dy[4] = {1, -1, 0, 0}; //상, 하, 좌, 우

bool indexCheck(point p, ll N, ll M){
    if(p.x < 0 or p.x >= M)
        return false;
    if(p.y <0 or p.y >= N)
        return false;
    return true;
}

bool isCabbage(ll n){
    if (n == 0)
        return false;
    return true;
}

void dfs(vector<vector<ll> >&farm, point p, ll N, ll M)
{
    point newPoint;
    farm[p.y][p.x] = 0; // 배추 삭제
    for(ll i=0; i<4; i++){ // 연결된 배추 탐색
        newPoint.x = p.x + dx[i];
        newPoint.y = p.y + dy[i];
        if(indexCheck(newPoint, N, M) == true and isCabbage(farm[newPoint.y][newPoint.x]) ==true){
            dfs(farm, newPoint, N, M);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll testCase, M, N, K, x, y;
    cin >> testCase;
    while (testCase--)
    {
        cin >> M >> N;
        vector<vector<ll> >farm(N, vector<ll>(M, 0)); // N x M 농장 생성
        cin >> K;
        for(ll i=0; i<K; i++){
            cin >> x >> y;
            farm[y][x] = 1;
        }

        ll answer = 0;
        point p;
        for(ll i=0; i<N; i++){
            for(ll j=0; j<M; j++){ // 농장을 모두 순회
                if(farm[i][j] == 1){ // 만약 배추가 있다면 배추를 삭제하고 dfs 탐색
                    farm[i][j] = 0;
                    p.x = j; p.y = i;
                    dfs(farm, p, N, M);
                    answer ++;
                }
            }
        }
        cout << answer << "\n";
    } // testCase
    return 0;
}