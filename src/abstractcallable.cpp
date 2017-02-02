#include "../include/abstractcallable.h"

dukpp03::ArgumentException::ArgumentException() : std::runtime_error("Bad argument")
{

}

dukpp03::ArgumentException::~ArgumentException() throw()
{

}

bool dukpp03::AbstractCallable::canBeCalledAsConstructor()
{
    return true;
}

bool dukpp03::AbstractCallable::canBeCalledAsFunction()
{
    return true;
}

dukpp03::AbstractCallable::~AbstractCallable()
{
    
}
