#pragma once
#include"utils.h"

void kf(vector<MatrixXd>& OUTPUT_VECTOR, vector<MatrixXd>& STATE_MATRIX, vector<MatrixXd>& RESULT )
{
	MatrixXd state_matrix = MatrixXd::Identity(2, 2);
	state_matrix(0, 1) = delta_time;

	MatrixXd output_matrix = MatrixXd::Constant(1, 2, 5);
	output_matrix(0, 0) = 1;

	MatrixXd state = MatrixXd::Constant(2, 1, 0);
	MatrixXd P = MatrixXd::Identity(2, 2)*100;

	MatrixXd K;
	for (int i = 0; i < (simulation_time / delta_time); i++)
	{
		state = STATE_MATRIX[i] * state;
		P = STATE_MATRIX[i] * P * STATE_MATRIX[i].transpose()+Q;

		K = P * output_matrix.transpose() * (output_matrix * P * output_matrix.transpose() + R).inverse();
		state = state + K * (*(OUTPUT_VECTOR.begin() + i) - output_matrix * state);
		P = P - K * output_matrix * P;
		RESULT.push_back(state);
	}
}