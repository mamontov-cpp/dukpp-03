/*! \file isnotpodreference.h
    
    Contains a trait, whether data is not POD reference
 */
#pragma once
#include <string>

namespace dukpp03
{

/*! By default  it's not POD reference
 */
template<
   typename T
>
struct IsNotPODReference
{
    inline static void typeMustBe() {}
};


/*! A macro for type substitution
 */
#define DUKPP03_TYPE(TYPE) TYPE

#define DUKPP03_TYPE_IPR(TYPE) template<> struct IsNotPODReference< DUKPP03_TYPE(TYPE) &> {  };

DUKPP03_TYPE_IPR(char)
DUKPP03_TYPE_IPR(signed char)
DUKPP03_TYPE_IPR(unsigned char)
DUKPP03_TYPE_IPR(short)
DUKPP03_TYPE_IPR(unsigned short)
DUKPP03_TYPE_IPR(int)
DUKPP03_TYPE_IPR(unsigned int)
DUKPP03_TYPE_IPR(long)
DUKPP03_TYPE_IPR(unsigned long)
DUKPP03_TYPE_IPR(long long)
DUKPP03_TYPE_IPR(unsigned long long)
DUKPP03_TYPE_IPR(std::string)

}