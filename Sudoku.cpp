#include "Sudoku.h"

Sudoku::Sudoku(){  		//initialize
	for( int i = 0 ; i < size ; ++i )
		board[i] = 0;
}

void Sudoku::printOut(){
	for( int i = 0 ; i < 81 ; ++i )
		printf("%d%c",board[i],(i+1)%9==0?'\n':' ');
}

void Sudoku::giveQuestion(){
	srand(time(NULL));
	if( rand()%5 == 0 ){
		printf("0 0 0 0 0 5 0 2 0\n1 0 0 9 0 0 0 0 0\n"
			   "4 0 0 0 0 0 0 0 0\n0 0 8 0 0 2 0 0 0\n"
		   	   "0 0 0 0 0 0 0 0 1\n0 0 0 0 0 0 9 0 4\n"
		   	   "0 0 5 0 0 0 3 0 0\n0 0 0 1 0 0 0 0 7\n"
		   	   "0 0 2 4 0 8 0 0 0\n");}
	else if( rand()%5 == 1){
		printf("0 0 0 0 0 0 0 0 0\n0 5 0 0 0 1 0 0 0\n"
				"0 0 0 6 0 0 7 8 0\n8 0 0 7 0 0 0 6 0\n"
				"0 0 0 0 0 0 0 0 0\n0 3 0 0 0 0 0 0 5\n"
				"7 0 6 0 0 0 0 4 0\n0 9 0 0 0 5 0 0 1\n"
				"0 0 0 0 0 3 0 0 0\n");}
	else if( rand()%5 == 2){
		printf("0 2 0 0 0 6 0 0 0\n0 0 0 0 0 0 4 0 0\n"
				"3 0 0 0 0 0 8 0 0\n0 0 0 8 0 0 0 0 0\n"
				"0 6 0 0 0 0 0 7 0\n9 0 0 4 0 0 3 0 0\n"
				"0 0 1 0 0 7 0 6 0\n0 0 0 0 0 0 0 2 0\n"
				"4 0 0 3 0 0 0 0 0\n");}	
	else if( rand()%5 == 3){
		printf("0 0 5 0 0 0 0 0 9\n0 0 0 0 0 0 0 0 0\n"
				"7 0 0 6 0 0 1 0 0\n0 0 0 0 0 4 0 0 0\n"
				"0 0 0 0 5 9 0 0 3\n2 0 0 0 0 0 0 7 0\n"
				"0 0 9 0 0 8 0 0 0\n0 0 0 7 0 0 2 6 0\n"
				"0 0 4 0 0 0 0 0 0\n");}
	else{
		printf("0 0 1 0 0 8 0 9 0\n0 4 0 0 0 0 0 0 5\n"
				"0 0 0 0 0 0 0 0 0\n0 0 0 0 9 0 0 0 7\n"
				"0 0 2 0 0 3 0 0 0\n0 0 8 0 0 0 6 0 0\n"
				"0 7 0 0 5 0 0 0 0\n0 0 0 0 0 2 8 0 0\n"
				"0 5 0 0 0 0 0 4 0\n");}
}

void Sudoku::readIn(){
	for( int i = 0 ; i < 81 ; ++i )
		cin >> board[i];
}

void Sudoku::changeNum(int a, int b){
	if( a == b ) 
		return;
	for( int i = 0 ; i < 81 ; ++i ){
		if( board[i] == a )
			board[i] = b;
		else if( board[i] == b )
			board[i] = a;}
}

void Sudoku::changeRow(int a, int b){
	int i,c,temp;
	if( a == b ) 
		return;
	c = a-b;
	for( i = 27*a ; i < 27*a+27 ; ++i ){
		temp = board[i];
		board[i] = board[i-27*c];
		board[i-27*c] = temp;}
}

void Sudoku::changeCol(int a, int b){
	int i,j,c,temp;
	if( a == b ) 
		return;
	c = a-b;
	for( j = 0 ; j < 3 ; ++j ){
		for( i = 3*a ; i < 3*a+73 ; i+=9){
			temp = board[i+j];
			board[i+j] = board[i+j-3*c];
			board[i+j-3*c] = temp;}
}	}

void Sudoku::rotate(int n){
	int i,j,temp;
	if( n%4 == 1 ){
		for( j = 0 ; j < 4 ; ++j ){
			for( i = 0 ; i < 8-2*j ; ++i ){
				temp = board[72-8*j-9*i];
				board[72-8*j-9*i] = board[80-10*j-i];
				board[80-10*j-i] = board[9*i+8*j+8];
				board[9*i+8*j+8] = board[i+10*j];
				board[i+10*j] = temp;}
			}	}
		else if( n%4 == 2 ){
			for( j = 0 ; j < 4 ; ++j ){
				temp = board[44-j];
				board[44-j] = board[36+j]; 
				board[36+j] = temp;
				for( i = 0 ; i < 9 ; ++i ){
					temp = board[80-i-9*j];
					board[80-i-9*j] = board[i+9*j];
					board[i+9*j] = temp;}
			}	}
		else if( n%4 == 3 ){
			for(j = 0 ; j < 4 ; ++j){
				for( i = 0 ; i < 8-2*j ; ++i ){
					temp = board[i+10*j];
					board[i+10*j] = board[9*i+8*j+8];
					board[9*i+8*j+8] = board[80-10*j-i];
					board[80-10*j-i] = board[72-8*j-9*i];
					board[72-8*j-9*i] = temp;}
			}	}
	else{
		return;}
}

void Sudoku::flip(int n){
	int i,j,temp;
	if ( n == 1 ){
		for( j = 0 ; j < 28 ; j+=9 ){
			for( i = 0 ; i < 9 ; ++i ){
				temp = board[i+j];
				board[i+j] = board[i+72-j];
				board[i+72-j] = temp;}
		}	}
	else{
		for( j = 0 ; j < 4 ; ++j ){
			for( i = 0 ; i < 73 ; i+=9){
				temp = board[i+j];
				board[i+j] = board[i+8-j];
				board[i+8-j] = temp;}
}	}	}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::transform(){
	change();
	printOut();
}

bool Sudoku::checkUnity(int arr[]){
	int unity[9]; 	//counters
	int i;
	for( i = 0 ; i < 9 ; ++i )
		unity[i] = 0; 	// initialize
	for( i = 0 ; i < 9 ; ++i ){
		if( arr[i] != 0 )       
			++unity[arr[i]-1];} 	 // count 
	for( i = 0 ; i < 9 ; ++i ){
		if(unity[i] > 1)
			return false;}
	return true;
}

bool Sudoku::isCorrect(){
	bool check_result;
	int check_arr[9];
	int location;
	int i,j;
	for( i = 0 ; i < 81 ; i+=9 ){       //check row
		for( j = 0 ; j < 9 ; ++j)
	    	check_arr[j] = board[i+j];
		check_result = checkUnity(check_arr);
		if( check_result == false )
			return false;}
	for( i = 0 ; i < 9 ; ++i ){         //check column
		for( j = 0 ; j < 9 ; ++j )
			check_arr[j] = board[i+9*j];
		check_result = checkUnity(check_arr);
		if( check_result == false )
			return false;}
	for( i = 0 ; i < 9 ; ++i ){         //check block
		for( j = 0 ; j < 9 ; ++j ){
			location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
			check_arr[j] = board[location];}
			check_result = checkUnity(check_arr);
			if( check_result == false )
				return false;}
	return true;
}

int Sudoku::next(int i) {       //find the next blank to solve
	while( i < size && board[i] != 0 )
		++i;
	return i;
}

int Sudoku::multiple(){   		//if clue < 17, there are more than one solution 
	int j = 0;
	for( int i = 0 ; i < 81 ; ++i ){
	if( board[i] != 0 )
		++j;}
	return j;
}

int Sudoku::judge(int x){   		//find the number which is not used before
	int i,j,r,c,lr,lc;
	int num[10] = {0}; 			//consider 0
	r = x/9;
	c = x%9;
	for( i = 0 ;i < 9 ; ++i ) 		//count row
		num[board[i+9*r]]++;
	for( i = 0 ; i < 9 ; ++i ) 		//count column
		num[board[9*i+c]]++;
	lr = r - (r%3);
	lc = c - (c%3);
	for( i = lr; i < lr+3; ++i ){ 		//count block
		for( j = lc; j < lc+3; ++j )
			num[board[9*i+j]]++;}
	int tmp = board[x];
	if(num[tmp]>3){
		for (i=tmp+1;i<10;i++){
			if (num[i] == 0) return i;}
		return 10;}
	return tmp;
}

void Sudoku::solve(){
	if( isCorrect() == false ){	
		cout << 0 << endl;
		return;}
	int clue = multiple();
	if( clue < 17 ){
		cout << 2 << endl;
		return;}
	if( next(0) == size ){
		cout << 1 << endl;
		printOut();
		return;}
	int nBlank = 81-clue;       //numbers of blank
	int map[nBlank]; 		//arr to save blank of board[]
	int mapidx = 0;	  		//index of map[]
	int tmp = next(0);
	map[0] = tmp;
	for( int j = 1 ; j < nBlank ; ++j )
		map[j] = next(map[j-1]+1);
	int nAns = 0;		//numbers of answer		
	int ans[81];
	do{
		board[tmp]++;
		board[tmp] = judge(tmp);
		if( board[tmp] > 9 ){	
			board[tmp] = 0;
			if( mapidx <= 0 )	
				tmp = -1;
			else
				tmp = map[--mapidx];}	
		else{
			mapidx++;			
			if( mapidx == nBlank ){
				for( int i = 0 ; i < 81 ; ++i )
					ans[i] = board[i];
				nAns++;
				tmp = map[--mapidx];}
			else
				tmp = map[mapidx];}	
	}while( tmp >= 0 && nAns < 2 );		
	if( nAns == 0 )		
		cout << 0 << endl;
	else if( nAns > 1 )		
		cout << 2 << endl;
	else{
		 cout << 1 << endl;
		 for( int i = 0 ; i < 81 ; ++i )
	     	printf("%d%c",ans[i],(i+1)%9==0?'\n':' ');}
}
