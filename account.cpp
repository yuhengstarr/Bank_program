#include<iostream>
#include"account.h"
#include<iomanip>

using namespace std;

SavingsAccounts::SavingsAccounts(int date, int id, double rate)//���캯����ʼ���û�
{
	total_money = 0;
	balance = 0;
	days = 0;
	LastDate = date;
	this->id = id;
	this->rate = rate;
	cout << setw(8) << setiosflags(ios::left) << date << "#" << this->id << " is created" << endl;
}

//��¼��Ϣ(���²������ڣ��������β���ʱ�����͵�ǰ���)
void SavingsAccounts::record(int date, double amount)
{
	days = date - LastDate;
	LastDate = date;
	balance += amount;
}

//���id
int SavingsAccounts::GetId()
{
	return this->id;
}

//���Balance
double SavingsAccounts::GetBalance()
{
	return this->balance;
}

//���date
double SavingsAccounts::GetRate()
{
	return this->rate;
}

//�������,ͬʱ���㵱ǰ��Ϣ
void SavingsAccounts::deposit(int date, double amount)
{
	days = date - LastDate;
	total_money += days * balance;
	LastDate = date;
	balance += amount;
	cout << setw(8) << date << "#" << setw(15) << this->id << setw(8) << amount << this->balance << endl;
}

//ȡ�����
void SavingsAccounts::withdraw(int date, double amount)
{
	if (amount > GetBalance())
	{
		cout << "Error:you don't have enough money.";
	}
	days = date - LastDate;
	total_money += days * balance;
	LastDate = date;
	balance -= amount;
	cout <<setw(8)<< date<< "#" <<setw(15) <<this->id << "-" <<setw(7)<< amount << this->balance << endl;
}

//�Զ�����
void SavingsAccounts::settle(int date)
{
	days = date - LastDate;
	total_money += days * balance;
	double interest = 0;
	interest = (total_money * this->rate) / 365;
	balance += interest;
	cout <<setw(8)<< date << "#" << setw(15)<<this->id << setprecision(4) << setw(8)<< interest;
	cout << setprecision(6) << this->balance << endl;
}

//��ʾ�˻���Ϣ����
void SavingsAccounts::show()
{
	cout << "#" << setw(15)<<this->id << "Balance: " << setprecision(6) << this->balance;
}
