#include "../include/abstractcallable.h"

dukpp03::ArgumentException::ArgumentException() : std::runtime_error("Bad argument")
{

}

dukpp03::ArgumentException::~ArgumentException() throw()
{

}

dukpp03::AbstractCallable::~AbstractCallable()
{
    
}
