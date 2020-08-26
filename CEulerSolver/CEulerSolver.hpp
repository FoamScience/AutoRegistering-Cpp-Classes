#ifndef CEULERSOLVER_H
#define CEULERSOLVER_H

#include <string>
#include "CSolver/CSolver.hpp"

using namespace std;

// All Solvers then need to inherit from CSolver
class CEulerSolver : public CSolver
{
public:

    // This is required
    static string ClassName;

	// The custom ctor
	CEulerSolver(const string& m, const int n) : CSolver(m,n) {}

};

#endif /* CEULERSOLVER_H */
