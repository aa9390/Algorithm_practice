#include <string>
using namespace std;

class Solution{
public:
    string decryptSpell(string str){
        // 문자열의 길이만큼 검사
        for(int i=0; i<str.length(); i++) {
            // 문자열에서 3으로 나누어 떨어지는 순서이면
            if((i+1)%3==0) {
                // 해당 문자가 소문자면 대문자로 변환
                if(str[i] >= 97 && str[i] <= 122) {
                    str[i] = toupper(str[i]);
                }
                // 해당 문자가 소문자가 아니면 느낌표로 변환
                else {
                    str[i] = '!';
                }
            }
        }
        return str;
    }
};
