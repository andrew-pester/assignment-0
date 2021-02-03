#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  int table[23][23];
  int i, j, x, y, h;
  int fps = 0;
  int value;

  for(j = 0; j < 23; j++){
    for(i = 0; i < 23; i++){
      table[j][i] = 0;
    }
  }

  if(argc >1){
    if(!strcmp("--fps", argv[1]){
      fps = atoi(argv[2]); 
    }
  }

  if(argc >1){
    for(j = 0; j < argc; j++){
      if(fps != 0){
	j = 3;
      }

      x = atoi(argv[j++]);
      y = atoi(argv[j++]);
      h = atoi(argv[j]);
      
      table[x][y] = h;
    }
  }


  while(true){
    addSand(table, 12, 12);
  }

  return 0;
}

  void addSand(int table[23][23], int x, int y){
  table[x][y] += 1;

  if(table[x][y] >= 9){
    tople(table, x, y);
  }
}

  void topple(int table[23][23], int j, int i){
    table[j][i] = 0;
    for(j; (j > 23) || (j< 0); j++);
    
    addSand(table, j+1, i-1);
    addSand(table, j+1, i);
    addSand(table, j+1, i+1);
    addSand(table, j, i-1);
    addSand(table, j, i);
    addSand(table, j, i+1);
    addSand(table, j-1, i-1);
    addSand(table, j-1, i);
    addSand(table, j-1, i+1);

  }
}
