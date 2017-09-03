#include "object.h"
#include "context.h"
#include <vector>
#include <utility>
#include <stdexcept>

namespace dukpp03
{

template<typename _Context>
class JSObject: public dukpp03::Object
{
public:
    /*! Makes new empty object
     */
    JSObject() : m_is_null(false)
    {
        
    }

    /*! Releases existing resources, destroying object
     */
    virtual ~JSObject()
    {
        
    }

    /*! Registers object as global in some context
	    \param[in] ctx context
	    \param[in] name a name of object as field
	 */
	virtual void registerIn(dukpp03::AbstractContext* ctx, const std::string& name)
    {
        throw new std::logic_error("This context is incompatible with this object");
    }


    /*! Registers object as global in some context
	    \param[in] ctx context
	    \param[in] name a name of object as field
	 */
	virtual void registerIn(_Context* ctx, const std::string& name)
    {
        m_registered_in.push_back(std::make_pair(ctx, name));
        this->dukpp03::Object::registerIn(ctx, name);
    }

	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[in] val a value
	    \param[in] own whether we own it
	 */
	virtual void addProperty(const std::string& name, dukpp03::AbstractCallable* val, bool own = true)
    {
        if (m_is_null)
        {
            throw new std::logic_error("Attempted to add property to a null object");
        }

        // TODO: 
    }
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[on] val a value
	 */
	virtual void addProperty(const std::string& name, dukpp03::JSObject<_Context>* val)
	{
        if (m_is_null)
        {
            throw new std::logic_error("Attempted to add property to a null object");
        }

        // TODO: 
    }
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[on] val a value
	 */
	virtual void addProperty(const std::string& name, dukpp03::Object* val)
	{
        if (m_is_null)
        {
            throw new std::logic_error("Attempted to add property to a null object");
        }
	    throw new std::logic_error("dukpp03::Object cannot be placed into dukpp03::JSObject");
	}
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[on] val a value, that will be evaluated in context
	 */
	virtual void addProperty(const std::string& name, const std::string val)
    {
        if (m_is_null)
        {
            throw new std::logic_error("Attempted to add property to a null object");
        }

        // TODO: 
    }
	/*! Removes property from object
	    \param[in] name a name for property of object
	 */
	virtual void removeProperty(const std::string& name)
    {
        this->dukpp03::Object::removeProperty(name);
        for(size_t i = 0; i < m_registered_in.size(); i++)
        {
            duk_context* c = m_registered_in[i].first;
            std::string parentname = m_registered_in[i].second;
            std::string rname = "delete ";
            rname += parentname;
            rname += ".";
            rname += name;
            rname += ";";
            duk_eval_string(c, rname.c_str());
        }
    }

    static JSObject<_Context>* null()
    {
        JSObject<_Context>* result = new JSObject<_Context>();
        result->m_is_null = true;
        return result;
    }

    /*! A names list for an object
        \return names of object in various context
     */
    const std::vector<std::pair<_Context*, std::string> >& names()
    {
        return m_registered_in;
    }

protected:

    /*! A contexts with name where object is registered
     */
    std::vector<std::pair<_Context*, std::string> > m_registered_in;
    /*! Whether we should push null value for object
     */
    bool m_is_null;
};


}