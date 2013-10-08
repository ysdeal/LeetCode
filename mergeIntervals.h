/**
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = intervals.size();
        if(n <= 0) return intervals;
        vector<Interval> res = intervals;
        for(int i = 0; i < n;){
            bool flag = false;
            for(int j = i+1; j < n;){
                if(res[i].start > res[j].end || res[i].end < res[j].start){
                   j++;
                   continue;
                }
                   res[i].start = min(res[i].start, res[j].start);
                   res[i].end = max(res[i].end,res[j].end);
                   res.erase(res.begin()+j);
                   n--;
                   flag = true;
            }
            if(!flag) i++;
        }
        return res;
    }
};