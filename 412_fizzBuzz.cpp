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

// APPROACH 1 : USING MAP : SCALABLE FUNCTION i.e. FizzBuzzJazz would also work with this approach
class Solution {
public:
    vector<string> fizzBuzz(int n) {

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

        return answer;
    }
};

// APPROACH 2 : USING STRING CONCATENATION
class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> answer;

        for(int i=1; i<=n; ++i)
        {   
            string str = "";
            if (i%3 == 0)
                str = str + "Fizz";
            if (i%5 == 0)
                str = str + "Buzz";
            if (i%3 != 0 && i%5 != 0)
                str = to_string(i);
            answer.push_back(str);

        }

        return answer;
    }
};

// APPROACH 3: NAIVE APPROACH
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> answer;

        for(int i=1; i<=n; ++i)
        {
            if(i%3==0 && i%5==0)
                answer.push_back("FizzBuzz");
            else if (i%3 == 0)
                answer.push_back("Fizz");
            else if (i%5 == 0)
                answer.push_back("Buzz");
            else {
                string str = to_string(i);
                answer.push_back(str);
            }
        }

        return answer;
    }
};