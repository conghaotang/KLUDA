#pragma once
#include"utils.h"

void ufir(vector<MatrixXd>& OUTPUT_VECTOR, vector<MatrixXd>& STATE_MATRIX, vector<MatrixXd>& RESULT,int N)
{
	MatrixXd state_matrix = MatrixXd::Identity(2, 2);
	state_matrix(0, 1) = delta_time;

	MatrixXd output_matrix = MatrixXd::Constant(1, 2, 5);
	output_matrix(0, 0) = 1;

	int output_vector_row = (*(OUTPUT_VECTOR.begin())).rows();
	int output_vector_col = (*(OUTPUT_VECTOR.begin())).cols();
	int state_matrix_row = (*(STATE_MATRIX.begin())).rows();
	int state_matrix_col = (*(STATE_MATRIX.begin())).cols();
	int output_matrix_row = output_matrix.rows();

	MatrixXd state = MatrixXd::Constant(2, 1, 0);
	MatrixXd P = MatrixXd::Constant(2, 2, 0);

	MatrixXd Z_K = MatrixXd::Constant(output_vector_row * s, output_vector_col, 0);
	MatrixXd L_K = MatrixXd::Constant(output_vector_row * s, state_matrix_col, 0);
	MatrixXd temp_g = G(0, p, STATE_MATRIX).inverse();
	for (int k = N; k <= (simulation_time / delta_time); k++)
	{
		
		if (k == N)
		{
			for (int i = 0; i < s; i++)
			{
				Z_K.block(i * output_vector_row, 0, output_vector_row, output_vector_col) = *(OUTPUT_VECTOR.begin() + i);
				L_K.block(i * output_matrix_row, 0, output_vector_row, state_matrix_col) = output_matrix * G(i, s - 1, STATE_MATRIX).inverse();
			}
			state = (L_K.transpose() * L_K).inverse() * L_K.transpose() * Z_K;
			P = (L_K.transpose() * L_K).inverse();
			for (int i = s; i < k; i++)
			{
				P = (output_matrix.transpose() * output_matrix + (state_matrix * P * state_matrix.transpose()).inverse()).inverse();
				state = state_matrix * state + P * output_matrix.transpose() * (*(OUTPUT_VECTOR.begin() + i) - output_matrix * state_matrix * state);
			}
			state = G(k - p, k, STATE_MATRIX).inverse() * state;
			P = G(k - p, k, STATE_MATRIX).inverse() * P * (G(k - p, k, STATE_MATRIX).inverse()).transpose();
			RESULT.push_back(state);
		}
		else
		{
			for (int i = 0, j = k - N; i < s; i++, j++)
			{
				Z_K.block(i * output_vector_row, 0, output_vector_row, output_vector_col) = *(OUTPUT_VECTOR.begin() + j);
				L_K.block(i * output_matrix_row, 0, output_vector_row, state_matrix_col) = output_matrix * G(k - N + i + 1, k - N + s, STATE_MATRIX).inverse();
			}
			state = (L_K.transpose() * L_K).inverse() * L_K.transpose() * Z_K;
			P = (L_K.transpose() * L_K).inverse();
			for (int i = k - N + s; i < k; i++)
			{
				P = (output_matrix.transpose() * output_matrix + (state_matrix * P * state_matrix.transpose()).inverse()).inverse();
				state = state_matrix * state + P * output_matrix.transpose() * (*(OUTPUT_VECTOR.begin() + i) - output_matrix * state_matrix * state);
			}
			state = temp_g * state;
			P = temp_g * P * temp_g.transpose();
			RESULT.push_back(state);
		}
	}
}