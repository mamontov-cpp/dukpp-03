/*! \file object.h
    
	Describes an object, which can be used to push some complex objects on stack
 */
#pragma once
#include <string>
#include <vector>

namespace dukpp03
{

class AbstractContext;	
class AbstractCallable;

/*! A JS object, as set of fields
 */
class Object
{
public:
	/*! A new empty object
	 */
	Object();
	/*! Copies this object
	    \param[in] o object
	 */
	Object(const dukpp03::Object& o);
	/*! Performs assignment to this object
	    \param[in] o other object
	    \return self-reference
	 */
	Object& operator=(const dukpp03::Object& o);
	/*! Destroys any related items in object
	 */
	~Object();
	/*! Pushes new object on stack of context
	    \param[in] ctx context
	 */ 
	void push(dukpp03::AbstractContext* ctx);
	/*! Registers object as global in some context
	    \param[in] ctx context
	    \param[in] name a name of object as field
	 */
	void registerIn(dukpp03::AbstractContext* ctx, const std::string& name);
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[in] val a value
	    \param[in] own whether we own it
	 */
	void addProperty(const std::string& name, dukpp03::AbstractCallable* val, bool own = true);
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[on] val a value
	 */
	void addProperty(const std::string& name, dukpp03::Object* val);
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[on] val a value, that will be evaluated in context
	 */
	void addProperty(const std::string& name, const std::string val);
	/*! Removes property from object
	    \param[in] name a name for property of object
	 */
	void removeProperty(const std::string& name);
protected:
/*! A field of object
 */
class Field
{
public:
	/*! Does nothing
	 */
	Field();
	/*! Can be inherited
	 */
	virtual ~Field();
	/*! Pushes a field in context
	    \param[in] ctx context
	 */
	virtual void push(dukpp03::AbstractContext* ctx) = 0;
	/*! Clones a field 
	 */
	virtual dukpp03::Object::Field* clone() = 0;
};


/*! A field of object with callable value
 */
class CallableField: public dukpp03::Object::Field
{
public:
	/*! Initializes object with callable value
	    \param[in] callable a callable value
		\param[in] own whether we own the callable
	 */
	CallableField(dukpp03::AbstractCallable* callable, bool own);
	/*! Can be inherited
	 */
	virtual ~CallableField();
	/*! Pushes a field in context
	    \param[in] ctx context
	 */
	virtual void push(dukpp03::AbstractContext* ctx);
	/*! Clones a field 
	 */
	virtual dukpp03::Object::Field* clone();
protected:
	/*! A stored callable value
	 */
	dukpp03::AbstractCallable* m_callable;
	/*! Whether we own the callable
	 */
	bool m_own;
};

/*! A field of object with object value
 */
class ObjectField: public dukpp03::Object::Field
{
public:
	/*! Initializes field with object value
	    \param[in] o object 
	 */
	ObjectField(dukpp03::Object* o);
	/*! Can be inherited
	 */
	virtual ~ObjectField();
	/*! Pushes a field in context
	    \param[in] ctx context
	 */
	virtual void push(dukpp03::AbstractContext* ctx);
	/*! Clones a field 
	 */
	virtual dukpp03::Object::Field* clone();
protected:
	/*! An inner object, stored as field
	 */
	dukpp03::Object* m_object;
};



/*! A field of object with evaluated value
 */
class EvalField: public dukpp03::Object::Field
{
public:
	/*! Initializes object with evaluated value
	    \param[in] s string
	 */
	EvalField(const std::string& s);
	/*! Can be inherited
	 */
	virtual ~EvalField();
	/*! Pushes a field in context
	    \param[in] ctx context
	 */
	virtual void push(dukpp03::AbstractContext* ctx);
	/*! Clones a field 
	 */
	virtual dukpp03::Object::Field* clone();
protected:
	/*! An inner value
	 */
	std::string m_value;
};
	/*! Copies object state into self
	    \param[in] o object
	 */
	void copy(const dukpp03::Object& o);
	/*! Destroys all items in object
	 */
	void destroy();
	/*! Adds new property to object. If property exists, replaces it
	    \param[in] name a name of property
        \param[on] val a value
	 */
	void addProperty(const std::string& name, dukpp03::Object::Field* val);
	/*! A list of property names
	 */
	std::vector<std::string> m_property_names;
	/*! A property value list
	 */
	std::vector<dukpp03::Object::Field* > m_property_values;
};


}
