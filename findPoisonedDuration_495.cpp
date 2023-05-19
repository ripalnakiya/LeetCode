/*
Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.

You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.

Return the total number of seconds that Ashe is poisoned.

Example 1:

Input: timeSeries = [1,4], duration = 2
Output: 4
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 4, Teemo attacks, and Ashe is poisoned for seconds 4 and 5.
Ashe is poisoned for seconds 1, 2, 4, and 5, which is 4 seconds in total.


Example 2:

Input: timeSeries = [1,2], duration = 2
Output: 3
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 2 however, Teemo attacks again and resets the poison timer. Ashe is poisoned for seconds 2 and 3.
Ashe is poisoned for seconds 1, 2, and 3, which is 3 seconds in total.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Optimized version of APPROACH 1
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poisonedDuration = 0;
        for(int i = 0; i < timeSeries.size()-1 ; i++)
            poisonedDuration += min(duration, timeSeries[i+1] - timeSeries[i]);
        return poisonedDuration+duration;
    }
};

// APPROACH 1
// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         int size = timeSeries.size();
//         int diff = 0;
//         int total = 0;
//         for(int i = 0; i < size-1 ; i++) {
//             diff = timeSeries[i+1] - timeSeries[i];
//             total += min(duration, diff);
//         }
//         cout<<total<<" ";
//         total += duration;
//         return total;
//     }
// };

// APPROACH 2 : THIS APPROACH TAKES HIGHER TIME FOR EXECUTION
// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         if(timeSeries.empty())
//             return 0;

//         int count = 0, i = 0;

//         int tsize = timeSeries.size();
//         int size = (timeSeries.back() - timeSeries.front())+duration+1;

//         vector<int> play(size);

//         for(int second = timeSeries[0] ; second <= timeSeries.back()+duration+1, i<tsize ;) {
//             if(second == timeSeries[i]){
//                 {
//                     int p = 0;
//                     while(p < duration){
//                         play[second-timeSeries[0]] = 1;
//                         ++count;
//                         ++p;
//                         ++second;
//                         if(i != tsize-1)
//                             if(second == timeSeries[i+1])
//                                 break;
//                     }
//                 }
//                 if(i == tsize-1 )
//                     break;
//                 i++;            
//             }
//             else
//                 ++second;
//         }
//         return count;
//     }
// };

int main(){
    vector<int> timeSeries = {1,2};
    int duration = 2;

    Solution sol;

    int count = sol.findPoisonedDuration(timeSeries,duration);

    cout<<"\ncount: "<<count<<endl;

    return 0;
}