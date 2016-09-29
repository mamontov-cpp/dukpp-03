# dukpp-03
A C++03 experimental bindings for Duktape library 

## Limitations

 * You cannot bind methods, that call on mutable reference of plain types (int, char, long, etc.) or std::string
 * Own string will be passed as objects, unless corresponding instantiation of dukpp03::GetValue and dukpp03::PushValue is implemented (see dukpp03::GetValue<std::string> and dukpp03::PushValue<std::string> as example)
