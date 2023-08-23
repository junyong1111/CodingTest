// https://jypark1111.tistory.com/130
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647

using namespace std;
typedef long long ll;

vector<ll>teamA;
vector<ll>teamB;
ll minValue = INF;

void backtracking(vector<vector<ll> >&startNlink,ll index, ll cnt){
    vector<ll>::iterator it;

    if(cnt== 0){
        for(ll i=1; i<startNlink.size(); i++){ // 모든 선수명단을 체크
	        it = find(teamA.begin(), teamA.end(), i); 
		        if(it == teamA.end()){ //만약 teamA에 속하지 못한 선수가 있는 경우
			        teamB.push_back(i); // teamB에 영입
	            }
        }

        ll sumA = 0;
        ll sumB = 0;
        
        for(ll i=0; i<teamA.size()-1; i++){
            for(ll j=i+1; j<teamA.size(); j++ ){
                sumA += startNlink[teamA[i]][teamA[j]];
                sumA += startNlink[teamA[j]][teamA[i]]; //A팀 시너지 계산

                sumB += startNlink[teamB[i]][teamB[j]];
                sumB += startNlink[teamB[j]][teamB[i]]; //B팀 시너지 계산
            }
        }
    
        if (minValue > abs(sumA - sumB)) // 최솟값 갱신
            minValue = abs(sumA - sumB);
        teamB.clear(); // B팀 초기화
        return ;
    }
    else{
        for(ll i=index; i<startNlink.size(); i++){
            teamA.push_back(i); // teamA에 선수 1명 영입
            backtracking(startNlink, i+1,  cnt-1); //위 선수를 제외한 다음 선수 탐색 시작
            teamA.pop_back(); // 영입했던 마지막 선수 제외
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll N = 0;
    cin >> N;
    vector<vector<ll> >startNlink(N+1, vector<ll>(N+1, 0));
    vector<ll>visit(N+1, 0);

    for(ll i=1; i<=N; i++){
        for(ll j=1; j<=N; j++){
            cin >> startNlink[i][j];
        }
    }
    backtracking(startNlink, 1, N/2);
    cout << minValue << "\n";
    return 0;
}