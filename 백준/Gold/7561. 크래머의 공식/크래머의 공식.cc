#include <stdio.h>
#define ep 0.0005
#define lint long long
using namespace std;

lint n, detA, detA1, detA2, detA3;
lint a[4][4], b[4];
double x1, x2, x3;

lint det(int col){
  lint copyA[4][4];
  for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
          copyA[i][j] = a[i][j];
      }
  }
  for(int i = 1; i <= 3; i++){
    copyA[i][col] = b[i];
  }
  lint d = 0;
  d += copyA[1][1]*(copyA[2][2]*copyA[3][3]-copyA[2][3]*copyA[3][2]);
  d -= copyA[1][2]*(copyA[2][1]*copyA[3][3]-copyA[2][3]*copyA[3][1]);
  d += copyA[1][3]*(copyA[2][1]*copyA[3][2]-copyA[2][2]*copyA[3][1]);
  return d;
}

int main() {
  scanf("%lld", &n);
  while(n--){
    for(int i = 1; i <= 3; i++){
      for(int j = 1; j <= 3; j++){
        scanf("%lld", &a[i][j]);
      }
      scanf("%lld", &b[i]);
    }
    detA = det(0);
    detA1 = det(1);
    detA2 = det(2);
    detA3 = det(3);
    printf("%lld %lld %lld %lld\n", detA1, detA2, detA3, detA);
    if(!detA) printf("No unique solution\n\n");
    else{
      x1 = (double)detA1/detA; x2 = (double)detA2/detA; x3 = (double)detA3/detA;
      if(-ep < x1 && x1 < ep) x1 = 0;
      if(-ep < x2 && x2 < ep) x2 = 0;
      if(-ep < x3 && x3 < ep) x3 = 0;
      printf("Unique solution: %.3lf %.3lf %.3lf\n\n",x1,x2,x3);
    }
  }
}