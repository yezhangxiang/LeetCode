#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
bool cmpIntervals(const Interval& interval1, const Interval& interval2)
{
	return interval1.start < interval2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> mergeInerval;
		if (intervals.empty())
		{
			return mergeInerval;
		}
		sort(intervals.begin(),intervals.end(),cmpIntervals);
		mergeInerval.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].start <= mergeInerval.rbegin()->end)
			{
				if (intervals[i].end > mergeInerval.rbegin()->end)
				{
					mergeInerval.rbegin()->end = intervals[i].end;
				}
			}
			else
			{
				mergeInerval.push_back(intervals[i]);
			}
		}
		return mergeInerval;
    }
};
int main()
{
	vector<Interval> intervals;
// 	intervals.push_back(Interval(1, 3));
// 	intervals.push_back(Interval(2, 6));
// 	intervals.push_back(Interval(3, 4));
// 	intervals.push_back(Interval(8, 10));
// 	intervals.push_back(Interval(15, 18));
// 	intervals.push_back(Interval(16, 20));

	Solution solution;
	vector<Interval> mergeInerval = solution.merge(intervals);

	for (int i = 0; i < mergeInerval.size(); ++i)
	{
		cout << "[" << mergeInerval[i].start << ", " << mergeInerval[i].end << "], ";
	}
	cout << endl;
}