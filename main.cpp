#include"utils.h"
#include"Data.h"
#include"KLUDA.h"
#include"UFIR.h"
#include"KF.h"

int main()
{
    //simulation data
    vector<MatrixXd> true_state, output_vector, state_matrix;
    generate_data(true_state, output_vector, state_matrix);
    

    int N[] = { 10,20,30 };
    for (int i = 0; i < 3; i++)
    {
        //simulation
        cout << "N=" << N[i] << endl;
        vector<MatrixXd> result1, result2;

        //KLUDA
        auto start = std::chrono::high_resolution_clock::now();
        kluda(output_vector, state_matrix, result1, N[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end - start;
        std::cout << "simulation time: " << elapsed_time.count() << " second" << std::endl;

        //TUFIR
        start = std::chrono::high_resolution_clock::now();
        ufir(output_vector, state_matrix, result2, N[i]);
        auto end2 = std::chrono::high_resolution_clock::now();
        elapsed_time = end2 - start;
        std::cout << "simulation time: " << elapsed_time.count() << " second" << std::endl;

        //KF
        start = std::chrono::high_resolution_clock::now();
        kf(output_vector, state_matrix,result2);
        auto end3 = std::chrono::high_resolution_clock::now();
        elapsed_time = end3 - start;
        std::cout << "simulation time: " << elapsed_time.count() << " second" << std::endl;


        //output raw data
        Output_kluda( result1, N[i]);
        Output_ufir( result2, N[i]);
        output_true_state(true_state, N[i]);
    }
    
}
