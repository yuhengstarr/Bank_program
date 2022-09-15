#pragma once
#include<iostream>


using namespace std;
class SavingsAccounts
{
public:
	double total_money;
	int id;//id号
	double balance;//余额
	double rate;//年利率
	int LastDate;//最近一次的账户操作日期
	int days;//用于计算两次操作之间间隔的时间
	SavingsAccounts(int date, int id, double rate);//构造函数初始化用户
	double acumulation(int date);
	void record(int date, double amount);
	int GetId();
	double GetBalance();
	double GetRate();
	void deposit(int date, double amount);
	void withdraw(int date, double amount);
	void show();
	void settle(int date);
};