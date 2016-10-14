#include "test.h"
#include "../../src/duktape.cpp"
#include <QObject>
#include <QMetaMethod>

#include "context.h"
#include <iostream>;

#include "../../src/abstractcallable.cpp"
#include "../../src/abstractcontext.cpp"

Q_DECLARE_METATYPE(Test2*);

int main()
{
	dukpp03::qt::Context ctx;
	ctx.setMaximumExecutionTime(30000);
	
	qRegisterMetaType<Test2*>("Test2*");
	
	Test f;
	QVariant v;
	Test2* vc;
	
	
		
	const QMetaObject* metaObject = f.metaObject();
	for(int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i)
	{
		QMetaMethod metaMethod = metaObject->method(i);
		QString empty = "";
		if (metaMethod.typeName() == NULL)
		{
			empty = "(empty|null)";
		}
		if (QString("") == metaMethod.typeName())
		{
			empty = "(empty|\"\")";
		}
		std::cout <<  metaMethod.typeName() << empty.toStdString() << "| "  << metaMethod.signature() << "\n";
	}
	
	QMetaMethod m = metaObject->method(metaObject->methodOffset());
	
	std::cout << "MetaType: " << QMetaType::type(m.typeName()) << "\n";
	void* ptr = NULL;
	QVariant returnValue(
		QMetaType::type(m.typeName()), 
		ptr
	);
		
	QVariant arg1(23);
	bool ok = m.invoke(&f, Qt::DirectConnection,  QReturnArgument<int>(m.typeName(), *reinterpret_cast<int*>(returnValue.data())), QGenericArgument(arg1.typeName(), arg1.data()));
	std::cout << ok << "\n";
	if (returnValue.typeName())
	{
	    std::cout << returnValue.typeName() << "\n";
	}
	std::cout << "aaaa";
	std::cout << returnValue.canConvert<Test2*>() << "\n";
	if (returnValue.canConvert<Test2*>())
	{
		std::cout << returnValue.value<Test2*>()->m_a;
	}
	return 0;
}