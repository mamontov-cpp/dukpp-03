#include "../include/object.h"
#include "../include/abstractcallable.h"
#include "../include/abstractcontext.h"

#include <cassert>
#include <algorithm>


// ======================================== PUBLIC METHODS ========================================

dukpp03::Object::Object()
{
	
}


dukpp03::Object::Object(const dukpp03::Object& o)
{
	this->copy(o);
}

dukpp03::Object& dukpp03::Object::operator=(const dukpp03::Object& o)
{
	this->destroy();
	this->copy(o);
	return *this;
}


dukpp03::Object::~Object()
{
	this->destroy();
}

void dukpp03::Object::push(dukpp03::AbstractContext* ctx)
{
	duk_push_object(ctx->context());
	for(size_t i = 0 ; i < m_property_names.size(); i++)
	{
		m_property_values[i]->push(ctx);
		duk_put_prop_string(ctx->context(), -2 /*idx:global*/, m_property_names[i].c_str());
	}
}

void dukpp03::Object::registerIn(dukpp03::AbstractContext* ctx, const std::string& name)
{
   duk_push_global_object(ctx->context());
   
   this->push(ctx);

   duk_put_prop_string(ctx->context(), -2 /*idx:global*/, name.c_str());
   duk_pop(ctx->context());  
}

void dukpp03::Object::addProperty(const std::string& name, dukpp03::AbstractCallable* val, bool own)
{
	this->addProperty(name, new dukpp03::Object::CallableField(val, own));
}

void dukpp03::Object::addProperty(const std::string& name, dukpp03::Object* val)
{
	this->addProperty(name, new dukpp03::Object::ObjectField(val));
}

void dukpp03::Object::addProperty(const std::string& name, const std::string val)
{
	this->addProperty(name, new dukpp03::Object::EvalField(val));	
}

void dukpp03::Object::removeProperty(const std::string& name)
{
	std::vector<std::string>::iterator it = std::find(m_property_names.begin(), m_property_names.end(), name);
	if (it != m_property_names.end())
	{
		std::vector<dukpp03::Object::Field*>::iterator iit = m_property_values.begin() + (it - m_property_names.begin());
		delete (*iit);
		m_property_values.erase(iit);
		m_property_names.erase(it);
	}
}

// ======================================== PROTECTED METHODS (dukpp03::Object::Field) ========================================


dukpp03::Object::Field::Field()
{

}


dukpp03::Object::Field::~Field()
{

}


// ======================================== PROTECTED METHODS (dukpp03::Object::CallableField) ========================================

dukpp03::Object::CallableField::CallableField(dukpp03::AbstractCallable* callable, bool own) : m_callable(callable), m_own(own)
{
	
}

dukpp03::Object::CallableField::~CallableField()
{
	if (m_own)
	{
		delete m_callable;
	}
}

void dukpp03::Object::CallableField::push(dukpp03::AbstractContext* ctx)
{
	ctx->pushCallable(m_callable, false);
}

dukpp03::Object::Field* dukpp03::Object::CallableField::clone()
{
	return new dukpp03::Object::CallableField(m_callable, false);
}


// ======================================== PROTECTED METHODS (dukpp03::Object::CallableField) ========================================

dukpp03::Object::ObjectField::ObjectField(dukpp03::Object* o) : m_object(o)
{
	
}

dukpp03::Object::ObjectField::~ObjectField()
{
	delete m_object;
}

void dukpp03::Object::ObjectField::push(dukpp03::AbstractContext* ctx)
{
	m_object->push(ctx);
}

dukpp03::Object::Field* dukpp03::Object::ObjectField::clone()
{
	return new dukpp03::Object::ObjectField(new dukpp03::Object(*m_object));
}

// ======================================== PROTECTED METHODS (dukpp03::Object::EvalField) ========================================

dukpp03::Object::EvalField::EvalField(const std::string& s) : m_value(s)
{
	
}

dukpp03::Object::EvalField::~EvalField()
{
	
}


void dukpp03::Object::EvalField::push(dukpp03::AbstractContext* ctx)
{
	int beforeStack = ctx->getTop();
	std::string error;
	bool result = ctx->eval(m_value, false, &error);

	assert( result );
	int afterStack  = ctx->getTop();
	assert( (afterStack - beforeStack) == 1 );
}

dukpp03::Object::Field* dukpp03::Object::EvalField::clone()
{
	return new dukpp03::Object::EvalField(m_value);
}

// ======================================== PROTECTED METHODS ========================================

void dukpp03::Object::copy(const dukpp03::Object& o)
{
	m_property_names = o.m_property_names;
	m_property_values = o.m_property_values;
	for(size_t i = 0; i < m_property_values.size(); i++)
	{
		m_property_values[i] = m_property_values[i]->clone();
	}
}

void dukpp03::Object::destroy()
{
	m_property_names.clear();
	for(size_t i = 0; i < m_property_values.size(); i++)
	{
		delete m_property_values[i];
	}
	m_property_values.clear();
}

void dukpp03::Object::addProperty(const std::string& name, dukpp03::Object::Field* val)
{
	std::vector<std::string>::iterator it = std::find(m_property_names.begin(), m_property_names.end(), name);
	if (it != m_property_names.end())
	{
		std::vector<dukpp03::Object::Field*>::iterator iit = m_property_values.begin() + (it - m_property_names.begin());
		delete (*iit);
		*iit = val;
	}
	else
	{
		m_property_names.push_back(name);
		m_property_values.push_back(val);
	}
}