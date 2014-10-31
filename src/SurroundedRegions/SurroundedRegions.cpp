#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char> > &board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
class Solution {
public:
	void solve(vector<vector<char>> &board) {
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (0 == i || board.size()-1 == i || 0 == j || board[i].size()-1 == j)
				{
					capture(board, i, j);
				}
			}
		}
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if ('O' == board[i][j])
				{
					board[i][j] = 'X';
				}
				if ('\0' == board[i][j])
				{
					board[i][j] = 'O';
				}
			}
		}
	}
private:
	void capture(vector<vector<char>> &board, int i, int j)
	{
		if ('O' == board[i][j])
		{
			board[i][j] = '\0';
			if (i-1 >= 0)				capture(board, i-1, j);
			if (i+1 < board.size())		capture(board, i+1, j);
			if (j-1 >= 0)				capture(board, i, j-1);
			if (j+1 < board[i].size())	capture(board, i, j+1);
		}
	}
};
int main()
{
	Solution solution;
	char board_tmp[][9] =	   {"XXXXXOOX",\
								"XOOXXOOO",\
								"XOXXOXXX",\
								"OXXOOOXX",\
								"OOOXXXXX",\
								"OXXOOOXX",\
								"XXXXXOXX"};
	vector<vector<char> > board;
	for (int i = 0; i < 7; ++i)
	{
		vector<char> tmp(board_tmp[i], board_tmp[i]+8);
		board.push_back(tmp);
	}
	print(board);
	solution.solve(board);
	print(board);
}