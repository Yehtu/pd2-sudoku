#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;

class Sudoku{
	public:
		Sudoku();
		static const int size = 81;
		bool isCorrect();
		void printOut();
		void giveQuestion();
		void readIn();
		void changeNum(int a ,int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void solve();
	private:
	    int board[size];
		void change(); 
		bool checkUnity(int arr[]);
		int next(int i);
		int multiple();
		int judge(int x);
};
