#include<iostream>
#include"account.h"
#include<iomanip>

using namespace std;

SavingsAccounts::SavingsAccounts(int date, int id, double rate)//构造函数初始化用户
{
	total_money = 0;
	balance = 0;
	days = 0;
	LastDate = date;
	this->id = id;
	this->rate = rate;
	cout << setw(8) << setiosflags(ios::left) << date << "#" << this->id << " is created" << endl;
}

//记录信息(更新操作日期，计算两次操作时间间隔和当前余额)
void SavingsAccounts::record(int date, double amount)
{
	days = date - LastDate;
	LastDate = date;
	balance += amount;
}

//输出id
int SavingsAccounts::GetId()
{
	return this->id;
}

//输出Balance
double SavingsAccounts::GetBalance()
{
	return this->balance;
}

//输出date
double SavingsAccounts::GetRate()
{
	return this->rate;
}

//储蓄操作,同时计算当前利息
void SavingsAccounts::deposit(int date, double amount)
{
	days = date - LastDate;
	total_money += days * balance;
	LastDate = date;
	balance += amount;
	cout << setw(8) << date << "#" << setw(15) << this->id << setw(8) << amount << this->balance << endl;
}

//取款操作
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

//自动结算
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

//显示账户信息操作
void SavingsAccounts::show()
{
	cout << "#" << setw(15)<<this->id << "Balance: " << setprecision(6) << this->balance;
}
