// lab7_sem2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{

    fstream in, out;

    if (argc > 1) {
        for (int i = 0; i < argc; i++)
        {
            if ((!strcmp(argv[i], "-I")) && (i + 1 < argc)) {
                in.open(argv[i + 1], ios_base::in);
            }
            if ((!strcmp(argv[i], "-O")) && (i + 1 < argc)) {
                out.open(argv[i + 1], ios_base::out);
            }
        }
    }
    else {
        string in_file, out_file;
        cout << "Enter input file name: " << endl;
        cin >> in_file;
        in.open(in_file, ios_base::in);

        cout << "Enter out file name: " << endl;
        cin >> out_file;
        out.open(out_file, ios_base::out | ios_base::app);
    }
    cout << "\n\n\n";

    if (!in.is_open() && !out.is_open()){

        cout << "File opening error!\n";
        
        exit(1);
    }

    string line;
    while (getline(in, line))
    {
        for (size_t i = 0; i < line.length(); i++)
        {
            if ((line[i] == ' ' || line[i] == '\t' || line[i] == '\n') && i < line.length() - 1) 
            {
                if (line.at(i+1) == ' ' || line.at(i+1) == '\t' || line.at(i+1) == '\n')
                {
                    line.erase(i, 1);
                    i--;
                }
            }
        }
        cout << line << endl;
        out << line << endl;
    }
    in.close();
    out.close();

    return 0x0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
