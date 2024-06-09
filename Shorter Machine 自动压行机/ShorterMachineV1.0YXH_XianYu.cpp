#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define REG register
#define LLI long long
#define DBL double
#define CHR char 
#define BOL bool
#define MOD (p)
const int MXN = 1000010;


int main(int argc,char *args[]) {
	freopen(args[1], "r", stdin);
	freopen(args[2], "w", stdout);
	REG CHR ch, lst; REG int i, flag = 0;
	REG BOL t1 = 0, t2 = 0, preline = 0;
	/*
	flag = -1 待消除注释 
	flag = 0 无注释
	flag = 1 单行注释
	flag = 2 惰性单行注释
	flag = 3 多行注释
	flag = 4 字符串
	flag = 5 字符
	*/
	
	for(scanf("%c", &lst); scanf("%c", &ch) != EOF; lst = ch, t1 = t2) {
		//std::cerr << t1 << t2 << '\n';
		if(lst == '#') preline = 1;
		if(lst == '\t') lst = ' ';
		if(flag == 3) {
			if(t1 == 0 && t2 == 0 && lst == '*' && ch == '/') {
				lst = ch; scanf("%c", &ch); flag = 0;
			}
			continue;
		}
		if(flag == 4) {
			t2 = (t1 == 0 && lst == '\\');
			if(t2 == 0 && ch == '"') {
				flag = 0;
			}
			putchar(lst);
			continue;
		}
		if(flag == 5) {
			t2 = (t1 == 0 && lst == '\\');
			if(t2 == 0 && ch == '\'')
				flag = 0;
			putchar(lst);
			continue;
		}
		if(flag == 1) {
			t2 = (lst == '\\');
			if(t2 == 0 && ch == 10) { // 10 换行符 
				lst = ch; scanf("%c", &ch); flag = 0;
			}
			continue;
		}
		if(flag == 0) {
			t2 = (t1 == 0 && lst == '\\');
			if(t1 == 0 && t2 == 0 && lst == '/' && ch == '*')
				flag = 3;
			else if(t2 == 0 && ch == '"')
				putchar(lst), flag = 4;
			else if(t2 == 0 && ch == '\'')
				putchar(lst), flag = 5;
			else if(t1 == 0 && t2 == 0 && lst == '/' && ch == '/')
				flag = 1;
			else {
				if(lst == ' ' && ch == ' ') continue;
				if(lst == 10) {
					if(preline) preline = 0, putchar(lst);
				}
				else putchar(lst);
			}
			continue;
		}
	}
	putchar(ch);
	
	return 0;
}



