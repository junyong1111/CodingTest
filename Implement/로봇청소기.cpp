// https://jypark1111.tistory.com/172
#include <iostream>
#include <vector>
#define MAX_SZ 50

using namespace std;

typedef long long ll;
typedef struct ROBOT{
    ll x;
    ll y;
    ll dir;
}ROBOT;

vector<vector<ll> >MAP(MAX_SZ, vector<ll>(MAX_SZ, 0));
ROBOT kobot;
ll CLEANEDROOM;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

void init(ll n, ll m)
{
    cin >> kobot.y >> kobot.x >> kobot.dir;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> MAP[i][j];
        }
    }
    CLEANEDROOM = 0;
}

void clean_room(ll n, ll m){
    ll x = kobot.x; ll y = kobot.y; 
    if(MAP[y][x] == 0){ // 청소가 안되어 있다면
        MAP[y][x] = -1; // 청소 하고 갯수 증가
        CLEANEDROOM++;
    }
}

bool is_possible(ll x, ll y, ll n, ll m){
    if(x < 0 || x >= m)
        return false;
    if(y < 0 || y >= n)
        return false;
    return true;
}

bool find_room(ll n, ll m){
    bool evertyting_clean = true;
    ll x = kobot.x; ll y = kobot.y;
    for(ll i=0; i<4; i++){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(is_possible(nx, ny, n, m) == true && MAP[ny][nx] == 0){
            evertyting_clean = false;
            return evertyting_clean;
        }
    }
    return evertyting_clean;
}

bool move_back(ll n, ll m){ // 바라보는 방향을 유치한 채로 1칸 후진
    ll x = kobot.x ; ll y = kobot.y;

    if(kobot.dir == 0){ // 북
        y = y + 1;
    }
    else if(kobot.dir == 1){ // 동
        x = x -1;
    }
    else if(kobot.dir == 2){ // 남
        y = y -1;
    }
    else if(kobot.dir == 3){ // 서
        x = x + 1;
    }   
    if(is_possible(x ,y, n, m) == true && MAP[y][x] != 1){ // 이동이 가능하며 벽이 아닌 경우 후진
        kobot.x = x; kobot.y = y;
        return true;
    }
    return false;
}

void rotate(){
    if(kobot.dir == 0){ //  북 -> 서
        kobot.dir = 3; 
    }
    else if(kobot.dir == 1){ // 동 -> 북
        kobot.dir = 0;
    }
    else if(kobot.dir == 2){ // 남 -> 동
        kobot.dir = 1;
    }
    else if(kobot.dir == 3){ // 서-> 남
        kobot.dir = 2;
    }
}

bool move(){
    ll x = kobot.x; ll y = kobot.y;
    if(kobot.dir == 0){ //  북 
        y--;
    }
    else if(kobot.dir == 1){ // 동 
        x++;
    }
    else if(kobot.dir == 2){ // 남 
        y++;
    }
    else if(kobot.dir == 3){ // 서
        x--;
    }

    if(MAP[y][x] == 0){
        kobot.x = x; kobot.y = y;
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);
    ll n =0; ll m =0;
    cin >> n >> m;
    init(n, m);
    // print(n, m);
    // ======================================================= init =================================================================

    while(1){
        // step 1 현재 칸이 청소가 되지 않았다면 청소
        clean_room(n, m);
        // step 2. 현재 칸의 주변 $4$칸 중 청소되지 않은 빈 칸이 없는 경우
        bool evertyting_clean = find_room(n, m); // 모두 청소가 되어있는 경우 true 반환

        if(evertyting_clean == true){ // 모두 청소가 되어 있으면 후진 가능성 확인
            bool possible_back = move_back(n, m);
            if(possible_back == true)
                continue; // 후진이 가능하면 방향을 유지한채 한 칸 후진 이후 step 1으로 
            if(possible_back == false){ //  후진이 불가능하다면 종료
                break;
            }  
        }
        // step 3. 현재 칸의 주변 $4$칸 중 청소되지 않은 빈 칸이 있는 경우,
        else{  
            for(ll i=0; i<4; i++){
                rotate(); // 청소되지 않은 공간 존재 하면 반시계 방향으로 90도 회전
                if (move() == true){ // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
                    break;
                }
            }
        }
    }
    cout << CLEANEDROOM << "\n";

    return 0;
}