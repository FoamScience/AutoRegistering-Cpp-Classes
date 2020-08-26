#ifndef CSOLVER_H
#define CSOLVER_H

#include <iostream>
#include <memory>
#include <map>
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

    // Another "alias" for a unique_ptr to a solver is a pointer to its ctor.
    // Not a bad practice because the pointer never get dereferenced here
    typedef unique_ptr<CSolver> (*FromStringCtorPtrType)(const string& m, const int n);

    // The map type to register ctors to
    typedef map<string, FromStringCtorPtrType> FromStringCtorMap;

    // A pointer to the map object
    static FromStringCtorMap* FromStringCtorMapPtr;

    // Management of map pointer; should we use shared_ptr instead of raw??
    static void constructFromStringCtorMaps();
    static void destroyFromStringCtorMaps();

    // A template to Add a derived class to the registry
    template<class CSolverDerived>
    class registerFromStringCtorToMap
    {
    public:
        // The create method just calls the to-be-registered ctor now.
        static unique_ptr<CSolver> CreateMethod (const string& m, const int n)
        {
            return unique_ptr<CSolver>(new CSolverDerived (m, n));
        }

        // Get derived class name and register it if not already there
        registerFromStringCtorToMap
        (
            const string& className = CSolverDerived::ClassName
        )
        {
            constructFromStringCtorMaps();
            if (FromStringCtorMapPtr->find(className)
                    == FromStringCtorMapPtr->end() )
            {
                (*FromStringCtorMapPtr)[className] = CreateMethod;
            } else {
                cerr << "ERROR: Attempting to register "
                    << className << " twice.";
                exit(1);
            }
        }

        ~registerFromStringCtorToMap()
        {
            destroyFromStringCtorMaps();
        }
    };
};

#endif /* CSOLVER_H */
