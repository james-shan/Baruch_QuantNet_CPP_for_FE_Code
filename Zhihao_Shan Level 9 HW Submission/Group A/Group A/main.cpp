//
//  main.cpp
//  GroupA
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This file implements EuropeanOption Class to do the compute price and greeks

#include "EuropeanOption.hpp"
#include "ArrayFuncs.hpp"
#include "MatrixFuncs.hpp"

int main()
{
    // Initialize data for each batch
    double T1 =  0.25;
    double K1 =  65.0;
    double sig1 =  0.30;
    double r1 =  0.08;
    double b1 =  0.08;
    double S1 =  60.0;
    
    double T2 =  1.00;
    double K2 =  100.00;
    double sig2 =  0.20;
    double r2 =  0.00;
    double b2 =  0.00;
    double S2 =  100.0;
    
    double T3 =  1.00;
    double K3 =  10.00;
    double sig3 =  0.50;
    double r3 =  0.12;
    double b3 =  0.12;
    double S3 =  5.00;
    
    double T4 =  30.00;
    double K4 =  100.00;
    double sig4 =  0.30;
    double r4 =  0.08;
    double b4 =  0.08;
    double S4 =  100.0;
    
    
    // ---------------------------------- A1(a) ---------------------------------------
    cout << "A1(a) Outputs:"<<endl;
    // Create and set an option with the specified values
    EuropeanOption option1;
    option1.SetOption(T1, K1, sig1, r1, b1, S1);
    cout << "Option1 Call price: " << option1.PriceEuro() << endl;
    option1.toggle();
    cout << "Option1 Put price: " << option1.PriceEuro() << endl;
    option1.toggle();
    
    EuropeanOption option2;
    option2.SetOption(T2, K2, sig2, r2, b2, S2);
    cout << "Option2 Call price: " << option2.PriceEuro() << endl;
    option2.toggle();
    cout << "Option2 Put price: " << option2.PriceEuro() << endl;
    option2.toggle();
    
    EuropeanOption option3;
    option3.SetOption(T3, K3, sig3, r3, b3, S3);
    cout << "Option3 Call price: " << option3.PriceEuro() << endl;
    option3.toggle();
    cout << "Option3 Put price: " << option3.PriceEuro() << endl;
    option3.toggle();
    
    EuropeanOption option4;
    option4.SetOption(T4, K4, sig4, r4, b4, S4);
    cout << "Option4 Call price: " << option4.PriceEuro() << endl;
    option4.toggle();
    cout << "Option4 Put price: " << option4.PriceEuro() << endl;
    option4.toggle();
    
    
    // ---------------------------------- A1(b) ---------------------------------------
    // Put-call parity
    cout <<"\nA1(b) Outputs:"<<endl;
    bool result1 = option1.PutCallParity();
    bool result2 = option2.PutCallParity();
    bool result3 = option3.PutCallParity();
    bool result4 = option4.PutCallParity();
    cout << "Put-call parity satisfied for Option1? " << (result1 ? "Yes." : "No.") << endl;
    cout << "Put-call parity satisfied for Option2? " << (result2 ? "Yes." : "No.") << endl;
    cout << "Put-call parity satisfied for Option3? " << (result3 ? "Yes." : "No.") << endl;
    cout << "Put-call parity satisfied for Option4? " << (result4 ? "Yes." : "No.") << endl;
    
    
    // ---------------------------------- A1(c) ---------------------------------------
    // Compute option price for a range of S
    cout <<"\nA1(c) Outputs:"<<endl;
    double S_start         =  55.0;
    double S_end           =  65.0;
    double S_interval      =  1.0;
    vector<double> S_array = MeshArray(S_start, S_end, S_interval);
    
    // Compute call/put price as a function of S and show result
    vector<double> S_CallPrices = option1.PriceEuro(S_array);
    option1.toggle();
    vector<double> S_PutPrices = option1.PriceEuro(S_array);
    option1.toggle();
    
    cout << "S of option, Call Price, Put Price" << endl;
    PrintArray(S_array, S_CallPrices, S_PutPrices);

    
    // ---------------------------------- A1(d) ---------------------------------------
    // initialize input paramter matrix
    cout <<"\nA1(d) Outputs:"<<endl;
    double T_start         = 1.00;
    double T_end           = 10.00;
    double T_interval      = 1.00;
    vector<double> T_array = MeshArray(T_start, T_end, T_interval);
    
    double K_start         = 60.00;
    double K_end           = 70.00;
    double K_interval      = 1.00;
    vector<double> K_array = MeshArray(K_start, K_end, K_interval);
    
    double sig_start         = 0.10;
    double sig_end           = 0.50;
    double sig_interval      = 0.05;
    vector<double> sig_array = MeshArray(sig_start, sig_end, sig_interval);
    
    double r_start         = 0.01;
    double r_end           =  0.10;
    double r_interval      =  0.01;
    vector<double> r_array = MeshArray(r_start, r_end, r_interval);
    
    double b_start         =  0.01;
    double b_end           =  0.10;
    double b_interval      =  0.01;
    vector<double> b_array = MeshArray(b_start, b_end, b_interval);
    
    vector<vector<double>> params;
    params.push_back(T_array);
    params.push_back(K_array);
    params.push_back(sig_array);
    params.push_back(r_array);
    params.push_back(b_array);
    params.push_back(S_array);
    
    // show input parameter matrix
    cout<<"Input Parameter Matrix:"<<endl;
    cout<<setw(12)<<"T"<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(params);
    
    // Compute prices with input parameter matrix
    vector<vector<double>> prices = option1.PriceEuro(params);
    
    // show result
    cout<<"\nCall Price depending on each parameter range:"<<endl;
    cout<<setw(12)<<"T"<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(prices);
    
    // Compute prices with input parameter matrix on Put options
    option1.toggle();
    prices = option1.PriceEuro(params);
    option1.toggle();
    
    // show result
    cout<<"\nPut Price depending on each parameter range:"<<endl;
    cout<<setw(12)<<"T"<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(prices);
    
    
    // ---------------------------------- A2(a) ---------------------------------------
    cout <<"\nA2(a) Outputs:"<<endl;
    // Initialize Futures option
    T1     =  0.5;
    K1     =  100.0;
    sig1   =  0.36;
    r1     =  0.1;
    b1     =  0.0;
    S1     =  105.0;
    option1.SetOption(T1, K1, sig1, r1, b1, S1);
    
    // Compute Delta, Gamma and output result
    cout << "Delta for call: " << option1.DeltaEuro() << endl;
    option1.toggle();
    cout << "Delta for put: " << option1.DeltaEuro() << endl;
    option1.toggle();
    cout << "Gamma: " << option1.GammaEuro() << endl;
    
    
    // ---------------------------------- A2(b) ---------------------------------------
    cout <<"\nA2(b) Outputs:"<<endl;
    // Specify a range of S
    S_start    =  55.0;
    S_end      =  65.0;
    S_interval =  1.00;
    S_array    = MeshArray(S_start, S_end, S_interval);
  
    // Compute delta for call for a range of S and show result
    vector<double> Deltas = option1.DeltaEuro(S_array);
    cout << "\n  S, Delta for Call" << endl;
    PrintArray(S_array, Deltas);
    
    // ---------------------------------- A2(c) ---------------------------------------
    cout <<"\nA2(c) Outputs:"<<endl;
    // show input parameter matrix (using the parameter matrix defined in A1(d)
    cout<<"Input Parameter Matrix:"<<endl;
    cout<<setw(12)<<"T"<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(params);
    
    // Compute deltas with input parameter matrix
    vector<vector<double>> deltas = option1.DeltaEuro(params);
    
    // show result
    cout<<"\nCall Deltas depending on each parameter range:"<<endl;
    cout<<setw(12)<<"T"<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(deltas);
    
    // Compute gammas with input parameter matrix
    vector<vector<double>> gammas = option1.GammaEuro(params);
    // show result
    cout<<"\nGamma depending on each parameter range:"<<endl;
    cout<<setw(12)<<"T"<<setw(12)<<"K"<<setw(12)<<"sig"<<setw(12)<<"r"<<setw(12)<<"b"<<"S"<<endl;
    PrintMatrix(gammas);
    
    // ---------------------------------- A2(d) ---------------------------------------
    cout <<"\nA2(d) Outputs:"<<endl;
    
    // initialize step size
    double h =  0.1;
    
    // Compute gamma and delta using exaxt formula
    cout << "\nGamma and Delta from the exact formula: " << endl;
    cout << "Gamma: " << option1.GammaEuro() << endl;
    cout << "Delta for call: " << option1.DeltaEuro() << endl;
    option1.toggle();
    cout << "Delta for put: " << option1.DeltaEuro() << endl;
    option1.toggle();
    
    // Compute Gamma and Delta using divided difference approximation
    cout << "\nGamma and Delta from divided difference approximation with step size 0.1:" << endl;
    cout << "Gamma: " << option1.GammaEuro(h) << endl;
    cout << "Delta for call: " << option1.DeltaEuro(h) << endl;
    option1.toggle();
    cout << "Delta for put: " << option1.DeltaEuro(h) << endl;
    option1.toggle();
    
    // do A2(b) with divided difference approximation
    Deltas = option1.DeltaEuro(S_array, h);
    cout << "\n  S, Delta for Call" << endl;
    PrintArray(S_array, Deltas);
    cout << endl;
    
    
    return 0;
     
}
