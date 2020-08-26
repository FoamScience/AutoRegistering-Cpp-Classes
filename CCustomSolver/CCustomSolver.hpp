#ifndef CCUSTOMSOLVER_H
#define CCUSTOMSOLVER_H

#include <string>
#include "CSolver/CSolver.hpp"

using namespace std;

class CCustomSolver : public CSolver
{
public:

    // This is required
    static string ClassName;

	// The custom constructor
	CCustomSolver(const string& m, const int n) : CSolver(m,n) {}

};

#endif /* CCUSTOMSOLVER_H */
