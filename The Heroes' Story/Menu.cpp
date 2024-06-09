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
      cout<<"(C) 版权所有 2016-2020 YXH咸鱼(Isaac Romero)           作者QQ:2258488076 2943003";
      cout<<"建议使用Windows XP游玩,否则将出现乱码等现象          WASD控制方向/选择,Enter确认";
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
