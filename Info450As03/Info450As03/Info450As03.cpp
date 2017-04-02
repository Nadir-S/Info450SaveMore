// Info450As03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


class BankAccount
{
protected:
	static int accNumGen;
	int accNum;
	double intRate;
	double balance;

public:
	BankAccount()
	{
		accNum = accNumGen++;
	}
	virtual int Deposit() {};
	virtual int Withdraw() {};
	virtual void Display() {};
};

int BankAccount::accNumGen = 1;

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount() : BankAccount()
	{
		if (balance >= 10000)
			intRate = .02;
		else
			intRate = .01;
	}

	void CalcInterest()
	{
		double monthlyInt = intRate / 12;
		double addMoney = balance * monthlyInt;

		balance += addMoney;
	}

	int Deposit()
	{
		double userInput;
		cout << "How much would you like to deposit?" << endl;
		cin >> userInput;
		balance += userInput;

		if (balance >= 10000)
			intRate = .02;

		return 0;
	}

	int Withdraw()
	{
		double userInput;
		cout << "How much would you like to withdraw?" << endl;
		cin >> userInput;
		if (balance - userInput - 2 < 0)
		{
			cout << "Error, cannot go negative" << endl;
			return -1;
		}
		else
		{
			balance -= userInput + 2;
		}

		if (balance < 10000)
			intRate = .01;

		return 0;
	}

	void Display()
	{
		cout << "Account Number: " << accNum << endl;
		cout << "Interest Rate: " << intRate << endl;
		cout << "Account Balance: " << balance << endl;
	}
};

class CheckingAccount : public BankAccount
{
public:
	CheckingAccount() : BankAccount()
	{

	}

	int Deposit()
	{
		double userInput;
		cout << "How much would you like to deposit?" << endl;
		cin >> userInput;
		balance += userInput;

		return 0;
	}

	int Withdraw()
	{
		double userInput;
		cout << "How much would you like to withdraw?" << endl;
		cin >> userInput;
		if (balance - userInput < 0)
		{
			cout << "Error, cannot go negative" << endl;
			return -1;
		}
		else
		{
			balance -= userInput;
		}

		if (balance < 500)
			balance -= 5;

		return 0;
	}

	void OrderCheck()
	{
		balance -= 15;
	}

	void Display()
	{
		cout << "Account Number: " << accNum << endl;
		cout << "Interest Rate: " << intRate << endl;
		cout << "Account Balance: " << balance << endl;
	}
};

class CertOfDeposit : public BankAccount
{
private:
	int term;

public:
	CertOfDeposit() : BankAccount()
	{
		int userInput;
		cout << "How long would you like the term to be?" << endl;
		cin >> userInput;

		if (userInput >= 5)
		{
			intRate = .1;
		}
		else
		{
			intRate = .05;
		}

		term = userInput;
	}

	void CalcInterest()
	{
		double monthlyInt = intRate / 12;
		double addMoney = balance * monthlyInt;

		balance += addMoney;
	}

	int Withdraw()
	{
		double userInput;
		cout << "How much would you like to withdraw?" << endl;
		cin >> userInput;
		if (balance - userInput < 0)
		{
			cout << "Error, cannot go negative" << endl;
			return -1;
		}
		else
		{
			double fee = balance * .1;
			balance -= fee;
			balance -= userInput;
		}

		return 0;
	}

	int Deposit()
	{
		double userInput;
		cout << "How much would you like to deposit?" << endl;
		cin >> userInput;
		balance += userInput;

		return 0;
	}

	void Display()
	{
		cout << "Account Number: " << accNum << endl;
		cout << "Interest Rate: " << intRate << endl;
		cout << "Account Balance: " << balance << endl;
	}

};

int main()
{
	SavingsAccount sacc;
	CheckingAccount cacc;
	CertOfDeposit dacc;
	SavingsAccount *s;
	CheckingAccount *c;
	CertOfDeposit *d;

	char userInput;
	cout << "What kind of Account would you like to open?" << endl;
	cout << "(S)avings, (C)hecking, CertOf(D)eposit" << endl;
	cin >> userInput;
	

	if ((userInput == 'S') || (userInput == 's'))
	{
		s = &sacc;
		cout << "What would you like to do?" << endl;
		cout << "(W)ithdraw, (D)eposit, (C)alcInt, D(i)splay" << endl;
		cin >> userInput;

		if ((userInput == 'W') || (userInput == 'w'))
		{
			s->Withdraw();
		}
		else if ((userInput == 'D') || (userInput == 'd'))
		{
			s->Deposit();
		}
		else if ((userInput == 'C') || (userInput == 'c'))
		{
			s->CalcInterest();
		}
		else if ((userInput == 'I') || (userInput == 'i'))
		{
			s->Display();
		}
	}
	else if ((userInput == 'C') || (userInput == 'c'))
	{
		c = &cacc;
		cout << "What would you like to do?" << endl;
		cout << "(W)ithdraw, (D)eposit, (O)rderCheck, D(i)splay" << endl;
		cin >> userInput;

		if ((userInput == 'W') || (userInput == 'w'))
		{
			c->Withdraw();
		}
		else if ((userInput == 'D') || (userInput == 'd'))
		{
			c->Deposit();
		}
		else if ((userInput == 'O') || (userInput == 'o'))
		{
			c->OrderCheck();
		}
		else if ((userInput == 'I') || (userInput == 'i'))
		{
			c->Display();
		}
	}
	else if ((userInput == 'D') || (userInput == 'd'))
	{
		d = &dacc;
		cout << "What would you like to do?" << endl;
		cout << "(W)ithdraw, (D)eposit, (C)alcInt, D(i)splay" << endl;
		cin >> userInput;

		if ((userInput == 'W') || (userInput == 'w'))
		{
			d->Withdraw();
		}
		else if ((userInput == 'D') || (userInput == 'd'))
		{
			d->Deposit();
		}
		else if ((userInput == 'C') || (userInput == 'c'))
		{
			d->CalcInterest();
		}
		else if ((userInput == 'I') || (userInput == 'i'))
		{
			d->Display();
		}
	}
	


	return 0;
}