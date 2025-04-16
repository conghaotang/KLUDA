#pragma once
#include<Eigen/core>
#include<Eigen/Dense>
#include <random>
#include <chrono>
#include<iostream>
#include<algorithm>
#include<fstream>
#include <iomanip>
#include <sstream>
using namespace Eigen;
using namespace std;

extern const double simulation_time = 200;
extern const double delta_time = 0.1;
extern const double sigma_w = 0.1;
extern const double sigma_v = 10;
const MatrixXd cov_w = MatrixXd::Identity(2, 2) * pow(sigma_w, 2);
const MatrixXd cov_v = MatrixXd::Identity(1, 1) * pow(sigma_v, 2);


//KLUDA
const int p = 0;

//traditional UFIR
const int s = 2;

extern const MatrixXd Q = cov_w;
extern const MatrixXd R = cov_v;