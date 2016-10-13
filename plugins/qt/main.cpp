#include "test.h"

#include "../../src/duktape.cpp"
#include <QObject>

#include "context.h"
#include <iostream>;

#include "../../src/abstractcallable.cpp"
#include "../../src/abstractcontext.cpp"

int main()
{
	dukpp03::qt::Context ctx;
	ctx.setMaximumExecutionTime(30000);
	
	Test f;
	QVariant v;
	int vc;
	QVariant arg1(23);
	QMetaObject::invokeMethod(&f, "slot", Qt::DirectConnection,  Q_RETURN_ARG(int, vc) /* TODO: How to get Q_RETURN_ARG to be friends with QVariant? */, QGenericArgument(arg1.typeName(), arg1.data()));
	std::cout << vc;
	return 0;
}