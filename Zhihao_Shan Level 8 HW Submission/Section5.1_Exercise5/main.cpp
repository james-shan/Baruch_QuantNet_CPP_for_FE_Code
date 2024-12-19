//
//  main.cpp
//  Section5.1_Exercise4
//
//  Created by Zhihao Shan on 2023/7/14.
//
//  This program tries random from boost

#include <boost/random.hpp>
#include <ctime>
#include <map>
#include <iostream>
using namespace std;

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;


int main()
{
    //-----------------Exponential Distribution-------------------------//
    
    // Don't forget to tell compiler which namespace
    using namespace boost::math;
    
    double x = 5.5;
    double scaleParameter = 0.5;
    exponential_distribution<> myExponential(scaleParameter); // Default type is 'double'
    
    cout << "Mean:" << mean(myExponential) << ",standard deviation: "
    << standard_deviation(myExponential) << endl;
    
    // Distributional properties
    // Print pdf and cdf of specified x
    cout << "pdf: " << pdf(myExponential, x) << endl;
    cout << "cdf: " << cdf(myExponential, x) << endl;
    
    // Choose another data type and now a N(0,1) variate
    exponential_distribution<float> myExponential2(2*scaleParameter);
    cout << "Mean: " << mean(myExponential2) << ", standard deviation: "
    << standard_deviation(myExponential2) << endl;
    
    cout << "pdf: " << pdf(myExponential2, x) << endl;
    cout << "cdf: " << cdf(myExponential2, x) << endl;

    // Other properties
    cout << "\n***exponential distribution: \n";
    cout << "mean: " << mean(myExponential) << endl;
    cout << "variance: " << variance(myExponential) << endl;
    cout << "median: " << median(myExponential) << endl;
    cout << "mode: " << mode(myExponential) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
    cout << "kurtosis: " << kurtosis(myExponential) << endl;
    cout << "characteristic function: " << chf(myExponential, x) << endl;
    cout << "hazard: " << hazard(myExponential, x) << endl;

    //-----------------Poisson Distribution-------------------------//
        
    double mean = 5;
    poisson_distribution<double> myPoisson(mean);
    
    // Print pdf and cdf of specified x
    x = 5.0;
    cout << "\n\n***Poisson distribution: \n";
    cout << endl <<  "pdf: " << pdf(myPoisson, x) << endl;
    cout << "cdf: " << cdf(myPoisson, x) << endl;
    
    vector<double> pdfList;
    vector<double> cdfList;
    
    double start = 0.0;
    double end = 10.0;
    long N = 30; // Number of subdivisions
    
    x = 0;
    double h = (end - start) / double(N);
    
    for (long j = 1; j <= N; ++j)
    {
        pdfList.push_back(pdf(myPoisson, x));
        cdfList.push_back(cdf(myPoisson, x));
        
        x += h;
    }
    
    for (long j = 0; j < pdfList.size(); ++j)
    {
        cout << pdfList[j] << ", ";
        
    }
    
    cout << "***" << endl;
    
    for (long j = 0; j < cdfList.size(); ++j)
    {
        cout << cdfList[j] << ", ";
    }
    
    cout<<endl;
        
    

    return 0;
}



