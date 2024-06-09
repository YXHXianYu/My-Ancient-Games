#include<algorithm>
#include<windows.h>
#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
#define PAUSE system("pause")                         //暂停 
#define CLS system("cls")                             //清屏 
#define COLOR_Basic system("color f5")                //初始化颜色
#define TITLE_Basic system("title 凯撒传说                                                                                  by.YXH咸鱼") 
#define MODE_Basic system("mode con cols=80 lines=25")//初始化界面 1行80个字符 1列25个字符 
#define MODE_Up system("mode con cols=157 lines=36"); //初始化界面 1行80个字符 1列36个字符 
#define FIGHT_Basic Fight_ChuShiHua(1)                //初始化战斗系统
#define FIGHT_Up Fight_ChuShiHua(2)                   //初始化战斗系统
#define D20 Random(1,20)
#define Show_Picture(x) system(x)
#define LEFT  'a'
#define RIGHT 'd'
#define UP    'w'
#define DOWN  's'

struct keyboard{
	char Left,
		 Right,
		 Up,
		 Down,
		 One,
		 Two,
		 Three,
		 Four,
		 Five,
		 Spe_Up,
		 Spe_Down,
		 Spe_Left,
		 Spe_Right;
}kb; 
void Key_Board_Basic(){
	kb.Up        = 'w' ;
	kb.Down      = 's' ;
	kb.Left      = 'a' ;
	kb.Right     = 'd' ;
	
	kb.One       = '1' ;
	kb.Two       = '2' ;
	kb.Three     = '3' ;
	kb.Four      = '4' ;
	kb.Five      = '5' ;
	
	kb.Spe_Up    =  72 ;
	kb.Spe_Down  =  80 ;
	kb.Spe_Left  =  75 ;
	kb.Spe_Right =  77 ;
	}
struct player{
	int money,
		hp,
		hp_max,
		sp,
		sp_max,
		ac,
		dmg,
		speed,
		food,
		wood,
		gold,
		stone;
	bool skill[101];
	int	skill_sum,
		level,
		exp;
	char name[20];
	int name_len;
	int Kind;       //注意为大写"K" 为了和"kind"区别 
}Hero;

struct monster{
	int money,
		hp,
		ac,
		dmg,
		speed;
	char name[100];
};

bool have_demo=0;//

void Play();                    //开始游戏 

void end(int n);                //换行 
void space(int n);              //空格
void check();                   //检查函数
void Loading();                 //加载界面 
int Random(int low,int high);   //随机函数
int Change_a_little(int n);     //属性调整值[3r] 
void Skill();                   //技能 
void Fight(int kind);           //战斗 
void Check_Body(monster m);

void Fight_ChuShiHua(int kind); //战斗初始化 
void CG(int n,int a);           //单独CG 
void Demo();                    //Demo停止 
void Input_Name();              //输入名字 
void Output_Name();             //输出名字 
void Hide_Cur();                //隐藏光标 

void Menu();                    //菜单
void Map();                     //查看地图 
void Maker_List();              //制作者名单 

void CG_1();                    //第一章CG 
void CG_1_Maze();               //第一章Maze
void CG_2();                    //第二章CG 
void CG_2_Maze();               //第二章Maze

int main(){
	
	COLOR_Basic;
	TITLE_Basic;
	MODE_Basic;
	Hide_Cur();
	have_demo=1;
	Menu();
	PAUSE;
	
	return 0;
	}

void Play(){
	
	FIGHT_Basic;
	CG_1();
	if(have_demo){
		Demo();
		return;
		}
	FIGHT_Up;
	MODE_Up;
	CG_2();
	CG_2_Maze();
	MODE_Basic;
	
	}

void end(int n){
	for(int i=1;i<=n;i++)
		cout<<endl;
	}

void space(int n){
	for(int i=1;i<=n;i++)
		cout<<" ";
	}

void check(string a,string b){
	CLS;
	cout<<" 程序出现bug!!!\n(你似乎听见了作者的哀嚎)\n";
	cout<<" 请立即向作者汇报\n";
	cout<<" 错误代码:\" "<<a<<" "<<b<<" \"\n";
	PAUSE;
	}

void Loading(){
	CLS;
	end(13);
	space(15);
	for(int i=1;i<=50;i++){
		cout<<"#";
		Sleep(5);
		}
	}

int Random(int low,int high){
	srand(time(NULL));
	int t=rand()%(high-low)+low;
	return t;
	}

int Change_a_little(int n){
	return n/2-5;
	}

inline void Skill(monster * m,bool * if_out,int kind){
	char in;
	while(in != '1' && in != '2' && in!='3' && in!='4'){
		CLS;
		end(1);
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//

		
		for(int i=1;i<=25;i++){
			cout<<"-    *";	
			space(65);
			switch(i){
				case 1:{
					cout<<"1.旋风斩";
					space(7);
					break;
					}
				
				case 2:{
					cout<<"2.四方斩";
					space(7);
					break;
					}
				case 3:{
					cout<<"3.集气";
					space(9);
					break;
					}
				case 4:{
					cout<<"4.取消";
					space(9);
					break;
					}
				default:{
					space(15);
					break;
					};
				}
			space(63);
			cout<<"*    -"<<endl;//
			}
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		in=_getch();
		switch(in){
				case '1':{
					if(Hero.sp<=0){
						CG(21,0);
						break;
						}
					Hero.sp--;
					int hurts=Hero.dmg*5+Random(10,20);
					m -> hp -= hurts;
					return;
					}
				case '2':{
					if(Hero.Kind==1){
						CG(20,0); 
						} 
					if(Hero.sp<=2){
						CG(21,0);
						break;
						}
					Hero.sp-=3;
					int hurts=Hero.dmg*5+Random(10,20);
					CG(12,hurts);
					m -> hp -= hurts;
					return;
					}
				case '3':{
					Hero.sp+=1;
					CG(1,0);
					return;
					}
				case '4':{
					*if_out=true;
					return;
					}
				}
		}
	}

void Skill_Basic(monster * m,bool * if_out){
	char in;
	while(in != '1' && in != '2'){
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		
		for(int i=1;i<=12;i++){
			cout<<"-   *";	
			space(27);
			switch(i){
				case 1:{
					cout<<"1.旋风斩";
					space(7);
					break;
					}
				case 2:{
					cout<<"2.取消";
					space(9);
					break;
					}
				default:{
					space(15);
					break;
					};
				}
			space(27);
			cout<<"*   -"<<endl;//
			}
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		in=_getch();
		switch(in){
				case '1':{
					if(Hero.sp<=0){
						CG(3,0);
						break;
						}
					Hero.sp--;
					int hurts=Hero.dmg*5+Random(10,20);
					CG(12,hurts);
					m -> hp -= hurts;
					return;
					}
				case '2':{
					*if_out=true;
					return;
					}
				}
		}
	}

inline void Fight(int kind){
	monster m;
	if(kind==1){//Skeleton Fighter
		m.ac=5;
		m.dmg=5;
		m.speed=1;
		m.hp=50;
		}
	if(kind==2){//Elf Hunter
		m.ac=0;
		m.dmg=10;
		m.speed=3;
		m.hp=30;
		}
	if(kind==3){//Slime
		m.ac=5;
		m.dmg=6;
		m.speed=3;
		m.hp=130;
		}
	char in;
	do{
		//Fight
		if(kind==1){//Skeleton Fighter
			CLS;
			end(1);
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                       *** ^                 -"<<endl;//
			cout<<"-                                                       *** |                 -"<<endl;//
			cout<<"-               ***                                 __   *  |                 -"<<endl;//
			cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
			cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
			cout<<"-                *  /                               \\/  ***                   -"<<endl;//
			cout<<"-               **-+-                                   * *                   -"<<endl;//
			cout<<"-                **                                     * *                   -"<<endl;//
			cout<<"-                *                                                            -"<<endl;//
			cout<<"-               * *                                                           -"<<endl;//
			cout<<"-              *  *                                                           -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *    1.攻击    2.防御    HP:"<<Hero.hp<<"\t                                  *   -"<<endl;//
			cout<<"-   *    3.技能              SP:"<<Hero.sp<<"\t                                  *   -"<<endl;// 
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			}
		if(kind==2){//Elf Hunter
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
			cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
			cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
			cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
			cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
			cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
			cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
			cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
			cout<<"-                             ***    *   /                                                             | *****                                             -"<<endl;//
			cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
			cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
			cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
			cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
			cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
			cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
			cout<<"-                           *     *                                                                        *                                               -"<<endl;//
			cout<<"-                          *      *                                                                        *                                               -"<<endl;//
			cout<<"-                         *       *                                                                                                                        -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *    1.攻击\t2.防御\t\tHP:"<<Hero.hp<<"\tElf Hunter HP:"<<m.hp<<"                                                                                    *     -"<<endl;//
			cout<<"-    *    3.技能\t4.状态\t\tSP:"<<Hero.sp<<"                                                                                                         *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			}
		if(kind==3){//Slime
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
			cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
			cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
			cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
			cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
			cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
			cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
			cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
			cout<<"-                             ***    *   /                                                             | *****                                             -"<<endl;//
			cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
			cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
			cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
			cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
			cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
			cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
			cout<<"-                           *     *                                                                        *                                               -"<<endl;//
			cout<<"-                          *      *                                                                        *                                               -"<<endl;//
			cout<<"-                         *       *                                                                                                                        -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *    1.攻击\t2.防御\t\tHP:"<<Hero.hp<<"\tSlime HP:"<<m.hp<<"                                                                                    *     -"<<endl;//
			cout<<"-    *    3.技能\t4.状态\t\tSP:"<<Hero.sp<<"                                                                                                         *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			
			}
		in=_getch();
		int luck;
		if(kind==1 || kind==3)
			luck=D20;
		else
			luck=Random(11,20);
		int hurts;
		switch(in){
			case '1':{
				if(luck>18 && luck<=20){
					hurts=Change_a_little(Random(9,14))+Hero.dmg;
					if(hurts<0) hurts=0;
					if(kind==1)
						CG(4,hurts*2);
					if(kind==2)
						CG(18,hurts*2);
					m.hp-=hurts*2;
					}
				if(luck>10 && luck<=18){
					hurts=Change_a_little(Random(9,14))+Hero.dmg;
					if(hurts<0) hurts=0;
					if(kind==1)
						CG(8,hurts);
					if(kind==2)
						CG(17,hurts);
					m.hp-=hurts;
					}
				if(luck<=10 && luck>=0){
					hurts=Change_a_little(Random(9,14))+Hero.dmg-m.ac;
					if(hurts<0) hurts=0;
					if(kind==1)
						CG(9,hurts);
					m.hp-=hurts;
					}
				if(luck>20 || luck<0){
					check("0001","0001");
					cout<<luck<<endl;
					PAUSE;
					}
				if(m.hp<=0)
					break;
				hurts=Change_a_little(Random(9,14))+m.dmg;
				if(hurts<0) hurts=0;
				if(kind==1)
					CG(7,hurts);
				if(kind==2)
					CG(20,hurts);
				Hero.hp-=hurts;
				break;
				}
			case '2':{
				if(kind==2){
					CG(19,0);
					break;
					}
				int hurts=Change_a_little(Random(9,14))-Hero.ac+m.dmg;
				if(hurts<0) hurts=0;
				if(kind==1)
					CG(5,hurts);
				Hero.hp-=hurts;
				Hero.sp++;
				break;
				}
			case '3':{
				bool if_out=0;
				if(Hero.skill_sum==0)
					CG(3,0);
				else{
					if(kind==1)
						Skill_Basic(&m,&if_out);
					else
						Skill(&m,&if_out,kind);
					}
				if(m.hp<=0)
					break;
				if(if_out)
					break;
				hurts=Change_a_little(Random(9,14))+m.dmg;
				if(hurts<0) hurts=0;
				if(kind==1)
					CG(7,hurts);
				if(kind==2)
					CG(20,hurts);
				Hero.hp-=hurts;
				break;
				}
			case '4':{
				if(kind==1)
					break;
				Check_Body(m);
				break;
				}
			case '5':{
				break;
				}
			}
		if(m.hp<=0){
			CG(0,0);
			Hero.exp++;
			Hero.hp=Hero.hp_max;
			Hero.sp=Hero.sp_max;
			
			return;
			}
		if(Hero.hp<=0){
			return;
			}
	}while(1);
	
	}

void Check_Body(monster m){
	CLS;
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                              你的血量      : "<<Hero.hp<<"/"<<Hero.hp_max<<endl;//
	cout<<"                                                              你的体力      : "<<Hero.sp<<"/"<<Hero.sp_max<<endl;//
	cout<<"                                                              你的攻击力    : "<<Hero.dmg<<endl;//
	cout<<"                                                              你的防御力    : "<<Hero.ac<<endl;//
	cout<<"                                                              你的速度      : "<<Hero.speed<<endl;//
	cout<<"                                                              你的等级      : "<<Hero.level<<endl;//
	cout<<"                                                              你的经验值    : "<<Hero.exp<<endl;//
	end(1);
	end(1);
	cout<<"                                                              怪物的血量    : "<<m.hp<<endl;//
	cout<<"                                                              怪物的体力    : "<<0<<endl;//
	cout<<"                                                              怪物的攻击力  : "<<m.dmg<<endl;//
	cout<<"                                                              怪物的防御力  : "<<m.ac<<endl;//
	end(14);
	PAUSE;
	}

inline void Menu(){
	int p=1,max_p=8;
	char ch=0;
	while(1){
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                 __                          -"<<endl;//
		cout<<"-                                                |  |                         -"<<endl;//
		cout<<"-                 *******************************|  |                         -"<<endl;//
		cout<<"-               **                               |  |_______#                 -"<<endl;//
		cout<<"-             **        -------------------------|   _______##                -"<<endl;// 
		cout<<"-               **                               |  |       #                 -"<<endl;//
		cout<<"-                 *******************************|  |                         -"<<endl;//
		cout<<"-                                                |__|                         -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		
		for(int i=1;i<=8;i++){
			cout<<"-";
			space(27);
			if(p==i)
				cout<<"->   ";
			else
				cout<<"     ";
			switch (i){
				case 1:
					cout<<" 开始游戏";
					space(7); 
					break;
				case 2:
					cout<<" 观看地图/世界观";
					//space(0);
					break;
				case 3:
					cout<<" 退出游戏";
					space(7);
					break;
				case 4:
					cout<<" 制作组名单";
					space(5);
					break;
				case 7:
					cout<<" 程序员测试选项";
					space(1);
					break;
				case 8:
					cout<<" 程序员测试选项";
					space(1);
					break;
				default:
					space(16);
					break;
				}
			space(29);
			cout<<"-";
			cout<<endl;
			}
		
		cout<<"-                                                                             -"<<endl;// 
		cout<<"-                                                                             -"<<endl;//
		cout<<"-  W S ↑↓Enter 进行操控                              制作组:MS Game Studio  -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		ch=_getch();
		if( (ch=='w' || ch==72)&&(p>=2) )
			p--;
		if( (ch=='s' || ch==80)&&(p<=max_p-1) )
			p++;
		if( ch=='\r' ){
			switch(p){
				case 1:
					Play();
					break;
				case 2:
					Map();
					break;
				case 3:
					return; 
					break;
				case 4:
					CLS;
					Maker_List();
					break;
				case 7:
					while(1){
						cout<<Random(11,20)<<endl;
						}
					break;
				case 8:
					FIGHT_Up;
					MODE_Up;
					CG_2_Maze();
					MODE_Basic;
				default:
					break;
				}
			}
		}
	
	PAUSE;
	}

void Map(){
	//Map
	CLS;
	end(1);
	cout<<"-------------------------------------------------------------------------------"<<endl;// 
	cout<<"-                                       *                                     -"<<endl;//[phiya]是[凯撒帝国]的首都，是整个国家的核心。
	cout<<"-  <咸鱼の王的故事> 凯撒大陆地图       *                                      -"<<endl;//
	cout<<"-                                    **                                       -"<<endl;//[Godigun]是一座要塞，城墙无比的坚固。
	cout<<"-    ~                          *****                                         -"<<endl;//公元前168年的[圣战]，<恶魔>入侵大陆，[Godigun]是人类最后的防线， 
	cout<<"-        ~             ~   *****                                              -"<<endl;//之后在< Ken.Caesar>的领导下，人们以[Godigun]为阵地，成功击退<恶魔>。 
	cout<<"-   ~            ~        *     #Godigun       @Phiya                         -"<<endl;//
	cout<<"-            ~           *                                                    -"<<endl;//[Sealidge]是[凯撒帝国]最为繁荣的城市。 
	cout<<"-        *               *                                                    -"<<endl;//海洋带给这座城市极大的财富， 
	cout<<"-  ~  * *         ~      ********   #Sealidge          / / / / /              -"<<endl;//但时不时这座城市也会受到海浪和<恶魔>的攻击。
	cout<<"-      ***      ~        *   ~   *                / / / / / / / /             -"<<endl;//
	cout<<"-       * *     ~       * ~    ~  *            / / / / / / / / / /            -"<<endl;//[Me City]在[圣战]前是整个大陆最大的城市， 
	cout<<"-      *                 ~    ~ ~ *           / / / / / / / / / / /           -"<<endl;//但在[圣战]中损失惨重，现在只剩下残垣断壁。 
	cout<<"-  ~          ~      ~            *            / / / / / / / / / /            -"<<endl;//经过修复，在Me City外围还有一些村落 
	cout<<"-      ~~         ~      *  ~  ~  *             / / / / / / / /               -"<<endl;//
	cout<<"-   ~                    ***     *                       / /                  -"<<endl;//[Wild City]正如其名，是[凯撒大陆]中最混乱的地方。 
	cout<<"-        ~     ~         * ******                         /   #Wild City      -"<<endl;//无数势力在此崛起，连<帝国近卫军>都无法约束它。 
	cout<<"-                   ~     *     #Me City                                      -"<<endl;//
	cout<<"-  @ 首都       ~          **                                                 -"<<endl;//[Ken City]是[圣战]大将<Ken.Caesar>的故乡。 
	cout<<"-  # 城市    ~        ~      ******              #Ken City                    -"<<endl;//
	cout<<"-  ~ 海           ~      ~         *                                          -"<<endl;//
	cout<<"-  / 沙漠   ~                        *                                         -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Map
	CLS;
	end(1);
	cout<<"-------------------------------------------------------------------------------"<<endl;// 
	cout<<"-                                       *                                     -"<<endl;//
	cout<<"-  <咸鱼の王的故事> 凯撒大陆地图       *          [phiya]是[凯撒帝国]的首都， -"<<endl;//
	cout<<"-                                    **                  是整个国家的核心。   -"<<endl;//
	cout<<"- [Godigun]是一座要塞，         *****                                         -"<<endl;// 
	cout<<"- 城墙无比的坚固。公元     *****                                              -"<<endl;// 
	cout<<"- 前168年的[圣战]，<恶魔> *     #Godigun       @Phiya                         -"<<endl;//
	cout<<"- 入侵大陆，[Godigun] 是 *                                                    -"<<endl;// 
	cout<<"- 人类最后的防线，之后在 *                     [Sealidge]是[凯撒帝国]最为繁荣 -"<<endl;// 
	cout<<"- <Ken.Caesar>的领导下， ********   #Sealidge  的城市。海洋带给这座城市极大的 -"<<endl;//
	cout<<"- 人们以[Godigun]为阵地，*       *             财富，但时不时这座城市也会受到 -"<<endl;//
	cout<<"- 成功击退<恶魔>。      *         *            海浪和<恶魔>的攻击。           -"<<endl;// 
	cout<<"-                                 *                                           -"<<endl;//
	cout<<"- [Me City]在[圣战]前是           *   [Wild City]正如其名，                   -"<<endl;//
	cout<<"- 整个大陆最大的城市，   *        *   是[凯撒大陆]中最混乱的地方。            -"<<endl;//
	cout<<"- 但在[圣战]中损失惨重， ***     *                                            -"<<endl;// 
	cout<<"- 现在只剩下残垣断壁。   * ******                             #Wild City      -"<<endl;//无数势力在此崛起，连<帝国近卫军>都无法约束它。 
	cout<<"-                         *     #Me City                                      -"<<endl;//
	cout<<"-  @ 首都                  **                                                 -"<<endl;// 
	cout<<"-  # 城市                    ******              #Ken City                    -"<<endl;//
	cout<<"-  ~ 海                            *     [Ken City]是[圣战]大将               -"<<endl;//
	cout<<"-  / 沙漠                           *        <Ken.Caesar>的故乡。             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	if(0){
		//Big_Map
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//1
		cout<<"-                                                                                                                                                          -"<<endl;//2
		cout<<"-                                                                                                                                                          -"<<endl;//3
		cout<<"-                                                                                                                                                          -"<<endl;//4
		cout<<"-                                                                                                                                                          -"<<endl;//5
		cout<<"-                                                                                                                                                          -"<<endl;//6
		cout<<"-                                                                                                                                                          -"<<endl;//7
		cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;// 
		cout<<"-                                      -                                       *                                     -                                     -"<<endl;//
		cout<<"-                                      -  <咸鱼の王的故事> 凯撒大陆地图       *                                      -                                     -"<<endl;//
		cout<<"-                                      -                                    **                                       -                                     -"<<endl;//
		cout<<"-                                      -    ~                          *****                                         -                                     -"<<endl;//
		cout<<"-                                      -        ~             ~   *****                                              -                                     -"<<endl;// 
		cout<<"-                                      -   ~            ~        *     #Godigun       @Phiya                         -                                     -"<<endl;//
		cout<<"-                                      -            ~           *                                                    -                                     -"<<endl;//
		cout<<"-                                      -        *               *                                                    -                                     -"<<endl;//
		cout<<"-                                      -  ~  * *         ~      ********   #Sealidge          / / / / /              -                                     -"<<endl;//
		cout<<"-                                      -      ***      ~        *   ~   *                / / / / / / / /             -                                     -"<<endl;//
		cout<<"-                                      -       * *     ~       * ~    ~  *            / / / / / / / / / /            -                                     -"<<endl;//
		cout<<"-                                      -      *                 ~    ~ ~ *           / / / / / / / / / / /           -                                     -"<<endl;//
		cout<<"-                                      -  ~          ~      ~            *            / / / / / / / / / /            -                                     -"<<endl;//
		cout<<"-                                      -      ~~         ~      *  ~  ~  *             / / / / / / / /               -                                     -"<<endl;//
		cout<<"-                                      -   ~                    ***     *                       / /                  -                                     -"<<endl;//
		cout<<"-                                      -        ~     ~         * ******                         /   #Wild City      -                                     -"<<endl;//
		cout<<"-                                      -                   ~     *     #Me City                                      -                                     -"<<endl;//
		cout<<"-                                      -  @ 首都       ~          **                                                 -                                     -"<<endl;//
		cout<<"-                                      -  # 城市    ~        ~      ******              #Ken City                    -                                     -"<<endl;//
		cout<<"-                                      -  ~ 海           ~      ~         *                                          -                                     -"<<endl;//
		cout<<"-                                      -  / 沙漠  ~                        *                                         -                                     -"<<endl;//
		cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//0
		cout<<"-                                                                                                                                                          -"<<endl;//1
		cout<<"-                                                                                                                                                          -"<<endl;//2
		cout<<"-                                                                                                                                                          -"<<endl;//3
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//4
		PAUSE;
		}
	}

void Maker_List(){
	//P 
	CLS;
	end(30); 
	cout<<"-                                    制作组                                   -"<<endl;Sleep(500);
	cout<<"-                                MS Game Studio                               -"<<endl;Sleep(500);
	end(1);Sleep(500);
	cout<<"-                                  程序制作者                                 -"<<endl;Sleep(500);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(500);
	end(1);Sleep(500);
	cout<<"-                                  动画制作者                                 -"<<endl;Sleep(500);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(500);
	end(1);Sleep(500);
	cout<<"-                            对我制作此游戏有贡献者                           -"<<endl;Sleep(500);
	cout<<"-                                 MS.DWTornier                                -"<<endl;Sleep(500);
	cout<<"-                                  MS.BlueCat                                 -"<<endl;Sleep(500);
	cout<<"-                                 MS.IceLocke                                 -"<<endl;Sleep(500);
	cout<<"-                                      CC                                     -"<<endl;Sleep(500);
	cout<<"-                      (想进入此名单？私聊QQ:2258488076)                      -"<<endl;Sleep(500);
	for(int i=1;i<=6;i++){
		end(1);
		Sleep(500);
		} 
	Sleep(2500);
	PAUSE;
	
	}

void Fight_ChuShiHua(int kind){
	switch(kind){
		case 1://Isaac
			Hero.Kind=1;
			Hero.ac=2;
			Hero.dmg=3;
			Hero.hp_max=50;
			Hero.hp=50;
			Hero.sp_max=0;
			Hero.sp=0;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=1;
			Hero.skill[1]=true;//旋风斩
			Hero.level=1;
			Hero.exp=0;
			break;
		case 2://Eden
			Hero.Kind=2;
			Hero.ac=1;
			Hero.dmg=5;
			Hero.hp_max=50;
			Hero.hp=50;
			Hero.sp_max=0;
			Hero.sp=0;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=1;
			Hero.skill[1]=true;//旋风斩 
			Hero.skill[2]=true;//四方斩 
			Hero.level=1;
			Hero.exp=0;
			break; 
		default:
			Hero.ac=1;
			Hero.dmg=3;
			Hero.hp=50;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=0;
			Hero.level=1;
			Hero.exp=0;
			break;
		}
	}

void CG(int n,int a){
	/*
	0.战斗胜利! 
	1.集气
	2.逃跑失败 
	3.没有技能 
	4.4.CG_1_攻击_剑_重击 
	5.CG_1_防御_剑 
	6.CG_1逃跑失败
	7.CG_1_受到攻击
	8.CG_1_攻击_剑_攻击
	9.CG_1_攻击被格挡 
	10.Game Over 
	11.You Dead 
	12.CG_1_旋风斩 
	13.CG_2_迷宫过场_go 
	14.CG_2_这里没有路 
	15.CG_2_迷宫过场_return 
	16.CG_2_精灵猎手_出现 
	17.CG_2_精灵猎手_攻击
	18.CG_2_精灵猎手_重击
	19.CG_2_精灵猎手_防御(无法)
	20.CG_2_精灵猎手_受到攻击
	21.CG_2_体力不足
	22.CG_2_精灵猎手_旋风斩
	23.
	*/
	if(n==0){//0.战斗胜利! 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                  ***                                        -"<<endl;//
		cout<<"-                                 *   *                                       -"<<endl;//
		cout<<"-                               *  ***  *                                     -"<<endl;//
		cout<<"-                                *  *  *                                      -"<<endl;//
		cout<<"-                                 *****                                       -"<<endl;//
		cout<<"-                                   *                                         -"<<endl;//
		cout<<"-                                   *                                         -"<<endl;//
		cout<<"-                                  * *                                        -"<<endl;//
		cout<<"-                                 *   *                                       -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                            战斗胜利！                               *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==1){//1.集气
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                        +                                                                                                 -"<<endl;//
		cout<<"-                                                                                              +                                                           -"<<endl;//
		cout<<"-                                                                                  +                                                                       -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        *****                                                                             -"<<endl;//
		cout<<"-                                                 +                *    *     *    *                                                                       -"<<endl;//
		cout<<"-                                                                    *   *****   *                                                                         -"<<endl;//
		cout<<"-                                                                      *   *   *                                                                           -"<<endl;//
		cout<<"-                                                                        *****                                                                             -"<<endl;//
		cout<<"-                                                                +         *                                                                                -"<<endl;//
		cout<<"-                                                                          *                                                                               -"<<endl;//
		cout<<"-                                                                          *                  +                                                            -"<<endl;//
		cout<<"-                                                +                         *                                                                               -"<<endl;//
		cout<<"-                                                                         * *                             +                                                -"<<endl;//
		cout<<"-                                                                        *   *                                                                             -"<<endl;//
		cout<<"-                                                                       *     *                                                                             -"<<endl;//
		cout<<"-                                                                      *       *                                                                           -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==2){//2.逃跑失败 
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       被敌人包围了！逃跑失败！                      *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==3){//3.体力不足 
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                              体力不足                               *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==4){//4.CG_1_攻击_剑_重击 
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                           /                     -"<<endl;//
		cout<<"-              *  * *   * *  *                        /                       -"<<endl;//
		cout<<"-              *  ***   ***  *                      /                         -"<<endl;//
		cout<<"-               *           *                     /                           -"<<endl;//
		cout<<"-                ***|||||***                    /                             -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *              |                                  -"<<endl;//
		cout<<"-              *  * *   * *  *             |                                  -"<<endl;//
		cout<<"-              *  ***   ***  *             |                                  -"<<endl;//
		cout<<"-               *           *              |                                  -"<<endl;//
		cout<<"-                ***|||||***               |                                  -"<<endl;//
		cout<<"-                   *****                  |                                  -"<<endl;//
		cout<<"-                                        --+--                                -"<<endl;//
		cout<<"-                                          ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *       \\                                         -"<<endl;//
		cout<<"-              *  * *   * *  *       \\                                        -"<<endl;//
		cout<<"-              *  ***   ***  *        \\                                       -"<<endl;//
		cout<<"-               *           *          \\                                      -"<<endl;//
		cout<<"-                ***|||||***            \\                                     -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *  \\                                              -"<<endl;//
		cout<<"-              *  * *   * *  *   \\                                            -"<<endl;//
		cout<<"-              *  ***   ***  *     \\                                          -"<<endl;//
		cout<<"-               *           *        \\                                        -"<<endl;//
		cout<<"-                ***|||||***           \\                                      -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** ====                                              -"<<endl;//
		cout<<"-              *  * *   * ========                                            -"<<endl;//
		cout<<"-              *  ***   *** ====\\                                             -"<<endl;//
		cout<<"-               *           *      \\                                          -"<<endl;//
		cout<<"-                ***|||||***          \\                                       -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       重击了骷髅战士！！！                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       重击了骷髅战士！！！                          *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==5){//5.CG_1_防御_剑 
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **       *                                          -"<<endl;//
		cout<<"-               * ***   *** *     /                                           -"<<endl;//
		cout<<"-              *  * *   * *  *   /                                            -"<<endl;//
		cout<<"-              *  ***   ***  *  /                                             -"<<endl;//
		cout<<"-               *           *  /                                              -"<<endl;//
		cout<<"-                ***|||||***  /                                               -"<<endl;//
		cout<<"-                   *****    /                                                -"<<endl;//
		cout<<"-                           /                                                 -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **           *                                      -"<<endl;//
		cout<<"-               * ***   *** *        /                                        -"<<endl;//
		cout<<"-              *  * *   * *  *     /                                          -"<<endl;//
		cout<<"-              *  ***   ***  *   /                                            -"<<endl;//
		cout<<"-               *           *  /                                              -"<<endl;//
		cout<<"-                ***|||||*** /                                                -"<<endl;//
		cout<<"-                   *****  /                                                  -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                                                 -"<<endl;//
		cout<<"-              *  * *   * *  *                                                -"<<endl;//
		cout<<"-              *  ***   ***  *                                                -"<<endl;//
		cout<<"-               *           *                                                 -"<<endl;//
		cout<<"-                ***|||||***   ----*                                          -"<<endl;//
		cout<<"-                   *****                                                     -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                                                 -"<<endl;//
		cout<<"-              *  * *   * *  *                                                -"<<endl;//
		cout<<"-              *  ***   ***  *                                                -"<<endl;//
		cout<<"-               *           *  |                                              -"<<endl;//
		cout<<"-                ***|||||***    |                                             -"<<endl;//
		cout<<"-                   *****        |                                            -"<<endl;//
		cout<<"-                                 *                                           -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                                                 -"<<endl;//
		cout<<"-              *  * *   * *  *                                                -"<<endl;//
		cout<<"-              *  ***   ***  *                                                -"<<endl;//
		cout<<"-               *           *  |                                              -"<<endl;//
		cout<<"-                ***|||||***   |                                              -"<<endl;//
		cout<<"-                   *****      |                                              -"<<endl;//
		cout<<"-                              |                                              -"<<endl;//
		cout<<"-                            ==|=      |   ***                                -"<<endl;//
		cout<<"-                      -----===|===----+--*   *                               -"<<endl;//
		cout<<"-                            ==*==     |   **  *                              -"<<endl;//
		cout<<"-                              =             *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                             铛！！！                                *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **       *                                          -"<<endl;//
		cout<<"-               * ***   *** *     /                                           -"<<endl;//
		cout<<"-              *  * *   * *  *   /                                            -"<<endl;//
		cout<<"-              *  ***   ***  *  /                                             -"<<endl;//
		cout<<"-               *           *  /                                              -"<<endl;//
		cout<<"-                ***|||||***  /                                               -"<<endl;//
		cout<<"-                   *****    /                                                -"<<endl;//
		cout<<"-                           /                                                 -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                      防御住了骷髅战士的攻击！                       *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==6){//6.CG_1_逃跑失败 
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  勇者:                                                              *   -"<<endl;//
		cout<<"-   *      这是我第一次与怪物战斗啊！                                     *   -"<<endl;//
		cout<<"-   *          怎么能逃跑呢！？！                                         *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==7){//7.CG_1_受到攻击
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                                   * *                   -"<<endl;//
		cout<<"-                **                                     * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                             -                               -"<<endl;//
		cout<<"-                             ***      -                                      -"<<endl;//
		cout<<"-               ***           ***                                             -"<<endl;//
		cout<<"-              *   *  /        *            -                                 -"<<endl;//
		cout<<"-               ***====      *****  __                                        -"<<endl;//
		cout<<"-                ==*--------*- *  *|  |                                       -"<<endl;//
		cout<<"-               **-+==         *   |  |   -                                   -"<<endl;//
		cout<<"-                **           ***   \\/        -                               -"<<endl;//
		cout<<"-                *            * *                                             -"<<endl;//
		cout<<"-               * *           * *                                             -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  勇者:                                                              *   -"<<endl;//
		cout<<"-   *      啊！             你受到了怪物的攻击                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                             -         *** ^                 -"<<endl;//
		cout<<"-                                      -                *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                     -      |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                     -             * *                   -"<<endl;//
		cout<<"-                **                           -         * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  勇者:                                                              *   -"<<endl;//
		cout<<"-   *      啊！             你受到了怪物的攻击                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                                   * *                   -"<<endl;//
		cout<<"-                **                                     * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       你受到了怪物的攻击                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==8){//8.CG_1_攻击_剑_攻击 
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                           /                     -"<<endl;//
		cout<<"-              *  * *   * *  *                        /                       -"<<endl;//
		cout<<"-              *  ***   ***  *                      /                         -"<<endl;//
		cout<<"-               *           *                     /                           -"<<endl;//
		cout<<"-                ***|||||***                    /                             -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *              |                                  -"<<endl;//
		cout<<"-              *  * *   * *  *             |                                  -"<<endl;//
		cout<<"-              *  ***   ***  *             |                                  -"<<endl;//
		cout<<"-               *           *              |                                  -"<<endl;//
		cout<<"-                ***|||||***               |                                  -"<<endl;//
		cout<<"-                   *****                  |                                  -"<<endl;//
		cout<<"-                                        --+--                                -"<<endl;//
		cout<<"-                                          ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *       \\                                         -"<<endl;//
		cout<<"-              *  * *   * *  *       \\                                        -"<<endl;//
		cout<<"-              *  ***   ***  *        \\                                       -"<<endl;//
		cout<<"-               *           *          \\                                      -"<<endl;//
		cout<<"-                ***|||||***            \\                                     -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *  \\                                              -"<<endl;//
		cout<<"-              *  * *   * *  *   \\                                            -"<<endl;//
		cout<<"-              *  ***   ***  *     \\                                          -"<<endl;//
		cout<<"-               *           *        \\                                        -"<<endl;//
		cout<<"-                ***|||||***           \\                                      -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** ====                                              -"<<endl;//
		cout<<"-              *  * *   * ========                                            -"<<endl;//
		cout<<"-              *  ***   *** ====\\                                             -"<<endl;//
		cout<<"-               *           *      \\                                          -"<<endl;//
		cout<<"-                ***|||||***          \\                                       -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       攻击了骷髅战士！！！                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       攻击了骷髅战士！！！                          *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==9){//9.CG_1_攻击被格挡 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 骷髅战士.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   ***____=_____                                         -"<<endl;//
		cout<<"-              *  * *   * |   ===    |                                        -"<<endl;//
		cout<<"-              *  ***   **|    =\\=   |                                        -"<<endl;//
		cout<<"-               *         |        \\ |                                        -"<<endl;//
		cout<<"-                ***|||||*|          |\\                                       -"<<endl;//
		cout<<"-                   ***** |          |   \\  -                                 -"<<endl;//
		cout<<"-                         |          |   -+-                                  -"<<endl;//
		cout<<"-                          \\        /   -  ***                                -"<<endl;//
		cout<<"-                            \\    /       *   *                               -"<<endl;//
		cout<<"-                              \\/          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                           攻击被格挡了！                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==10){//10.Game Over 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                 你被杀死了                                  -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-    GGGGG     A      M M    EEEEE           OOOOO   V   V   EEEEE   RRRR     -"<<endl;//
		cout<<"-    G        A A    M M M   E               O   O   V   V   E       R   R    -"<<endl;//
		cout<<"-    G   G   AAAAA   M M M   EEEEE           O   O   V   V   EEEEE   RRRR     -"<<endl;//
		cout<<"-    G   G   A   A   M M M   E               O   O    V V    E       R  R     -"<<endl;//
		cout<<"-    GGGGG   A   A   M M M   EEEEE           OOOOO     V     EEEEE   R   R    -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                             Thanks For Playing                              -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==11){//11.You Dead 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-        Y   Y   OOOOO   U   U               DDDD    EEEEE     A     DDDD     -"<<endl;//
		cout<<"-         Y Y    O   O   U   U               D   D   E        A A    D   D    -"<<endl;//
		cout<<"-          Y     O   O   U   U               D   D   EEEEE   AAAAA   D   D    -"<<endl;//
		cout<<"-          Y     O   O   U   U               D   D   E       A   A   D   D    -"<<endl;//
		cout<<"-          Y     OOOOO    UUU                DDDD    EEEEE   A   A   DDDD     -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==12){//12.CG_1_旋风斩 
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                                   * *                   -"<<endl;//
		cout<<"-                **                                     * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***            __   *  |                 -"<<endl;//
		cout<<"-             -                     *   *          |  |*****|                 -"<<endl;//
		cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
		cout<<"-         -                           *             \\/  ***                   -"<<endl;//
		cout<<"-                -                 |  **                * *                   -"<<endl;//
		cout<<"-                       -----------+-**                 * *                   -"<<endl;//
		cout<<"-      -                           |  *                                       -"<<endl;//
		cout<<"-              -                     * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***            __   *  |                 -"<<endl;//
		cout<<"-                                   *   *          |  |*****|                 -"<<endl;//
		cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
		cout<<"-                                     *             \\/  ***                   -"<<endl;//
		cout<<"-                                    **                 * *                   -"<<endl;//
		cout<<"-                                     **\\ /             * *                   -"<<endl;//
		cout<<"-                                     *  +                                    -"<<endl;//
		cout<<"-                                    * */ \\                                   -"<<endl;//
		cout<<"-                                   *  *   \\                                  -"<<endl;//
		cout<<"-                                           \\                                 -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***            __   *  |                 -"<<endl;//
		cout<<"-                                   *   *          |  |*****|                 -"<<endl;//
		cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
		cout<<"-                                     *             \\/  ***                   -"<<endl;//
		cout<<"-                                    ** |               * *                   -"<<endl;//
		cout<<"-                                     **+-----------    * *                   -"<<endl;//
		cout<<"-                                     * |                                     -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***          ==__   *  |                 -"<<endl;//
		cout<<"-                                   *   *        =/== |*****|                 -"<<endl;//
		cout<<"-                                    ***       /  ==  |  *  |                 -"<<endl;//
		cout<<"-                                     *     /       \\/  ***                   -"<<endl;//
		cout<<"-                                    **| /              * *                   -"<<endl;//
		cout<<"-                                     **+               * *                   -"<<endl;//
		cout<<"-                                     *  |                                    -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		for(int i=1;i<=5;i++){
			CLS;
			end(1); 
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                       *** ^                 -"<<endl;//
			cout<<"-                                                       *** |                 -"<<endl;//
			cout<<"-                                    ***            __   *  |                 -"<<endl;//
			cout<<"-                                   *   *          |  |*****|                 -"<<endl;//
			cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
			cout<<"-                                     *             \\/  ***                   -"<<endl;//
			cout<<"-                                  |  **                * *                   -"<<endl;//
			cout<<"-                       -----------+-**                 * *                   -"<<endl;//
			cout<<"-                                  |  *                                       -"<<endl;//
			cout<<"-                                    * *                                      -"<<endl;//
			cout<<"-                                    *  *                                     -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                                 !                                   *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			Sleep(300);
			CLS;
			end(1); 
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                       *** ^                 -"<<endl;//
			cout<<"-                                                       *** |                 -"<<endl;//
			cout<<"-                                    ***          ==__   *  |                 -"<<endl;//
			cout<<"-                                   *   *        =/== |*****|                 -"<<endl;//
			cout<<"-                                    ***       /  ==  |  *  |                 -"<<endl;//
			cout<<"-                                     *     /       \\/  ***                   -"<<endl;//
			cout<<"-                                    **| /              * *                   -"<<endl;//
			cout<<"-                                     **+               * *                   -"<<endl;//
			cout<<"-                                     *  |                                    -"<<endl;//
			cout<<"-                                    * *                                      -"<<endl;//
			cout<<"-                                   *  *                                      -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                               ! ! !                                 *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			Sleep(300);
			}
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                      \\                                      -"<<endl;//
		cout<<"-                                   -   \\                                     -"<<endl;//
		cout<<"-                               -    -   \\              *** ^                 -"<<endl;//
		cout<<"-                                     -   \\             *** |                 -"<<endl;//
		cout<<"-                                    ***   \\  -     __   *  |                 -"<<endl;//
		cout<<"-                                   *   *  -+-     |  |*****|                 -"<<endl;//
		cout<<"-                                    ***  -*       |  |  *  |                 -"<<endl;//
		cout<<"-                                     *   *         \\/  ***                   -"<<endl;//
		cout<<"-                                    *****              * *                   -"<<endl;//
		cout<<"-                                     *                 * *                   -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                    *  *                                     -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       -  -  -  -  -  -  -  -                        *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                    =  *** ^                 -"<<endl;//
		cout<<"-                                             =         *** |                 -"<<endl;//
		cout<<"-                                    ***         ====_  ==  |                 -"<<endl;//
		cout<<"-                                   *   * =   ====/====*****|                 -"<<endl;//
		cout<<"-                                    ***       / ==== |  *= |                 -"<<endl;//
		cout<<"-                                     *     /   =   \\/  ***                   -"<<endl;//
		cout<<"-                                    **| /          =   * *                   -"<<endl;//
		cout<<"-                                     **+               * *                   -"<<endl;//
		cout<<"-                                     *  |                                    -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                         ! ! ! 旋风斩 ! ! !                          *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==13){//13.CG_2_迷宫过场_go 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *          ↑         *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==14){//14.CG_2_这里没有路 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            这里没有路可以走orz                                                                *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==15){//15.CG_2_迷宫过场_return 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *          ↓         *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==16){//16.CG_2_精灵猎手_出现 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ********************************           ********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||      ***      |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||      ***      |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||       *       |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||    |\\***      |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*     |*|*        *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *       * |*          *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *         |/* *           *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *             *               *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                    出现怪物                                                                   *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==17){//17.CG_2_精灵猎手_攻击 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                             *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                              * ************* *                                                           -"<<endl;//
		cout<<"-                                                                               ***         ***                                                            -"<<endl;//
		cout<<"-                                                                               ***          **                                                            -"<<endl;//
		cout<<"-                                                                               **           **                                                            -"<<endl;//
		cout<<"-                                                                                *           *                                                             -"<<endl;//
		cout<<"-                                                                                 **       **                                                              -"<<endl;//
		cout<<"-                                                                                   *******                                                                -"<<endl;//
		cout<<"-                                                          /\\                                                                                              -"<<endl;//
		cout<<"-                            ******************************||                                                                                              -"<<endl;//
		cout<<"-                          *                               ||  *****                                                                                       -"<<endl;//
		cout<<"-                        *---------------------------------||=*     *=]                                                                                    -"<<endl;//
		cout<<"-                          *                               ||  *   *                                                                                       -"<<endl;//
		cout<<"-                            ******************************||  *   *                                                                                       -"<<endl;//
		cout<<"-                                                          \\/ *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                       \\ \\                   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                      \\ \\  \\                  * ************* *                                                           -"<<endl;//
		cout<<"-                                                      \\  \\  \\                  ***         ***                                                            -"<<endl;//
		cout<<"-                                                       \\  \\  \\                 ***          **                                                            -"<<endl;//
		cout<<"-                                                        \\  \\  \\                **           **                                                            -"<<endl;//
		cout<<"-                                                         \\  \\  \\                *           *                                                             -"<<endl;//
		cout<<"-                                                          \\  \\  \\                **       **                                                              -"<<endl;//
		cout<<"-                                                           \\  \\  \\ *               *******                                                                -"<<endl;//
		cout<<"-                                                            \\  *                                                                                          -"<<endl;//
		cout<<"-                                                           *    \\                                                                                         -"<<endl;//
		cout<<"-                                                              *****                                                                                       -"<<endl;//
		cout<<"-                                                             *     *                                                                                      -"<<endl;//
		cout<<"-                                                              *   *\\                                                                                      -"<<endl;//
		cout<<"-                                                              *   * *                                                                                     -"<<endl;//
		cout<<"-                                                             *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       |||   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                      | | |   * ************* *                                                           -"<<endl;//
		cout<<"-                                                                     |  |  |   ***         ***                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   ***          **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   **           **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |    *           *                                                             -"<<endl;//
		cout<<"-                                                                     |  |  |     **       **                                                              -"<<endl;//
		cout<<"-                                                                     |  |  |       *******                                                                -"<<endl;//
		cout<<"-                                                                     |  |  |                                                                              -"<<endl;//
		cout<<"-                                                                    /-------\\                                                                             -"<<endl;//
		cout<<"-                                                                    \\-------/                                                                             -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   *   |                                                                                 -"<<endl;//
		cout<<"-                                                             *   *      *                                                                                 -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *    *********    *                                                         -"<<endl;//
		cout<<"-                                                                               * */ /********* *                                                          -"<<endl;//
		cout<<"-                                                                              /    / /      ***                                                           -"<<endl;//
		cout<<"-                                                                             /    /          **                                                           -"<<endl;//
		cout<<"-                                                                            /    /    /      **                                                           -"<<endl;//
		cout<<"-                                                                           /    /    /       *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *  =====******    *                                                         -"<<endl;//
		cout<<"-                                                                              ====/ /===****** *                                                          -"<<endl;//
		cout<<"-                                                                            ==/    / /===== ***                                                           -"<<endl;//
		cout<<"-                                                                        =====/    /   =======**                                                           -"<<endl;//
		cout<<"-                                                                         ===/    /    /===   **                                                           -"<<endl;//
		cout<<"-                                                                          =/    /    /==     *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            攻击了骷髅战士！！！                                                                *    -"<<endl;//
		cout<<"-    *                                                                 <"<<a<<">\t                                                                    *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==18){//18.CG_2_精灵猎手_防御 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                             *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                              * ************* *                                                           -"<<endl;//
		cout<<"-                                                                               ***         ***                                                            -"<<endl;//
		cout<<"-                                                                               ***          **                                                            -"<<endl;//
		cout<<"-                                                                               **           **                                                            -"<<endl;//
		cout<<"-                                                                                *           *                                                             -"<<endl;//
		cout<<"-                                                                                 **       **                                                              -"<<endl;//
		cout<<"-                                                                                   *******                                                                -"<<endl;//
		cout<<"-                                                          /\\                                                                                              -"<<endl;//
		cout<<"-                            ******************************||                                                                                              -"<<endl;//
		cout<<"-                          *                               ||  *****                                                                                       -"<<endl;//
		cout<<"-                        *---------------------------------||=*     *=]                                                                                    -"<<endl;//
		cout<<"-                          *                               ||  *   *                                                                                       -"<<endl;//
		cout<<"-                            ******************************||  *   *                                                                                       -"<<endl;//
		cout<<"-                                                          \\/ *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                       \\ \\                   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                      \\ \\  \\                  * ************* *                                                           -"<<endl;//
		cout<<"-                                                      \\  \\  \\                  ***         ***                                                            -"<<endl;//
		cout<<"-                                                       \\  \\  \\                 ***          **                                                            -"<<endl;//
		cout<<"-                                                        \\  \\  \\                **           **                                                            -"<<endl;//
		cout<<"-                                                         \\  \\  \\                *           *                                                             -"<<endl;//
		cout<<"-                                                          \\  \\  \\                **       **                                                              -"<<endl;//
		cout<<"-                                                           \\  \\  \\ *               *******                                                                -"<<endl;//
		cout<<"-                                                            \\  *                                                                                          -"<<endl;//
		cout<<"-                                                           *    \\                                                                                         -"<<endl;//
		cout<<"-                                                              *****                                                                                       -"<<endl;//
		cout<<"-                                                             *     *                                                                                      -"<<endl;//
		cout<<"-                                                              *   *\\                                                                                      -"<<endl;//
		cout<<"-                                                              *   * *                                                                                     -"<<endl;//
		cout<<"-                                                             *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       |||   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                      | | |   * ************* *                                                           -"<<endl;//
		cout<<"-                                                                     |  |  |   ***         ***                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   ***          **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   **           **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |    *           *                                                             -"<<endl;//
		cout<<"-                                                                     |  |  |     **       **                                                              -"<<endl;//
		cout<<"-                                                                     |  |  |       *******                                                                -"<<endl;//
		cout<<"-                                                                     |  |  |                                                                              -"<<endl;//
		cout<<"-                                                                    /-------\\                                                                             -"<<endl;//
		cout<<"-                                                                    \\-------/                                                                             -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   *   |                                                                                 -"<<endl;//
		cout<<"-                                                             *   *      *                                                                                 -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *    *********    *                                                         -"<<endl;//
		cout<<"-                                                                               * */ /********* *                                                          -"<<endl;//
		cout<<"-                                                                              /    / /      ***                                                           -"<<endl;//
		cout<<"-                                                                             /    /          **                                                           -"<<endl;//
		cout<<"-                                                                            /    /    /      **                                                           -"<<endl;//
		cout<<"-                                                                           /    /    /       *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *  =====******    *                                                         -"<<endl;//
		cout<<"-                                                                              ====/ /===****** *                                                          -"<<endl;//
		cout<<"-                                                                            ==/    / /===== ***                                                           -"<<endl;//
		cout<<"-                                                                        =====/    /   =======**                                                           -"<<endl;//
		cout<<"-                                                                         ===/    /    /===   **                                                           -"<<endl;//
		cout<<"-                                                                          =/    /    /==     *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            重击了骷髅战士！！！                                                               *    -"<<endl;//
		cout<<"-    *                                                                 <"<<a<<">\t                                                                    *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==19){//CG_2_精灵猎手_防御(无法) 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                 弓箭不能被防御                                                                *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==20){//20.CG_2_精灵猎手_受到攻击 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
		cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
		cout<<"-                             ***    *   /                                                        *----|-*****                                             -"<<endl;//
		cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                                        -   / |  *****                                         -"<<endl;//
		cout<<"-                              * *    /   /                                                            | -| **   *                                         -"<<endl;//
		cout<<"-                             ***    *   /                                                   *-------  | *|  * **                                          -"<<endl;//
		cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                                  -|  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                   -        /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                            -               / |  *****                                         -"<<endl;//
		cout<<"-                              * *    /   /                                     -            -     -   |  | **   *                                         -"<<endl;//
		cout<<"-                             ***    *   /                                    *-------                 | *|  * **                                          -"<<endl;//
		cout<<"-                            ********    *                                                        -    *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                     -             |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                             -       \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                 -                        **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                         -                  /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                        -      -                            / |  *****                                         -"<<endl;//
		cout<<"-                              * *    /   /                     -             -                        |  | **   *                                         -"<<endl;//
		cout<<"-                             ***    *   /                 *-------      - -               -           | *|  * **                                          -"<<endl;//
		cout<<"-                            ********    *                                             -               *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                 -         -                       |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                              -                          \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/  =/   /                                                            / |  *****                                         -"<<endl;//
		cout<<"-                              * *  =========                                                          |  | **   *                                         -"<<endl;//
		cout<<"-                             *** ====*-------                                                         | *|  * **                                          -"<<endl;//
		cout<<"-                            *******=======                                                            *  |  *                                             -"<<endl;//
		cout<<"-                              **  / ==                                                                |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                              你被弓箭社保了！                                                                 *    -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                  *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		} 
	if(n==21){//体力不足
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                 体力不足                                                                      *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
		if(n==22){//22.CG_2_精灵猎手_旋风斩 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
		cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
		cout<<"-                             ***    *   /                                                             | *****                                             -"<<endl;//
		cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                           *******                                                                     *         *                                        -"<<endl;//
		cout<<"-                          *********                                                                     **     **                                         -"<<endl;//
		cout<<"-                          *       *                                                                       *****                                           -"<<endl;//
		cout<<"-                          *       *                                                                     /|  *                                             -"<<endl;//
		cout<<"-                           *******                                                                     / |  ****                                          -"<<endl;//
		cout<<"-                              *                                                                       |  | ** *                                           -"<<endl;//
		cout<<"-                             ***                                                                      | *****                                             -"<<endl;//
		cout<<"-                            *****                                                                     *  |  *                                             -"<<endl;//
		cout<<"-                              ***\\                                                                    |  |  *                                             -"<<endl;//
		cout<<"-                              *   *                                                                    \\ |  *                                             -"<<endl;//
		cout<<"-                              *    \\   *                                                                \\| * *                                            -"<<endl;//
		cout<<"-                             ***    *  \\                                                                  *   *                                           -"<<endl;//
		cout<<"-                            *   **   \\  \\                                                                 *   *                                           -"<<endl;//
		cout<<"-                           *     * \\  \\  \\                                                                *                                               -"<<endl;//
		cout<<"-                           *      * \\  \\  \\                                                               *                                               -"<<endl;//
		cout<<"-                           *       * \\  \\  \\                                                                                                              -"<<endl;//
		cout<<"-                                      \\  \\  \\                                                                                                             -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                           *******                                                                     *         *                                        -"<<endl;//
		cout<<"-                          *********                                                                     **     **                                         -"<<endl;//
		cout<<"-                          *       *                                                                       *****                                           -"<<endl;//
		cout<<"-                          *       *                                                                     /|  *                                             -"<<endl;//
		cout<<"-                           *******                                                                     / |  ****                                          -"<<endl;//
		cout<<"-                              *                                                                       |  | ** *                                           -"<<endl;//
		cout<<"-     ___________________*    ***                                                                      | *****                                             -"<<endl;//
		cout<<"-    -                       ****                                                                      *  |  *                                             -"<<endl;//
		cout<<"-   ---------------------*--****                                                                       |  |  *                                             -"<<endl;//
		cout<<"-    -___________________      *                                                                        \\ |  *                                             -"<<endl;//
		cout<<"-                        *     *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                    *******                                                            *         *                                        -"<<endl;//
		cout<<"-                                   *********                                                            **     **                                         -"<<endl;//
		cout<<"-                                   *       *                                                              *****                                           -"<<endl;//
		cout<<"-                                   *       *                                                            /|  *                                             -"<<endl;//
		cout<<"-                                    *******                                                            / |  ****                                          -"<<endl;//
		cout<<"-                                       *    *___________________                                      |  | ** *                                           -"<<endl;//
		cout<<"-                                      ***                       -                                     | *****                                             -"<<endl;//
		cout<<"-                                      *****-*---------------------                                    *  |  *                                             -"<<endl;//
		cout<<"-                                       *     ___________________-                                     |  |  *                                             -"<<endl;//
		cout<<"-                                       *    *                                                          \\ |  *                                             -"<<endl;//
		cout<<"-                                       *                                                                \\| * *                                            -"<<endl;//
		cout<<"-                                      ***                                                                 *   *                                           -"<<endl;//
		cout<<"-                                     *   *                                                                *   *                                           -"<<endl;//
		cout<<"-                                     *    *                                                               *                                               -"<<endl;//
		cout<<"-                                     *     *                                                              *                                               -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                                      *******                                          *         *                                        -"<<endl;//
		cout<<"-                                                     *********                                          **     **                                         -"<<endl;//
		cout<<"-                                                     *       *                                            *****                                           -"<<endl;//
		cout<<"-                                                     *       *                                          /|  *                                             -"<<endl;//
		cout<<"-                                                      *******                                          / |  ****                                          -"<<endl;//
		cout<<"-                                                         *                                            |  | ** *                                           -"<<endl;//
		cout<<"-                                ___________________*    ***                                           | *****                                             -"<<endl;//
		cout<<"-                               -                       ****                                           *  |  *                                             -"<<endl;//
		cout<<"-                              ---------------------*--****                                            |  |  *                                             -"<<endl;//
		cout<<"-                               -___________________      *                                             \ |  *                                             -"<<endl;//
		cout<<"-                                                   *     *                                              \| * *                                            -"<<endl;//
		cout<<"-                                                        ***                                               *   *                                           -"<<endl;//
		cout<<"-                                                       *   *                                              *   *                                           -"<<endl;//
		cout<<"-                                                      *     *                                             *                                               -"<<endl;//
		cout<<"-                                                     *      *                                             *                                               -"<<endl;//
		cout<<"-                                                    *       *                                                                                             -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                                                        *******                        *         *                                        -"<<endl;//
		cout<<"-                                                                       *********                        **     **                                         -"<<endl;//
		cout<<"-                                                                       *       *                          *****                                           -"<<endl;//
		cout<<"-                                                                       *       *                        /|  *                                             -"<<endl;//
		cout<<"-                                                                        *******                        / |  ****                                          -"<<endl;//
		cout<<"-                                                                           *    *___________________  |  | ** *                                           -"<<endl;//
		cout<<"-                                                                          ***                       - | *****                                             -"<<endl;//
		cout<<"-                                                                          *****-*---------------------*  |  *                                             -"<<endl;//
		cout<<"-                                                                           *     ___________________- |  |  *                                             -"<<endl;//
		cout<<"-                                                                           *    *                      \ |  *                                             -"<<endl;//
		cout<<"-                                                                           *                            \| * *                                            -"<<endl;//
		cout<<"-                                                                          ***                             *   *                                           -"<<endl;//
		cout<<"-                                                                         *   *                            *   *                                           -"<<endl;//
		cout<<"-                                                                         *    *                           *                                               -"<<endl;//
		cout<<"-                                                                         *     *                          *                                               -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		for(int i=1;i<=5;i++){
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
			cout<<"-                                                                                                      **         **                                       -"<<endl;//
			cout<<"-                                                                        *******                        *         *                                        -"<<endl;//
			cout<<"-                                                                       *********                        **     **                                         -"<<endl;//
			cout<<"-                                                                       *       *                          *****                                           -"<<endl;//
			cout<<"-                                                                       *       *                        /|  *                                             -"<<endl;//
			cout<<"-                                                                        *******                        / |  ****                                          -"<<endl;//
			cout<<"-                                                                           *                          |  | ** *                                           -"<<endl;//
			cout<<"-                                                  ___________________*    ***                         | *****                                             -"<<endl;//
			cout<<"-                                                 -                       ****                         *  |  *                                             -"<<endl;//
			cout<<"-                                                ---------------------*--****                          |  |  *                                             -"<<endl;//
			cout<<"-                                                 -___________________      *                           \ |  *                                             -"<<endl;//
			cout<<"-                                                                     *     *                            \| * *                                            -"<<endl;//
			cout<<"-                                                                          ***                             *   *                                           -"<<endl;//
			cout<<"-                                                                         *   *                            *   *                                           -"<<endl;//
			cout<<"-                                                                        *     *                           *                                               -"<<endl;//
			cout<<"-                                                                       *      *                           *                                               -"<<endl;//
			cout<<"-                                                                      *       *                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			Sleep(500);
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
			cout<<"-                                                                                                      **         **                                       -"<<endl;//
			cout<<"-                                                                          *******                      *         *                                        -"<<endl;//
			cout<<"-                                                                         *********                      **     **                                         -"<<endl;//
			cout<<"-                                                                         *       *                        *****                                           -"<<endl;//
			cout<<"-                                                                         *       *                      /|  *                                             -"<<endl;//
			cout<<"-                                                                          *******                      / |  ****                                          -"<<endl;//
			cout<<"-                                                                             *    *_________________=====| ** *                                           -"<<endl;//
			cout<<"-                                                                            ***                       -===***                                             -"<<endl;//
			cout<<"-                                                                            *****-*---------------------====*                                             -"<<endl;//
			cout<<"-                                                                             *     ___________________-===  *                                             -"<<endl;//
			cout<<"-                                                                             *    *                 ==== |  *                                             -"<<endl;//
			cout<<"-                                                                             *                          \| * *                                            -"<<endl;//
			cout<<"-                                                                            ***                           *   *                                           -"<<endl;//
			cout<<"-                                                                           *   *                          *   *                                           -"<<endl;//
			cout<<"-                                                                          *     *                         *                                               -"<<endl;//
			cout<<"-                                                                          *      *                        *                                               -"<<endl;//
			cout<<"-                                                                          *       *                                                                       -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			Sleep(500);
			}
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                                                        *******                        *         *                                        -"<<endl;//
		cout<<"-                                                                       *********                        **     **                                         -"<<endl;//
		cout<<"-                                                                       *       *                          *****                                           -"<<endl;//
		cout<<"-                                                                       *       *                        /|  *                                             -"<<endl;//
		cout<<"-                                                                        *******                        / |  ****                                          -"<<endl;//
		cout<<"-                                                                           *    *___________________  |  | ** *                                           -"<<endl;//
		cout<<"-                                                                          ***                       - | *****                                             -"<<endl;//
		cout<<"-                                                                          *****-*---------------------*  |  *                                             -"<<endl;//
		cout<<"-                                                                           *     ___________________- |  |  *                                             -"<<endl;//
		cout<<"-                                                                           *    *                      \ |  *                                             -"<<endl;//
		cout<<"-                                                                           *                            \| * *                                            -"<<endl;//
		cout<<"-                                                                          ***                             *   *                                           -"<<endl;//
		cout<<"-                                                                         *   *                            *   *                                           -"<<endl;//
		cout<<"-                                                                          *   *                           *                                               -"<<endl;//
		cout<<"-                                                                          *    *                          *                                               -"<<endl;//
		cout<<"-                                                                         *     *                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		PAUSE;
		} 
	
	}

void Demo(){
	//Demo
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-    *****   *   *    *     *   *  *   *  *****       *****  *****  *****     -"<<endl;//
	cout<<"-      *     *   *   * *    **  *  *  *   *           *      *   *  *   *     -"<<endl;//
	cout<<"-      *     *****  *****   * * *  ***    *****       ***    *   *  *****     -"<<endl;//
	cout<<"-      *     *   *  *   *   *  **  *  *       *       *      *   *  *  *      -"<<endl;//
	cout<<"-      *     *   *  *   *   *   *  *   *  *****       *      *****  *   *     -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-              *****  *        *    *   *  *****   *   *  *****               -"<<endl;//
	cout<<"-              *   *  *       * *    * *     *     **  *  *                   -"<<endl;//
	cout<<"-              *****  *      *****    *      *     * * *  *  **               -"<<endl;//
	cout<<"-              *      *      *   *    *      *     *  **  *   *               -"<<endl;//
	cout<<"-              *      *****  *   *    *    *****   *   *  *****               -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                 Demo Over                                   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;	
	} 

void Input_Name(){
	//Input_Name
	CLS;
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                               请输入你的名字:                                 "<<endl;//
	cout<<"                               ";//
	cin.getline(Hero.name,16);
	Hero.name_len=strlen(Hero.name);
	}
void Output_Name(){
	if(Hero.name_len<=4)
		cout<<"-    *    "<<Hero.name<<":\t                                                                                                                                     *     -"<<endl;//
	if(Hero.name_len>=5 && Hero.name_len<=11)
		cout<<"-    *    "<<Hero.name<<":\t                                                                                                                             *     -"<<endl;//
	if(Hero.name_len>=12 && Hero.name_len<=15)
		cout<<"-    *    "<<Hero.name<<":\t                                                                                                                     *     -"<<endl;//
	}
void Hide_Cur(){
	CONSOLE_CURSOR_INFO cur=(CONSOLE_CURSOR_INFO){1,0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cur);
	}

void CG_1(){
	//第一章 
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                       序章                                                  -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                故事的起点                                   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_1
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-             ******                                                          -"<<endl;//
	cout<<"-         ****      *******                           *****                   -"<<endl;//
	cout<<"-      ***                 *                         *******                  -"<<endl;//
	cout<<"-       *****           ***                          **   **                  -"<<endl;//
	cout<<"-            ***********                      **     *** ***                  -"<<endl;//
	cout<<"-                                            *  *      * *                    -"<<endl;//
	cout<<"-                                             *       ** **                   -"<<endl;//
	cout<<"-                                              *    **     **                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Niya>先知:                                                        *   -"<<endl;//
	cout<<"-   *        ......                                                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *  <Niya>  :  <尼娅>                                                      *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_2
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-              ******                                                         -"<<endl;//
	cout<<"-          ****      *******                          *****                   -"<<endl;//
	cout<<"-       ***                 *                        *******                  -"<<endl;//
	cout<<"-        *****           ***                         **   **                  -"<<endl;//
	cout<<"-             ***********                     **     *** ***                  -"<<endl;//
	cout<<"-                                            *  *      * *                    -"<<endl;//
	cout<<"-                                             *       ** **                   -"<<endl;//
	cout<<"-                                              *    **     **                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Niya>先知:                                                        *   -"<<endl;//
	cout<<"-   *        一千年了...                                                  *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_3
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-               ******                                                        -"<<endl;//
	cout<<"-           ****      *******                         *****                   -"<<endl;//
	cout<<"-        ***                 *                       *******                  -"<<endl;//
	cout<<"-         *****           ***                        **   **                  -"<<endl;//
	cout<<"-              ***********                    **     *** ***                  -"<<endl;//
	cout<<"-                                            *  *      * *                    -"<<endl;//
	cout<<"-                                             *       ** **                   -"<<endl;//
	cout<<"-                                              *    **     **                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Niya>先知:                                                        *   -"<<endl;//
	cout<<"-   *        他们...回来了...                                             *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_4
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                 *************************           勇者经过长途跋涉，      -"<<endl;//
	cout<<"-                   *    DE il Ho  e    *             终于到达了Ken City      -"<<endl;//
	cout<<"-             *********************************       外围雨林中的神庙。      -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-           *************************************                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      啊，终于找到了！                                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *  <Isaac> : <以撒>                                                      *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_5
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                 *************************                                   -"<<endl;//
	cout<<"-                   *    DE il Ho  e    *                                     -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-           *************************************                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      听说里面有Ken.Caesar留下的宝藏！                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_6
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                 *************************                                   -"<<endl;//
	cout<<"-                   *    DE il Ho  e    *                                     -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-           *************************************                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      找到的话就发财啦！                                             *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_7
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      好黑啊，有种不妙的感觉...                                      *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	CG_1_Maze();
	
	//Maze_8
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      前面好像有亮光。                                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_9
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =       =  宝箱↓ =       =                             -"<<endl;//
	cout<<"-                     =       =  *=+=*  =       =                             -"<<endl;//
	cout<<"-                     =       =  *   *  =       =                             -"<<endl;//
	cout<<"-                     =       =  *****  =       =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      哦！找到了！                                                   *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_10
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =   突然边上的尸体站了起来，  -"<<endl;//
	cout<<"-                     =               ^         =   那原来是被恶魔同化的怪物  -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =       __   *  |         =                             -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =                             -"<<endl;//
	cout<<"-                     =      |/\\|  *  |         =                             -"<<endl;//
	cout<<"-                     =       \\/   *            =                             -"<<endl;//
	cout<<"-                     =           ***           =                             -"<<endl;//
	cout<<"-                     =    -      * *      -    =                             -"<<endl;//
	cout<<"-                     =  -    -   * *   -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  怪物嘶吼着:                                                        *   -"<<endl;//
	cout<<"-   *          厄啊啊！                                                   *   -"<<endl;//
	cout<<"-   *                       <骷髅战士>出现!                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_11
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =               ^         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =       __   *  |         =                             -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =                             -"<<endl;//
	cout<<"-                     =      |/\\|  *  |         =                             -"<<endl;//
	cout<<"-                     =       \\/   *            =                             -"<<endl;//
	cout<<"-                     =           ***           =                             -"<<endl;//
	cout<<"-                     =    -      * *      -    =                             -"<<endl;//
	cout<<"-                     =  -    -   * *   -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      ！！！                                                         *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_12
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =               ^         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =       __   *  |         =                             -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =                             -"<<endl;//
	cout<<"-                     =      |/\\|  *  |         =                             -"<<endl;//
	cout<<"-                     =       \\/   *            =                             -"<<endl;//
	cout<<"-                     =           ***           =                             -"<<endl;//
	cout<<"-                     =    -      * *      -    =                             -"<<endl;//
	cout<<"-                     =  -    -   * *   -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者心想:                                                   *   -"<<endl;//
	cout<<"-   *      终于，我的第一次战斗就要开始了吗，我早就迫不及待了呢，         *   -"<<endl;//
	cout<<"-   *      在帝国皇家学院里学的近身格斗术终于可以派上用场了！             *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_13
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =               ^         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =       /                     -"<<endl;//
	cout<<"-                     =       __   *  |         =      /                      -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =     /                       -"<<endl;//
	cout<<"-                     =      |/\\|  *  |              /                        -"<<endl;//
	cout<<"-                     =       \\/   *                /                         -"<<endl;//
	cout<<"-                     =           ***           *  /                          -"<<endl;//
	cout<<"-                     =    -      * *            *+*                          -"<<endl;//
	cout<<"-                     =  -    -   * *   -        *  *                         -"<<endl;//
	cout<<"-                     =-     -     -     -      *                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                    你拿出了父亲送你的木剑                           *   -"<<endl;//
	cout<<"-   *                          <攻击+1>                                   *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	Hero.dmg++;
	PAUSE;
	
	Fight(1);
	
	if(Hero.hp<=0){
		CG(11,0);
		CG(10,0);
		return;
		}
	
	//CG_1_14
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =       =  宝箱↓ =       =                             -"<<endl;//
	cout<<"-                     =       =  *=+=*  =       =                             -"<<endl;//
	cout<<"-                     =       =  *   *  =       =                             -"<<endl;//
	cout<<"-                     =       =  *****  =       =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      呼，好险。总算杀死他了。                                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =       =  宝箱↓ =       =                             -"<<endl;//
	cout<<"-                     =       =  *=+=*  =       =                             -"<<endl;//
	cout<<"-                     =       =  *   *  =       =                             -"<<endl;//
	cout<<"-                     =       =  *****  =       =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
	cout<<"-   *      现在该看看宝箱里有什么，可不要让我失望啊                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                      * * * * * * * * * * * * * * *                          -"<<endl;//
	cout<<"-                    **************************      *                        -"<<endl;//
	cout<<"-                      *                        *     *                       -"<<endl;//
	cout<<"-                        *                        *   *                       -"<<endl;//
	cout<<"-                         **                       **                         -"<<endl;//
	cout<<"-                         **************************                          -"<<endl;//
	cout<<"-                        *                        **                          -"<<endl;//
	cout<<"-                       *                        * *                          -"<<endl;//
	cout<<"-                      *                        *  *                          -"<<endl;//
	cout<<"-                     **************************   *                          -"<<endl;//
	cout<<"-                     *                        *  *                           -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                              咔嚓。                                 *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                             **************************                      -"<<endl;//
	cout<<"-                            *                        * *                     -"<<endl;//
	cout<<"-                           *                        *  *                     -"<<endl;//
	cout<<"-                          *                        *  *                      -"<<endl;//
	cout<<"-                         *************************** *                       -"<<endl;//
	cout<<"-                        *                        **                          -"<<endl;//
	cout<<"-                       *                        * *                          -"<<endl;//
	cout<<"-                      *                        *  *                          -"<<endl;//
	cout<<"-                     **************************   *                          -"<<endl;//
	cout<<"-                     *                        *  *                           -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                              。。。                                 *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                ___                          -"<<endl;//
	cout<<"-                                               |   |                         -"<<endl;//
	cout<<"-                 ******************************|   |                         -"<<endl;//
	cout<<"-               **                              |\\|/|_*****_#                 -"<<endl;//
	cout<<"-             **--------------------------------|-+- _*   *_##                -"<<endl;// 
	cout<<"-               **                              |/|\\| ***** #                 -"<<endl;//
	cout<<"-                 ******************************|   |  * *                    -"<<endl;//
	cout<<"-                          * *                  |___|  * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                  你从宝箱里扛出来一把沉重的大剑                     *   -"<<endl;//
	cout<<"-   *               大剑剑柄的上方镶嵌的一枚海蓝色的宝石                  *   -"<<endl;//
	cout<<"-   *                  宝石在昏暗的房间中发出奇妙的光芒                   *   -"<<endl;//
	cout<<"-   *                          驱散着这里的黑暗                           *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                ___                          -"<<endl;//
	cout<<"-                                               |   |                         -"<<endl;//
	cout<<"-                 ******************************|   |                         -"<<endl;//
	cout<<"-               **  ~       -   ~      -    ~   |   |_*****_#                 -"<<endl;//
	cout<<"-             **--------------------------------|[+] _*   *_##                -"<<endl;// 
	cout<<"-               **     -  ~   -       ~   -   - |   | ***** #                 -"<<endl;//
	cout<<"-                 ******************************|   |  * *                    -"<<endl;//
	cout<<"-                          * *                  |___|  * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                       剑身上刻着远古的花纹                          *   -"<<endl;//
	cout<<"-   *                          虽然它锈迹斑斑                             *   -"<<endl;//
	cout<<"-   *                   但你知道，这不是一把普通的剑                      *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                   ***                                       -"<<endl;//
	cout<<"-                                  *   *  =                                   -"<<endl;//
	cout<<"-                                   **====                                    -"<<endl;//
	cout<<"-                                    */ ====                                  -"<<endl;//
	cout<<"-                                  **/   /                                    -"<<endl;// 
	cout<<"-                                 * /   /                                     -"<<endl;//
	cout<<"-                                * /   /                                      -"<<endl;//
	cout<<"-                                  |__/                                       -"<<endl;//
	cout<<"-                                  *  *                                       -"<<endl;//
	cout<<"-                                 *    *                                      -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                            你将它收好                               *   -"<<endl;//
	cout<<"-   *                            固定在背上                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                  =                          =               -"<<endl;//
	cout<<"-      =                  =            =               =                      -"<<endl;//
	cout<<"-                                                                     =       -"<<endl;//
	cout<<"-           =         =                      =                    =           -"<<endl;//
	cout<<"-                                 =                                 =         -"<<endl;//
	cout<<"-               =                                 ==                          -"<<endl;//
	cout<<"-         =       =                                       =                   -"<<endl;//
	cout<<"-                         =         =      =                                  -"<<endl;//
	cout<<"-           =                                 =             =         =       -"<<endl;//
	cout<<"-                  =          ==                                              -"<<endl;//
	cout<<"-            =                     =                   = =                    -"<<endl;//
	cout<<"-                 =          =               =        =           =           -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *            \"咕咚咕咚..\"突然，上方的岩石穿了不祥的声音               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-   ====================                             ================         -"<<endl;//
	cout<<"-    =========     =======   ==================        =      =               -"<<endl;//
	cout<<"-      =                  =            = ===============     ==               -"<<endl;//
	cout<<"-            =============         =====                              =       -"<<endl;//
	cout<<"-           =         =                      ===========          =           -"<<endl;//
	cout<<"-                                 =======                           =         -"<<endl;//
	cout<<"-  =====       =========     ===                  ==      =========           -"<<endl;//
	cout<<"-         =       =           ===                   ==========                -"<<endl;//
	cout<<"-            ===========  =         =============                             -"<<endl;//
	cout<<"-           =       ===    ======             =  ========   =         =       -"<<endl;//
	cout<<"-        ===========          ==                                              -"<<endl;//
	cout<<"-      ==    =           ===========          ========== =                    -"<<endl;//
	cout<<"-  =           =  =          =               =        =============           -"<<endl;//
	cout<<"-          ===                        ==========          =============       -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                   \"咚咚咚咚咚！\"岩石落了下来                        *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-   ====================                             ================         -"<<endl;//
	cout<<"-    =========     =======   ==================        =      =               -"<<endl;//
	cout<<"-      =         =======================================     ==========       -"<<endl;//
	cout<<"-            ====================================          ============       -"<<endl;//
	cout<<"-      ==========================            ===========     =============    -"<<endl;//
	cout<<"-                         ===============              ===============        -"<<endl;//
	cout<<"-  =============================        ================  =========           -"<<endl;//
	cout<<"-         ===============     ====================================            -"<<endl;//
	cout<<"-            ===========  =======================                             -"<<endl;//
	cout<<"-       ===============================       =  ========   ============      -"<<endl;//
	cout<<"-    ===============       =====    =================================         -"<<endl;//
	cout<<"-      =======       ===============   ================= =                    -"<<endl;//
	cout<<"-  ===========================================        =============           -"<<endl;//
	cout<<"-          ===        =============  ==========          =============        -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *            虽然你已经感到不妙，但来不及了，你昏了过去。             *   -"<<endl;//
	cout<<"-   *                晕倒之前 你用尽最后的力量抱紧了宝剑                  *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                             。。。。                                *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	}

void CG_1_Maze(){
	
	char ch;
	while(ch!='1' && ch!='2' && ch!='l' && ch!='r'){
		Maze_1_goto:
		//Maze-Start-1
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           ===================                               -"<<endl;//
		cout<<"-                           =                 =                               -"<<endl;//
		cout<<"-                           =-----------------=                               -"<<endl;//
		cout<<"-                           =                 =                               -"<<endl;//
		cout<<"-                           = <--         --> =                               -"<<endl;//
		cout<<"-                           = left      right =                               -"<<endl;//
		cout<<"-                           =                 =                               -"<<endl;//
		cout<<"-                           =-----------------=                               -"<<endl;//
		cout<<"-                           =- - - - - - - - -=                               -"<<endl;//
		cout<<"-                           =  -  -  -  -  -  =                               -"<<endl;//
		cout<<"-                           =-   -   -   -   -=                               -"<<endl;//
		cout<<"-                         =-    -    -    -    -=                             -"<<endl;//
		cout<<"-                       =-     -     -     -     -=                           -"<<endl;//
		cout<<"-                     =-      -      -      -      -=                         -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  <Isaac>勇者:                                                       *   -"<<endl;//
		cout<<"-   *      这边分成2条路了，那我该往哪里走啊？                            *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *  1.left    2.right     请输入1或2                                   *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		ch=_getch();
		}
	//Maze-Start-2
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                           ===================                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =-----------------=                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =-----------------=                               -"<<endl;//
	cout<<"-                           =- - - - - - - - -=                               -"<<endl;//
	cout<<"-                           =  -  -  -  -  -  =                               -"<<endl;//
	cout<<"-                           =-   -   -   -   -=                               -"<<endl;//
	cout<<"-                         =-    -    -    -    -=                             -"<<endl;//
	cout<<"-                       =-     -     -     -     -=                           -"<<endl;//
	cout<<"-                     =-      -      -      -      -=                         -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	Sleep(1000);
	if(ch=='1' || ch=='l'){
		//Maze-Left-1
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           =====                                             -"<<endl;//
		cout<<"-                           =    ====                                         -"<<endl;//
		cout<<"-                           =      = ====                                     -"<<endl;//
		cout<<"-                           =      =     =====                                -"<<endl;//
		cout<<"-                           =      =         =                                -"<<endl;//
		cout<<"-                           =     -          =                                -"<<endl;//
		cout<<"-                           =    -     -     =                                -"<<endl;//
		cout<<"-                           =   -     -     -=                                -"<<endl;//
		cout<<"-                           =  -     -     - =                                -"<<endl;//
		cout<<"-                           = -     -     -  =                                -"<<endl;//
		cout<<"-                           =-     -     -   =                                -"<<endl;//
		cout<<"-                          =-     -     -    =                                -"<<endl;//
		cout<<"-                         =-     -     -     =                                -"<<endl;//
		cout<<"-                        =-     -     -     -=                                -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		//Maze-Left-2
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           ==================                                -"<<endl;//
		cout<<"-                         = =                =                                -"<<endl;//
		cout<<"-                       =   =                =                                -"<<endl;//
		cout<<"-                     =     =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =-    -    -    -=                                -"<<endl;//
		cout<<"-                   =     = -    -     -    -                                 -"<<endl;//
		cout<<"-                   =   =  -    -      -    -                                 -"<<endl;//
		cout<<"-                   = =   -    -       -    -                                 -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		//Maze-Left-3
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
		cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
		cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
		cout<<"-                      =      - - - - -      =                                -"<<endl;//
		cout<<"-                      =       =-----=       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =-----=       =                                -"<<endl;//
		cout<<"-                      =      - - - - -      =                                -"<<endl;//
		cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
		cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
		cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(ch=='2' || ch=='r'){
		//Maze-Right-1
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                       ======                                -"<<endl;//
		cout<<"-                                    ====    =                                -"<<endl;//
		cout<<"-                                ==== =      =                                -"<<endl;//
		cout<<"-                           =====     =      =                                -"<<endl;//
		cout<<"-                           =         =      =                                -"<<endl;//
		cout<<"-                           =          -     =                                -"<<endl;//
		cout<<"-                           =     -     -    =                                -"<<endl;//
		cout<<"-                           =-     -     -   =                                -"<<endl;//
		cout<<"-                           = -     -     -  =                                -"<<endl;//
		cout<<"-                           =  -     -     - =                                -"<<endl;//
		cout<<"-                           =   -     -     -=                                -"<<endl;//
		cout<<"-                           =    -     -     -=                               -"<<endl;//
		cout<<"-                           =     -     -     -=                              -"<<endl;//
		cout<<"-                           =-     -     -     -=                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		//Maze-Right-2
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           ==================                                -"<<endl;//
		cout<<"-                           =                = =                              -"<<endl;//
		cout<<"-                           =                =   =                            -"<<endl;//
		cout<<"-                           =                =     =                          -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =-    -    -    -=       =                        -"<<endl;//
		cout<<"-                            -    -     -    - =     =                        -"<<endl;//
		cout<<"-                            -    -      -    -  =   =                        -"<<endl;//
		cout<<"-                            -    -       -    -   = =                        -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		
		goto Maze_1_goto;
		
		}
	
	}

void CG_2(){
	//第二章 
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              -                                                            -                                              -"<<endl;//
	cout<<"-                                                                                                                                           -              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                      第一章                                                            *********                                                         -"<<endl;//
	cout<<"-                                         -                    **          ****        *************                                                       -"<<endl;//
	cout<<"-                                                                     ****      **    ***************                                                      -"<<endl;//
	cout<<"-                                   新生                *                   **    *********     *****                         -                            -"<<endl;//
	cout<<"-                                                                    ** *     ***********          **                                                      -"<<endl;//
	cout<<"-                                                                          *************            *                                        *******       -"<<endl;//
	cout<<"-                   -       --      -   *      **                ***    ** ***************        **                                        *       *      -"<<endl;//
	cout<<"-            -      -                                               ***    ***********    ********                                          *       *      -"<<endl;//
	cout<<"-              -                                         **            ***     ****         *  *                                            *       *      -"<<endl;//
	cout<<"-                                                                   ***                    ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        *  *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  **    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                      *  * *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  *__   *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        * |  |  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *|__|  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                   * *    *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                                   * * *   *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                          * *        *     *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                         * * *       *********************-"<<endl;//
	cout<<"-                                                                                          *    *                           *    *****                     -"<<endl;//
	cout<<"-                                                                                          *    *                           *****                          -"<<endl;//
	cout<<"-                                                                                          *    *                      *****                               -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_1
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        我突然从沙发上惊醒起，大口的喘着气。。。          -"<<endl;//5,117 
	cout<<"-                                                                                                        离恶魔二次入侵凯撒大陆，已经整整过去了3年。       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        啊！                                                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *    <Eden> : <伊甸>                                                                                                                            *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_2
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        3年前的今天，也是噩梦开始的地方。                 -"<<endl;//
	cout<<"-                                                                                                        父亲在探险时，洞穴崩塌，不幸身亡，                -"<<endl;//
	cout<<"-                                                                                                        然后恶魔就发动了入侵。。                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        。。。                                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_3
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        然后母亲为了保护年幼的我，也被恶魔撕成了2半。     -"<<endl;//
	cout<<"-                                                                                                        那个场景在我心中变成了梦魇，                      -"<<endl;//
	cout<<"-                                                                                                        每当我熟睡时，他就会缠上我。                      -"<<endl;//
	cout<<"-                                                                                                        我发誓一定要杀光恶魔，为母亲报仇！                -"<<endl;//
	cout<<"-                                                                                                        但很无奈，不知所措。。。                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        (哭)                                                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_4
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        “叩叩叩”突然，门外传来了敲门声。                -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        ！                                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_5
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       我立刻站起身，小跑的去开门。                       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        来了来了。                                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_6
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       门外站着一个微笑的大汉，抱着一个巨大的包裹。       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Reno大叔:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        啊，这是学院寄给你的包裹。                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *    <Reno> : <雷诺>                                                                                                                            *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_7
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       他是帝国皇家学院的教练，                           -"<<endl;//
	cout<<"-                                                                                                       小时候他和父亲一起回来过。                         -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        哦，谢谢。                                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_8
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       因为生前父亲和他经常在家喝酒，                     -"<<endl;//
	cout<<"-                                                                                                       所以我也和他很熟。                                 -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Reno大叔:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        又梦到了？别那么沮丧，里面有你想要的东西。                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_9
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       我一直想进入帝国皇家学院进行学习。                 -"<<endl;//
	cout<<"-                                                                                                       他也知道，难道他弄到名额了？                       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        什么！？                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_10
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       Reno大叔猜到了我的反应，笑了一下。                 -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                          *   *   *                                                                       -"<<endl;//
	cout<<"-                                                                         *    *       *                                                                   -"<<endl;//
	cout<<"-                                                                        *         *       *                                                               -"<<endl;//
	cout<<"-                                                                       *              *   *   *                                                           -"<<endl;//
	cout<<"-                                                                      *              *       *                                                            -"<<endl;//
	cout<<"-                                                                     *              *       *                                                             -"<<endl;//
	cout<<"-                                                                    *    =         *       *                                                              -"<<endl;//
	cout<<"-                                                                   *         =    *       *                                                               -"<<endl;//
	cout<<"-                                                                  *              *   =   *                                                                -"<<endl;//
	cout<<"-                                                                 *              *       *                                                                 -"<<endl;//
	cout<<"-                                                                *    =         *       *                                                                  -"<<endl;//
	cout<<"-                                                               *         =    *       *                                                                   -"<<endl;//
	cout<<"-                                                              *              *   =   *                                                                    -"<<endl;//
	cout<<"-                                                             *              *       *                                                                     -"<<endl;//
	cout<<"-                                                            *    =         *       *                                                                      -"<<endl;//
	cout<<"-                                                           *          =   *       *                                                                       -"<<endl;//
	cout<<"-                                                          *              *   =   *                                                                        -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Reno大叔:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        给你吧，自己好好利用。                                                                                                                 *     -"<<endl;//
	cout<<"-    *        到时候你可要自己从Ken City到Phiya。                                                                                                    *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_10
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       我迫不及待地接过了包裹，轻轻的放到沙发上。         -"<<endl;//
	cout<<"-                                                                                                       拿出剪刀，拆开了包裹。                             -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        嗯！谢谢Reno大叔。                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_11
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                        /\\                                                                                -"<<endl;//
	cout<<"-                                                         ***************||                                                                                -"<<endl;//
	cout<<"-                                                       *----------------||===]    ____                                                                    -"<<endl;//
	cout<<"-                                                         ***************||       |帝国|                                                                   -"<<endl;//
	cout<<"-                                                                        \\/       |____|                                                                   -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                          里面装着一把铁剑                                                                     *     -"<<endl;//
	cout<<"-    *                                                     和一封帝国皇家学院的邀请信                                                                *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Big_Map//CG_2_12
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//1
	cout<<"-                                                                                                                                                          -"<<endl;//2
	cout<<"-                                                                                                                                                          -"<<endl;//3
	cout<<"-                                                                                                                                                          -"<<endl;//5
	cout<<"-                                                          于是，我便踏上了前往[Phiya]的旅程。                                                             -"<<endl;//4
	cout<<"-                                                             我先拿出地图，把路线规划好。                                                                 -"<<endl;//6
	cout<<"-                                                                                                                                                          -"<<endl;//7
	cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;// 
	cout<<"-                                      -                                       *                                     -                                     -"<<endl;//
	cout<<"-                                      -  <咸鱼の王的故事> 凯撒大陆地图       *                                      -                                     -"<<endl;//
	cout<<"-                                      -                                    **                                       -                                     -"<<endl;//
	cout<<"-                                      -    ~                          *****                                         -                                     -"<<endl;//
	cout<<"-                                      -        ~             ~   *****                                              -                                     -"<<endl;// 
	cout<<"-                                      -   ~            ~        *     #Godigun       @Phiya                         -                                     -"<<endl;//
	cout<<"-                                      -            ~           *                     ..                             -                                     -"<<endl;//
	cout<<"-                                      -        *               *                     .                              -                                     -"<<endl;//
	cout<<"-                                      -  ~  * *         ~      ********   #Sealidge...       / / / / /              -                                     -"<<endl;//
	cout<<"-                                      -      ***      ~        *   ~   *   .            / / / / / / / /             -                                     -"<<endl;//
	cout<<"-                                      -       * *     ~       * ~    ~  *  .         / / / / / / / / / /            -                                     -"<<endl;//
	cout<<"-                                      -      *                 ~    ~ ~ *  .        / / / / / / / / / / /           -                                     -"<<endl;//
	cout<<"-                                      -  ~          ~      ~            *  .         / / / / / / / / / /            -                                     -"<<endl;//
	cout<<"-                                      -      ~~         ~      *  ~  ~  *  .          / / / / / / / /               -                                     -"<<endl;//
	cout<<"-                                      -   ~                    ***     *   .                   / /                  -                                     -"<<endl;//
	cout<<"-                                      -        ~     ~         * ******    .                    /   #Wild City      -                                     -"<<endl;//
	cout<<"-                                      -                   ~     *     #Me City                                      -                                     -"<<endl;//
	cout<<"-                                      -  @ 首都       ~          **        .                                        -                                     -"<<endl;//
	cout<<"-                                      -  # 城市    ~        ~      ******  ............#Ken City                    -                                     -"<<endl;//
	cout<<"-                                      -  ~ 海           ~      ~         *                                          -                                     -"<<endl;//
	cout<<"-                                      -  / 沙漠  ~                        *                                         -                                     -"<<endl;//
	cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//0
	cout<<"-                                                                                                                                                          -"<<endl;//1
	cout<<"-                                                                                                                                                          -"<<endl;//2
	cout<<"-                                                                                                                                                          -"<<endl;//3
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//4
	PAUSE;
	//CG_2_13
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                      背包.                                                                                               -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                    *********                                                                                             -"<<endl;//
	cout<<"-                                                   *=       =*                                                                                            -"<<endl;//
	cout<<"-                                             ***** *  *****  * *********************************                                                          -"<<endl;//
	cout<<"-                                             *     * *_____* *                                **                                                          -"<<endl;//
	cout<<"-                                             **    * *_____* *                         匕首  * *                                                          -"<<endl;//
	cout<<"-                                             **    * *_____* *   剑(外面有剑袋) /\\      /\\   * *                                                          -"<<endl;//
	cout<<"-                                             * *   * *_____* *   ***************||      ||  *  *                                                          -"<<endl;//
	cout<<"-                                             * *   *=       =*  *               ||===]  ==  *  *                                                          -"<<endl;//
	cout<<"-                                             *  *   *********    ***************||      =  *   *                                                          -"<<endl;//
	cout<<"-                                             *  *                               \\/    O=   *   *                                                          -"<<endl;//
	cout<<"-                                             *  ********************************************   *                                                          -"<<endl;//
	cout<<"-                                             *   ******************************************    *                                                          -"<<endl;//
	cout<<"-                                             *   *                                        *    *                                                          -"<<endl;//
	cout<<"-                                             *   *                                        *    *                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                     接着我花了整天准备我的装备，                                                              *     -"<<endl;//
	cout<<"-    *                                                          晚上兴奋的睡不着。                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_14
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                      -  -  -                                                                             -"<<endl;//
	cout<<"-                                                                    -         -                                                                           -"<<endl;//
	cout<<"-                                                                   -           -                                                                          -"<<endl;//
	cout<<"-                                                                  -             -                                                                         -"<<endl;//
	cout<<"-                                                                  -             -                                                                         -"<<endl;//
	cout<<"-                                                                   -           -                                                                          -"<<endl;//
	cout<<"-                                                                    -         -                                                                           -"<<endl;//
	cout<<"-                                                                     -       -                                                                            -"<<endl;//
	cout<<"-                                                                      -     -                                                                             -"<<endl;//
	cout<<"-                                                                       - | -                                                                              -"<<endl;//
	cout<<"-                                                                        -+-                                                                               -"<<endl;//
	cout<<"-                                                                         |                                                                                -"<<endl;//
	cout<<"-                                                                         |                                                                                -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        哦，对了。我还要带上母亲留下的项链，听说它可以看到危险。                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *    <可以查看怪物状态>                                                                                                                         *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_15
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       第二天早上，我走到后院，那里是母亲的墓。           -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        。。。                                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_16
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              -                                                            -                                              -"<<endl;//
	cout<<"-                                                                                                                                           -              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                        *********                                                         -"<<endl;//
	cout<<"-                                         -                    **          ****        *************                                                       -"<<endl;//
	cout<<"-                                                                     ****      **    ***************                                                      -"<<endl;//
	cout<<"-                                                       *                   **    *********     *****                         -                            -"<<endl;//
	cout<<"-                                                                    ** *     ***********          **                                                      -"<<endl;//
	cout<<"-                                                                          *************            *                                        *******       -"<<endl;//
	cout<<"-                   -       --      -   *      **                ***    ** ***************        **                                        *       *      -"<<endl;//
	cout<<"-            -      -                                               ***    ***********    ********                                          *       *      -"<<endl;//
	cout<<"-              -                                         **            ***     ****         *  *                                            *       *      -"<<endl;//
	cout<<"-                                                                   ***                    ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        *  *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  **    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                      *  * *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  *__   *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        * |  |  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *|__|  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-    ******************************************************************                   *      *                                          *       *      -"<<endl;//
	cout<<"-    *    Eden:                                                       *                   ********                                   * *    *       *      -"<<endl;//
	cout<<"-    *        母亲。                                                  *                    *    *                                   * * *   *       *      -"<<endl;//
	cout<<"-    *        我要离开这里了，希望你接下来也要过得开心。              *                    *    *                          * *        *     *       *      -"<<endl;//
	cout<<"-    *        保佑我吧！                                              *                    *    *                         * * *       *********************-"<<endl;//
	cout<<"-    *                                                                *                    *    *                           *    *****                     -"<<endl;//
	cout<<"-    ******************************************************************                    *    *                           *****                          -"<<endl;//
	cout<<"-                                                                                          *    *                      *****                               -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_17
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       随着一声脆响，我关上了门，                         -"<<endl;//
	cout<<"-                                                                                                       离开了这里，去远在北方的学院。                     -"<<endl;//
	cout<<"-                                                                                                       为我的目标而奋斗！                                 -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_18 
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       毕竟是第一次离开[Ken City]，                       -"<<endl;//
	cout<<"-                                                                                                       我的心情还是十分愉快的。                           -"<<endl;//
	cout<<"-                                                                                                       于是，我迈着轻快的脚步，                           -"<<endl;//
	cout<<"-                                                                                                       走进了[Ken City]东边的[Iron Forest]。              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                       ***       ***                                                                      -"<<endl;//
	cout<<"-                                                                     *******   *******                                                                    -"<<endl;//
	cout<<"-                                                                    ********* *********                                                                   -"<<endl;//
	cout<<"-                                                                    ********* *********                                                                   -"<<endl;//
	cout<<"-                                       ***         ***         ***      |         |      ***         ***         ***                                      -"<<endl;//
	cout<<"-                                     *******     *******     *******    |         |    *******     *******     *******                                    -"<<endl;//
	cout<<"-                                    *********   *********   *********   |         |   *********   *********   *********                                   -"<<endl;//
	cout<<"-                                    *********   *********   *********   |   * *   |   *********   *********   *********                                   -"<<endl;//
	cout<<"-                                        |           |           |       | *     * |       |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           |       *         *       |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           |     *             *     |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           |   *                 *   |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           | *                     * |           |           |                                       -"<<endl;//
	cout<<"-                                                                *                         *                                                               -"<<endl;//
	cout<<"-                                                              *                             *                                                             -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_19
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       随着我的深入，森林越来越密集。                     -"<<endl;//
	cout<<"-                                                                                                       森林越来越密集，                                   -"<<endl;//
	cout<<"-                   ***         ***         ***         ***         ***               ***         ***   阳光越来越稀疏。  ***         ***                  -"<<endl;//
	cout<<"-                 *******     *******     *******     *******     *******           *******     *******     *******     *******     *******                -"<<endl;//
	cout<<"-                *********   *********   *********   *********   *********         *********   *********   *********   *********   *********               -"<<endl;//
	cout<<"-                *********   *********   *********   *********   *********         *********   *********   *********   *********   *********               -"<<endl;//
	cout<<"-           ***      |  ***      |  ***      |  ***      |  ***      |  ***       ***  |      ***  |      ***  |      ***  |      ***  |      ***          -"<<endl;//
	cout<<"-         *******    |*******    |*******    |*******    |*******    |*******   *******|    *******|    *******|    *******|    *******|    *******        -"<<endl;//
	cout<<"-        *********   *********   *********   *********   *********   ********* *********   *********   *********   *********   *********   *********       -"<<endl;//
	cout<<"-        *********   *********   *********   *********   *********   ********* *********   *********   *********   *********   *********   *********       -"<<endl;//
	cout<<"-            |  ***  |   |  ***  |   |  ***  |   |  ***  |   |  ***  |   |         |   |  ***  |   |  ***  |   |  ***  |   |  ***  |      ***  |           -"<<endl;//
	cout<<"-            |*******    |*******    |*******    |*******    |*******    |         |    *******|    *******|    *******|    *******|    *******|           -"<<endl;//
	cout<<"-            *********   *********   *********   *********   *********   |         |   *********   *********   *********   *********   *********           -"<<endl;//
	cout<<"-            *********   *********   *********   *********   *********   |   * *   |   *********   *********   *********   *********   *********           -"<<endl;//
	cout<<"-            |   |       |   |       |   |       |   |       |   |       | *     * |       |   |       |   |       |   |       |   |       |   |           -"<<endl;//
	cout<<"-                |           |           |           |           |       *         *       |           |           |           |           |               -"<<endl;//
	cout<<"-                |           |           |           |           |     *             *     |           |           |           |           |               -"<<endl;//
	cout<<"-                |           |           |           |           |   *                 *   |           |           |           |           |               -"<<endl;//
	cout<<"-                |           |           |           |           | *                     * |           |           |           |           |               -"<<endl;//
	cout<<"-                                                                *                         *                                                               -"<<endl;//
	cout<<"-                                                              *                             *                                                             -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
	cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
	cout<<"-                                                    ***************************************************                                                   -"<<endl;//
	cout<<"-                                                  *******************************************************                                                 -"<<endl;//
	cout<<"-                                                  *******************************************************                                                 -"<<endl;//
	cout<<"-                                                **********************************************************                                                -"<<endl;//
	cout<<"-                                            ******************************************************************                                            -"<<endl;//
	cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     |||||***************|||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     ||||| <-         -> |||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
	cout<<"-                                                        *                                         *                                                       -"<<endl;//
	cout<<"-                                                      *                                             *                                                     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        这里怎么有岔路？                                                                                                                       *     -"<<endl;//
	cout<<"-    *        那我要往哪里走阿。                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	CG_2_Maze();
	
	PAUSE;
	}

void CG_2_Maze(){
	char in;
	
	int x=3,                       // 1 -> 分叉( 2 ) -> x-1
		y=3;                       // 2 -> 三叉( 3 )
	
	int Maze_Map[12][12]={    // 3 -> 死路 
		0, 0,0,0,0,0, 0,0,0,0,0, 0,// 4 -> 提示 1 死路 
		                           // 5 -> 提示 2 狼窝 
		0, 0,0,0,0,0, 0,3,0,0,0, 0,// 6 -> 宝藏 1  
		0, 0,0,0,0,0, 0,0,0,0,0, 0,// 7 -> 宝藏 2 
		0, 0,0,1,0,3, 0,0,0,0,0, 0,// * -> monster 
		0, 0,1,0,1,0, 6,0,0,0,0, 0,// * -> Boss
		0, 3,0,3,0,2, 1,1,3,0,0, 0,// 9 -> 终点 
		
		0, 0,0,0,3,1, 2,3,0,0,0, 0,
		0, 0,0,0,0,4, 5,3,0,0,3, 0,
		0, 0,0,0,7,1, 0,0,0,9,2, 0,
		0, 0,0,0,0,3, 0,0,0,0,3, 0,
		0, 0,0,0,0,0, 3,0,1,3,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x1_to[12][12]={//分叉 or 三叉 左路 x
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,//1
		0, 0,0,0,0,0, 0,0,0,0,0, 0,//2
		0, 0,0,4,0,0, 0,0,0,0,0, 0,//3
		0, 0,5,0,3,0, 0,0,0,0,0, 0,//4
		0, 0,0,0,0,5, 4,1,0,0,0, 0,//5
		
		0, 0,0,0,0,7, 6,0,0,0,0, 0,//6
		0, 0,0,0,0,8, 10,0,0,0,0, 0,//7
		0, 0,0,0,0,9, 0,0,0,0,9, 0,//8
		0, 0,0,0,0,0, 0,0,0,0,0, 0,//9
		0, 0,0,0,0,0, 0,0,8,0,0, 0,//10
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y1_to[12][12]={//分叉 or 三叉 左路 y
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,4,0,0, 0,0,0,0,0, 0,
		0, 0,3,0,5,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 6,7,0,0,0, 0,
		
		0, 0,0,0,0,5, 7,0,0,0,0, 0,
		0, 0,0,0,0,5, 8,0,0,0,0, 0,
		0, 0,0,0,0,5, 0,0,0,0,10, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,10,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x2_to[12][12]={//分叉 or 三叉 右路 x
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,4,0,0, 0,0,0,0,0, 0,
		0, 0,5,0,5,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 5,5,0,0,0, 0,
		
		0, 0,0,0,0,6, 7,0,0,0,0, 0,
		0, 0,0,0,0,0, 10,0,0,0,0, 0,
		0, 0,0,0,0,8, 0,0,0,0,7, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,10,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y2_to[12][12]={//分叉 or 三叉 右路 y
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,2,0,0, 0,0,0,0,10, 0,
		0, 0,1,0,5,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,5, 7,8,0,0,0, 0,
		
		0, 0,0,0,0,4, 6,0,0,0,0, 0,
		0, 0,0,0,0,0, 6,0,0,0,0, 0,
		0, 0,0,0,0,4, 0,0,0,0,10, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,9,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x3_to[12][12]={//三叉 中路 x
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 7,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,8, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y3_to[12][12]={//三叉 中路 y 
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 7,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,9, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x_return[12][12]={//返回 
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,5,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,4, 0,0,0,0,0, 0,
		0, 0,3,0,3,0, 5,0,0,0,0, 0,
		0, 4,0,4,0,4, 5,5,5,0,0, 0,
		
		0, 0,0,0,6,5, 5,6,0,0,0, 0,
		0, 0,0,0,0,6, 6,6,0,0,8, 0,
		0, 0,0,0,8,7, 0,0,0,8,10, 0,
		0, 0,0,0,0,8, 0,0,0,0,8, 0,
		0, 0,0,0,0,0, 7,0,10,10,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y_return[12][12]={//返回
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,7,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,4, 0,0,0,0,0, 0,
		0, 0,3,0,3,0, 6,0,0,0,0, 0,
		0, 2,0,2,0,4, 5,6,7,0,0, 0,
		
		0, 0,0,0,5,5, 5,6,0,0,0, 0,
		0, 0,0,0,0,5, 6,6,0,0,10, 0,
		0, 0,0,0,5,5, 0,0,0,10,8, 0,
		0, 0,0,0,0,5, 0,0,0,0,10, 0,
		0, 0,0,0,0,0, 6,0,6,8,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		};
	bool wolf1=1,wolf2=1,wolf3=1,wolf4,wolfking=1;
	/*
	wolf1 -> x=3 y=5
	wolf2 -> x=8 y=4
	wolf3 -> x=7 y=10
	wolf4 -> x=9 y=10
	slime -> x=8 y=9
	*/
	
	while(1){
		in='0';	
		
		if( (x==3 && y==5 && wolf1)||(x==8 && y==4 && wolf2)||(x==7 && y==10 &&wolf3)||(x==9 && y==10 && wolf4) ){//Elf Hunter
			CG(16,0);
			Fight(2);
			if(Hero.hp<=0)
				return;
			CG(0,0);
			if(x==3)
				wolf1=0;
			if(x==8)
				wolf2=0;
			if(x==7)
				wolf3=0;
			if(x==9)
				wolf4=0;
			} 
		if( x==8 && y==9 && wolfking ){//Slime
			//CG(16,0);
			Fight(3);
			if(Hero.hp<=0)
				return;
			CG(0,0);
			} 
		
		switch(Maze_Map[x][y]){
			case 1 :{//分叉( 2 ) -> x-1
				while(in!=LEFT && in!=RIGHT && in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||***************|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     ||||| <-         -> |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                        A 往左走[Left]                                     D 往右走[Right]                                     *     -"<<endl;//
				cout<<"-    *                                                              S 返回上一步[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case LEFT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case RIGHT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x2_to[x][y];
						t2=Maze_y2_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						if(x==3 && y==3){
							CG(14,0);
							break;
							}
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0001");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						cout<<"Maze_x1_to[x][y]:"<<Maze_x1_to[x][y]<<endl<<"Maze_y1_to[x][y]:"<<Maze_y1_to[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 2 :{//三叉( 3 )
				while(in!=UP && in!=DOWN && in!=LEFT && in!=RIGHT){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||       ^       |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*****  |  *****|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     ||||| <-         -> |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                        A 往左走[Left]          W 往前走[Forward]          D 往右走[Right]                                     *     -"<<endl;//
				cout<<"-    *                                                              S 返回上一步[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case LEFT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case RIGHT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x2_to[x][y];
						t2=Maze_y2_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case UP:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x3_to[x][y];
						t2=Maze_y3_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0002");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 3 :{//死路( 0 )
				while(in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *         *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*             *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                              S 返回上一步[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0003");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 4 :{//提示 1 死路 
				while(in!=UP && in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*        ^        *|||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *          |          *  |   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *|   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
			 	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
			 	cout<<"-                                                        *                                         *                                                       -"<<endl;//
			 	cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                    W 向前走[Forward]     边上有个告示牌，写着:                                                *     -"<<endl;//
				cout<<"-    *                                                   S 返回上一步[Return]        前方是死路                                                      *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case UP:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0004");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 5 :{//提示 2 狼窝
				while(in!=UP && in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*        ^        *|||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *          |          *  |   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *|   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
			 	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
			 	cout<<"-                                                        *                                         *                                                       -"<<endl;//
			 	cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                    W 向前走[Forward]     边上有个告示牌，写着:                                                *     -"<<endl;//
				cout<<"-    *                                                   S 返回上一步[Return]        前方是狼窝                                                      *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case UP:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0005");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 6 :{//宝藏
				while(in!=DOWN){
				//.........
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *        箱子↑       *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                              S 返回上一步[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0006");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 7 :{//宝藏2
				while(in!=DOWN){
				//.........
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *        箱子↑       *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                              S 返回上一步[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0007");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 9 :{//终点 
				while(in!=UP && in!=DOWN){
				//CG_2_Boss();
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *        箱子↑       *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                W 通关！[Yeah!]                                                                *     -"<<endl;//
				cout<<"-    *                                                   S 不，我还想再探索一会。[森林内有隐藏宝藏。]                                                *     -"<<endl;// 
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case UP:{
						CG(13,0);
						return;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0009");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				
				break;
				}
			default:{
				check("0001","0002");
				cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
				PAUSE;
				break;
				}
			}
		//...
		}
	}


/*
taskkill /f /im StudentMain.exe
	//CG_2_6
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
		//P
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
*/
