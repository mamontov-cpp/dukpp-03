#include "test.h"
#include "../../src/duktape.cpp"
#include <QObject>
#include <QMetaMethod>

#include "context.h"
#include <iostream>

#include "../../src/abstractcallable.cpp"
#include "../../src/abstractcontext.cpp"

#define HAS_QT5  ( QT_VERSION >= 0x050000 )

Q_DECLARE_METATYPE(int*);
Q_DECLARE_METATYPE(Test*);
Q_DECLARE_METATYPE(Test**);
Q_DECLARE_METATYPE(Test2*);

int main()
{
	dukpp03::qt::Context ctx(true);
	ctx.setMaximumExecutionTime(30000);
	
	qRegisterMetaType<Test*>("Test*");
	qRegisterMetaType<Test2*>("Test2*");

	dukpp03::qt::ClassBinding* testbinding = new dukpp03::qt::ClassBinding();
	testbinding->addConstructor("Test", dukpp03::qt::qobject::construct<Test>());
	testbinding->addConstructor("Test", dukpp03::qt::qobject::construct<Test, int>());
	testbinding->addMethod("speak", dukpp03::qt::bind_method::from(&Test::speak));
	ctx.registerCallable("free_speak", dukpp03::qt::make_method::from(&Test::speak));
	ctx.addClassBinding("Test*", testbinding);
	std::string error;
	ctx.eval("var a = new Test(); a.speak(); free_speak(a); deleteQObject(a);", false, &error);
	std::cout << error;
	Test f;
	QVariant v;
	Test2* vc;
	
    QVariant v1;
    //v1.setValue(f);
    std::cout << "v1: Can convert to QObject " <<  v1.canConvert<QObject*>() << ":" << v1.value<QObject*>() << "\n";
    QVariant v2;
    v2.setValue(&f);
    std::cout << "v2: Can convert to QObject " <<  v2.canConvert<QObject*>() << ":" << v2.value<QObject*>() << "\n";

	
		
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
#ifndef HAS_QT5
		std::cout <<  metaMethod.typeName() << empty.toStdString() << "| "  << metaMethod.signature() << "\n";
#else
		std::cout <<  metaMethod.typeName() << empty.toStdString() << "| "  << QString(metaMethod.methodSignature()).toStdString() << "\n";
#endif
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