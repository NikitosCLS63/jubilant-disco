// Potoki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


//
//void DoWork() {
//
//
//
//    for (int i = 0; i < 10; i++) {
//
//        cout << "ID potoka v DoWork" << this_thread::get_id() << endl;
//
//        this_thread::sleep_for(chrono::milliseconds(500));
//
//
//    }
//
//
//
//
//}

//int main()
//{   
//   /* setlocale(LC_ALL, "ru");
//
//    thread thread1(DoWork);
//
//    for (int i = 0; i < 10; i++) {
//
//        cout << "ID potoka v main" << this_thread::get_id() << endl;
//
//        this_thread::sleep_for(chrono::milliseconds(200));
//
//
//    }
//
//    thread1.join();
//
//
//*/
//
//}
using namespace std;


class MergeSort {
public:
    void Sort(vector<int>& rar) {
        if (rar.size() <= 1) {
            return;
        }

        int var = rar.size() / 2;

        vector<int> levo(rar.begin(), rar.begin() + var);
        vector<int> pravo(rar.begin() + var, rar.end());

        Sort(levo);
        Sort(pravo);
        Merge(rar, levo, pravo);
    }

private:
    void Merge(vector<int>& rar, const vector<int>& left, const vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                rar[k++] = left[i++];
            }
            else {
                rar[k++] = right[j++];
            }
        }

        while (i < left.size()) {
            rar[k++] = left[i++];
        }

        while (j < right.size()) {
            rar[k++] = right[j++];
        }

    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> a(10);

    cout << "введите 10 целых чисел для сортирования:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }

    MergeSort mergeSort;

    auto sortFunc = [&mergeSort, &a]() { 
        mergeSort.Sort(a); 
        
    };
    thread mergeSortthread(sortFunc);

    mergeSortthread.join();

    cout << "отсортированный массив:\n";
    for (int chislo : a) {
        cout << chislo << " ";
    }
    cout << endl;

    
}
