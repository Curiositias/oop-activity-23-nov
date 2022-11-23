#include <iostream>
#include <string>
using namespace std;
class account
{
protected:
    string name;
    long ano;
    long abal;

public:
    account()
    {
        cout << "enter acount holder name" << endl;
        getline(cin, name);
        getline(cin, name);
        cout << "enter acount no" << endl;
        cin >> ano;
        cout << "enter acount balance" << endl;
        cin >> abal;
    }
    virtual void withdraw()
    {
        cout << "virtual withdraw base";
    }
    virtual void deposit()
    {
        cout << "virtual deposit base";
    }
    virtual void display()
    {
        cout << "virtual display base";
    }
};
class saccont : public account
{
protected:
    long minb;

public:
    saccont()
    {
        cout << "enter minimum balance" << endl;
        cin >> minb;
    }

    void deposit()
    {
        long db;
        cout << "enter amount you want to deposit" << endl;
        cin >> db;
        abal += db;
    }
    void withdraw()
    {
        cout << "your corrent balance and minuimum balance is rs : " << endl;
        cout << "balance ->" << abal << "Minimum bal -->" << minb << endl;
        int k;
        long wb;
        cout << "enter 1 if you wnat to withdraw" << endl;
        cin >> k;
        if (k == 1)
        {
            cout << "enter amount you want to withdraw" << endl;
            cin >> wb;
            if (wb < (abal - minb))
            {
                abal -= wb;
            }
            else
            {
                cout << "insufficient balance" << endl;
            }
        }
    }
    void display()
    {
        cout << "--------------------SAVINGS ACOUNT DETAAILS------------------------" << endl;
        cout << "NAME\taccount no\t acount balance(rs)\tminumum balance" << endl;
        cout << name << "\t   " << ano << "\t"
             << "\t" << abal << "\t\t" << minb << endl;
    }
};
class Caccont : public account
{
protected:
    long overb;

public:
    Caccont()
    {
        cout << "Enter overdue balance" << endl;
        cin >> overb;
    }
    void deposit()
    {
        long db;
        cout << "enter amount you want to deposit" << endl;
        cin >> db;
        abal += db;
    }
    void withdraw()
    {
        cout << "your current balance and overddue balance is rs : " << endl;
        cout << "balance ->" << abal << "\n overdue bal -->" << overb << endl;
        int k;
        long wb;
        cout << "enter 1 if you want to withdraw" << endl;
        cin >> k;
        if (k == 1)
        {
            cout << "enter amount you want to withdraw" << endl;
            cin >> wb;
            if (overb == 0)
                abal -= wb;
            else
                cout << "insufficient balance" << endl;
        }
    }
    void display()
    {
        cout << "--------------------CURRENT ACOUNT DETAAILS------------------------" << endl;
        cout << "NAME\taccount no\tacount balance\toverdue balance" << endl;
        cout << name << "\t\t" << ano << "\t" << abal << "\t" << overb << endl;
    }
};
int main()
{
    account *a;
    int ch;
    while (1)
    {
        cout << "1 for savings\n2 for current account\n3 to exit\nEnter your choice:" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int n;
            saccont s;
            a = &s;
            cout << "1 to deposit and 2 to withdraw" << endl;
            cin >> n;
            switch (n)
            {
            case 1:
            
                a->deposit();
                a->display();
                break;
            case 2:
                a->withdraw();
                a->display();
                break;
            }
            }
        
        break;
        case 2:
        {
            int n;
            Caccont c;
            a = &c;
            cout << "1 to deposit and 2 to withdraw" << endl;
            cin >> n;
            switch (n)
            {
            case 1:
            {
                a->deposit();
                a->display();
                break;
            case 2:
                a->withdraw();
                a->display();
                break;
            }
            }
        }
        break;
        case 3:
        {
            exit(0);
            break;
        }
        }
    }
    return 0;
}
