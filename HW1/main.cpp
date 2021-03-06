#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

// Функции
float phiing(double x, double y);

// Основная часть программы

int main()
{
    // Месим глину

    double xl = 0;
    double yl = 0;
    double xr = 0;
    double yr = 0;
    
    string file_path = "in.txt";


    // Открываем файл и достаём первую точку (Прямая (через первую точку и начало координат) делит всю плоскость на две части, пребразуем всё это дело в полярные координаты и сравним угол)
    // Т.к. координаты полярные, мы можем легко повернуть их, сравнивая не с нулём, а с Фи_0(phi_baza)
    ifstream file;
    file.open(file_path);

    double x_baza;
    double y_baza;

    file >> x_baza;
    file >> y_baza;
    float phi_baza = phiing(x_baza,y_baza);
    float phi_l = phi_baza;
    float phi_r = phi_baza;

    
    // Начинается жуткий заплыв в глине (Фиинг превращает точку)
    double x;
    double y;
    float phi;
    for (int i = 0; i > -1; i++) {
        if (file.eof()) {
            break;
        }
        file >> x;
        file >> y;
        phi = phiing(x,y) + phi_baza; 

                // Мясо

        if (phi > phi_baza){ // Left
            if (phi >= phi_l ){
                xl = x;
                yl = y;
                phi_l = phi;
            }
        } else {
            if (phi <= phi_l ){
                xr = x;
                yr = y;
                phi_r = phi;
        }
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
    

    return 228;
}

float phiing(double x, double y)
{
    float phi;
    if (x == 0 ){
        phi = y *M_PI_2 / abs(y); // Моё любимое
    } else{
        phi = atan(y/x);
        if (x < 0 ){
            phi = phi + M_PI * y / abs(y); }      
    }   
    return phi;
}