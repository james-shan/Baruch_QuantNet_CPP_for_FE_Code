//
//  TestMC.cpp
//  MonteCarlo
//
//  C++ code to price an option, essential algorithms.
//
//  We take CEV model with a choice of the elaticity parameter
//  and teh Euler method. We give option price and number of times
//  S hits the origin.
//


#include "OptionData.hpp"
#include "SDSE.hpp"
#include "UtilitiesDJD/RNG/NormalGenerator.cpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"
#include <vector>
#include <iostream>
using namespace std;


template <class T> void print (const vector<T>& l)
{ // A generic print function for vectors
    
    cout << endl << "Size of vector is " << l.size() << "\n[";
    
    // We must use a const iterator here, otherwise we get a compiler error.
    typename vector<T>::const_iterator i;
    for (i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << ",";
    }
    
    cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data
    
    OptionData* data;        // The data for the option MC
    
    double drift(double t, double X)
    { // Drift term
        
        return (data->r)*X; // r - D
        // return (date->r-D)*X;
    }
    
    double diffusion(double t, double X)
    { // Diffusion term
        
        double betaCEV = 1.0;
        return data->sig * pow(X, betaCEV);
    }
    
    double diffusionDerivative(double t, double X)
    { // Diffusion term, needed for the Milstein method
        
        double betaCEV = 1.0;
        return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
    }
} // End of namespace


int main()
{
    std::cout << "1 factor Monte Carlo with explicit Euler\n";

    /*
    // Batch 1
    OptionData myOption;
    myOption.K = 65.0;
    myOption.T = 0.25;
    myOption.r = 0.08;
    myOption.sig = 0.3;
    myOption.type = 1;   // Put: -1, Call: +1
    double S_0 = 60;
     */

    // Batch 2
    OptionData myOption;
    myOption.K = 100.0;
    myOption.T = 1.00;
    myOption.r = 0.00;
    myOption.sig = 0.2;
    myOption.type = -1;   // Put -1, Call +1
    double S_0 = 100.00;
    

    long N = 100;
    std::cout << "Number of subintervals in time: ";
    std::cin >> N;

    // Create the basic SDE (Context class)
    Range<double> range(0.0, myOption.T);
    double VOld = S_0;
    double VNew = VOld; // Initialized it

    Vector<double, long> x = range.mesh(N);

    // V2 mediator stuff
    long NSim = 50000;
    std::cout << "Number of simulations: ";
    std::cin >> NSim;

    double k = myOption.T / static_cast<double>(N);
    double sqrk = sqrt(k);

    // Normal random number
    double dW;
    double price = 0.0;  // Option price
    std::vector<double> CTjs; // Vector to store prices

    // NormalGenerator is a base class
    NormalGenerator* myNormal = new BoostNormal();

    using namespace SDEDefinition;
    data = &myOption;

    std::vector<double> res;
    int coun = 0; // Number of times S hits origin

    // A.
    for (long i = 1; i <= NSim; ++i)
    { // Calculate a path at each iteration

        if ((i / 10000) * 10000 == i)
        { // Give status after each 10000th iteration
            std::cout << i << std::endl;
        }

        VOld = S_0;
        for (long index = x.MinIndex() + 1; index <= x.MaxIndex(); ++index)
        {
            // Create a random number
            dW = myNormal->getNormal();

            // The FDM (in this case explicit Euler)
            VNew = VOld + (k * drift(x[index - 1], VOld))
                + (sqrk * diffusion(x[index - 1], VOld) * dW);

            VOld = VNew;

            // Spurious values
            if (VNew <= 0) coun++;
        }

        double tmp = myOption.myPayOffFunction(VNew); // Calculate call price at t=T
        price += (tmp) / static_cast<double>(NSim);

        CTjs.push_back(tmp);
    }

    // D. Finally, discounting the average price
    price *= exp(-myOption.r * myOption.T);

    // Cleanup; V2 use scoped pointer
    delete myNormal;

    std::cout << "Price, after discounting: " << price << ", " << std::endl;
    std::cout << "Number of times origin is hit: " << coun << std::endl;
    std::cout << "SD: " << optionSD(CTjs, myOption.r, myOption.T)
        << ", SE: " << optionSE(CTjs, myOption.r, myOption.T) << std::endl;

    return 0;
}

