#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int score(int arr[], int n) {
    int min = 0, max = 0, sum = 0;
    for (int i = 1; i < n; i++) {
        if (arr[min] > arr[i]) min = i;
        if (arr[max] < arr[i]) max = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != min and i != max) {
            sum = sum + arr[i];
        }
    }
    sum = sum / (n - 2);
    ofstream fout("2labaout.txt");
    cout << sum << endl;
    fout << sum;
    fout.close();
    return 0;
}

int fail() {
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("2laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        int n, i;
        fin >> n;
        int* arr;
        arr = new int[n];
        for (i = 0; i < n; i++) {
            fin >> arr[i];
        }
        score(arr, n);
    }
    return 0;
}

int cons() {
    cout << "Хорошо, вводите данные. Для начала введите число n." << endl;
    int n;
    cin >> n;
    cout << "Теперь введите оценки." << endl;
    int i;
    int *arr;
    arr = new int[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    score(arr, n);
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    int a;
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        cout << "Хорошо, завершаю работу." << endl;
    }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    int a;
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        fail();
    }
}