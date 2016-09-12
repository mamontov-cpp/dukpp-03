/*! \file id.h
    
    Describes a simple identifier, used to identify variants in pool
 */
#pragma once
#include <string>

namespace dukpp03
{

/*! A simple identifier, used to identify variants in pool
 */
class Id 
{
public:
    /*! Constructs new identifier
     */
    Id();
    /*! Returns string representation for identifier
        \return bytes representation for id
     */
    const std::string& bytes() const;
    /*! Increments identifier by one
     */
    void next();
private:
    /*! A string storage for storing numeric bytes of identifier
     */
    std::string m_bytes;
};  
    
}
