# dukpp-03
A C++03 experimental bindings for Duktape library. A library for bindings like [RubberDuk](https://gitlab.com/calcyss/rubberduk), but with C++03 support. This library allows to bind arbitrary classes and functions into Duktape and use them a scripting values. This library also implements timeouts for script execution. 

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

An example of implementation see in https://github.com/mamontov-cpp/dukpp-03/blob/master/tests/utils.h and in https://github.com/mamontov-cpp/dukpp-03/blob/master/tests/getaddressoftype.h

After defining prerequisites we can simplify binding values by specifiying context implementation, using following code

```cpp
typedef dukpp03::Context<dukpp03::utils::MapInterface, dukpp03::utils::VariantInterface, dukpp03::utils::TimerInterface> Context;
typedef dukpp03::make_fun<Context> mkf;
typedef dukpp03::register_constructor<Context> register_constructor;
typedef dukpp03::make_method<Context> mkm;
typedef dukpp03::bind_method<Context> bnd;
typedef dukpp03::CompiledFunction<Context> compiledfunc;
typedef dukpp03::getter<Context> getter;
typedef dukpp03::setter<Context> setter;
typedef dukpp03::ClassBinding<Context> ClassBinding;
```
... and we are ready to start binding functions and classes.

### Binding classes and structures to be used in JavaScript

Let's start by having struct:

```cpp
struct Point
{
    int m_x;
    int m_y;
    
    Point();
    Point(int x, int y);

    void setX(int x);
    void setY(int y);
    
    int x() const;
    int y() const;
};
```

To use it in script, you can just do

```cpp
Context t;

ClassBinding* c = new ClassBinding();
c->addConstructor<Point>("Point");
c->addConstructor<Point, int, int>("Point");

// A simple method bindings
c->addMethod("x",  bnd::from(&Point::x));
c->addMethod("setX",  bnd::from(&Point::setX));

// A simple methods bindings. Note, that those will be pushed in multimethod, so y() could be easily overloaded by another call to
// c->addMetod("y", bnd::from(&Point::someOtherMethod))
c->addMethod("y",  bnd::from(&Point::y));
c->addMethod("setY",  bnd::from(&Point::setY));
// m_x and m_y will be accessed as field
c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));

t.addClassBinding<Point>(c);

// And you can write code like these, after binding class
t.eval("var a = new Point(), b = new Point(2,3); print(a.x() + a.m_x);", false)
```

### Binding functions

You can bind a functions too:

```cpp

void print_number_3(int a, int b, int c)
{
    printf("print_number_3: %d %d %d\n", a, b, c ); 
}

... Somewhere in main
Context ctx;
ctx.registerCallable("f03", mkf::from(print_number_3));
eval_result = ctx.eval(" f03(21, 44, 56); ", true); // Outputs 21, 44, 56
...
```

You can get a value from functions on stack like this

```cpp
int return_something()
{
    return 32;
}

... Somewhere in main
Context ctx;
ctx.registerCallable("f00", mkf::from(return_something));
bool eval_result = ctx.eval(" f00() ", false, &error);
dukpp03::Maybe<int> result = dukpp03::GetValue<int, Context>::perform(&ctx, -1);
std::cout << result.value(); // Outputs 32
```

### Working with value stack

dukpp-03 works with stack, used in Duktape, so you can push and get values from it as typed values

```cpp
Context ctx;
int c = 121;
// Push new value on stack
dukpp03::PushValue<int, Context>::perform(&ctx, c);
// Get last value from stack
dukpp03::Maybe<int> maybev = dukpp03::GetValue<int, Contextt>::perform(&ctx, -1); // maybev now hold 121
```

### Working with global variables

You can set, get and delete global variables, using dukpp-03, using following code

```cpp
Context ctx;
// Register global variable
ctx.registerGlobal("x", 2);
// Get global variable
dukpp03::Maybe<int> m = ctx.getGlobal<int>("x");  // m.value() will return 2 after this
// Remove global variable
ctx.unregisterGlobal();
```

### Registering methods as functions

You can register method to be used as functions, using following code (see Point class for method definition)

```cpp
dukpp03::context::Context ctx;
ctx.registerCallable("x", mkm::from(&Point::x)); // Now, if we call - x(Point(2,3)) in JS it will evaluate to 2
```

### Compiled functions and passing callbacks to native code

To work with callbacks from JS, dukpp-03 uses class CompiledFunction, which internally stores Duktape bytecode. You can receive it in binding and save it to store before. When you have a need to call it with argument, you can push it on stack after arguments and call it. 

Note, that the stack must be clean, when calling compiled function

To illustrate the example:

```cpp
compiledfunc func;

void set_func(const compiledfunc& f)
{
    func = f;
}

... Somewhere in main
Context ctx;
ctx.registerCallable("setFunction", mkf::from(set_func));

// Setting callback from JS code
ctx.eval(" setFunction(function(a) { print(a); return a;  }); ", false);
// Clean stack after evaluating
ctx.cleanStack();

// Push argument (22) on stack
dukpp03::PushValue<int, Context>::perform(&ctx, 22);
// Evaluate function - it will print 22 and return 22 on stack
func.call(&ctx);
```
