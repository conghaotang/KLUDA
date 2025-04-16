#pragma once
#include"utils.h"

void kluda(vector<MatrixXd>& OUTPUT_VECTOR, vector<MatrixXd>& STATE_MATRIX, vector<MatrixXd>& RESULT, int N)
{
	MatrixXd state_matrix = MatrixXd::Identity(2, 2);
	state_matrix(0, 1) = delta_time;

	MatrixXd output_matrix = MatrixXd::Constant(1, 2, 5);
	output_matrix(0, 0) = 1;

	int output_vector_row = (*(OUTPUT_VECTOR.begin())).rows();
	int output_vector_col = (*(OUTPUT_VECTOR.begin())).cols();
	int state_matrix_row = (*(STATE_MATRIX.begin())).rows();
	int state_matrix_col = (*(STATE_MATRIX.begin())).cols();


	MatrixXd state = MatrixXd::Constant(2, 1, 0);
	MatrixXd P = MatrixXd::Identity(2, 2);
	MatrixXd G_K_P, K_k;
	MatrixXd temp_k = G_K_P = G(0, N - p - 1, STATE_MATRIX).inverse();//fix state matrix ------ accelerated computing

	MatrixXd Z_K = MatrixXd::Constant(output_vector_row * s, output_vector_col, 0);
	MatrixXd L_K = MatrixXd::Constant(output_vector_row * s, state_matrix_col, 0);
	for (int k = N; k <= (simulation_time / delta_time); k++)
	{
		if (k > N)
		{
			//G_K_P = G(k - p - 1, k, STATE_MATRIX);
			G_K_P = STATE_MATRIX[k - p - 1];
			K_k = P * G_K_P.transpose() * output_matrix.transpose() * (output_matrix * G_K_P * P * G_K_P.transpose() * output_matrix.transpose() + MatrixXd::Identity(output_vector_row, output_vector_row)).inverse();
			state = state + K_k * (*(OUTPUT_VECTOR.begin() + k - 1) - output_matrix * G_K_P * state);
			P = P - K_k * output_matrix * G_K_P * P;

			//G_K_P = G(k - N, k - p - 1, STATE_MATRIX).inverse();
			G_K_P = temp_k;
			K_k = P * G_K_P.transpose() * output_matrix.transpose() * (output_matrix * G_K_P * P * G_K_P.transpose() * output_matrix.transpose() - MatrixXd::Identity(output_vector_row, output_vector_row)).inverse();
			state = state + K_k * (*(OUTPUT_VECTOR.begin() + k - 1 - N) - output_matrix * G_K_P * state);
			P = P - K_k * output_matrix * G_K_P * P;

			state = STATE_MATRIX[k - p - 1] * state;
			P = STATE_MATRIX[k - p - 1] * P * STATE_MATRIX[k - p - 1].transpose();
			RESULT.push_back(state);
		}
		else
		{
			for (int i = 0; i < s; i++)
			{
				Z_K.block(i * output_vector_row, 0, output_vector_row, output_vector_col) = *(OUTPUT_VECTOR.begin() + i);
				L_K.block(i * output_matrix.rows(), 0, output_vector_row, state_matrix_col) = output_matrix * G(i, s - 1, STATE_MATRIX).inverse();
			}
			state = (L_K.transpose() * L_K).inverse() * L_K.transpose() * Z_K;
			P = (L_K.transpose() * L_K).inverse();
			for (int i = s; i < k; i++)
			{
				P = (output_matrix.transpose() * output_matrix + (state_matrix * P * state_matrix.transpose()).inverse()).inverse();
				state = STATE_MATRIX[i - 1] * state + P * output_matrix.transpose() * (*(OUTPUT_VECTOR.begin() + i) - output_matrix * STATE_MATRIX[i - 1] * state);
			}
			state = G(k - p, k, STATE_MATRIX).inverse() * state;
			P = G(k - p, k, STATE_MATRIX).inverse() * P * (G(k - p, k, STATE_MATRIX).inverse()).transpose();
			RESULT.push_back(state);
		}
	}
}

