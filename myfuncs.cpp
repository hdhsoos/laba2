    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std; 
    void score(int arr[], int n, int x) {
        int min{0}, max{0}, sum{0};
        for (int i{1}; i < n; i++) {
            if (arr[min] > arr[i]) min = i;
            if (arr[max] < arr[i]) max = i;
        }
        for (int i{0}; i < n; i++) {
            if (i != min and i != max) {
                sum = sum + arr[i];
            }
        }
        sum = sum / (n - 2);
        if (x == 1) {
            cout << sum << endl;
        }
        else {
            ofstream fout("2labaout.txt");
            fout << sum;
            fout.close();
        }
    }

    void fail() {
        int x;
        x = vivod();
        cout << "������, ����� ����." << endl;
        ifstream fin("2laba.txt");
        if (!fin.is_open())
            cout << "���� ���������� �������. �������� ������." << endl;
        else {
            int n{}, i{};
            fin >> n;
            int* arr{};
            arr = new int[n];
            for (i = 0; i < n; i++) {
                fin >> arr[i];
            }
            score(arr, n, x);
        }
    }

    int end_cons() {
        cout << "������ ��������� ���� �������� ������ ? �� � 1, ��� � 0." << endl;
        char a[256]{};
        cin >> a;
        if (a[0] == '1') {
            cons();
        }
        else {
            if (a[0] == '0') {
                cout << "������, �������� ������" << endl;
                return 0;
            }
            else {
                cout << "������ �����. ���������� �����." << endl;
                end_cons();
            }
        }
    }

    void cons() {
        int x;
        x = vivod();
        cout << "������, ������� ������. ��� ������ ������� ����� n." << endl;
        int n{};
        cin >> n;
        cout << "������ ������� ������." << endl;
        int i{};
        int* arr{};
        arr = new int[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        score(arr, n, x);
        end_cons();
    }

    int vivod() {
        setlocale(LC_ALL, "rus");
        cout << "�� ������ ������� ������ � ���� ��� �������?" << endl;
        cout << "0 - � ����, 1 - � �������." << endl;
        char a[256]{};
        cin >> a;
        if (a[0] == '1') {
            return 1;
        }
        else {
            if (a[0] == '0') {
                return 0;
            }
            else {
                cout << "������ �����. ���������� �����." << endl;
                vivod();
            }
        }
    }
