// https://jypark1111.tistory.com/manage/posts/
#include <iostream>
#include <vector>

#define INF 2100000000
#define SIZE 100001

using namespace std;

typedef long long ll;
vector<ll>DISTANCE(SIZE, 0);
ll dx[3] = {-1, 1, 2}; 
//1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동

bool IndexCheck(ll point){
    if(point < 0 || point >= SIZE)
        return false;
    return true;
}

bool DisCheck(ll point, ll N){
    if(DISTANCE[point] == 0)
        return true;
    return false;
}   

void bfs(vector<ll> q, ll N, ll target){
    while(q.size() !=0){
        ll newPoint = 0;
        ll old_point = q.front();
        q.erase(q.begin());
        for(ll i=0; i<3; i++){
            if(i == 2)
                newPoint = old_point * dx[i]; // 2*X 위치
            else
                newPoint = old_point + dx[i]; //  X-1 Or X+1 위치
            
            if((IndexCheck(newPoint) == true) and (DisCheck(newPoint, N) == true)){
                DISTANCE[newPoint] = DISTANCE[old_point] + 1;
                q.push_back(newPoint);
                if(newPoint == target) // Target을 찾으면 종료
                    return ;
                
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);
    
    ll N, K;
    cin >> N >> K;
    if( N == K){
        cout << 0 << "\n";
        return 0;
    }
    
    vector<ll>q;
    DISTANCE[N] = 1;
    q.push_back(N);
    bfs(q, N, K);

    cout << DISTANCE[K]-1 << "\n";
    return 0;
}