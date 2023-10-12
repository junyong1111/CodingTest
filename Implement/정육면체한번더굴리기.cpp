// https://jypark1111.tistory.com/manage/posts/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX_GRID 20

using namespace std;

typedef long long ll;

typedef struct dice{
    ll right; ll left; ll top; ll bottom; ll front; ll rear;
}dice;

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

dice DICE;
vector<vector<ll> >GRID(MAX_GRID+1, vector<ll>(MAX_GRID+1, 0));
vector<vector<ll> >BOARD(MAX_GRID+1, vector<ll>(MAX_GRID+1, 0));
vector<vector<ll> >VISIT(MAX_GRID+1, vector<ll>(MAX_GRID+1, 0));
ll cnt; ll dir;

void init(ll n){
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            cin >> GRID[i][j];
        }
    }
    BOARD[1][1] = 1;
    dir = 0;
}

void print(ll n, string str){
    if(str == "GRID"){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                cout << GRID[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                cout << BOARD[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
void init_dice(){
    // 1번 주사위 setting 
    DICE.top = 1; DICE.front = 2; DICE.right = 3; DICE.left = 4; DICE.rear = 5; DICE.bottom = 6; 
}

bool isValidPosition(ll x, ll y, ll sz){
    if(x <=0 || x > sz)
        return false;
    if( y<= 0 || y> sz)
        return false;
    return true;
}
pair<ll, ll>get_point(ll sz){
    ll x = 0; ll y = 0;
    for(ll i=1; i<=sz; i++){
        for(ll j=1; j<=sz; j++){
            if(BOARD[i][j] == 1){
                x = j;
                y = i;
                break;
            }
        }
    }
    return make_pair(y, x);
}
void move_right(ll sz);
void move_left(ll sz);
void move_up(ll sz);
void move_down(ll sz);

void move_right(ll sz){
    pair<ll, ll>point = get_point(sz);
    ll dx = point.second + 1;
    if(!isValidPosition(dx, point.first, sz)){
        move_left(sz); dir =2; return; // 만약에 벽에 박은경우 반대방향으로 움직이면서 방향 재설정
    }
    BOARD[point.first][point.second] = 0;
    BOARD[point.first][dx] = 1;
    dice temp = DICE; DICE.top = temp.left; DICE.bottom = temp.right; DICE.left = temp.bottom; DICE.right = temp.top;
}

void move_left(ll sz){
    pair<ll, ll>point = get_point(sz);
    ll dx = point.second - 1;
    if(!isValidPosition(dx, point.first, sz)){
        move_right(sz); dir = 0; return; // 만약에 벽에 박은경우 반대방향으로 움직이면서 방향 재설정
    }
        
    BOARD[point.first][point.second] = 0;
    BOARD[point.first][dx] = 1;
    dice temp = DICE; DICE.top = temp.right;  DICE.bottom = temp.left; DICE.left = temp.top; DICE.right = temp.bottom;
}

void move_down(ll sz){
    pair<ll, ll>point = get_point(sz);
    ll dy = point.first + 1;
    if(!isValidPosition(point.second, dy, sz)){
        move_up(sz); dir = 3; return; // 만약에 벽에 박은경우 반대방향으로 움직이면서 방향 재설정
    }
    BOARD[point.first][point.second] = 0;
    BOARD[dy][point.second] = 1;

    dice temp = DICE; DICE.top = temp.rear; DICE.bottom = temp.front; DICE.front = temp.top; DICE.rear = temp.bottom;
}

void move_up(ll sz){
    pair<ll, ll>point = get_point(sz);
    ll dy = point.first - 1;
    if(!isValidPosition(point.second, dy, sz)){
        move_down(sz); dir =1; return ; // 만약에 벽에 박은경우 반대방향으로 움직이면서 방향 재설정
    }
    BOARD[point.first][point.second] = 0;
    BOARD[dy][point.second] = 1;

    dice temp = DICE; DICE.top = temp.front; DICE.bottom = temp.rear; DICE.front = temp.bottom; DICE.rear = temp.top;
}
                
void init_visit(ll sz){
    for(ll i=0; i<=sz; i++){
        for(ll j=0; j<=sz; j++){
            VISIT[i][j] = 0;
        }
    }
}

void visit(ll sz){
    init_visit(sz);
    pair<ll, ll>p = get_point(sz);
    VISIT[p.first][p.second] = 1;
}


ll get_number(ll sz){
    pair<ll,ll>point = get_point(sz);
    return GRID[point.first][point.second];
}

void dfs(ll sz, ll y, ll x, ll target){
    for(ll k=0; k<4; k++){
        ll nx = x + dx[k];
        ll ny = y + dy[k];
        if(isValidPosition(nx, ny, sz) == true && GRID[ny][nx] == target){
            if(VISIT[ny][nx] ==0){
                VISIT[ny][nx] = 1;
                cnt = cnt+1;
                dfs(sz, ny, nx, target);
            }
        }
    }
}


void find_number(ll sz, ll target){
    cnt = 1;
    visit(sz);
    pair<ll, ll>point = get_point(sz);
    dfs(sz, point.first, point.second, target);
}

void set_dir(ll sz){
    pair<ll, ll>point = get_point(sz);
    ll x = point.second; ll y = point.first;
    if(GRID[y][x] < DICE.bottom){ // 주사위 아래가 보드의 값보다 크면 시계 방향으로 회전
        dir = (dir + 1) % 4;
    }
    else if(GRID[y][x] > DICE.bottom){
        dir = (dir - 1 + 4) % 4;
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n = 0; ll m = 0; ll answer = 0;
    cin >> n >> m;
    init_dice();  init(n);
    // ============= input setting ==============

    
    for(ll i=0; i<m; i++){
        // ==============================  step1. 주사위 이동 ============================== 
        if(dir == 0)
            move_right(n);
        else if(dir == 1)
            move_down(n);
        else if(dir == 2)
            move_left(n);
        else if(dir == 3)
            move_up(n);
        // ============================== step2  ============================== 
        ll number = get_number(n); // 해당 주사위가 위치한 보드에 있는 값 가져오기 
        find_number(n, number);
        answer += (number * cnt); // 그만큼 갯수 추가
        // ============================== step3. 주사위 아랫면과 숫자를 비교해서 이동방향 결정  ============================== 
        set_dir(n); // 방향 결정
    }
    cout << answer << "\n"; 
    return 0;
}