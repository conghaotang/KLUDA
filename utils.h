#pragma once
#include"config.h"

MatrixXd Errors(int col, int row, double mean, double standard)
{
	// 从epoch（1970年1月1日00:00:00 UTC）开始经过的纳秒数，unsigned类型会截断这个值
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	// 第一个参数为高斯分布的平均值，第二个参数为标准差
	std::normal_distribution<double> distribution(mean, standard);
	MatrixXd errors = MatrixXd::Zero(col, row);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			errors(i, j) = distribution(generator);
		}
	}
	return errors;
}

MatrixXd G(int start, int end,vector<MatrixXd> F)
{
	int row = (*(F.begin())).rows();
	MatrixXd gain=MatrixXd::Identity(row, row);
	if (start == end) return gain;
	if (start == (end-1)) return F[start];
	for (int i = start; i < end; ++i)
	{
		gain = F[i] * gain;
	}
	return gain;
}

void Output_kluda( vector<MatrixXd> SIMULATION_STATE,int N)
{
	fstream fs1;
	stringstream ss;
	ss << "./result/kluda" << N << ".txt";
	string fillepath = ss.str();
	cout << fillepath << endl;
	fs1.open(fillepath, ios::out);
	for (int i = 0; i < (simulation_time / delta_time-N); i++)
	{
		MatrixXd temp =*(SIMULATION_STATE.begin() + i) ;
		fs1 << temp(0, 0) << "," << temp(1, 0) << ",";
	}
	fs1.close();
}

void Output_ufir( vector<MatrixXd> SIMULATION_STATE, int N)
{
	fstream fs1;
	stringstream ss;
	ss << "./result/ufir" << N << ".txt";
	string fillepath = ss.str();
	cout << fillepath << endl;
	fs1.open(fillepath, ios::out);
	for (int i = 0; i < (simulation_time / delta_time-N ); i++)
	{
		MatrixXd temp = *(SIMULATION_STATE.begin() + i);
		//cout << *(SIMULATION_STATE.begin() + i) << endl;
		fs1 << temp(0, 0) << "," << temp(1, 0) << ",";
	}
	fs1.close();
}

void output_true_state(vector<MatrixXd> TRUE_STATE, int N)
{
	fstream fs1;
	stringstream ss;
	ss << "./result/true" << N << ".txt";
	string fillepath = ss.str();
	cout << fillepath << endl;
	fs1.open(fillepath, ios::out);
	for (int i = 0; i < (simulation_time / delta_time - N); i++)
	{
		MatrixXd temp = *(TRUE_STATE.begin() + i+N);
		fs1 << temp(0, 0) << "," << temp(1, 0) << ",";
	}
	fs1.close();
}