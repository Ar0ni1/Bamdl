#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initBalance) {
        accountNumber = accNumber;
        balance = initBalance;
        interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Чиназес." << endl;
        }
        else {
            cout << "Не чиназес" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Чиназес" << endl;
        }
        else {
            cout << "Не чиназес" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    bool transfer(BankAccount& to, double amount) {
        if (balance >= amount) {
            balance -= amount;
            to.balance += amount;
            cout << "Успешно." << endl;
            return true;
        }
        else {
            cout << "Ошибка." << endl;
            return false;
        }
    }

    void printAccountNumber() const {
        cout << "Номер счета: " << accountNumber << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    BankAccount person1(18928819, 100000.0);
    BankAccount person2(92873627, 150200.0);

    int accountChoice;
    cout << "Еже балик выбери для обмывки one or two писать цифрами: ";
    cin >> accountChoice;

    BankAccount* selectedAccount;
    if (accountChoice == 1) {
        selectedAccount = &person1;
    }
    else if (accountChoice == 2) {
        selectedAccount = &person2;
    }
    else {
        cout << "Неверный выбор счета." << endl;
        return 1;
    }

    int choice;
    double amount;

    do {
        cout << "Меню:" << endl;
        cout << "1. ЕЖЕ закинь лавеху на счет" << endl;
        cout << "2. Выведи балик " << endl;
        cout << "3. Проанализировать баланс после депа" << endl;
        cout << "4. Рассчитать и вернуть сумму процентов, заработанных на счете" << endl;
        cout << "5. Обновить процентную ставочку (на реальчик)" << endl;
        cout << "6. Вывести цифры счета" << endl;
        cout << "7. Закинуть бабос на другой балик" << endl;
        cout << "8. Поменять балик" << endl;
        cout << "9. ЛИвнуть " << endl;
        cout << "Еже цифру делай: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите число денег на пополнение балика: Франков ";
            cin >> amount;
            selectedAccount->deposit(amount);
            break;
        case 2:
            cout << "Введите чсило лавехи на вывод: Франков ";
            cin >> amount;
            selectedAccount->withdraw(amount);
            break;
        case 3:
            cout << "ОСтаток после депчика: Франков " << selectedAccount->getBalance() << endl;
            break;
        case 4:
            cout << "Процентики: Франков " << selectedAccount->getInterest() << endl;
            break;
        case 5:
            cout << "Введите новую процентную ставку: ";
            double newRate;
            cin >> newRate;
            selectedAccount->setInterestRate(newRate);
            break;
        case 6:
            selectedAccount->printAccountNumber();
            break;
        case 7:
            int transferToAccount;
            double transferAmount;
            cout << "Выберите счет для обмывки бабоса (one or two пиши цифрами): ";
            cin >> transferToAccount;
            if (transferToAccount == 1) {
                cout << "Введите количество деняг для обмывки " << person1.getAccountNumber() << ": $";
                cin >> transferAmount;
                selectedAccount->transfer(person1, transferAmount);
            }
            else if (transferToAccount == 2) {
                cout << "Введите количество деняг для обмывки " << person2.getAccountNumber() << ": $";
                cin >> transferAmount;
                selectedAccount->transfer(person2, transferAmount);
            }
            else {
                cout << "НЕ тот счет для обывки." << endl;
            }
            break;
        case 8:
            cout << "Выберите счет для депчика (1 или 2): ";
            cin >> accountChoice;
            if (accountChoice == 1) {
                selectedAccount = &person1;
            }
            else if (accountChoice == 2) {
                selectedAccount = &person2;
            }
            else {
                cout << "Не тот счет для обмывки." << endl;
                return 1;
            }
            break;
        case 9:
            cout << "ЛИВ..." << endl;
            break;
        default:
            cout << "Еже куда газанул всего 9 вариков выбора (и один варик темка на вечер но это лично)." << endl;
        }
    } while (choice != 9);

    return 0;
}
