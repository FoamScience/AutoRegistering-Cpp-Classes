#include "CEulerSolver/CEulerSolver.hpp"


// Static Variables initialization
string CEulerSolver::ClassName = "CEulerSolver";
// Instantiate a helper object to register
// CEulerSolver to CSolver's map
CSolver::registerFromStringCtorToMap<CEulerSolver>
    registerCEulerSolverFromStringCtorToCSolverMap;
