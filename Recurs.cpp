#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

double sinus(double val, int count)   ;

double SQRT(int count)  ;

int main()
{   
    setlocale(LC_ALL, "Russian");   
    int value, cnt;     
    cout << "Enter the value of the argument and their number:" << endl;
    cin >> value >> cnt;
    cout << "Sinus\t" << sinus(value, cnt) << endl;
    cout << "Sqrt\t" << SQRT(cnt) << endl;
    return 0;   
}

double sinus(double x, int count) {
    if (count == 1)
        return sin(x);
    else
        return sin(x / count) + sinus(x, count - 1);
}

double SQRT(int count) {
    if (count > 99 || count < 3)
        return 0;
    else 
        return sqrt(count + SQRT(count - 3));
}
