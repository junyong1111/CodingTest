// https://jypark1111.tistory.com/180
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

typedef struct weihgt_price{
  ll price;
  ll weight;
}wp;

// 배낭의 무게 W, 귀금속의 종류 

bool com(wp wp1, wp wp2){
  return wp1.price < wp2.price;
}
int main(int argc, char** argv)
{
  // 배당의 무게 100, 귀금속의 종류 2
  // 1번 귀금속의 무게 90,  가격 1
  // 2번 귀금속의 무게 70, 가격 2

  // 가장 가격이 높은 거를 가져가야함

  ll weight = 0; ll N = 0; ll answer = 0;
  cin >> weight >> N ;

  vector<wp>w_p;

  wp temp;
  for(ll i=0; i<N; i++){
    cin >> temp.weight >> temp.price;
    w_p.push_back(temp);
  }

  sort(w_p.rbegin(), w_p.rend(), com);

  for(ll i=0; i<N; i++){
    if(weight >= w_p[i].weight){
      answer += w_p[i].weight * w_p[i].price;
      weight -= w_p[i].weight;
    }
    else{
      answer += weight * w_p[i].price;
      break;
    }
  }
  cout << answer << "\n";

   return 0;
}