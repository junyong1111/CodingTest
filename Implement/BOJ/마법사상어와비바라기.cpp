// https://jypark1111.tistory.com/170
#include <iostream>
#include <vector>
#define MAX_MAP_SZ 51

using namespace std;

typedef long long ll;

// //왼대위,  오대위, 오대아, , 왼대아
ll dx[4] = {-1, 1, 1, -1};
ll dy[4] = {-1, -1, 1, 1};

vector<vector<ll> >Map(MAX_MAP_SZ, vector<ll>(MAX_MAP_SZ, 0));
vector<vector<ll> >biba(MAX_MAP_SZ, vector<ll>(MAX_MAP_SZ, 0));

void init(ll N){
    for(ll i=1; i<=N; i++){
        for(ll j=1; j<=N; j++){
            cin >> Map[i][j];
        }
    }


    biba[N-1][1] = 1; biba[N-1][2] = 1;
    biba[N][1] = 1; biba[N][2] = 1;

}

void print(ll N, string str){
    if(str == "map"){
        for(ll i=1; i<=N; i++){
            for(ll j=1; j<=N; j++){
                cout << Map[i][j] << " ";
            }
        cout << "\n";
        }
    }
    else{
        for(ll i=1; i<=N; i++){
            for(ll j=1; j<=N; j++){
                cout << biba[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
}

void move_left(ll n){
    vector<vector<ll> >temp(n+1, vector<ll>(n+1, 0));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(biba[i][j] == 1){
                biba[i][j] = 0;
                ll tmp = j-1;
                if(tmp<=0){ //넘어가는 경우
                    tmp = n;
                }
                temp[i][tmp] = 1;
            }
        }
    }
    biba = temp;
}

void move_right(ll n){
    vector<vector<ll> >temp(n+1, vector<ll>(n+1, 0));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(biba[i][j] == 1){
                biba[i][j] = 0;
                ll tmp = j+1;
                if(tmp>n){ //넘어가는 경우
                    tmp = 1;
                }
                temp[i][tmp] = 1;
            }
        }
    }
    biba = temp;
}



void move_up(ll n){
    vector<vector<ll> >temp(n+1, vector<ll>(n+1, 0));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(biba[i][j] == 1){
                biba[i][j] = 0;
                ll tmp = i-1;
                if(tmp<=0){ //넘어가는 경우
                    tmp = n;
                }
                temp[tmp][j] = 1;
            }
        }
    }
    biba = temp;
}

void move_down(ll n){
    vector<vector<ll> >temp(n+1, vector<ll>(n+1, 0));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(biba[i][j] == 1){
                biba[i][j] = 0;
                ll tmp = i+1;
                if(tmp>n){ //넘어가는 경우
                    tmp = 1;
                }
                temp[tmp][j] = 1;
            }
        }
    }
    biba = temp;
}


void move_bibaragi(ll dir, ll number, ll n){
    if(dir == 1){ // 왼쪽 이동
        for(ll i=0; i<number; i++){
            move_left(n);
        }
    }
    else if(dir == 2){ // 왼쪽위대각
        for(ll i=0; i<number; i++){
            move_left(n);
            move_up(n);
        }
    }
    else if(dir == 3){ // 위
        for(ll i=0; i<number; i++){
            move_up(n);
        }
    }
    else if(dir == 4){ // 오른쪽위대각
        for(ll i=0; i<number; i++){
            move_right(n);
            move_up(n);
        }
    }
    
    else if(dir == 5){ // 오른쪽
        for(ll i=0; i<number; i++){
            move_right(n);
        }
    }
    else if(dir == 6){ // 오른쪽아래대각
        for(ll i=0; i<number; i++){
            move_right(n);
            move_down(n);
        }
    }
    else if(dir == 7){ // 아래
        for(ll i=0; i<number; i++){
            move_down(n);
        }
    }
    else{
        for(ll i=0; i<number; i++){
            move_left(n);
            move_down(n);
            
        }
    }
}

void water(ll n){
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(biba[i][j] == 1){ // 구름이 있는 칸
                Map[i][j]++;
            }
        }
    }
}

bool index_check(ll x, ll y, ll sz){
    if(x <= 0 || x > sz)
        return false;
    if(y <= 0 || y > sz)
        return false;
    return true;
}

void copy_water(ll n){
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            ll cnt = 0;
            if(biba[i][j] == 1){ // 구름이 있는 칸
                for(ll k=0; k<4; k++){
                    ll nx = j + dx[k];
                    ll ny = i + dy[k];
                    if(index_check(nx, ny, n) == true && Map[ny][nx] >0){
                        cnt++;
                    }
                }
                Map[i][j] = Map[i][j] + cnt;
            }
        }
    }
}

void make_cloud(ll n){
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(biba[i][j] != 1 && Map[i][j] >= 2){ // 구름이 없던 칸에는 구름을 만들기
                biba[i][j] = 1;
                Map[i][j] = Map[i][j]-2; 
            }
            else{ // 구름이 있던 칸에는 구름 제거
                biba[i][j] = 0;
            }
        }
    }
}

ll get_water(ll n){
    ll answer = 0;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            answer += Map[i][j];
        }
    }
    return answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" ,"r" ,stdin);

    ll N = 0; ll M = 0; ll dir, number;
    cin >> N >> M;
    init(N); 
    // init 바구니 셋팅 + 비바라기 시전
    
    for(ll i=0; i<M; i++){
        cin >> dir >> number;
        // step1. 8방향으로 이동
        move_bibaragi(dir, number, N);
        // step2. 구름이 있는 칸에 물 증가
        water(N);
        // step3. 구름이 있던 칸에 대각선에 물이 존재하면 그 갯수만큼 해당 물복사
        copy_water(N);
        // step4. 기존에 구름이 있던 칸을 제외하고 나머지 칸 중 물이 2개 이상이라면 구름 생성
        make_cloud(N);
    }
    // step5. 바구니에 있는 총 물의 양 구하기
    cout << get_water(N) << "\n";
    return 0;
}