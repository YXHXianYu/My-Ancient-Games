#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int i,j,n,m;
const char grass='_',coin=char(36),devil=char(15),zombie=char(20);
const char sword=char(33),double_sword=char(19),life=char(3);
const char npc=char(2);
//grass,devil,coin,zombie,sword,life,npc

char map[9][81];int bomap[9][81];//地图 8*80(25*80)
int h1=4,h2=10,money=10,hp,dmg;//角色参数、基础值
char hero=char(1);//角色参数、基础值
char ans,pw[10];
bool bo,die=0,bonpc=0;
int monster_kind;

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
      {bomap[h1][h2]=0;hp+=3;}
    if(bomap[h1][h2]==5)//sword
      {bomap[h1][h2]=0;dmg++;}
    if(bomap[h1][h2]==6)//npc
      {bomap[h1][h2]=0;bonpc++;}
}

void endl(int n){//换行函数 
     for(i=1;i<=n;i++)
       cout<<endl;}
       
void talking_npc(){
     cout<<"NPC:Oh!You are killing me!\n";
     cout<<"    I will die!Ahhhhhhhh~~\n";
     }
     
       
void choose_hero(){
    cout<<"挑选你的角色: 1:Human   "<<char(1)<<endl;
    cout<<"              2:Fighter "<<char(38)<<endl;
    cout<<"              3:DJ      "<<char(14)<<endl;
    cout<<"              4:Angle   "<<char(12)<<endl;
    cout<<"怪物注释: 1:Zombie  "<<char(20)<<endl;
    cout<<"          2:Devil   "<<char(15)<<endl;
    cout<<"          3:NPC     "<<npc<<endl;
    cout<<"道具注释: 1:Coin    "<<coin<<endl;
    cout<<"          2:Life    "<<life<<endl;
    cout<<"          3:Sword   "<<sword<<endl;
    bo=0;
    while(bo==0){
      cin>>ans;
      switch(ans){
        case '1':hero=char(1);hp=10;dmg=2;bo++;break;
        case '2':hero=char(38);hp=15;dmg=3;bo++;break;
        case '3':hero=char(14);hp=10;dmg=1;bo++;break;
        case '4':hero=char(12);hp=5;dmg=1;bo++;break;
        default:cout<<"Error!\n";}
    }
}
void birth_coin(int x,int y){//生成金币函数 
     map[x][y]=coin;
     bomap[x][y]=1;}
     
void birth_life(int x,int y){//生成爱心函数
     map[x][y]=life;
     bomap[x][y]=4;}
     
void birth_sword(int x,int y){//生成剑函数
     map[x][y]=sword;
     bomap[x][y]=5;}
     
void birth_npc(int x,int y){//生成npc函数
     map[x][y]=npc;
     bomap[x][y]=6;}

void birth_monster(int x,int y,int z){//生成怪物函数
     if(z==1){
     map[x][y]=zombie;
     bomap[x][y]=2;}
     if(z==2){
     map[x][y]=devil;
     bomap[x][y]=3;}
     }
     
void monster_fight(int kind){
     if(kind==0);
     else{
     int mhp=0,mdmg,mm=0; 
     if(kind==1){mhp=5;mdmg=1;mm=3;}//Zombie
     if(kind==2){mhp=6;mdmg=2;mm=5;}//devil
     while(mhp>0){
       mhp-=dmg;
       hp-=mdmg;
       if(hp<=0){die=1;break;}
       }
     money+=mm;
     }
     }
     
void birth(){//注意:列数必须为5的倍数 
     birth_coin(3,20);//        生成金币
     birth_coin(5,60);//        生成金币
     birth_coin(3,50);//        生成金币
     birth_life(8,10);//        生成爱心
     birth_life(2,60);//        生成爱心
     birth_sword(7,55);//       生成爱心
     birth_monster(7,30,1);//   生成怪物
     birth_monster(7,40,1);//   生成怪物
     birth_monster(7,35,1);//   生成怪物
     birth_monster(6,40,1);//   生成怪物
     birth_monster(5,40,1);//   生成怪物
     birth_monster(4,40,1);//   生成怪物 
     birth_monster(2,10,2);//   生成怪物 
     birth_npc(1,5);//   生成npc
}
       

int main(){
    memset(map,'_',sizeof(map));
    memset(bomap,0,sizeof(bomap));
    choose_hero();//         选择hero 
    map[h1][h2]=hero;//      生成hero 
    birth();//               生成道具 
    
    while(die==0){
    endl(2);
    for(i=1;i<=8;i++)
      for(j=1;j<=80;j++)
        cout<<map[i][j]; 
    monster_fight(monster_kind);
    monster_kind=0;
    cout<<"money:"<<money<<endl;
    cout<<"   HP:"<<hp<<endl;
    cout<<"  DMG:"<<dmg<<endl;
    if(bonpc==1){
      talking_npc();
      bonpc=0;
      endl(10);
    }
    else
      endl(12);
    cin>>ans;
    move(ans);
    
    }
    endl(25);
    cout<<"                 You Died!"<<endl;
    cout<<"          ---The Game Is Over---"<<endl;
    cout<<endl;
    for(i=1;i<=25;i++){
      _sleep(1000);cout<<endl;}
    return 0;}
