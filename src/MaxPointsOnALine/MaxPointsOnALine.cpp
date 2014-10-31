/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
struct Point {
	int x;
	int y;
// 	bool operator < (const Point& p) const  
// 	{  
// 		if(this->x != p.x)
// 		{
// 			return this->x < p.x;
// 		}else
// 		{
// 			return this->y < p.y;
// 		}
// 	}  
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
// class Solution {
// public:
// 	int maxPoints_map(vector<Point> &points) {
// 		int n = points.size();
// 		map<Point, int> points_uni;
// 		for (auto it = points.begin(); it != points.end(); ++it)
// 		{
// 			points_uni[*it]++;
// 		}
// 		int max_points=points_uni.begin()->second, cnt=0;
// 		for (auto it_i = points_uni.begin(); it_i != points_uni.end(); ++it_i)
// 		{
// 			auto it_j = ++it_i;
// 			it_i--;
// 			for (; it_j != points_uni.end(); ++it_j)
// 			{
// 				cnt=it_i->second+it_j->second;
// 				auto it_k = ++it_j;
// 				it_j--;
// 				for (; it_k != points_uni.end(); ++it_k)
// 				{
// 					if (inSameLine(it_i->first, it_j->first, it_k->first))
// 					{
// 						cnt+=it_k->second;
// 					}
// 				}
// 				if (max_points<cnt)
// 				{
// 					max_points = cnt;
// 				}
// 			}
// 		}
// 		return max_points;
// 	}
// 
//     int maxPoints(vector<Point> &points) {
// 		int n = points.size();
// 		vector<Point> points_uni;
// 		vector<int> points_num;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			int j = 0;
// 			for (; j < points_uni.size(); ++j)
// 			{
// 				if (isSamePoint(points[i], points_uni[j]))
// 				{
// 					points_num[j]++;
// 					break;
// 				}
// 			}
// 			if (j==points_uni.size())
// 			{
// 				points_uni.push_back(points[i]);
// 				points_num.push_back(1);
// 			}
// 		}
//         int max_points=points_num[0], cnt=0;
// 		n = points_num.size();
// 		for (int i = 0; i < n; ++i)
// 		{
// 			for (int j = i+1; j < n; ++j)
// 			{
// 				cnt = points_num[i]+points_num[j];
// 				for (int k = j+1; k < n; ++k)
// 				{
// 					if (inSameLine(points_uni[i], points_uni[j], points_uni[k]))
// 					{
// 						cnt+=points_num[k];
// 					}
// 				}
// 				if (max_points<cnt)
// 				{
// 					max_points = cnt;
// 				}
// 			}
// 		}
// 		return max_points;
//     }
// private:
// 	bool inSameLine(const Point& p1, const Point& p2, const Point& p3) const
// 	{
// 		return (p3.y - p1.y)*(p2.x - p1.x) == (p2.y - p1.y) * (p3.x - p1.x);
// 	}
// 
// 	bool isSamePoint(const Point& p1, const Point& p2) const
// 	{
// 		return p1.x == p2.x && p2.y == p1.y;
// 	}
// };

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:

	int maxPoints_wrong(vector<Point> &points) {
		int size=points.size();
		int num_point=0;
		int i=0,j=0,max=0;
		for(i=0;i<size;i++){
			num_point=1;
			if(num_point>max) max=num_point;
			for(j=i+1;j<size;j++){
				num_point=2;
				while(points[i].x==points[j].x&&points[i].y==points[j].y&&j<size-1){
					num_point++;
					j++;            
				}
				for(int k=j+1;k<size;k++){
					if((points[k].x-points[i].x)*(points[j].y-points[i].y)==(points[j].x-points[i].x)*(points[k].y-points[i].y))
						num_point++;
				}
				if(num_point>max) max=num_point;
			}
		}
		return max;

	}

    int maxPoints(vector<Point> &points) {
		int n = points.size();
		if (0==n)
		{
			return 0;
		}
		vector<Point> points_uni;
		vector<int> points_num;
		for (int i = 0; i < n; ++i)
		{
			int j = 0;
			for (; j < points_uni.size(); ++j)
			{
				if (isSamePoint(points[i], points_uni[j]))
				{
					points_num[j]++;
					break;
				}
			}
			if (j==points_uni.size())
			{
				points_uni.push_back(points[i]);
				points_num.push_back(1);
			}
		}
        int max_points=points_num[0], cnt=0;
		n = points_num.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				cnt = points_num[i]+points_num[j];
				for (int k = j+1; k < n; ++k)
				{
					if (inSameLine(points_uni[i], points_uni[j], points_uni[k]))
					{
						cnt+=points_num[k];
					}
				}
				if (max_points<cnt)
				{
					max_points = cnt;
				}
			}
		}
		return max_points;
    }
private:
	bool inSameLine(const Point& p1, const Point& p2, const Point& p3) const
	{
		return (p3.y - p1.y)*(p2.x - p1.x) == (p2.y - p1.y) * (p3.x - p1.x);
	}

	bool isSamePoint(const Point& p1, const Point& p2) const
	{
		return p1.x == p2.x && p2.y == p1.y;
	}
};

int main()
{
// 	string input = "(40,-23),(9,138),(429,115),(50,-17),(-3,80),(-10,33),(5,-21),(-3,80),(-6,-65),(-18,26),(-6,-65),(5,72),(0,77),(-9,86),(10,-2),(-8,85),(21,130),(18,-6),(-18,26),(-1,-15),(10,-2),(8,69),(-4,63),(0,3),(-4,40),(-7,84),(-8,7),(30,154),(16,-5),(6,90),(18,-6),(5,77),(-4,77),(7,-13),(-1,-45),(16,-5),(-9,86),(-16,11),(-7,84),(1,76),(3,77),(10,67),(1,-37),(-10,-81),(4,-11),(-20,13),(-10,77),(6,-17),(-27,2),(-10,-81),(10,-1),(-9,1),(-8,43),(2,2),(2,-21),(3,82),(8,-1),(10,-1),(-9,1),(-12,42),(16,-5),(-5,-61),(20,-7),(9,-35),(10,6),(12,106),(5,-21),(-5,82),(6,71),(-15,34),(-10,87),(-14,-12),(12,106),(-5,82),(-46,-45),(-4,63),(16,-5),(4,1),(-3,-53),(0,-17),(9,98),(-18,26),(-9,86),(2,77),(-2,-49),(1,76),(-3,-38),(-8,7),(-17,-37),(5,72),(10,-37),(-4,-57),(-3,-53),(3,74),(-3,-11),(-8,7),(1,88),(-12,42),(1,-37),(2,77),(-6,77),(5,72),(-4,-57),(-18,-33),(-12,42),(-9,86),(2,77),(-8,77),(-3,77),(9,-42),(16,41),(-29,-37),(0,-41),(-21,18),(-27,-34),(0,77),(3,74),(-7,-69),(-21,18),(27,146),(-20,13),(21,130),(-6,-65),(14,-4),(0,3),(9,-5),(6,-29),(-2,73),(-1,-15),(1,76),(-4,77),(6,-29)";
// 	string input = "(0,0),(1,1),(0,0),(2,2),(3,3),(4,4),(0,0)";
// 	string input = "(0,0),(0,0),(0,0),(0,0),(0,0),(1,1),(0,0),(2,2),(3,3),(4,4),(0,0)";
	string input = "(0,0),(0,0),(1,1),(0,0),(0,0),(0,0),(0,0),(1,1),(1,1)";
// 	string input = "(0,0),(0,0),(0,0),(0,0),(0,0),(0,0),(0,0)";
	vector<Point> points;
	size_t left = input.find('(');
	size_t right = input.find(')', left);
	while (right!=string::npos)
	{
		size_t split = input.find(',', left);
		string x_str = input.substr(left+1, split-left-1);
		string y_str = input.substr(split+1, right-split-1);
		left = input.find('(', right);
		right = input.find(')', left);
		int x = atoi(x_str.c_str());
		int y = atoi(y_str.c_str());
		Point new_point(x, y);
		points.push_back(new_point);
	}
	Solution solution;
	cout << solution.maxPoints_wrong(points);
}