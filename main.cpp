//
// USAGE:
//   - "./main" runs with no custom solvers loaded
//   - "./main libCCustomSolvers.so" loads custom solvers from shared lib
//

#include <memory>
#include <iostream>
#include "CSolver/CSolver.hpp"
#include <dlfcn.h>


using namespace std;

int main(int argc, char *argv[])
{
    void* lib;
    if (argc > 1)
    {
        lib = dlopen(argv[1], RTLD_LAZY);
        if (!lib)
        {
            cerr << "Could not load library" << endl;
        }
        dlerror();
    }

    // !! We should also check if the loaded lib
    // !! added anything to the registry map

    // Now Print known solvers
    for (auto v: *CSolver::FromStringCtorMapPtr)
    {
        cout << v.first << endl;
    }

    if (argc > 1)
    {
        dlclose(argv[1]);
    }
}
