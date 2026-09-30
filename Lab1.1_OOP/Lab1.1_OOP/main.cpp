#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

int main() {
    system("chcp 1251 > nul");

    cout << "=== ЛАБОРАТОРНА РОБОТА № 1.1 (Варіант 1) ===" << endl;

    Account acc;
    acc.Init("Шевченко Т.Г.", 100452, 7.5, 15000.00);

    acc.Display();

    cout << "\n--- Зарахування та зняття коштів ---" << endl;
    acc.Deposit(5000.00);
    acc.Withdraw(3000.00);
    acc.Withdraw(25000.00);

    cout << "\n--- Нарахування відсотків ---" << endl;
    acc.EarnInterest();

    cout << "\n--- Зміна власника ---" << endl;
    acc.ChangeOwner("Франко І.Я.");

    cout << "\n--- Конвертація у валюту ---" << endl;
    double usdRate = 41.50;
    double eurRate = 44.20;

    cout << "Залишок у USD (курс " << usdRate << "): $"
        << fixed << setprecision(2) << acc.ConvertToUSD(usdRate) << endl;
    cout << "Залишок у EUR (курс " << eurRate << "): €"
        << fixed << setprecision(2) << acc.ConvertToEUR(eurRate) << endl;

    acc.Display();

    return 0;
}