/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        //Method 1
        vector<string> answer;
        map<int, string> mp{{3 , "Fizz"}, {5 , "Buzz"}};

        for(int i=1; i<=n; ++i){
            string str = "";
            for(auto& pair : mp){
                if(i % pair.first == 0)
                    str = str + pair.second;
            }
            if (str == "")
                str = to_string(i);
            answer.push_back(str);       
        }

        //Method 2
        // for(int i=1; i<=n; ++i)
        // {   
        //     string str = "";
        //     if (i%3 == 0)
        //         str = str + "Fizz";
        //     if (i%5 == 0)
        //         str = str + "Buzz";
        //     if (i%3 != 0 && i%5 != 0)
        //         str = to_string(i);
        //     answer.push_back(str);
        // }

        //Method 3
        // for(int i=1; i<=n; ++i)
        // {
        //     if(i%3==0 && i%5==0)
        //         answer.push_back("FizzBuzz");
        //     else if (i%3 == 0)
        //         answer.push_back("Fizz");
        //     else if (i%5 == 0)
        //         answer.push_back("Buzz");
        //     else {
        //         string str = to_string(i);
        //         answer.push_back(str);
        //     }
        // }

        return answer;
    }
};

int main(){
    int n = 15;

    Solution sol;

    vector<string> answer = sol.fizzBuzz(n);

    for (auto& ch : answer)
        cout << ch << ", ";

    return 0;
}