#include<iostream>
#include<cstring>
#include<cstdio>
#include<conio.h>
#include"YXH.cpp"
using namespace std;

int menu(int n,char str[][50]){
  //cout<<"                                                                                ";	
	
	char temp;
    int p=1;
    while(1){
      cout<<"                                                                                ";
      cout<<"     ***** *         *   *                      *   *****                       ";
      cout<<"       *   *         *   *                      *   *      *                    ";
      cout<<"       *   *** ***   ***** *** **** *** *** *--     ***** *** *** **** | |      ";
      cout<<"       *   * * ***   *   * ***  *   * * *** *-*         *  *  * *  *   | |      ";
      cout<<"       *   * * ***   *   * ***  *   *** *** --*     *****  ** ***  *   **|      ";
      cout<<"                                                                         |      ";
      cout<<"                                                                        **      ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      for(int i=1;i<=n-1;i++){
      	
        space(25);
        if(p==i)
          cout<<"---> ";
        else
          space(5);
        cout<<str[i]<<endl;
        }
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"(C) ��Ȩ���� 2016-2020 YXH����(Isaac Romero)           ����QQ:2258488076 2943003";
      cout<<"����ʹ��Windows XP����,���򽫳������������          WASD���Ʒ���/ѡ��,Enterȷ��";
      temp=_getch();
      system("cls");
      if(temp==int(13))
        return p;
      if(temp=='w' && p>1)
        p--;
      if(temp=='s' && p<n-1)
        p++;
      }
    }
