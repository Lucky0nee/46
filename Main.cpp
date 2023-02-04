#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class Class {
public:
    // 0) конструктор, що створює об’єкт з пустим вектором
    Class() {
        for (int i = 0; i < 12; i++)
            this->RandVector.push_back(NULL);
    }
    // 1) конструктор для заповнення елементів вектора випадковими цілими числами від 10 до 99 включно, всього 12 чисел;
    void fillVectorRandNum() {
        for (int i = 0; i < elements; i++)
            this->RandVector[i] = rand() % 89 + 10;
    }
    // 2) метод для виведення на екран дванадцяти елементів вектора у вигляді таблиці 4 на 3 протягом 20 секунд;
    void CoutRandVector(bool useTimer) {
        const int time = 2;
        if (useTimer) {
            for (int i = 0; i < time; i++) {
                for (int i = 0; i < elements; i++) {
                    if (i % 4 == 0 && i != 0)
                        cout << "\n";
                    cout << this->RandVector[i] << " ";
                }
                cout << "\n\nMemorize the numbers...";
                cout << "\nTime left: " << time - i;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                system("cls");
            }
        }
        else
        {
            for (int i = 0; i < elements; i++) {
                if (i % 4 == 0 && i != 0)
                    cout << "\n";
                cout << this->RandVector[i] << " ";
            }
        }
    }
    void CoutVector(vector<int> Vector) {
        for (int i = 0; i < elements; i++) {
            if (i % 4 == 0 && i != 0)
                cout << "\n";

            cout << Vector[i] << " ";
        }
    }
    // 3) створіть метод редагування вектора, щоб користувач міг задати з клавіатури 12 елементів вектора;
    void ChangeVectorNum(vector<int>& Vector) {
        if (Vector.empty())
            for (int i = 0; i < elements; i++)
                Vector.push_back(NULL);

        int number;
        for (int i = 0; i < elements; i++) {
            cout << "\n" << i + 1 << ". Enter vector element from keyboard: "; cin >> number;
            Vector[i] = number;
        }
    }

    // 4) функцію або метод для порівняння двох об’єктів, що містять вектори, вона має повертати кількість однакових
    int CheckForCoincidences(vector<int> Vector) {
        vector<int> TempRandVector = RandVector;
        int NumOfCoincidences = 0;
        for (int i = 0; i < (int)TempRandVector.size(); i++) {
            for (int j = 0; j < (int)Vector.size(); j++) {
                if (TempRandVector[i] == Vector[j] && TempRandVector[i] != NULL && Vector[j] != NULL) {
                    NumOfCoincidences++;
                    TempRandVector[i] = NULL;
                    Vector[j] = NULL;
                }
            }
        }
        return NumOfCoincidences;
    }
private:
    // Створіть клас, в якому був би вектор (або масив).
    vector<int> RandVector{};
    const int elements = 12;
};
int main() {
    srand((unsigned)time(NULL));
    system("chcp 1251>nul");
    // 0) конструктор, що створює об’єкт з пустим вектором +
    Class Programm;  vector<int> Vector{};
    // 1) конструктор для заповнення елементів вектора випадковими цілими числами від 10 до 99 включно, всього 12 чисел; +
    Programm.fillVectorRandNum();
    // 2) метод для виведення на екран дванадцяти елементів вектора у вигляді таблиці 4 на 3 протягом 20 секунд;
    // В головній програмі попередьте користувача, що йому буде потрібно запам’ятати якомога більше чисел і виведіть на екран значення вектра з випадковими числами.
    Programm.CoutRandVector(true);

    // 3) створіть метод редагування вектора, щоб користувач міг задати з клавіатури 12 елементів вектора;
    // Після зникнення виведених чисел попросіть користувача згадати і ввести їх з клавіатури.
    Programm.ChangeVectorNum(Vector);
    // 4) функцію або метод для порівняння двох об’єктів, що містять вектори, вона має повертати кількість однакових елементів.
    // Порівняйте результати з попереднім вектором і кількість правильно згаданих чисел виведіть на екран.
    system("cls");
    cout << "Number of identical elements: " << Programm.CheckForCoincidences(Vector);
    cout << "\nRand Vector: \n"; Programm.CoutRandVector(false);
    cout << "\nYour Vector: \n"; Programm.CoutVector(Vector);
    return 0;
}

/*
Створіть клас, в якому був би вектор (або масив). Розробіть:
0) конструктор, що створює об’єкт з пустим вектором +
1) конструктор для заповнення елементів вектора випадковими цілими числами від 10 до 99 включно, всього 12 чисел; +
2) метод для виведення на екран дванадцяти елементів вектора у вигляді таблиці 4 на 3 протягом 20 секунд;
3) створіть метод редагування вектора, щоб користувач міг задати з клавіатури 12 елементів вектора;
4) функцію або метод для порівняння двох об’єктів, що містять вектори, вона має повертати кількість однакових
елементів.
В головній програмі попередьте користувача, що йому буде потрібно запам’ятати якомога більше чисел і виведіть на
екран значення вектра з випадковими числами. Можете підказувати користувачу, скільки у нього залишилось часу для
запам’ятовування. Після зникнення виведених чисел попросіть користувача згадати і ввести їх з клавіатури.
Порівняйте результати з попереднім вектором і кількість правильно згаданих чисел виведіть на екран.
*/
