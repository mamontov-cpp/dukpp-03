# dukpp-03
A C++03 experimental bindings for Duktape library 

## Limitations

 * You cannot bind methods or functions, that require mutable references for plain types (int, char, long, etc.) or std::string
 * Own string will be passed as objects, unless corresponding instantiation of dukpp03::GetValue and dukpp03::PushValue is implemented (see dukpp03::GetValue&lt;std::string&gt; and dukpp03::PushValue&lt;std::string&gt; as example)
