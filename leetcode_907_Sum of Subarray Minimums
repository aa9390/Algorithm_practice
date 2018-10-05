class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
//         int answer = 0;
        
//         for(int i=0; i<A.size(); i++) {
//             vector<int> v;
//             int minValue = 30001;
//             for(int j=i; j<A.size(); j++) {
//                 v.insert(v.end(), A.begin() + j, A.begin() + j+1);
//                 for(int k=0; k<v.size(); k++) {
//                     if(v[k] < minValue) minValue = v[k];
//                 }
//                 answer += minValue;
//             }
//         }

//         return answer;
        
//         long answer = 0;
        
//         for(int i=0; i<A.size(); i++) {
//             int minValue = 30001;
//             for(int j=i; j<A.size(); j++) {
//                 if(minValue > A[j]) {
//                   minValue = A[j];
//                 }
//                 answer += minValue;
//             }
//         }
//         return answer % 1000000007;
        
        long answer = 0;
        
        for(int i=0; i<A.size(); i++) {
          int minValue = 30001;
          stack<int> s;
          for(int j=i; j<A.size(); j++) {
            s.push(A[j]);
            int m = s.top();
            if(minValue > m) {
              minValue = m;
              s.pop();
            }
            answer += minValue;

          }
        }
        return answer % 1000000007;
    }
};
