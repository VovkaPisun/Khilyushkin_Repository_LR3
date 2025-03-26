#include <iostream>

using namespace std;

// Объявление функций (прототипы)
void calculateNewDate();
void calculateDaysToNextYear();
void exitProgram();

int main() {
    int choice;

    do {
        // Вывод меню
        cout << "\n--- Меню ---" << endl;
        cout << "1. Вычислить новую дату после прибавления дней" << endl;
        cout << "2. Найти разницу в днях между текущей датой и 1 января следующего года" << endl;
        cout << "3. Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        // Обработка выбора пользователя
        switch (choice) {
            case 1:
                calculateNewDate();
                break;
            case 2:
                calculateDaysToNextYear();
                break;
            case 3:
                exitProgram();
                break;
            default:
                cout << "Неверный ввод. Пожалуйста, выберите пункт меню от 1 до 3." << endl;
        }
    } while (choice != 3);

    return 0;
}