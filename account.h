#pragma once
#include<iostream>


using namespace std;
class SavingsAccounts
{
public:
	double total_money;
	int id;//id��
	double balance;//���
	double rate;//������
	int LastDate;//���һ�ε��˻���������
	int days;//���ڼ������β���֮������ʱ��
	SavingsAccounts(int date, int id, double rate);//���캯����ʼ���û�
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