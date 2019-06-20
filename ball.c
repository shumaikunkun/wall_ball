#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#define M 40
#define N 23
int main() {
  int x=1, y=1;  //球の初期座標
  bool vec_tate=true, vec_yoko=true;  //vec_tateがtrueの時に下に進む, vec_yokoがtrueの時に右に進む
  for(;;) {
    for(int j=0; j<N; j++ ) {
      for(int i=0; i<M; i++ ){
        if(x==i && y==j){
          printf("0");
        }else if((i==0&&j==0) || (i==M-1&&j==0) || (i==0&&j==N-1) || (i==M-1&&j==N-1)){
          printf("+");
        }else if(i==0||i==M-1){
          printf("|");
        }else if(j==0||j==N-1){
          printf("-");
        }else{
          printf(" ");
        }
      }
      printf( "\n" );
    }
    vec_yoko ? x++ : x--;
    vec_tate ? y++ : y--;
    if(x==M-2 || x==1) vec_yoko=!vec_yoko;
    if(y==N-2 || y==1) vec_tate=!vec_tate;
    // if((x=vec_yoko?x+1:x-1)==M-2 || x==1) vec_yoko=!vec_yoko;
    // if((y=vec_tate?y+1:y-1)==N-2 || y==1) vec_tate=!vec_tate;
    getchar();
    //usleep( 300 );
  }
}
