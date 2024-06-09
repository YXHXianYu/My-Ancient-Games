#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<windows.h>
#include"Random_Maker.cpp"
#include"YXH.cpp"
#include"movie.cpp"
#include"The Heroes' Story struct.cpp"
#define CLS system("cls")
#define PAUSE system("pause")
#define MS mapsum
#define BR birth_
using namespace std;

int i,j,n;
char cname[300];

const int mapsum=5;//地图总数 
const char grass=' ',//               0
           coin=char(36),//           1
		   devil=char(15),//          2-monster
		   zombie=char(20),//		  3-monster
		   life=char(3),//            4
           sword=char(33),//          5
           npc=char(2),//             6 
		   coin_monster=char(36),//   7-monster
		   ghost=char(128),//         8-monster
		   trap=char(127),//          9-monster
		   double_sword=char(19),//   10
		   exit1=char(21);//          100

char map[MS+1][10][81];//地图 8*80(25*80)
int bomap[MS+1][10][81];//地图属性


//int h1=4,h2=10,money=10,hp,dmg,score=0;//玩家坐标&钱 血 攻 分 
//char hero=char(1);//玩家图标 
int newmapset[MS+1][3]={-1,-1,-1,
                        -1,4,10,
						-1,8,5,
						-1,4,40,
						-1,4,40,
						-1,1,5}; 

char ans,//玩家的回答 
     pw[10];//密码??? 
bool bo,
     bodie=0,//是否死亡 
	 bojump=0,//是否跳过商店 
	 newmap=1;//是否进入新地图--->以便初始化 
int  monster_kind,//是否遇到怪&怪的种类 
     bonpc=0,//是否遇到npc 
	 bofscore=5,//???
	 shop_level=0,//商店等级 
     boexit=1;//当前地图&是否通关 

void die();
void about();
int menu_();
int menu(int n,char str[][50],char note[][50]);
void console();//控制台!?!
void gameover();
void option();

void fcout(){//输出高分榜---close 
    freopen("High_Score.txt","w",stdout);
    freopen("High_Score.xy","r",stdin);
    char fcname[5][15];int fscore[5],temp[5];
    for(i=0;i<=4;i++){
      cin>>temp[i];
      cin>>fcname[i];
      cin>>fscore[i];
      }
    for(i=4;i>=0;i--)
      if(h.score>=fscore[i])bofscore=i;
    if(bofscore==5){
      fclose(stdin);
      fclose(stdout);
      return;}
    for(i=4;i>=bofscore+1;i--){
      fscore[i]=fscore[i-1];
      strcpy(fcname[i],fcname[i-1]);}
    fscore[bofscore]=h.score;
    strcpy(fcname[bofscore],cname);
    for(i=0;i<=4;i++){
      cout<<i+1<<endl;
      cout<<fcname[i]<<endl;
      cout<<fscore[i]<<endl<<endl;}
    system("pause");
    //fclose(stdin);
    //fclose(stdout);
    system("pause");
    return;
     }
void move(int k,char t){//                   移动函数 
    //if(bomap[k][h.x][h.y]=-1)
    //  return;
    if((t=='a')&&(h.y!=5))
      {map[k][h.x][h.y]=grass;h.y-=5;map[k][h.x][h.y]=h.ico;}
    if((t=='d')&&(h.y!=80))
      {map[k][h.x][h.y]=grass;h.y+=5;map[k][h.x][h.y]=h.ico;}
    if((t=='w')&&(h.x!=1))
      {map[k][h.x][h.y]=grass;h.x-=1;map[k][h.x][h.y]=h.ico;}
    if((t=='s')&&(h.x!=8))
      {map[k][h.x][h.y]=grass;h.x+=1;map[k][h.x][h.y]=h.ico;}
    if(bomap[k][h.x][h.y]==1)//coin 
      {bomap[k][h.x][h.y]=0;h.money++;}
    if(bomap[k][h.x][h.y]==2)//zombie
      {bomap[k][h.x][h.y]=0;monster_kind=1;}
    if(bomap[k][h.x][h.y]==3)//devil
      {bomap[k][h.x][h.y]=0;monster_kind=2;}
    if(bomap[k][h.x][h.y]==4)//life
      {bomap[k][h.x][h.y]=0;h.hp+=3;h.score+=3;}
    if(bomap[k][h.x][h.y]==5)//sword
      {bomap[k][h.x][h.y]=0;h.dmg++;h.score+=5;}
    if((k==1 || k==2) && h.x==1 && h.y==5)//Shop  注意这里的先后顺序 
      {bomap[k][h.x][h.y]=0;bonpc=2;}
    if(bomap[k][h.x][h.y]==6)//npc 注意这里的先后顺序
      {bomap[k][h.x][h.y]=0;bonpc=1;h.score+=5;}
    if(bomap[k][h.x][h.y]==7)
      {bomap[k][h.x][h.y]=0;monster_kind=3;}
    if(bomap[k][h.x][h.y]==8)
      {bomap[k][h.x][h.y]=0;monster_kind=4;}
	if(bomap[k][h.x][h.y]==9)
      {bomap[k][h.x][h.y]=0;monster_kind=5;}
	if(bomap[k][h.x][h.y]==10)
      {bomap[k][h.x][h.y]=0;h.dmg+=2;h.score+=5;}
	if(bomap[k][h.x][h.y]==100)//exit
      {bomap[k][h.x][h.y]=0;boexit++;h.score+=100;newmap=1;}
}

void birth_coin(int k,int x,int y){//        生成金币函数:1
     map[k][x][y]=coin;
	 bomap[k][x][y]=1;
     }
void birth_life(int k,int x,int y){//        生成爱心函数:4
     map[k][x][y]=life;
	 bomap[k][x][y]=4;
     }
void birth_sword(int k,int x,int y){//       生成剑函数:5
     map[k][x][y]=sword;
	 bomap[k][x][y]=5;
     }
void birth_npc(int k,int x,int y){//         生成npc函数:6
     map[k][x][y]=npc;
	 bomap[k][x][y]=6;
     }
void birth_double_sword(int k,int x,int y){//         生成npc函数:6
     map[k][x][y]=double_sword;
	 bomap[k][x][y]=10;
     }
void birth_exit(int k,int x,int y){//         生成传送门:100
     map[k][x][y]=exit1;
	 bomap[k][x][y]=100;
     }
void birth_monster(int k,int x,int y,int z){//生成怪物函数
     if(z==1){
     map[k][x][y]=zombie;//              zombie:2
     bomap[k][x][y]=2;}
     if(z==2){
     map[k][x][y]=devil;//               devil:3
     bomap[k][x][y]=3;}
     if(z==3){
     map[k][x][y]=coin_monster;//        coin_monster:7
     bomap[k][x][y]=7;}
     if(z==4){
     map[k][x][y]=ghost;//               ghost:8
     bomap[k][x][y]=8;}
    if(z==5){
     map[k][x][y]=trap;//                trap:9
     bomap[k][x][y]=9;}
	}     
       
void choose_hero(){
	system("cls");
	int choose_hero_temp=1;
    while(1){
      space(30);cout<<"你要折磨哪个角色?\n";
	  if(choose_hero_temp==1){
	    space(28);cout<<"-->  ";}
	  else
	    space(33);
	  cout<<"1:Human   "<<char(1)<<endl;
      if(choose_hero_temp==2){
	    space(28);cout<<"-->  ";}
	  else
	    space(33);
	  cout<<"2:Fighter "<<char(38)<<endl;
      if(choose_hero_temp==3){
	    space(28);cout<<"-->  ";}
	  else
	    space(33);
	  cout<<"3:DJ      "<<char(14)<<endl;
      if(choose_hero_temp==4){
	    space(28);cout<<"-->  ";}
	  else
	    space(33);
	  cout<<"4:Mercy   "<<char(12)<<endl;
      ans=_getch();
      if(ans=='\n' || ans=='\r')
        break;
      if(ans=='w' && choose_hero_temp>=2)
        choose_hero_temp--;
      if(ans=='s' && choose_hero_temp<=3)
        choose_hero_temp++;
      CLS;
	  }
    endl(12);
    switch(choose_hero_temp){
      case 1:h.ico=char(1);h.score=10;h.hp=30;h.dmg=2;h.def=1;break;
      case 2:h.ico=char(38);h.score=-10;h.hp=50;h.dmg=3;h.def=1;break;
      case 3:h.ico=char(14);h.score=20;h.hp=30;h.dmg=1;h.def=1;break;
      case 4:h.ico=char(12);h.score=50;h.hp=30;h.dmg=1;h.def=0;break;
      }
    
    }
void random_hero(int a){
    system("cls");
	endl(3);space(10);
	cout<<"你面前出现了一扇通天的大门,门框似乎是用藤蔓做的.\n";
	_sleep(3000);space(10);
	cout<<"门中漆黑一片,只有门外站着一位低着头披着黑袍的\"人\".\n";
	_sleep(3000);space(10);
	cout<<"守门人窃窃私语:\"贪婪的人类总是控制不住他们的欲望\"\n";
	_sleep(3000);space(10);
	cout<<"守门人窃窃私语:\"你看又有人来了\"\n";
    _sleep(3000);system("cls");
	endl(5);
	space(30);cout<<"你是...?\n";
	space(30);cin.getline(cname,300);
    system("cls");
    endl(3);space(10);
	cout<<"守门人看了看你\n"; 
	switch(a){
      case 1:h.ico=char(1);h.score=10;h.hp=40;h.dmg=2;
	    space(10);cout<<"守门人:\"哦,又一个勇士.\"\n";
		_sleep(3000);
		space(10);cout<<"守门人:\"希望你能活着回来\".\n";
	    space(10);cout<<"门上的枯枝在摆动,你觉得这个门十分罕见.\n";
		break;
      case 2:h.ico=char(38);h.hp=50;h.dmg=3;
	    space(10);cout<<"守门人:\"装备精良的骑士...\"\n";
	    _sleep(3000);
		space(10);cout<<"守门人低着头.\n";
	    space(10);cout<<"你的威名让Dead-GlassLand上的怪物们颤抖...\n";
		break;
      case 3:h.ico=char(14);h.score=20;h.hp=30;h.dmg=1;
	    space(10);cout<<"守门人:\"一个DJ?\"\n";
	    _sleep(3000);
		space(10);cout<<"守门人:\"激情并不能帮你战斗,你还需要智慧的引领...\"\n";
		space(10);cout<<"你感到门散发出一股邪样的气息\n"; 
		break;
      case 4:h.ico=char(12);h.score=75;h.hp=5;h.dmg=1;
	    space(10);cout<<"守门人:\"女人??\"\n";
	    _sleep(2000);
		space(10);cout<<"守门人:\"你就不怕暗影吞噬了你那娇小的身躯!?!\"\n";
		space(10);cout<<"用深绿枯枝做成门似乎在对你笑...\n";
		break;
      }
    endl(10);space(10);
    system("pause");
	}    

void shop(){//                         商店函数 
     cout<<"Welcome to <Dead-Glassland Shop>\n";
     cout<<"NPC:输入数字购买道具.\n";
     int shop_cost[10]={-1,5,3,8,9,0};
     cout<<"1.大剑:"<<shop_cost[1]+shop_level/4<<"$   2.红瓶:"<<shop_cost[2]<<"$   3.盾牌:"<<shop_cost[3]<<"$   ";
	 cout<<"4.双刀:"<<shop_cost[4]+shop_level/3<<"$   5.退出\n";
     bo=0;
     while(bo==0){
     ans=_getch();
     switch(ans){
       case '1':h.money-=shop_cost[1]+shop_level/4;h.dmg+=1;bo++;break;
       case '2':h.money-=shop_cost[2];h.hp+=3;bo++;break;
       case '3':h.money-=shop_cost[3];h.def+=1;bo++;break;
	   case '4':h.money-=shop_cost[4]+shop_level/3;h.dmg+=2;bo++;break;
       case '5':bo++;break;
       default:cout<<"Error\n";
       }
     }
     
     }    
void monster_fight(int kind){
     if(kind==0);
     else{
       CLS;//movie_monster(kind);
       if(kind==1){m.hp=10;m.dmg=3;m.def=0;m.m=3;m.score=5;}//Zombie
       if(kind==2){m.hp=15;m.dmg=3;m.def=1;m.m=5;m.score=5;}//devil
       if(kind==3){m.hp=50;m.dmg=3;m.def=3;m.m=1;m.score=50;}//coin_monster
       if(kind==4){m.hp=30;m.dmg=10;m.def=3;m.m=1;m.score=500;}//ghost
	   if(kind==4){m.hp=10;m.dmg=10;m.def=0;m.m=0;m.score=10;}//trap
	   while(m.hp>0){
	   	 int tem=h.dmg-m.def;
	   	 if(tem>=1)
           m.hp-=tem;
	   	 if(tem<=0 && tem>=-5)
	   	   m.hp--;
	   	 if(m.hp<=0) 
		   break;
		 tem=m.dmg-h.def;
		 if(tem>=1)
           h.hp-=tem;
	   	 if(tem<=0 && tem>=-5)
	   	   h.hp--;
         if(h.hp<=0){bodie=1;die();gameover();return;}
         }
       h.money+=m.m;
       h.score+=m.score;
       }
     }
     
void birth(int k){//注意:列数必须为5的倍数
	 if(k==1){
       for(i=1;i<=4;i++)//        生成商店 
         map[k][2][i]=char(35);//    生成商店
       map[k][1][4]='|';//           生成商店
       birth_exit(k,8,80);//        生成传送门 
       birth_coin(k,3,20);//        生成金币
       birth_coin(k,5,60);//        生成金币
       birth_coin(k,3,50);//        生成金币
       birth_life(k,8,10);//        生成爱心
       birth_life(k,2,60);//        生成爱心
       birth_sword(k,7,55);//       生成爱心
       birth_monster(k,7,40,1);//   生成怪物
       birth_monster(k,7,35,1);//   生成怪物
       birth_monster(k,6,40,1);//   生成怪物
       birth_monster(k,5,40,1);//   生成怪物
       birth_monster(k,4,40,2);//   生成怪物 
       birth_monster(k,2,10,2);//   生成怪物 
       //birth_npc(k,1,5);//          生成npc
       birth_npc(k,1,1);//          生成npc
       birth_npc(k,1,3);//          生成npc 
	   }  
     if(k==2){
	   for(i=1;i<=4;i++)//        生成商店 
         map[k][2][i]=char(35);//    生成商店
       map[k][1][4]='|';//           生成商店
       birth_exit(k,1,80);//        生成传送门 
       birth_coin(k,3,20);//        生成金币
       birth_coin(k,5,60);//        生成金币
       birth_coin(k,3,50);//        生成金币
       birth_life(k,8,10);//        生成爱心
       birth_life(k,2,60);//        生成爱心
       birth_sword(k,6,55);//       生成爱心
       birth_monster(k,8,30,1);//   生成怪物
       birth_monster(k,8,40,1);//   生成怪物
       birth_monster(k,7,35,2);//   生成怪物
       birth_monster(k,6,40,1);//   生成怪物
       birth_monster(k,5,40,1);//   生成怪物
       birth_monster(k,4,40,1);//   生成怪物 
       birth_monster(k,7,10,2);//   生成怪物 
       birth_monster(k,2,10,1);//   生成怪物 
       //birth_npc(k,1,5);//          生成npc
       birth_npc(k,1,1);//          生成npc
       birth_npc(k,1,3);//          生成npc   
	   } 
	 if(k==3){
	   birth_exit(k,8,80);
	   birth_monster(k,1,5,4);
	   birth_coin(k,1,10);
	   birth_coin(k,1,15);
	   birth_coin(k,2,5);
	   birth_monster(k,2,10,3);
	   birth_coin(k,2,15);
	   birth_coin(k,3,5);
	   birth_coin(k,3,10);
	   birth_coin(k,3,15);
	   birth_monster(k,1,70,5);
	   birth_monster(k,2,70,5);
	   birth_monster(k,2,75,4);
	   birth_monster(k,2,80,5);
	   
	   }
	 if(k==4){
	   birth_exit(k,1,80);
	   birth_monster(k,1,75,3);
	   birth_coin(k,2,80);
	   birth_coin(k,3,70);
	   birth_monster(k,2,75,3);
	   
	   }
	 if(k==5){
	   birth_exit(k,1,80);
	   
	   }
}
       
int main(){
    system("title The Heroes' Story");
    cout<<"(The Heroes' Story)[Alpha 10]\n";
    cout<<"(C) 版权所有 2016 YXH咸鱼(Isaac Romero)\n";
    cout<<"建议使用Windows XP游玩,否则将出现乱码等现象\n";
    cout<<"作者QQ:2943003\n\n";
    cout<<"WASD控制方向/选择,Enter确认\n";
    endl(17);
	system("pause");
	system("cls");
    
    memset(map,grass,sizeof(map));
    memset(bomap,0,sizeof(bomap));
    for(int k=1;k<=mapsum;k++)
	  for(i=1;i<=80;i++)
        map[k][9][i]='_';
    int p;
    do{
      p=menu_();
	  switch(p){
	    case 1:movie1();choose_hero();break;//                 随机hero
	    case 2:movie1();random_hero(random()%4+1);break;//     选择hero
	    case 3:about();break;//                       帮助&关于 
	    case 4:option();break;//                      设置 
	    case 5:exit(0);break;//                       退出 
	    }
	  CLS;
	}while(p==3 || p==4);
    system("cls");
    
	while(boexit<=mapsum && bodie==0){
      if(newmap){
	    newmap=0;
	    h.x=newmapset[boexit][1];
	    h.y=newmapset[boexit][2];
	    map[boexit][h.x][h.y]=h.ico;
	    birth(boexit);
	    }
	  monster_fight(monster_kind);
      monster_kind=0;
      for(i=1;i<=9;i++)
        for(j=1;j<=80;j++)
          cout<<map[boexit][i][j];
      cout<<"money:"<<h.money<<endl;
      cout<<"   HP:"<<h.hp<<endl;
      cout<<"  DMG:"<<h.dmg<<endl;
      cout<<"score:"<<h.score<<endl;
      cout<<"怪物:  Zombie  "<<char(20)<<endl;
      cout<<"       Devil   "<<char(15)<<endl;
      cout<<"人物:  NPC     "<<npc<<endl;
      cout<<"道具:  Coin    "<<coin<<endl;
      cout<<"       Life    "<<life<<endl;
      cout<<"       Sword   "<<sword<<endl;
  	  switch(bonpc){//                   商店npc 
        case 1:endl(2);
               bonpc=0;break;
        case 2:shop();bojump=1;bonpc=0;break;
        default:endl(4);break;
        } 
      if(bojump==1)bojump=0;
      else{
      ans=_getch();//                    移动 
      if(ans!='~')
        move(boexit,ans);
      else
        console();//控制台!?! 
      }
      system("cls");
    }
    ///////////////////////////////////
    gameover();
    return 0;}

void console(){//                    HELL-CONSOLE
    endl(25);
    cout<<"Welcome to Heeeeeeeeeeeell-Console!\n";
    cout<<"What things do you want from me?(The Devil!?!)\n";
    endl(21);
    cin.getline(pw,10);
    if(strcmp(pw,"money")==0){
      h.money+=100;return;}
    else if(strcmp(pw,"HP")==0){
      h.hp+=100;return;}
    else if(strcmp(pw,"DMG")==0){
      h.dmg+=30;return;}
    else if(strcmp(pw,"score")==0){
      h.score+=100;return;}
    else if(strcmp(pw,"BFG")==0){
      endl(25);
      cout<<"A strong and big gun...\n";
      h.dmg=32767;
      endl(12);
      system("pause");
      return;}
    else if(strcmp(pw,"ass")==0){
      endl(25);
      cout<<"Oh Oh YiJianLian"<<char(11)<<endl;
      h.hp=32767;
      endl(12);
      system("pause");
      return;}
    else if(strcmp(pw,"shit")==0){
      endl(25);
      cout<<"Em...OK,it's my shit.            (From YXH_XianYu?!?)\n"<<char(14);
      h.hp=1;
      h.dmg=1;
      h.money=1;
      h.score=32767;
      endl(12);
      system("pause");
      return;}
    }
int menu_(){
	int n=6;
	char str[n][50]={"-1",
	                 "Start Game   开始游戏   ",
	                 "Random Mode  随机模式   ",
	                 "Help & About 帮助&关于  ",
					 "Option       设置       ",
					 "Exit         退出游戏   "};
	char note[n][50]={"-1",
	                  "Let's play.",
	                  "Roooooooooogue!",
	                  "\"May I help U?\"Isaac said.",
	                  "There is something wrong.",
	                  "You're leaving Isaac."
					  };
    return (menu(n,str,note));
	}
int menu(int n,char str[][50],char note[][50]){
  //cout<<"                                                                                ";	
	
	char temp;
    int p=1;
    while(1){
      cout<<"                                                                                ";
      cout<<"     ***** * * ***   *   * *** **** *** *** *** |  ***** *** *** ****           ";
      cout<<"       *   * * *     *   * *   *  * * * *   *      *      *  * * *  *           ";
      cout<<"       *   *** ***   ***** *** ***  * * *** ***    *****  *  * * ***  | |       ";
      cout<<"       *   * * *     *   * *   * *  * * *     *        *  *  * * * *  | |       ";
      cout<<"       *   * * ***   *   * *** *  * *** *** ***    *****  *  *** *  * **|       ";
      cout<<"                                                                        |       ";
      cout<<"                                                                       **       ";
      cout<<"                                ---New Origin Immortal World's adventure.       ";
      cout<<"                                                                                ";
      for(int i=1;i<=n-1;i++){
      	
        space(15);
        if(p==i)
          cout<<"---> ";
        else
          space(5);
        cout<<str[i];
        if(p==i)
          cout<<note[i];
        cout<<endl;
        }
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"                                                                                ";
      cout<<"   (C)2016 YXH咸鱼(Isaac Romero)                    作者QQ:2258488076 2943003   ";
      cout<<"                                                                                ";
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
void about(){
    CLS;
    endl(5);
    cout<<"上:W 下:S 左:A 右:D 确认:Enter\n";
    cout<<"控制台:~\n";
    system("pause");
	}
void gameover(){
	CLS;endl(25);
    if(bodie==1)
    cout<<"                                   You Died!"<<endl;
    else{
	  if(h.score>150&&h.score<=250)
        cout<<"                                   Good Play"<<endl;
      if(h.score>250&&h.score<=300)
         cout<<"                                  !Nice Play!"<<endl;
      if(h.score>300&&h.score<=1000)
        cout<<"                                !Wonderful Play!"<<endl;
      if(h.score>1000)
        cout<<"                               Don't Cheat!My son!"<<endl;
	  }
    cout<<"                        ---Thank You For your play---"<<endl;
    cout<<"                                   "<<cname<<endl;
    cout<<"                                   Score:"<<h.score<<endl;
    //fcout();//一个失败品!!! 
    for(i=1;i<=12;i++){
    _sleep(1000);cout<<endl;}
	PAUSE;
	exit(0);
	}
void die(){
    CLS;
    for(int i=1;i<=25;i++)
      for(int j=1;j<=80;j++){
	    cout<<"-";
	    _sleep(1);
		}
	}
void option(){
    return;
	}


/*
1.添加新怪物方法:
	1.添加图标 
	2.添加怪物属性
	3.修改move函数 
	4.添加birth 
*/






