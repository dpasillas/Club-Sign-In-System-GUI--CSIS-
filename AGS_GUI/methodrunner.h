#ifndef METHODRUNNER_H
#define METHODRUNNER_H

template<typename Class, typename R_TYPE>
class MethodRunner
{
public:
    typedef R_TYPE (Class::*MPTR)();
    MethodRunner(Class *object, MPTR method)
    {
        obj = object;
        meth = method;
    }

    ~MethodRunner()
    {
        (obj->*meth)();
    }

private:
    Class* obj;
    MPTR meth;
};

#endif // METHODRUNNER_H
