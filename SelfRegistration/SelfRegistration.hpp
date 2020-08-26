#ifndef SELFREGISTRATION_H
#define SELFREGISTRATION_H

#include <memory>


#define constructRegistrationMap(CtorName,BaseClass,CtorArgs,CtorParams)       \
    typedef unique_ptr<BaseClass> (*CtorName##CtorPtrType)CtorArgs;            \
    typedef map<string, CtorName##CtorPtrType> CtorName##CtorMap;              \
    static CtorName##CtorMap* CtorName##CtorMapPtr;                            \
                                                                               \
    static void construct##CtorName##CtorMaps();                               \
    static void destroy##CtorName##CtorMaps();                                 \
                                                                               \
    template<class CSolverDerived>                                             \
    class register##CtorName##CtorToMap                                        \
    {                                                                          \
    public:                                                                    \
        static unique_ptr<BaseClass> CreateMethod CtorArgs                     \
        {                                                                      \
            return unique_ptr<BaseClass>(new CSolverDerived CtorParams );      \
        }                                                                      \
                                                                               \
        register##CtorName##CtorToMap                                          \
        (                                                                      \
            const string& class_name = CSolverDerived::ClassName               \
        )                                                                      \
        {                                                                      \
            construct##CtorName##CtorMaps();                                   \
            if (CtorName##CtorMapPtr->find(class_name)                         \
                    == CtorName##CtorMapPtr->end() )                           \
            {                                                                  \
                (*CtorName##CtorMapPtr)[class_name] = CreateMethod;            \
            } else {                                                           \
                cerr << "ERROR: Attempting to register "                       \
                    << class_name << " twice.";                                \
                exit(1);                                                       \
            }                                                                  \
        }                                                                      \
                                                                               \
        ~register##CtorName##CtorToMap()                                       \
        {                                                                      \
            destroy##CtorName##CtorMaps();                                     \
        }                                                                      \
    };                                                                         \


#define defineRegistrationConstructor(CtorName, BaseClass)                     \
    BaseClass::CtorName##CtorMap* BaseClass::CtorName##CtorMapPtr = nullptr;   \
    void CSolver::construct##CtorName##CtorMaps()                              \
    {                                                                          \
        static bool is_constructed = false;                                    \
        if (!is_constructed)                                                   \
        {                                                                      \
            is_constructed = true;                                             \
            BaseClass::CtorName##CtorMapPtr                                    \
                = new BaseClass::CtorName##CtorMap;                            \
        }                                                                      \
    }                                                                          \
    void BaseClass::destroy##CtorName##CtorMaps()                              \
    {                                                                          \
        if (BaseClass::CtorName##CtorMapPtr)                                   \
        {                                                                      \
            delete BaseClass::CtorName##CtorMapPtr;                            \
            BaseClass::CtorName##CtorMapPtr = nullptr;                         \
        }                                                                      \
    }                                                                          \


#define registerConstructorToParent(CtorName, BaseClass, DerivedClass)         \
    BaseClass::register##CtorName##CtorToMap<DerivedClass>                     \
        register##DerivedType##CtorName##CtorTo##BaseClass##Map;

#endif /* SELFREGISTRATION_H */
