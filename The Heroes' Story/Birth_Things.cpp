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

