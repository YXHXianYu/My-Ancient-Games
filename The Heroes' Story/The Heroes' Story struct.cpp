#include<iostream>
using namespace std;

struct hero_struct{
    int x,      //x            x轴坐标 
        y,      //y            y轴坐标 
        money,  //money        金钱 
        hp,     //headth point 血量 
        dmg,    //damage       攻击力 
        def,    //defense      防御力 
        spd,    //speed        速度 
        score;  //score        分数 
    char ico=char(1);
	}h;

struct monster_struct{
    int hp,
	    dmg,
		m,
		def,
		score;
	}m;
