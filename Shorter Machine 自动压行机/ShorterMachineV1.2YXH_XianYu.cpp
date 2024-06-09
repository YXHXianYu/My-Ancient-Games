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

inline BOL isSign(CHR ch) {
	if(ch == '=') return true;
	if(ch == '+') return true;
	if(ch == '-') return true;
	if(ch == '*') return true;
	if(ch == '/') return true;
	if(ch == ')') return true;
	if(ch == '(') return true;
	if(ch == ';') return true;
	if(ch == ',') return true;
	if(ch == '}') return true;
	if(ch == '{') return true;
	return false;
}

int main(int argc,char *args[]) {
	freopen(args[1], "r", stdin);
	freopen(args[2], "w", stdout);
	REG CHR llst=0, lst, ch; REG int i, flag = 0;
	REG BOL t1 = 0, t2 = 0, preline = 0;
	REG BOL define_tag = 0;
	/*
	flag = -1 ´ıÏû³ı×¢ÊÍ 
	flag = 0 ÎŞ×¢ÊÍ
	flag = 1 µ¥ĞĞ×¢ÊÍ
	flag = 2 ¶èĞÔµ¥ĞĞ×¢ÊÍ
	flag = 3 ¶àĞĞ×¢ÊÍ
	flag = 4 ×Ö·û´®
	flag = 5 ×Ö·û
	llst  lst  ch
	      t1   t2
	*/
	
	for(scanf("%c", &lst); scanf("%c", &ch) != EOF; llst = lst, lst = ch, t1 = t2) {
		//std::cerr << t1 << t2 << '\n';
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
			if(t2 == 0 && ch == 10) { // 10 »»ĞĞ·û 
				lst = ch; scanf("%c", &ch); flag = 0;
			}
			continue;
		}
		if(flag == 0) {
			if(lst == '#') {preline = 1;if(define_tag==0)putchar(10);}
			if(lst == '\t') lst = ' ';
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
				if(llst == ' ' && lst == ' ') continue;
				if(lst == 10) {
					if(preline) preline = 0, putchar(lst), define_tag = 1;
					else define_tag = 0;
					continue;
				}
				if(lst == ' ' && isSign(ch)) continue;
				if(isSign(llst) && lst == ' ') continue;
				putchar(lst);
			}
			continue;
		}
	}
	putchar(ch);
	
	return 0;
}



