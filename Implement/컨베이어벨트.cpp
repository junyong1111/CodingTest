// https://jypark1111.tistory.com/169
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <bitset>

#define MAX_SZ 1001
#define MAX_BIT 201

using namespace std;
typedef long long ll;

deque<ll>A;
bitset<MAX_BIT>bit;
ll CNT;
ll Answer;

void init(ll N){
    ll temp = 0;
    for(ll i=0; i<N*2; i++){
        cin >> temp;
        A.push_back(temp);
    }
    CNT = 0;
}

void print(ll N){
    for(ll i=0; i<N*2; i++){
        cout << A[i] << " ";
    }
    cout << "\n";

    for(ll i=1; i<=N*2; i++){
        cout << bit[i] << " ";
    }
    cout << "\n";
}


void get_A(ll n){
    ll cnt = 0;
    for(ll i=0; i<2*n; i++){
        if(A[i] == 0){
            cnt++;
        }
    }
    CNT = cnt;
}

void set_robot(ll N){
    if(A[0] <= 0 )
        return;
    A[0]--;
    bit[1] = 1;
    // 1번 위치에 로봇 올리기
    get_A(N);
}

void getout_robot(ll N){
    if(bit[N] == 1){
        bit[N] = 0;
    }
}

void move_belf(ll N){
    if(bit[2*N] == 1){
        bit = bit << 1;
        bit[1] = 1;
    }
    else bit = bit << 1;
    A.push_front(A.back());
    A.pop_back();
    getout_robot(N);
}


void move_robot(ll idx){
    bit[idx] = 0; bit[idx+1] = 1;
    A[idx] -- ;
}

void move(ll N){
    if((bit[N*2] == 1 && bit[1] == 0) && A[1] > 0){
        bit[N*2] = 0; bit[1] = 1; A[1] -- ;
    }
    for(ll i= (2*N)-1; i>=1; i-- ){
        if((bit[i] == 1 && bit[i+1] == 0) && A[i] > 0){ // 로봇이 이동할 수 있다면
            move_robot(i); // 로봇을 움직임
            getout_robot(N); // 움직인 이후 바로 나갈 수 있다면 나감
            get_A(N); // 계산함
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" , stdin);

    ll N, K;
    cin >> N >> K;
    init(N);
    // ---------- input and setting ---------
    
    if(K <= CNT)
        return Answer;   
    while(1){
        Answer++; 
        move_belf(N); // step1. 컨베이어 벨트 회전 
        move(N); // step2. 로봇의 이동 가능성 확인 
        set_robot(N); // step3. 로봇 올리기
        if(K <= CNT)
            break;
    }
    cout << Answer << "\n";
    return 0;
}