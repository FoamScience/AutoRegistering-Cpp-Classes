#include "CCustomSolver/CCustomSolver.hpp"


// Static Variables initialization
string CCustomSolver::ClassName = "CCustomSolver";
// Declare templated class
CSolver::registerFromStringCtorToMap<CCustomSolver>
    registerCCustomSolverFromStringCtorToCSolverMap;
