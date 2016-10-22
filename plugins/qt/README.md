# dukqt

A C++03 experimental bindings for Duktape library interaction with Qt, built on top of [dukpp-03](https://github.com/mamontov-cpp/dukpp-03). This library allows to bind arbitrary Qt classes and functions into Duktape and use them a scripting values. 

Also it supports serializing and deserializing QVectors and QLists as arrays and QHash and QMaps as objects (if key type supplied for those is string).

The library will uses this method https://gist.github.com/andref/2838534 to support calling metamethods.

## Limitations

 * You cannot bind methods or functions, that require mutable references for plain types (int, char, long, etc.) or std::string
 * Own string will be passed as objects, unless corresponding instantiation of dukpp03::GetValue and dukpp03::PushValue is implemented (see dukpp03::GetValue&lt;std::string&gt; and dukpp03::PushValue&lt;std::string&gt; as example)
 * Classes are bind just like in parent library, so slots will overload default bindings. See [dukpp-03](https://github.com/mamontov-cpp/dukpp-03) for details
 * You cannot change passed QVectors, QLists, QHash, QMaps inside of binding.
 * You must additionally register some types, you're working with in order for metamethods to work properly
 
## How to build

You need [dukpp-03](https://github.com/mamontov-cpp/dukpp-03) to build source library. Also, you should use either QtCreator or Microsoft Visual Studio to build a library.


Properties is filled an behave according to class binding rules.

## Examples

### Prerequisites 

An examples of classes for bindings can be found [test.h](https://github.com/mamontov-cpp/dukpp-03/blob/master/tests/dukqt/test.h) and [test2.h](https://github.com/mamontov-cpp/dukpp-03/blob/master/tests/dukqt/test2.h)

### Registering class without constructors

```cpp
static ::Test* make(int a)
{
    return new ::Test(a); 
}

int main()
{
    dukpp03::qt::registerMetaType<::Test>();
    dukpp03::qt::registerMetaType<Test2>();

    dukpp03::qt::Context ctx;
    ctx.registerCallable("make", dukpp03::qt::make_function::from(make));

    std::string error;
    bool result = ctx.eval("var t = make(2); t.return3() + t.value", false, &error);
    if (!result)
    {
        std::cout << error;
    }

    dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1); // val now holds 5
    return 0;
}
```

### Registering class with constructors

```cpp
int main()
{
    dukpp03::qt::Context ctx;
    dukpp03::qt::registerTypeInContext<::Test>(&ctx);
    dukpp03::qt::registerTypeInContext<Test2>(&ctx);


    std::string error;
    bool result = ctx.eval("var t = new Test(2); t.return3() + t.value", false, &error);
    if (!result)
    {
        std::cout << error;
    }

    dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1); // val now holds 5
    return 0;
}
```

### Returning plain values from slots

You can also return plain values from slots, see example:

```cpp
int main()
{
    dukpp03::qt::Context ctx;
    dukpp03::qt::registerTypeInContext<::Test>(&ctx);
    dukpp03::qt::registerTypeInContext<Test2>(&ctx);
    
    dukpp03::qt::registerMetaType<Test::ValueHolder>();

    dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
    binding->addMethod("printValue", dukpp03::qt::bind_method::from(&Test::ValueHolder::printValue));
    binding->addMethod("getValue", dukpp03::qt::bind_method::from(&Test::ValueHolder::getValue));
    ctx.addClassBinding("Test::ValueHolder", binding);

    std::string error;
    bool result = ctx.eval("var t = new Test(2); var b = t.returnHolder(); b.printValue(); b.getValue() ", false, &error);
    if (!result)
    {
        std::cout << error;
    }

    dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1); // val holds 2
    return 0;
}
```

### Returning QObject* descendant from slot

You can also return descendant of QObject* from slots

```cpp
int main()
{
    dukpp03::qt::Context ctx;
    dukpp03::qt::registerTypeInContext<::Test>(&ctx);

    dukpp03::qt::registerMetaType<Test2>();
    std::string error;
    bool result = ctx.eval("var b = new Test(2); b.returnDerived(2).get()", false, &error);
    if (!result)
    {
        std::cout << error;
    }

    dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1); // val holds 2
    return 0;
}
```


### Mixing binding of methods and automatic binding of slots

You can mix bindings of methods and automatic binding of slots too!

```cpp
int main()
{
    dukpp03::qt::registerMetaType<::Test>();
    dukpp03::qt::registerMetaType<Test2>();

    dukpp03::qt::Context ctx;
    dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
    binding->addMethod("setHalfOfValue", dukpp03::qt::bind_method::from(&::Test::setHalfOfValueFromSum));
    binding->registerMetaObject<::Test>();
    ctx.addClassBinding("Test", binding);
    // Call slot
    {
        std::string error;
        bool result = ctx.eval("var t = new Test(2); t.setHalfOfValue(4); t.value", false, &error);
        if (!result)
        {
            std::cout << error;
        }

        dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
    }
    // Call real method
    {
        std::string error;
        bool result = ctx.eval("var t = new Test(2); t.setHalfOfValue(2, 2); t.value", false, &error);
        if (!result)
        {
            std::cout << error;
        }

        dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
    }
    return 0;
}
```

