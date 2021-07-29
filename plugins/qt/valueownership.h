/*! \file valueownership.h
 
    Describes a type of ownership in value
 */
#pragma once


namespace dukpp03
{
    
namespace qt
{
    
/*! Describes a type of ownership in value
 */ 
enum class ValueOwnership: int
{
    /*! Script owns and destroys QObject
     */ 
    DQ_SCRIPT,
    /*! QObject owned by external code and must be destroyed manually
     */
    DQ_OWN
};

}

}