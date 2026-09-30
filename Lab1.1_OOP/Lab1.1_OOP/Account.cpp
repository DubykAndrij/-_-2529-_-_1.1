#include "Account.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Account::Init(string ownerName, int accNo, double percent, double sum) {
    owner = ownerName;
    no = accNo;
    percentage = percent;
    summa = (sum >= 0) ? sum : 0;
}

string Account::GetOwner() const { return owner; }
int Account::GetNo() const { return no; }
double Account::GetPercentage() const { return percentage; }
double Account::GetSumma() const { return summa; }

void Account::SetOwner(string ownerName) { owner = ownerName; }
void Account::SetNo(int accNo) { no = accNo; }
void Account::SetPercentage(double percent) { percentage = percent; }
void Account::SetSumma(double sum) { if (sum >= 0) summa = sum; }

void Account::ChangeOwner(string newOwner) {
    owner = newOwner;
    cout << "[Інфо] Власника рахунку №" << no << " змінено на: " << owner << endl;
}

bool Account::Withdraw(double amount) {
    if (amount <= 0) {
        cout << "[Помилка] Сума для зняття повинна бути додатною!" << endl;
        return false;
    }
    if (amount > summa) {
        cout << "[Помилка] Недостатньо коштів на рахунку №" << no << "!" << endl;
        return false;
    }
    summa -= amount;
    cout << "[Успіх] Знято " << amount << " грн. Залишок: " << summa << " грн." << endl;
    return true;
}

void Account::Deposit(double amount) {
    if (amount > 0) {
        summa += amount;
        cout << "[Успіх] Зараховано " << amount << " грн. Новий залишок: " << summa << " грн." << endl;
    }
    else {
        cout << "[Помилка] Сума для зарахування повинна бути додатною!" << endl;
    }
}

void Account::EarnInterest() {
    double interest = summa * (percentage / 100.0);
    summa += interest;
    cout << "[Успіх] Нараховано відсотки (" << percentage << "%): +" << interest
        << " грн. Новий залишок: " << summa << " грн." << endl;
}

double Account::ConvertToUSD(double usdRate) const {
    if (usdRate <= 0) return 0;
    return summa / usdRate;
}

double Account::ConvertToEUR(double eurRate) const {
    if (eurRate <= 0) return 0;
    return summa / eurRate;
}

void Account::Display() const {
    cout << "\n==========================================" << endl;
    cout << " Інформація про банківський рахунок №" << no << endl;
    cout << "------------------------------------------" << endl;
    cout << " Власник:          " << owner << endl;
    cout << " Відсоток:         " << percentage << "%" << endl;
    cout << " Залишок (UAH):    " << fixed << setprecision(2) << summa << " грн." << endl;
    cout << "==========================================" << endl;
}