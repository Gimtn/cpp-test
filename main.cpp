#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Введення масиву
    cout << "Введіть елементи масиву через пробіл: ";
    vector<int> arr;
    int num;
    
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') break;
    }
    
    int n = arr.size();
    cout << "\nПочатковий масив: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Ініціалізація змінних
    int max_index = 0;
    int first_zero = -1, second_zero = -1;

    // Основний алгоритм - пошук максимуму та нулів за один прохід
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
        if (arr[i] == 0) {
            if (first_zero == -1) {
                first_zero = i;
            } else if (second_zero == -1) {
                second_zero = i;
            }
        }
    }

    // Обчислення добутку
    long long product = 0;
    if (first_zero != -1 && second_zero != -1 && second_zero - first_zero > 1) {
        product = 1;
        for (int i = first_zero + 1; i < second_zero; i++) {
            product *= arr[i];
        }
    }

    // Виведення результатів
    cout << "\nРезультати обчислень:" << endl;
    cout << "1) Номер максимального елемента: " << max_index << endl;
    cout << "2) Добуток елементів між нулями: " << product << endl;

    return 0;
}
