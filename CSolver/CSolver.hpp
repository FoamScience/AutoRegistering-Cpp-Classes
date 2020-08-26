#ifndef CSOLVER_H
#define CSOLVER_H

#include <iostream>
#include <memory>
#include <map>
#include "SelfRegistration/SelfRegistration.hpp"
using namespace std;

class CSolver
{
public: 
	// Default ctor/dtor
	CSolver() = default;
	virtual ~CSolver() = default;

	// Custom Ctor
	CSolver(const string& m, const int n) {} // <-----------------------------+
    //                                                                        |
    //  !! Chosen pointer type for CSolver model is unique_ptr                |
    //  !! But can also be "macroed"                                          |
    //  !! i.e. When we create a solver we always return unique_ptr<CSolver>  |
    //                                                                        |   
    //  !! The idea is to give a constructor a name instead of forcing        |
    //  !! devs to create the CreateMethod. You need to have a constructor    |
    //  !! anyway, so just name it                                            |
    //                                                                        |
    //  !! Obviously, we can have multiple ctors and can register them all    |
    //                                                                        |
    // CtorName = FromString    >---------------------------------------------+
    // BaseClass = CSolver
    // CtorArgs  = (const string& m, const int n)
    // CtorParams  = (m , n)

    constructRegistrationMap(
        FromString,
        CSolver,
        ( const string& m, const int n),
        (m, n)
    );
};

#endif /* CSOLVER_H */
