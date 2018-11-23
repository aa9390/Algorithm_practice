#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution{
public:
    string BinaryToHex(int number){
	    int value = 0;
	    string result;
	    int mul = 1;
	    
	    // 함수의 인자를 2진수로 보고, 10진수로 변환
	    while (number > 0){
		    if (number % 2)
			    value += mul;
		    mul *= 2;
		    number /= 10;
	    }
	    
	    char temp[8];
	    
	    // 16진수로 변환하여 
	    if(value < 16) {
	        sprintf(temp, "0%X", value);
	    }
	    else {
	        sprintf(temp, "%X", value);
	    }
	    
	    result = temp;
	    return result;
    }
    
    string encoder(string message){
        string bit = "";
        string byte = "";
        
        for(int i=0; i<message.length(); i++) {
            // 알파벳 소문자면
            if(message[i] >= 97 && message[i] <= 122) {
              bit += bitset<6>(int(message[i] - 97)).to_string();
            }
            // 알파벳 대문자면
            else if(message[i] >= 65 && message[i] <= 90) {
              bit += bitset<6>(int(message[i] - 39)).to_string();
            }
            else if(message[i] >= 48 && message[i] <= 57) {
              bit += bitset<6>(int(message[i] + 4)).to_string();
            }
            else if(message[i] == 32) {
              bit += bitset<6>(62).to_string();
            }
        }
        
        while(bit.length()%8 != 0) {
            bit += '0';
        }
        
		for (int i=0; i<bit.length(); i+=8) {
		    string temp = bit.substr(i,8);
			byte += BinaryToHex(stoi(temp));
		}
		
        return byte;
    }
};
