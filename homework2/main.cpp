#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



int main(int argc, char** argv) {
  if(argc == 2){
      // есть один агрумент
      // в argv[1] содержится строка с первым агрументом (имя файла)
    //std::cout << "1st argument: "<< argv[1] << std::endl;
  }else{

  }
  
  // Остальной код
  ifstream file (argv[1]);
  float h;
  double x;
  double vx;
  double vy;
  double total = 0;
  float t=0;
  file >> h;
  file >> vx >> vy;
  double A[10005][3];
  A[0][1] = h;
  A[0][0] = 0;
  A[0][2] = 0;
  int n = 1;
  int k = 1;
  int max = 1;
  bool flag = false;
  bool mozhno = true;

  while (mozhno){ // Если мы уже столкнулись, значит, дальше того n не пролетим
      if (max == n)
    {
        file >> A[n][0] >> A[n][1];
        A[n][2] = n;
    }
    t = t + abs(x - A[n][0])/vx;
    x = A[n][0];
    h = A[0][1] + vy*t - (9.81*t*t)/2;

    //if (h > A[n][1]){}
    if (h < A[n][1]){
        total = A[n][2]-1;
        if (k == -1){
            total = total + 1;
            }
        k=-k;
    }

    n = n + k;
    if (n > max) max = n ;
    if (n < 2){
        bool flag = true;
        break;
    }
    if (h<=0) mozhno = false;
  }
  file.close();
  
    //Хитрость
  if (flag) total = 0;
            
  

  cout << total;
  return 0;
}
