#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account {
private:
    string owner;
    int no;
    double percentage;
    double summa;

public:
    void Init(string ownerName, int accNo, double percent, double sum);

    string GetOwner() const;
    int GetNo() const;
    double GetPercentage() const;
    double GetSumma() const;

    void SetOwner(string ownerName);
    void SetNo(int accNo);
    void SetPercentage(double percent);
    void SetSumma(double sum);

    void ChangeOwner(string newOwner);
    bool Withdraw(double amount);
    void Deposit(double amount);
    void EarnInterest();
    double ConvertToUSD(double usdRate) const;
    double ConvertToEUR(double eurRate) const;
    void Display() const;
};

#endif
