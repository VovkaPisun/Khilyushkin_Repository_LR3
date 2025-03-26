#include <iostream>

using namespace std;


int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void calculateNewDate(currentDay,currentMonth,currentYear, daysToAdd) {
    while (daysToAdd > 0) {
        int daysInCurrentMonth = daysInMonth(currentMonth, currentYear);
        int daysRemainingInMonth = daysInCurrentMonth - currentDay + 1;

        if (daysToAdd >= daysRemainingInMonth) {
            daysToAdd -= daysRemainingInMonth;
            currentDay = 1;  // Переходим к первому дню следующего месяца
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        } else {
            currentDay += daysToAdd;
            daysToAdd = 0;
        }
    }
}
void calculateDaysToNextYear(currentDay,currentMonth,currentYear){
    int days = 0;
    int nextYear = currentYear + 1;
    for (int m = currentMonth; m <= 12; ++m) {
        int daysInCurrentMonth = daysInMonth(m, currentYear);
        if (m == currentMonth) {
            days += (daysInCurrentMonth - day + 1);
        } else {
            days += daysInCurrentMonth;
        }
    }

    return days;
};
void exitProgram();
int day(){
    cout << "Введите текущий день: ";
    cin >> currentDay;
    return currentDay;
}
int mounth(){
    cout << "Введите текущий месяц: ";
    cin >> currentMonth;
    return currentMonth;
}
int year(){
    cout << "Введите текущий год: ";
    cin >> currentYear;
    return currentYear;
}
int add_day(){
    cout << "Введите количество дней для прибавления: ";
    cin >> daysToAdd;
    return daysToAdd;
}


int main() {
    int choice;

    do {
        // Вывод меню
        cout << "\n--- Меню ---" << endl;
        cout << "1. Введите текущий день" << endl;
        cout << "2. Введите текущий месяц" << endl;
        cout << "3. Введите текущий год" << endl;
        cout << "4. Введите количество дней для прибавления" << endl;
        cout << "5. Вычислить новую дату после прибавления дней" << endl;
        cout << "6. Найти разницу в днях между текущей датой и 1 января следующего года" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        // Обработка выбора пользователя
        switch (choice) {
            case 1:
                int currentDay=day();
                break;
            case 2:
                int currentMonth=mounth();
                break;
            case 3:
                int currentYear=year();
                break;
            case 4:
                int daysToAdd=add_day();
                break;
            case 5:
                calculateNewDate(currentDay,currentMonth,currentYear, daysToAdd);
                break;
            case 6:
                calculateDaysToNextYear();
                break;
            case 0:
                exitProgram();
                break;
            default:
                cout << "Неверный ввод. Пожалуйста, выберите пункт меню от 1 до 3." << endl;
        }
    } while (choice != 3);

    return 0;
}