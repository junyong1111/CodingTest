// https://jypark1111.tistory.com/117
#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;

int solution(string s)
{
    int answer = 0;
    char key;
    stack<char>S;
    
    for(ll i=0; i<s.size(); i++){
        if(!S.empty() and s[i] == S.top())
                S.pop();
        else
            S.push(s[i]);
    }
    if(S.empty())
        answer = 1;
 
    return answer;
}