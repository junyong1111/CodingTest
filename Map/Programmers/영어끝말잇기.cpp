// https://jypark1111.tistory.com/122
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef long long ll;

vector<int> solution(int n, vector<string> words) {
    char lastWord = words[0][0];
    vector<int>answer;
    map<string, ll>m;
    ll i = 0;
    
    for(i=0; i<words.size(); i++){ // words를 순회
        // 만약 끝말잇기 조건이 충족되면서 처음 들어온 단어라면 map에 저장
        if(lastWord == words[i][0] and m.count(words[i]) == 0) 
            m.insert(make_pair(words[i], 1));
        else // 아니라면 끝말잇기 종료
            break;
        lastWord = words[i][words[i].size()-1]; // 마지막 문자 저장
    }
    
    if(words.size()== i){ //정상종료된 경우
        answer.push_back(0);
        answer.push_back(0);
    }
    else{ //탈락자가 발생한 경우 
        answer.push_back((i%n) + 1);
        answer.push_back((i/n) + 1);
    }
        
    return answer;
}