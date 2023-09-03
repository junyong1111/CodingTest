// https://jypark1111.tistory.com/140
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef struct point{
    ll x;
    ll y;
}point;

ll dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
ll dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool indexCheck(ll size, point p){
    if(p.x < 0 || p.x >= size) 
        return false;
    if(p.y <0 || p.y >= size)
        return false;
    return true;
}
bool distanceCheck(vector<vector<ll> >&distance, point p){
    if(distance[p.y][p.x] != -1)
        return false;
    return true;
}

void bfs(vector<vector<ll> >&distance, queue<point>& q, point end)
{
    while(!q.empty()){
        point old_point, new_point;
        old_point = q.front();
        q.pop();

        for(ll i=0; i<8; i++){
            new_point.x = dx[i] + old_point.x;
            new_point.y = dy[i] + old_point.y;
            if(indexCheck(distance.size(), new_point) == true and distanceCheck(distance, new_point) == true){
                distance[new_point.y][new_point.x] = distance[old_point.y][old_point.x] + 1;
                q.push(new_point);
            }
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll testCase = 0;
    ll size;
    cin >> testCase;

    while(testCase--){
        cin >> size;
        vector<vector<ll> >distance(size, vector<ll>(size, -1));
        point start, end;
        queue<point>q;
        cin >> start.y >> start.x;
        cin >> end.y >> end.x;
        distance[start.y][start.x] = 0;
        q.push(start);
        bfs(distance, q, end);
        cout << distance[end.y][end.x] << "\n";
    }

    return 0;
}