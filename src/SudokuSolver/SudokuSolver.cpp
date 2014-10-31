#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char> > &board)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		int next_x = 0, next_y = 0;
		if (findNext(board, next_x, next_y))
		{
			for (char next_k = '1'; next_k <= '9'; ++next_k)
			{
				recursion(board, next_x, next_y, next_k);
			}
		}
	}
private:
	bool recursion(vector<vector<char> > &board, int x, int y, char k) {
		if (check(board, x, y, k))
		{
			board[x][y] = k;
			int next_x = x, next_y = y+1;
			if (findNext(board, next_x, next_y))
			{
				for (char next_k = '1'; next_k <= '9'; ++next_k)
				{
					if (recursion(board, next_x, next_y, next_k))
					{
						return true;
					}
				}
			}
			else
			{
				return true;
			}
			board[x][y] = '.';
		}
		return false;
	}
	bool check(vector<vector<char> > &board, int i, int j, char k)
	{
		for (int l = 0; l < 9; ++l)
		{
			if (board[i][l] == k || board[l][j] == k ||\
				board[i/3*3+l/3][j/3*3+l%3] == k)
			{
				return false;
			}
		}
		return true;
	}
	bool findNext(vector<vector<char> > &board, int &next_x, int &next_y)
	{
		int cursor = next_x*9+next_y;
		while (cursor < 81)
		{
			if (board[cursor/9][cursor%9] == '.')
			{
				next_x = cursor/9;
				next_y = cursor%9;
				return true;
			}
			cursor++;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	char board_tmp[][10] = {"53..7....",\
		"6..195...",\
		".98....6.",\
		"8...6...3",\
		"4..8.3..1",\
		"7...2...6",\
		".6....28.",\
		"...419..5",\
		"....8..79"};
// 	char board_tmp[][10] = {".........",\
// 		".........",\
// 		".........",\
// 		".........",\
// 		".........",\
// 		".........",\
// 		".........",\
// 		".........",\
// 		"........."};
// 	char board_tmp[][10] =    {"53467.912",\
// 								"672195348",\
// 								".9834256.",\
// 								"859761423",\
// 								"4268.3..1",\
// 								"713924856",\
// 								"96153728.",\
// 								"287419635",\
// 								".45286179"};
	vector<vector<char> > board;
	for (int i = 0; i < 9; ++i)
	{
		vector<char> tmp(board_tmp[i], board_tmp[i]+9);
		board.push_back(tmp);
	}
	solution.solveSudoku(board);
	print(board);
}