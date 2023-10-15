#include <iostream>
#include <vector>
#include <cmath>
#define MAX_SZ 10
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

vector<vector<ll> >MAP(MAX_SZ+1, vector<ll>(MAX_SZ+1, 0));
vector<pi>participant;
pi REC[2]; pi E; ll CNT;

void init(ll N, ll M){
    for(ll i=1; i<=N; i++){
        for(ll j=1; j<=N; j++){
            cin >> MAP[i][j];
        }
    }
    pi p ;
    for(ll i=0; i<M; i++){
        cin >> p.first >> p.second;
        participant.push_back(p);
    }
    cin >> E.first >> E.second;
    CNT = 0;
}
void print(ll n){
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "map printng.....\n";

    for(ll i=0; i<participant.size(); i++){
        cout << "y : " << participant[i].first << " x : " << participant[i].second << "\n"; 
    }
    cout << "participant printing.....\n";

    cout << "y : " << E.first << " x : " << E.second << "\n"; 
    cout << "EXIT printing.....\n";
}
void print_arr(ll n, vector<vector<ll> >& arr){
    for(ll i=1;  i<=n; i++){
        for(ll j=1; j<=n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "arr printing.........\n";
}
void update_map(ll n){
    vector<vector<ll> >tmp(n+1, vector<ll>(n+1, 0));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n ;j++){
            if(MAP[i][j] >=0 )
                tmp[i][j] = MAP[i][j]; // 내구도 정보와 이동 가능 경로만 옮긴다.
        }
    }
    for(ll i=0; i<participant.size(); i++){
        ll y = participant[i].first; ll x = participant[i].second; 
        tmp[y][x] = -2; // 참가자는 -2로 
    }
    tmp[E.first][E.second] = -1; // 출구는 -1로
    MAP = tmp;
}
void update_parti(ll n){
    participant.clear();
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(MAP[i][j] == -2){
                participant.push_back(make_pair(i,j));
            }
            if(MAP[i][j] == -1){
                E.first = i; E.second =j;
            }
        }
    }
}
void exit_participant(ll idx)
{  
    participant.erase(participant.begin() + idx);
    CNT++; // 이동 횟수 증가
}
ll cal_dis(pi p1, pi p2){
    ll dis = abs(p1.second - p2.second) + abs(p1.first - p2.first);
    return dis;
}
bool is_possbile(ll y, ll x, ll sz){
    if( y <= 0 || y > sz)
        return false;
    if( x <= 0 || x > sz)
        return false;
    return true;
}
void move_participant(ll n){
    ll dx[4] = {0, 0, 1, -1};
    ll dy[4] = {-1, 1, 0, 0};

   for(ll i=0; i<participant.size(); i++){
    vector<vector<ll> >tmp(n+1, vector<ll>(n+1, -1));
        ll target_dis = cal_dis(make_pair(participant[i].first,participant[i].second), make_pair(E.first, E.second));
        tmp[participant[i].first][participant[i].second] = target_dis;
        ll min = 100000;
        pi point;
        for(ll j=0; j<4; j++){ // 이동로직
            ll ny = participant[i].first + dy[j];
            ll nx = participant[i].second + dx[j];
            
            if(is_possbile(ny, nx, n) == true && MAP[ny][nx] <= 0){
                if(ny == E.first && nx == E.second){ // 출구를 찾은경우
                    exit_participant(i);  CNT++; continue;
                }
                tmp[ny][nx] = cal_dis(make_pair(ny,nx), make_pair(E.first, E.second));
                if(min > tmp[ny][nx]){
                    min = tmp[ny][nx];
                    point.first = ny; point.second = nx;
                    // 좌표 저장
                }
            }
        } // 4방향을 탐색

        // 탐색한 결과에서 이동하는게 더 좋으면 이동 하고 아니면 안함
        if(min >= target_dis) continue; // 가만히 있는게 더 좋은 경우 패스
        participant[i].first = point.first; participant[i].second = point.second; 
        CNT =  CNT+1;
   } 
}

ll find_min_rec(ll N){
    for(ll rec = 2; rec <=N; rec++){
        for(ll x= 0; x<= (N-rec+1); x++){
            for(ll y=0; y<= (N-rec+1); y++){
                bool person = false; bool door = false; 
                for(ll i=1+y; i<=rec+y; i++){
                    for(ll j=1+x; j<=rec+x; j++){
                        if(MAP[i][j] == -2 && person == false){
                            person = true;
                            // REC[idx].first =i; REC[idx].second = j; idx++;
                        } 
                        if(MAP[i][j] == -1 && door == false){
                            door = true;
                            // REC[idx].first =i; REC[idx].second = j; idx++;
                        }
                    if(person && door)// 둘다 찾으면 
                    {
                        REC[0].first =y+1; REC[0].second = x+1;
                        REC[1].first =y+rec; REC[1].second = x+rec;
                        return rec;

                    }
                } // 정사각형안에 있는지 확인
            } // 정사각형안에 있는지 확인
        } // 왼쪽부터 내려옴   
        }
        
    }
    return -1; // 못찾음
}
void rotate_rec(ll min_size, ll n){
    vector<vector<ll> >ro_arr(min_size, vector<ll>(min_size));
    vector<vector<ll> >ro_tmp(min_size, vector<ll>(min_size));
    ll idxx = 0; ll idxy = 0;

    for(ll i=REC[0].first; i<=REC[1].first; i++){
        idxx = 0;
        for(ll j= REC[0].second; j<=REC[1].second; j++){
            ro_arr[idxy][idxx] = MAP[i][j];
            idxx++;
        }
        idxy++;
    }

    for(ll i=0; i<min_size; i++){
        for(ll j=0; j<min_size; j++){
            ro_tmp[i][j] = ro_arr[min_size-j-1][i];
            if(ro_tmp[i][j] >0){
                ro_tmp[i][j]--;// 내구도 감소
            }
        }
    }
    // 90도 시계 방향 회전 

    // 다시 옮겨 담기
    idxx = 0; idxy = 0;

    for(ll i=REC[0].first; i<=REC[1].first; i++){
        idxx = 0;
        for(ll j= REC[0].second; j<=REC[1].second; j++){
            MAP[i][j] = ro_tmp[idxy][idxx];
            idxx++;
        }
        idxy++;
    }
    update_parti(n); // 참가자 + 출구 업데이트
    return ;


    for(ll i=0; i<min_size; i++){
        for(ll j=0; j<min_size; j++){
            cout << ro_arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "min_rota_arr\n";
    for(ll i=0; i<min_size; i++){
        for(ll j=0; j<min_size; j++){
            cout << ro_tmp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "min_rota_arr\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r" ,stdin);

    ll N, M, K ;
    cin >> N >> M >> K;

    init(N, M);
    // print(N);








    ll turn = 1;
    while(K--){
        update_map(N);

        // step1. 참가자 전원 이동
        move_participant(N);
        update_map(N);
        if(participant.size() ==0){ // 모든 참가자가 나간 경우
            break;
        }

        // step2. 제일 작은 정사각형 찾고 회전
        // MAP[1][2] = -1;
        ll min_rec = find_min_rec(N); // 2-1 작은 정사각형 찾기

        // cout << REC[0].first << " " << REC[0].second << "\n";
        // cout << REC[1].first << " " << REC[1].second << "\n";

        rotate_rec(min_rec, N); // 작은 정사각형 크기만큼 회전
        // print(N);
        cout << turn << "번 째 턴 종료\n"; cout << CNT  << "만큼 움직임\n";
        turn++;
    }



    return 0;
}