#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
using namespace std;
int i,j,n,m,score=0;char cname[15]; 
const char grass='_',coin=char(36),devil=char(15),zombie=char(20);
const char sword=char(33),double_sword=char(19),life=char(3);
const char npc=char(2),exit1=char(21);
//grass,devil,coin,zombie,sword,life,npc
char map2[9][81];int bomap2[9][81];//地图1 8*80(25*80)
char map[9][81];int bomap[9][81];//地图1 8*80(25*80)
int h1=4,h2=10,money=10,hp,dmg;//角色参数、基础值
char hero=char(1);//角色参数、基础值
char ans,pw[10];//step变量 
bool bo,bodie=0,bojump=0;
int monster_kind,bonpc=0,bofscore=5,boexit=0;

void console();//控制台!?! 

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
      if(score>=fscore[i])bofscore=i;
    if(bofscore==5){
      fclose(stdin);
      fclose(stdout);
      return;}
    for(i=4;i>=bofscore+1;i--){
      fscore[i]=fscore[i-1];
      strcpy(fcname[i],fcname[i-1]);}
    fscore[bofscore]=score;
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

void move(char t){//                   移动函数 
    if((t=='a')&&(h2!=5))
      {map[h1][h2]=grass;h2-=5;map[h1][h2]=hero;}
    if((t=='d')&&(h2!=80))
      {map[h1][h2]=grass;h2+=5;map[h1][h2]=hero;}
    if((t=='w')&&(h1!=1))
      {map[h1][h2]=grass;h1-=1;map[h1][h2]=hero;}
    if((t=='s')&&(h1!=8))
      {map[h1][h2]=grass;h1+=1;map[h1][h2]=hero;}
    if(bomap[h1][h2]==1)//coin 
      {bomap[h1][h2]=0;money++;}
    if(bomap[h1][h2]==2)//zombie
      {bomap[h1][h2]=0;monster_kind=1;}
    if(bomap[h1][h2]==3)//devil
      {bomap[h1][h2]=0;monster_kind=2;}
    if(bomap[h1][h2]==4)//life
      {bomap[h1][h2]=0;hp+=3;score+=3;}
    if(bomap[h1][h2]==5)//sword
      {bomap[h1][h2]=0;dmg++;score+=5;}
    if(h1==1 && h2==5)//Shop  注意这里的先后顺序 
      {bomap[h1][h2]=0;bonpc=2;}
    if(bomap[h1][h2]==6)//npc 注意这里的先后顺序
      {bomap[h1][h2]=0;bonpc=1;score+=5;}
    if(bomap[h1][h2]==100)//exit
      {bomap[h1][h2]=0;boexit=1;score+=100;}
}
void move2(char t){//                   移动函数 
    if((t=='a')&&(h2!=5))
      {map2[h1][h2]=grass;h2-=5;map2[h1][h2]=hero;}
    if((t=='d')&&(h2!=80))
      {map2[h1][h2]=grass;h2+=5;map2[h1][h2]=hero;}
    if((t=='w')&&(h1!=1))
      {map2[h1][h2]=grass;h1-=1;map2[h1][h2]=hero;}
    if((t=='s')&&(h1!=8))
      {map2[h1][h2]=grass;h1+=1;map2[h1][h2]=hero;}
    if(bomap2[h1][h2]==1)//coin 
      {bomap2[h1][h2]=0;money++;}
    if(bomap2[h1][h2]==2)//zombie
      {bomap2[h1][h2]=0;monster_kind=1;}
    if(bomap2[h1][h2]==3)//devil
      {bomap2[h1][h2]=0;monster_kind=2;}
    if(bomap2[h1][h2]==4)//life
      {bomap2[h1][h2]=0;hp+=3;score+=3;}
    if(bomap2[h1][h2]==5)//sword
      {bomap2[h1][h2]=0;dmg++;score+=5;}
    if(h1==1 && h2==5)//Shop  注意这里的先后顺序 
      {bomap2[h1][h2]=0;bonpc=2;}
    if(bomap2[h1][h2]==6)//npc 注意这里的先后顺序
      {bomap2[h1][h2]=0;bonpc=1;score+=5;}
    if(bomap2[h1][h2]==100)//exit
      {bomap2[h1][h2]=0;boexit=2;score+=100;}
    
}

void endl(int n){//                    换行函数 
     for(i=1;i<=n;i++)
       cout<<endl;}
       
void talking_npc(){//                  npc
     cout<<"NPC:Oh!You are killing me!\n";
     cout<<"    I will die!Ahhhhhhhh~~\n";
     money-=5;
     }
     
       
void choose_hero(){
    cout<<"你要折磨哪个角色? 1:Human   "<<char(1)<<endl;
    cout<<"                  2:Fighter "<<char(38)<<endl;
    cout<<"                  3:DJ      "<<char(14)<<endl;
    cout<<"                  4:Mercy   "<<char(12)<<endl;
    cout<<"怪物脸谱:   1:Zombie  "<<char(20)<<endl;
    cout<<"            2:Devil   "<<char(15)<<endl;
    cout<<"人物脸谱:   1:NPC     "<<npc<<endl;
    cout<<"道具脸谱!?: 1:Coin    "<<coin<<endl;
    cout<<"            2:Life    "<<life<<endl;
    cout<<"            3:Sword   "<<sword<<endl;
    cout<<"传送门:"<<exit1<<endl;
    endl(12);
    bo=0;
    while(bo==0){
      ans=_getch();
      switch(ans){
        case '1':hero=char(1);score+=10;hp=40;dmg=2;bo++;break;
        case '2':hero=char(38);hp=50;dmg=3;bo++;break;
        case '3':hero=char(14);score+=20;hp=30;dmg=1;bo++;break;
        case '4':hero=char(12);score+=50;hp=10;dmg=1;bo++;break;
        default:cout<<"Error!\n";}
    }
}
void birth_coin(int x,int y,int cm){//        生成金币函数:1
     if(cm==1){map[x][y]=coin;bomap[x][y]=1;}
     if(cm==2){map2[x][y]=coin;bomap2[x][y]=1;}
     }
     
void birth_life(int x,int y,int cm){//        生成爱心函数:4
     if(cm==1){map[x][y]=life;bomap[x][y]=4;}
     if(cm==2){map2[x][y]=life;bomap2[x][y]=4;}
     }
     
void birth_sword(int x,int y,int cm){//       生成剑函数:5
     if(cm==1){map[x][y]=sword;bomap[x][y]=5;}
     if(cm==2){map2[x][y]=sword;bomap2[x][y]=5;}
     }
     
void birth_npc(int x,int y,int cm){//         生成npc函数:6
     if(cm==1){map[x][y]=npc;bomap[x][y]=6;}
     if(cm==2){map2[x][y]=npc;bomap2[x][y]=6;}
     }
     
void birth_exit(int x,int y,int cm){//         生成传送门:100
     if(cm==1){map[x][y]=exit1;bomap[x][y]=100;}
     if(cm==2){map2[x][y]=exit1;bomap2[x][y]=100;}
     }

void birth_monster(int x,int y,int z,int cm){//生成怪物函数
   if(cm==1){
     if(z==1){
     map[x][y]=zombie;//              zombie:2
     bomap[x][y]=2;}
     if(z==2){
     map[x][y]=devil;//               devil:3
     bomap[x][y]=3;}
     }
   if(cm==2){
     if(z==1){
     map2[x][y]=zombie;//              zombie:2
     bomap2[x][y]=2;}
     if(z==2){
     map2[x][y]=devil;//               devil:3
     bomap2[x][y]=3;}
     }
   }
     
void shop(){//                         商店函数 
     endl(1);
     cout<<"Welcome to <Dead-Glassland Shop>\n";
     endl(1);
     cout<<"NPC:输入数字购买道具.\n";
     cout<<"1.Sword:5$   2.Life:3$   3.Double_Sword=9$   4.Exit.\n";
     endl(5);
     
     bo=0;
     while(bo==0){
     ans=_getch();
     switch(ans){
       case '1':money-=5;dmg++;score-=2;bo++;break;
       case '2':money-=3;hp+=3;bo++;break;
       case '3':money-=9;dmg+=2;score-=5;bo++;break;
       case '4':bo++;break;
       default:cout<<"Error\n";
       }
     }
     
     }
     
void monster_fight(int kind){
     if(kind==0);
     else{
     int mhp=0,mdmg,mm=0; 
     if(kind==1){mhp=10;mdmg=1;mm=3;}//Zombie
     if(kind==2){mhp=15;mdmg=2;mm=5;}//devil
     while(mhp>0){
       mhp-=dmg;
       hp-=mdmg;
       score--;
       if(hp<=0){bodie=1;score-=5;break;}
       }
     money+=mm;
     score+=10;
     }
     }
     
void birth1(){//注意:列数必须为5的倍数
     for(i=1;i<=4;i++)//        生成商店 
       map[2][i]=char(35);//    生成商店
     map[1][4]='|';//           生成商店
     birth_exit(8,80,1);//        生成传送门 
     birth_coin(3,20,1);//        生成金币
     birth_coin(5,60,1);//        生成金币
     birth_coin(3,50,1);//        生成金币
     birth_life(8,10,1);//        生成爱心
     birth_life(2,60,1);//        生成爱心
     birth_sword(7,55,1);//       生成爱心
     birth_monster(7,30,1,1);//   生成怪物
     birth_monster(7,40,1,1);//   生成怪物
     birth_monster(7,35,1,1);//   生成怪物
     birth_monster(6,40,1,1);//   生成怪物
     birth_monster(5,40,1,1);//   生成怪物
     birth_monster(4,40,2,1);//   生成怪物 
     birth_monster(2,10,2,1);//   生成怪物 
     //birth_npc(1,5,1);//          生成npc
     birth_npc(1,1,1);//          生成npc
     birth_npc(1,3,1);//          生成npc    
}

void birth2(){//注意:列数必须为5的倍数
     for(i=1;i<=4;i++)//        生成商店 
       map2[2][i]=char(35);//    生成商店
     map2[1][4]='|';//           生成商店
     birth_exit(1,80,2);//        生成传送门 
     birth_coin(3,20,2);//        生成金币
     birth_coin(5,60,2);//        生成金币
     birth_coin(3,50,2);//        生成金币
     birth_life(8,10,2);//        生成爱心
     birth_life(2,60,2);//        生成爱心
     birth_sword(6,55,2);//       生成爱心
     birth_sword(7,55,2);//       生成爱心
     birth_monster(8,30,1,2);//   生成怪物
     birth_monster(8,40,1,2);//   生成怪物
     birth_monster(7,35,2,2);//   生成怪物
     birth_monster(6,40,1,2);//   生成怪物
     birth_monster(5,40,1,2);//   生成怪物
     birth_monster(4,40,1,2);//   生成怪物 
     birth_monster(7,10,2,2);//   生成怪物 
     birth_monster(2,10,1,2);//   生成怪物 
     //birth_npc(1,5,2);//          生成npc
     birth_npc(1,1,2);//          生成npc
     birth_npc(1,3,2);//          生成npc    
}
       

int main(){
    system("title The Heroes' Story");
    cout<<"<The Heroes' Story>[Alpha 7]\n";
    cout<<"<C> 版权所有 2016-2020 YXH_XianYu\n";
    cout<<"建议使用Windows XP游玩，否则将出现乱码等现象\n";
    cout<<"作者QQ:2943003\n\n";
    cout<<"WASD控制方向,Enter确认\n";
    endl(1);
    cout<<"Enter your name.\n";
    cin.getline(cname,15);
    endl(25);
    memset(map,grass,sizeof(map));
    memset(bomap,0,sizeof(bomap));
    choose_hero();//                   选择hero 
    map[h1][h2]=hero;//                生成hero 
    birth1();//                         生成道具,场景 
    while(boexit==0 && bodie==0){
    endl(2);
    for(i=1;i<=8;i++)
      for(j=1;j<=80;j++)
        cout<<map[i][j]; 
    monster_fight(monster_kind);
    monster_kind=0;
    cout<<"money:"<<money<<endl;
    cout<<"   HP:"<<hp<<endl;
    cout<<"  DMG:"<<dmg<<endl;
    cout<<"score:"<<score<<endl;
    switch(bonpc){//                   商店npc 
      case 1:endl(2);talking_npc();
             bonpc=0;endl(7);break;
      case 2:shop();bojump=1;bonpc=0;break;
      default:endl(11);break;
      } 
    if(bojump==1)bojump=0;
    else{
    ans=_getch();
    if(ans!='t')
      move(ans);
    else
      console();//控制台!?! 
    }
    }
    ///////////////////////////////////
    if(boexit==1){
    memset(map2,grass,sizeof(map2));
    memset(bomap2,0,sizeof(bomap2));
    h1=8;h2=5;
    map2[h1][h2]=hero;//生成hero 
    birth2();//生成道具,场景
    }
    while(boexit==1 && bodie==0){
    endl(2);
    for(i=1;i<=8;i++)
      for(j=1;j<=80;j++)
        cout<<map2[i][j];
    monster_fight(monster_kind);
    monster_kind=0;
    cout<<"money:"<<money<<endl;
    cout<<"   HP:"<<hp<<endl;
    cout<<"  DMG:"<<dmg<<endl;
    cout<<"score:"<<score<<endl;
    switch(bonpc){//                   商店npc 
      case 1:endl(2);talking_npc();
             bonpc=0;endl(7);break;
      case 2:shop();bojump=1;bonpc=0;break;
      default:endl(11);break;
      } 
    if(bojump==1)bojump=0;
    else{
    ans=_getch();
    if(ans!='t')
      move2(ans);
    else
      console();//控制台!?! 
    }
    }
    ///////////////////////////////////
    endl(25);
    if(bodie==1)
    cout<<"                                   You Died!"<<endl;
    if(score>150&&bodie==0&&score<=250)
    cout<<"                                   Good Play"<<endl;
    if(score>250&&bodie==0&&score<=300)
    cout<<"                                  !Nice Play!"<<endl;
    if(score>300&&bodie==0&&score<=1000)
    cout<<"                                !Wonderful Play!"<<endl;
    if(score>1000&&bodie==0)
    cout<<"                               Don't Cheat!My son!"<<endl;
    cout<<"                        ---Thank You For your play---"<<endl;
    cout<<"                                   "<<cname<<endl;
    cout<<"                                   Score:"<<score<<endl;
    //fcout();//一个失败品!!! 
    for(i=1;i<=12;i++){
      _sleep(1000);cout<<endl;}
    _sleep(5000);
    return 0;}

void console(){//HELL-CONSOLE
    endl(25);
    cout<<"Welcome to Heeeeeeeeeeeell-Console!\n";
    cout<<"What things do you want from me?(The Devil!?!)\n";
    endl(21);
    cin.getline(pw,10);
    if(strcmp(pw,"money")==0){
      money+=100;return;}
    else if(strcmp(pw,"HP")==0){
      hp+=100;return;}
    else if(strcmp(pw,"DMG")==0){
      dmg+=30;return;}
    else if(strcmp(pw,"score")==0){
      score+=100;return;}
    else if(strcmp(pw,"BFG")==0){
      endl(25);
      cout<<"A strong and big gun...\n";
      dmg=32767;
      endl(12);
      system("pause");
      return;}
    else if(strcmp(pw,"ass")==0){
      endl(25);
      cout<<"Oh Oh YiJianLian"<<char(11)<<endl;
      hp=32767;
      endl(12);
      system("pause");
      return;}
    else if(strcmp(pw,"shit")==0){
      endl(25);
      cout<<"Em...OK,it's my shit.            (From YXH_XianYu?!?)\n"<<char(14);
      hp=1;
      dmg=1;
      money=1;
      score=32767;
      endl(12);
      system("pause");
      return;}
    }
