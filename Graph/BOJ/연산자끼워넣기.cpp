// https://jypark1111.tistory.com/146
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
#define MIN_INF -2147483646
using namespace std;

typedef long long ll;

ll max_value;
ll min_value;

void backtracking(vector<ll>&numbers, vector<ll>&visit_cal,ll *value, ll level){
    if(numbers.size()-1 == level){ // 최종 노드에 도달한 경우 최종 value값에 따라 최대 최소 갱신
        if(max_value < *value)
            max_value = *value;
        if(min_value > *value)
            min_value = *value;
        return ;
    }    
    for(ll i=0; i<4; i++){
        if(visit_cal[i] != 0){ // 현재 연산자를 이용 가능한 경우
            visit_cal[i]--;
            ll temp = *value; // 값 복구를 위한 임시 저장
            switch(i){
                case 0 : // +
                    *value = (*value) + numbers[level+1];
                    backtracking(numbers, visit_cal, value, level+1);
                    *value = temp;
                    visit_cal[i]++;
                    break;
                case 1 : // - 
                    *value = (*value) - numbers[level+1];
                    backtracking(numbers, visit_cal, value, level+1);
                    *value = temp;
                    visit_cal[i]++;
                    break;
                case 2 : // *
                    *value = (*value) * numbers[level+1];
                    backtracking(numbers, visit_cal,value,  level+1);
                    *value = temp;
                    visit_cal[i]++;
                    break;
                case 3: // %
                    if(*value < 0){ //음수의 경우
                        *value = *value * -1; // 양수로 바꾼 후 
                        (*value) = (*value) / numbers[level+1]; // 나눗셈 연산 후
                        *value = *value * -1; // 다시 음수로 
                        backtracking(numbers, visit_cal, value, level+1);
                        (*value) = temp;
                    }
                    else{
                        (*value) = (*value) / numbers[level+1];
                        backtracking(numbers, visit_cal, value, level+1);
                        (*value) = temp;
                    }
                    visit_cal[i]++;
                    break;
            } 
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n = 0;
    cin >> n;

    vector<ll>numbers(n, 0);
    vector<ll>visit_cal(4);
    
    max_value = MIN_INF;
    min_value = INF;
    
    for(ll i=0; i<n; i++)
        cin >> numbers[i];
    for(ll i=0; i<4; i++)
        cin >> visit_cal[i];

    ll value = numbers[0];
    numbers[0] = 1;
    backtracking(numbers, visit_cal, &value, 0);
    cout << max_value << "\n";
    cout << min_value << "\n";


    return 0;
}