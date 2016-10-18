Here will be placed a supplementary library for interacting with Qt.

The library will use method https://gist.github.com/andref/2838534 to support calling metamethods.

Now, library do not support having both method and slot share the same name. Or atribute or slot. 

Properties is filled in following order:

  * First, static methods and accessors, defined via ClassBinding
  * Second, slots and methods from Qt
  * And then properties