#include <CSolver/CSolver.hpp>


// Static Variables initialization
CSolver::FromStringCtorMap* CSolver::FromStringCtorMapPtr = nullptr;

// Static Methods definition
void CSolver::constructFromStringCtorMaps()
{
    static bool is_constructed = false;
    if (!is_constructed)
    {
        is_constructed = true;
        CSolver::FromStringCtorMapPtr
            = new CSolver::FromStringCtorMap;
    }
}

void CSolver::destroyFromStringCtorMaps()
{
    if (CSolver::FromStringCtorMapPtr)
    {
        delete CSolver::FromStringCtorMapPtr;
        CSolver::FromStringCtorMapPtr = nullptr;
    }
}
