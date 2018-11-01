#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <regex>
using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    string url[21];
    int basicPoint[21] = {0};
    string exUrl[21][21] = {""};
    int exPoint[21] = {0};
    double linkPoint[21] = {0.0};
    
    for(int i=0; i<pages.size(); i++) {
        // 페이지 url 추출
        string url_s = "";
        string content_s = "content=\""; string close_s="\"/>";
        
        for(int j=pages[i].find(content_s)+content_s.size(); j<pages[i].find(close_s); j++) {
            url_s += pages[i][j];
        }
        url[i] = url_s;

        // 기본점수 & 외부 링크 수
        string body_s = "";
        string body_open = "<body>"; string body_close = "</body>";
        regex word_reg(word, std::regex_constants::icase);
        regex link_reg("(https://\"?.*?(\">))");
        
        int startIdx = pages[i].find(body_open) + body_open.size();
        int endIdx = pages[i].find(body_close);
        
        for(int j=startIdx; j<endIdx; j++) {
            body_s += pages[i][j];
        }
        
        int cnt = 0;
        smatch matches; string temp = body_s;
        while (regex_search(temp, matches, word_reg)) {
            cout << "match string is " << matches[0] << endl;
            temp = matches.suffix();
            cnt++;
        }
        
        basicPoint[i] = cnt;
        cout << url[i] << "의 기본점수 : " << basicPoint[i] << endl;
        
        temp = body_s; string exUrl_s = ""; int j=0;
        while (regex_search(temp, matches, link_reg)) {
            string s1 = matches[0];
            int idx = s1.find("\">");
            string s2 = s1.erase(idx);
            cout << "match string is " << s1 << endl;
            exUrl[i][j++] = s1;
            temp = matches.suffix();
            exPoint[i]++;
        }
        
        cout << url[i] << "의 외부 링크 수 : " << exPoint[i] << endl;
        cout << "=================================" << endl;
    }
    
    // 링크점수
    cout << exUrl[0][0] << endl;
    cout << exUrl[1][0] << endl; cout << exUrl[1][1] << endl;
    cout << exUrl[2][0] << endl;
    
    for(int i=0; i<pages.size(); i++) {
        for(int j=0; j<pages.size(); j++) {
            // if(exUrl[i][j] == url[j]) {
            //     cout << url[i];
            // }
        }
        // cout <<endl;
    }
    
    return answer;
}
