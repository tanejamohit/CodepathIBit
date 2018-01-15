/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

*You may assume that the intervals were initially sorted according to their start times*.

**Example 1:**

Given intervals `[1,3],[6,9]` insert and merge `[2,5]` would result in `[1,5],[6,9]`.

**Example 2:**

Given `[1,2],[3,5],[6,7],[8,10],[12,16]`, insert and merge `[4,9]` would result in `[1,2],[3,10],[12,16]`.

This is because the new interval `[4,9]` overlaps with `[3,5],[6,7],[8,10]`.

Make sure the returned intervals are also sorted. 
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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> result;
    bool isIntervalMerged = false;
    for (int i = 0; i < intervals.size(); i++) {
        //cout<< "Interval from "<<intervals[i].start<< " to " <<intervals[i].end;
        if (intervals[i].end < newInterval.start) {
            //cout<<" is early"<<endl;
            result.push_back(intervals[i]);
        }
        if (intervals[i].start > newInterval.end) {
            if (!isIntervalMerged) {
                result.push_back(newInterval);
                isIntervalMerged = true;
                //cout<<"Inserted new interval in the middle"<<endl;
            }
            //cout<<" is after"<<endl;
            result.push_back(intervals[i]);
        }
        
        // Check if start lies between this interval
        if ((intervals[i].start <= newInterval.start 
        && intervals[i].end >= newInterval.start) || 
        (intervals[i].start >= newInterval.start 
        && intervals[i].start <= newInterval.end)) {
            //cout<<"is in the middle"<<endl;
            Interval mergeInterval = intervals[i];
            mergeInterval.start = min(newInterval.start, intervals[i].start);
            while (intervals[i].end < newInterval.end && i < intervals.size()) {
                //cout<< "Skipping Interval from "<<intervals[i].start<< " to " <<intervals[i].end<<endl;
                i++;
            }
            if (intervals[i].start > newInterval.end) {
                //cout<< "Interval from "<<intervals[i].start<< " to " <<intervals[i].end<<" is after the new interval"<<endl;
                mergeInterval.end = newInterval.end;
                result.push_back(mergeInterval);
                result.push_back(intervals[i]);
            }
            else {
                mergeInterval.end = max(newInterval.end, intervals[i].end);
                //cout<< "Merge Interval from "<<mergeInterval.start<< " to " <<mergeInterval.end<<endl;
                result.push_back(mergeInterval);
            }
            isIntervalMerged = true;
        }
    }
    if (!isIntervalMerged) {
        result.push_back(newInterval);
    }
    return result;
}
