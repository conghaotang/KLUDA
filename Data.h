#pragma once
#include"utils.h"


void generate_data(vector<MatrixXd> &TRUE_STATE, vector<MatrixXd> &OUTPUT_VECTOR, vector<MatrixXd>& STATE_MATRIX)
{
	MatrixXd state_matrix = MatrixXd::Identity(2, 2);
	state_matrix(0, 1) = delta_time;
	//cout << state_matrix << endl;
	MatrixXd output_matrix = MatrixXd::Constant(1, 2,5);
	output_matrix(0, 0) = 1;
	//cout << output_matrix << endl;

	MatrixXd temp_state = MatrixXd::Constant(2, 1, 1);
	for (int i = 0; i < (simulation_time / delta_time); i++)
	{
		temp_state = state_matrix * temp_state + Errors(2,1,0, sigma_w);
		MatrixXd temp = temp_state;
		TRUE_STATE.push_back(temp);
		MatrixXd output_vector = output_matrix* temp_state+ Errors(1, 1, 0, sigma_v);
		OUTPUT_VECTOR.push_back(output_vector);
		STATE_MATRIX.push_back(state_matrix);
	}
}
