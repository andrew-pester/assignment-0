#include <stdio.h>
#include <stdlib.h>
//makes table 23x23 with center at 11 11
int table[23][23];

int main(int argc, char *argv[]){

  
  int i, j, x, y, h;
  int fps = 0;
  int value;
//checks if fps switch is present
//argv[0] is program name argv[1] is first argument passed
  if(argc >1){
    if(!strcmp("--fps", argv[1])){
      fps = atoi(argv[2]); 
    }
  }
//finds first argument for the file
//argv[1] first argument if no fps if fps != 0 then argv[3] is first argument
//has to start at 1 otherwise tries to pass in program name
  if(argc >1){
    for(j = 1; j < argc; j++){
      if(fps != 0){
	      j = 3;
      }

      x = atoi(argv[j++]);
      y = atoi(argv[j++]);
      h = atoi(argv[j]);

      table[x][y] = h;
    }
  }

  while(1){
  //adding sand causes weird issue with sinks
    addSand(11, 11);
    for(int j=0; j<23;j++){
      for(int i =0; i<23; i++){
        if(table[j][i] == -1){
          printf("%3c", '#');
        }else{
          printf("%3d", table[j][i]);
        }
      }
    printf("\n");
    }
    printf("\n");
    if(fps !=0){
      usleep(1000000/fps);
    }
    
  }

  return 0;
}

void addSand(int x, int y){
  int tmp = table[x][y];
  //need to check if height is -1 for sinks something like if this x,y = -1 then do nothing
  if(tmp != -1){
  if(tmp < 8){
    table[x][y]++;
  }else{
    table[x][y] = tmp - 7;
    if(x > 0){
      addSand(x-1,y);
    }
    if(x<22){
      addSand(x+1,y);
    }
    if(y>0){
      addSand(x,y-1);
    }
    if(y<22){
      addSand(x,y+1);
    }
    if(x>0&& y>0){
      addSand(x-1,y-1);
    }
    if(x>0 && y<22){
      addSand(x-1,y+1);
    }
    if(x<22&&y>0){
      addSand(x+1,y-1);
    }
    if(x<22&&y<22){
      addSand(x+1,y+1);
    }
  }
  }
}
