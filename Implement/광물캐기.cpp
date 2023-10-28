#include <iostream>
#include <string>
#include <vector>

#define MAX_SZ 10

using namespace std;
typedef long long ll;


vector<ll>SCORES(MAX_SZ, 0);
ll MIN;

ll init(ll sz){
    ll size = (sz/5);
    if(sz%5 != 0){
        size++;
    }
    
    for(ll i=0; i<size; i++){
        SCORES[i] = 0;
    }
    return size;
}


void print(ll sz, vector<vector<string> >&arr){
    for(ll i=0; i<sz; i++){
        for(ll j=0; j<5; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// SCORES[idx] = get_score(i, idx, cut_minerals);
ll get_score(ll idx, ll level,  vector<vector<string> >&arr){
    ll score = 0;
    if(idx == 0){ // 다이아 
        for(ll i=0; i<5; i++){
            if(arr[level][i] == "")continue;
            score++;
        }
    } // 다이아
    
    else if(idx == 1){ // 철
        for(ll i=0; i<5; i++){
            if(arr[level][i] =="")continue;
            if(arr[level][i] == "diamond") score += 5;
            else score++;
        }
    } // 철
    
    else if(idx == 2){ // 돌
        for(ll i=0; i<5; i++){
            if(arr[level][i] =="")continue;
            if(arr[level][i] =="diamond") score += 25;
            else if(arr[level][i] == "iron") score+= 5;
            else score++;
        }
        
    } // 돌
    return score;
}

bool check_picks(vector<int>&picks){
    for(ll i=0; i<picks.size(); i++){
        if(picks[i] !=0)
            return true;
    }
    return false;
}


ll get_sum(ll sz);
void backtracking(vector<int>&picks, ll idx, vector<vector<string> >&cut_minerals, ll sz){
    if(idx == sz){
        ll sum = 0;
        for(ll i=0; i<sz; i++){
            sum += SCORES[i];
        }
        if(MIN >= sum){MIN = sum;}
        return ;
    }
    
    for(ll i=0; i<3; i++){
        if(picks[i] <= 0){continue;} // 해당 곡괭이가 선택이 된다면 진행
        SCORES[idx] = get_score(i, idx, cut_minerals);
        picks[i] --;
        if(check_picks(picks) == false){
            ll sum = get_sum(sz);
            if(MIN >= sum )MIN = sum; return;
        }
        backtracking(picks, idx+1, cut_minerals, sz);
        picks[i] ++;
    }
}


ll get_sum(ll sz){
    ll sum = 0;
    for(ll i=0; i<sz; i++){
        sum += SCORES[i];
    }
    return sum;
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    ll sz = init(minerals.size());
    vector<vector<string> >cut_minerals(sz, vector<string>(5));
    MIN = 21000000000000000;
    
    
    for(ll i=0; i<sz; i++){
        for(ll j=0; j<5; j++){
            if((i*5) + j >= minerals.size()) continue;
            cut_minerals[i][j] = minerals[(i*5)+j];
        }
    }
    
    // print(sz, cut_minerals);
    
    bool check = false;
    for(ll i=0; i<3; i++){
        if(picks[i] <= 0){continue;} // 해당 곡괭이가 선택이 된다면 진행
        check = true;
        SCORES[0] = get_score(i, 0, cut_minerals);
        // 점수 까지 완료
        picks[i] --;
        // 탐구하기전에 이미 끝난거면 현재 까지 정보로만 최종값 선정빠이
        if(check_picks(picks) == false){
            ll sum = get_sum(sz);
            if(MIN >= sum )MIN = sum; break;
        }
        backtracking(picks, 1, cut_minerals, sz);
        picks[i] ++;
    }
    if(check == false)MIN = 0;
   
    return MIN;
}