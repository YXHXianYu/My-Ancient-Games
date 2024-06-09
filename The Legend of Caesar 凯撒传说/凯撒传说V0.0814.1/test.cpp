#include<iostream>
#include"Color.h"
using namespace std;
int main(){
	for(int i=1;i<=256;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
		cout<<i<<endl;
		
		}
	return 0;
	}
