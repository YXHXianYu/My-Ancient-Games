#include<cstdlib>
#include<ctime>
int random_maker(unsigned a){
  srand(a);
  return rand();
  }

int seed_maker(){
  srand(time(0));
  return rand();
  }

int random(){
  return random_maker(seed_maker());
  }
//random(seed);
