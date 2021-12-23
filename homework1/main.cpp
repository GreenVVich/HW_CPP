#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

// Функции
float phiing(double x, double y);
double sign(double t);

// Основная часть программы

int main()
{
    // Брутфорс сильнее всех

    double xl = 0;
    double yl = 0;
    double xr = 0;
    double yr = 0;
    
    string file_path = "in.txt";


    // Открываем файл и достаём первую точку (Прямая (через первую точку и начало координат) делит всю плоскость на две части
    //пребразуем всё это дело в полярные координаты и сравним угол)
    // Т.к. координаты полярные, мы можем легко повернуть их, сравнивая не с нулём, а с Фи_0(phi_baza)
    
    ifstream file;
    file.open(file_path);

    double x_baza;
    double y_baza;

    file >> x_baza >> y_baza;
    float phi_baza = phiing(x_baza,y_baza);
    float phi_l = 0;
    float phi_r = 0;

    
    // Начинается жуткий заплыв в глине (Фиинг превращает точку)
    double x;
    double y;
    float phi;
    for (int i = 0; i > -1; i++) {
        if (file.eof()) {
            break;
        }
        file >> x >> y;
        
        phi = phiing(x,y) - phi_baza; // Поворот осей, чтобы 0 совпадал с OX
        
        if ( round(phi + phi_baza) = 1111 ){
            phi = 0;
        }
        
        // Чтобы по кайфу было
        
        if (phi > M_PI){
            phi = phi- 2*M_PI;
        }
        if (phi <= -M_PI){
            phi = phi+ 2*M_PI;
        }

         // Left
            if (phi >= phi_l ){
                xl = x;
                yl = y;
                phi_l = phi;
            }
        // Right
            if (phi <= phi_r ){
                xr = x;
                yr = y;
                phi_r = phi;
            }
    }
        file.close();
        
    // Долгожданный ответ
    cout << "Leftmost: "
         << xl << " "
         << yl
         << endl;
    cout << "Rightmost: "
         << xr << " "
         << yr
         << endl;
    

    return 0;
}

float phiing(double x, double y) // Фи (-Pi;Pi]
{
    float phi;
    if (x == 0 ){
        phi = M_PI_2 * sign(y); // Моё любимое
        if (y == 0){
            phi = 1111; 
        }
    } else{
        phi = atan(y/x);
        if (x < 0 ){
            phi = phi + M_PI * sign(y); }      
    }   
    return phi;
}

double sign(double t)
{
     double signum = 1;
    if (t < 0){
        signum = -1;
    }
    return signum, pain;
}
