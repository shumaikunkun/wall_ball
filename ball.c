#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#define M 40
#define N 23
int main() {
  int x=1, y=1;
  bool vec_tate=true, vec_yoko=true, kado=true;  //vec_tateがtrueの時に下に進む, vec_yokoがtrueの時に右に進む,角に当たったらkadoの値を反転
  for(;;) {
    for(int j=0; j<N; j++ ) {
      for(int i=0; i<M; i++ ){
        if(x==i && y==j){
          kado ? vec_tate^vec_yoko ? printf("1") : printf("0") : vec_tate^vec_yoko ? printf("0") : printf("1"); //角あったったら、１と０逆にする
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
    if((x==1&&y==1) || (x==M-2&&y==1) || (x==1&&y==N-2) || (x==M-2&&y==N-2)) kado=!kado;
    getchar();
    usleep( 300 );
  }
}
