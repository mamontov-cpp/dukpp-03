#include "../../src/duktape.cpp"


#include "context.h"
#include <iostream>;

#include "../../src/abstractcallable.cpp"
#include "../../src/abstractcontext.cpp"

int main()
{
	dukpp03::qt::Context ctx;
	ctx.setMaximumExecutionTime(30000);
	QTime t;
	t.start();
	ctx.eval("while(true) {}", false);
	std::cout << t.elapsed() << "\n";
	t.restart();
	ctx.eval("while(true) {}", false);
	std::cout << t.elapsed() << "\n";
	return 0;
}