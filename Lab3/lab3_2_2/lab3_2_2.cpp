
// lab3_2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    unsigned n, m, k, l;
    cout << "Введите через размеры (кол-во строк и столбцов), после каждого ввода делайте enter\n";
    cin >> m; // lines
    cin >> n; // columns
    cout << "Введите расположение элемента (номер строки и номре столбца, после каждого ввода делайте enter\n";
    cin >> k; // line
    cin >> l; // column
    unsigned num_line_el = k - 1, num_coolumn_el = l - 1;
    int max_the_max = 0;
    vector <vector<int>> mat(m, vector<int>(n));
    for (size_t num_line = 0; num_line < m; ++num_line)
        for (size_t num_column = 0; num_column < n; ++num_column)
        {
            int line_ = num_line - num_line_el;
            if (line_ < 0)
                line_ *= -1;
            int column_ = num_column - num_coolumn_el;
            if (column_ < 0)
                column_ *= -1;
            int the_max = 0;
            if (column_ >= line_)
                the_max = column_ + 1;
            if (column_ < line_)
                the_max = line_ + 1;
            mat[num_line][num_column] = the_max;
            if (max_the_max <= the_max)
                max_the_max = the_max;
        }
    string for_setw = to_string(max_the_max);
    for (size_t li = 0; li < m; ++li)
    {
        for (size_t co = 0; co < n; ++co)
            cout << setw(for_setw.length()) << mat[li][co] << " ";
        cout << endl;
    }
}

