//
//  main.cpp
//  GroupB
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This file implements AmericanOption Class to do the compute price

#include "AmericanOption.hpp"
#include "ArrayFuncs.hpp"
#include "MatrixFuncs.hpp"

int main()
{
    // ---------------------------------- B(a) ---------------------------------------
    // Code to accomodate American Option is implemented in AmericanOption class and PricingFuncs
    
    
    // ---------------------------------- B(b) ---------------------------------------
    cout << "\nB(b) Outputs:"<<endl;
    
    // Initialize AmericanOption Class
    double K = 100;
    double sig = 0.1;
    double r = 0.1;
    double b = 0.02;
    double S = 110;
    AmericanOption option1;
    option1.SetOption(K, sig, r, b, S);
    
    // Compute price and show result
    cout << "Price, call, " << option1.PerpetualPrice() << endl;
    option1.toggle();
    cout << "Price, put, " << option1.PerpetualPrice() << endl << endl;
    option1.toggle();
    
    
    // ---------------------------------- B(c) ---------------------------------------
    cout << "\nB(c) Outputs:"<<endl;
    
    // Set S vector
    double S_start         =  105.0;
    double S_end           =  115.0;
    double S_interval      =  1.0;
    vector<double> S_array = MeshArray(S_start, S_end, S_interval);
    
    // Compute call/put price as a function of S and show result
    vector<double> S_CallPrices = option1.PerpetualPrice(S_array);
    option1.toggle();
    vector<double> S_PutPrices = option1.PerpetualPrice(S_array);
    option1.toggle();
    
    cout << "S of option, Call Price, Put Price" << endl;
    PrintArray(S_array, S_CallPrices, S_PutPrices);
    
    
    // ---------------------------------- B(d) ---------------------------------------
    cout << "\nB(d) Outputs:"<<endl;
    
    // initialize input paramter matrix
    double K_start         = 95.00;
    double K_end           = 105.00;
    double K_interval      = 1.00;
    vector<double> K_array = MeshArray(K_start, K_end, K_interval);
    
    double sig_start         = 0.10;
    double sig_end           = 0.50;
    double sig_interval      = 0.05;
    vector<double> sig_array = MeshArray(sig_start, sig_end, sig_interval);
    
    double r_start         = 0.05;
    double r_end           =  0.15;
    double r_interval      =  0.01;
    vector<double> r_array = MeshArray(r_start, r_end, r_interval);
    
    double b_start         =  0.01;
    double b_end           =  0.05;
    double b_interval      =  0.01;
    vector<double> b_array = MeshArray(b_start, b_end, b_interval);

    vector<vector<double>> params;
    params.push_back(K_array);
    params.push_back(sig_array);
    params.push_back(r_array);
    params.push_back(b_array);
    params.push_back(S_array);
    
    // show input parameter matrix
    cout<<"Input Parameter Matrix:"<<endl;
    cout<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(params);
    
    // Compute prices with input parameter matrix
    vector<vector<double>> prices = option1.PerpetualPrice(params);
    
    // show result
    cout<<"\nCall Price depending on each parameter range:"<<endl;
    cout<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(prices);
    
    // Compute prices with input parameter matrix on Put options
    option1.toggle();
    prices = option1.PerpetualPrice(params);
    option1.toggle();
    
    // show result
    cout<<"\nPut Price depending on each parameter range:"<<endl;
    cout<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(prices);
    
    return 0;
}
