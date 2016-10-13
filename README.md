# dukpp-03
A C++03 experimental bindings for Duktape library. This library allows to bind arbitrary classes and functions into Duktape and use them a scripting values. This library also implements timeouts for script execution. 

## Limitations

 * You cannot bind methods or functions, that require mutable references for plain types (int, char, long, etc.) or std::string
 * Own string will be passed as objects, unless corresponding instantiation of dukpp03::GetValue and dukpp03::PushValue is implemented (see dukpp03::GetValue&lt;std::string&gt; and dukpp03::PushValue&lt;std::string&gt; as example)

## How to build

You need CMake to build source library. Also, you can use Boost to build tests

## Examples

### Prerequisites 

This library is designed to be independent from environments as possible, so, to start working with it we need boilerplate for following stuff:

* Variants and getting name of type as string (see VariantInterface. Here we use boost::an and typeid. Second one is not good, because it gives us mangled type name, which makes execution errors look confusing. You can use own, or demangle that one, using boost::demangle)
* An implementation of unordered map. (see MapInterface. Here we wrap boost::unordered_map into this class. All the functions, presented in this class are strictly required)
* Timer interface to be used in timeout checks (see TimerInterface)
* Optionally a type-dependent value wrapper generator, but context can do it for us.

An example of implementation see in https://github.com/mamontov-cpp/dukpp-03/blob/master/tests/utils.h

After defining prerequisites we can simplify binding values by specifiying context implementation, using following code

```cpp
typedef dukpp03::Context<dukpp03::utils::MapInterface, dukpp03::utils::VariantInterface, dukpp03::utils::TimerInterface> Context;
typedef dukpp03::make_fun<dukpp03::context::Context> mkf;
typedef dukpp03::register_constructor<dukpp03::context::Context> register_constructor;
typedef dukpp03::make_method<dukpp03::context::Context> mkm;
typedef dukpp03::bind_method<dukpp03::context::Context> bnd;
typedef dukpp03::CompiledFunction<dukpp03::context::Context> compiledfunc;
typedef dukpp03::getter<dukpp03::context::Context> getter;
typedef dukpp03::setter<dukpp03::context::Context> setter;
typedef dukpp03::ClassBinding<dukpp03::context::Context> ClassBinding;
```
