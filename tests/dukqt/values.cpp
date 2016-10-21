#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <iostream>
#include "context.h"
#include <dukqt.h>
#include "test.h"
#include "gccollectcheck.h"

#include "math.h"
#include "../dukpp03/include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)


inline bool toIntAndEqual(int a, int b)
{
    return a == b;
}

struct ValuesTest : tpunit::TestFixture
{
public:
    ValuesTest() : tpunit::TestFixture(
       TEST(ValuesTest::testConvertNumeric),
       TEST(ValuesTest::testConvertQObjectTest),
       TEST(ValuesTest::testConvertTestQObject),
       TEST(ValuesTest::testConvertStdStringToQString),
       TEST(ValuesTest::testConvertQStringToStdString),
       TEST(ValuesTest::testGetPushQObject),
       TEST(ValuesTest::testGetPushQString),
       TEST(ValuesTest::testGetPushQVariant),
       TEST(ValuesTest::testGetPushQVector),
       TEST(ValuesTest::testGetPushQList),
       TEST(ValuesTest::testGetPushQVectorQList),
       TEST(ValuesTest::testGetPushQHash),
       TEST(ValuesTest::testGetPushQMap),
       TEST(ValuesTest::testGetPushQHashQMap),
       TEST(ValuesTest::testPushObjectWithOwnOwnership),
       TEST(ValuesTest::testPushObjectWithScriptOwnership)
    ) {}

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConvertNumeric()
    {

        dukpp03::qt::registerMetaType<::Test>();

        // Sanity checks
        {
            QVariant v(2);
            QVariant result;
            ASSERT_TRUE(dukpp03::qt::Convert::canConvert("int", &v))
            ASSERT_TRUE(dukpp03::qt::Convert::convert("int", &v, result));
            ASSERT_TRUE(result.value<int>() == 2);
        }

        {
            QVariant v(2);
            QVariant result;
            ASSERT_FALSE(dukpp03::qt::Convert::canConvert("QObject*", &v))
            ASSERT_FALSE(dukpp03::qt::Convert::convert("QObject*", &v, result));
            ASSERT_TRUE(result.value<QObject*>() == NULL);

        }

        {
            QVariant v(2);
            QVariant result;
            ASSERT_TRUE(dukpp03::qt::Convert::canConvert("long", &v))
            ASSERT_TRUE(dukpp03::qt::Convert::convert("long", &v, result));
            ASSERT_TRUE(result.value<long>() == 2);
        }

        // Actual tests
#define CONVERSION_TEST(X, Y)                                                         \
        {                                                                             \
           std::cout << "Starting test: " << #X  << " -> " << #Y << "\n";             \
           QVariant v = QVariant::fromValue((DUKPP03_TYPE(X))2);                      \
           QVariant result;                                                           \
           ASSERT_TRUE(dukpp03::qt::Convert::canConvert(#Y, &v));                     \
           ASSERT_TRUE(dukpp03::qt::Convert::convert(#Y, &v, result));                \
           ASSERT_TRUE(toIntAndEqual(result.value<DUKPP03_TYPE(Y)>(), 2));            \
           std::cout << "Successfully passsed test: " << #X  << " -> " << #Y << "\n"; \
        }

#define CONVERSION_TEST_PAIR(X, Y) CONVERSION_TEST(X, Y) CONVERSION_TEST(Y, X)

        CONVERSION_TEST(char, char);
        CONVERSION_TEST(unsigned char, unsigned char);
        CONVERSION_TEST_PAIR(char, unsigned char);
        

        CONVERSION_TEST_PAIR(float, double);
        CONVERSION_TEST_PAIR(float, long double);
        CONVERSION_TEST_PAIR(double, long double);

        CONVERSION_TEST(float, float);
        CONVERSION_TEST_PAIR(float, short);
        CONVERSION_TEST_PAIR(float, unsigned short);
        CONVERSION_TEST_PAIR(float, int);
        CONVERSION_TEST_PAIR(float, unsigned int);
        CONVERSION_TEST_PAIR(float, long);
        CONVERSION_TEST_PAIR(float, unsigned long);
        CONVERSION_TEST_PAIR(float, long long);
        CONVERSION_TEST_PAIR(float, unsigned long long);

        CONVERSION_TEST(double, double);
        CONVERSION_TEST_PAIR(double, short);
        CONVERSION_TEST_PAIR(double, unsigned short);
        CONVERSION_TEST_PAIR(double, int);
        CONVERSION_TEST_PAIR(double, unsigned int);
        CONVERSION_TEST_PAIR(double, long);
        CONVERSION_TEST_PAIR(double, unsigned long);
        CONVERSION_TEST_PAIR(double, long long);
        CONVERSION_TEST_PAIR(double, unsigned long long);

        CONVERSION_TEST(long double, long double);
        CONVERSION_TEST_PAIR(long double, short);
        CONVERSION_TEST_PAIR(long double, unsigned short);
        CONVERSION_TEST_PAIR(long double, int);
        CONVERSION_TEST_PAIR(long double, unsigned int);
        CONVERSION_TEST_PAIR(long double, long);
        CONVERSION_TEST_PAIR(long double, unsigned long);
        CONVERSION_TEST_PAIR(long double, long long);
        CONVERSION_TEST_PAIR(long double, unsigned long long);
        CONVERSION_TEST_PAIR(long double, double);
        CONVERSION_TEST_PAIR(long double, float);

        CONVERSION_TEST(short, short);
        CONVERSION_TEST_PAIR(short, unsigned short);
        CONVERSION_TEST_PAIR(short, int);
        CONVERSION_TEST_PAIR(short, unsigned int);
        CONVERSION_TEST_PAIR(short, long);
        CONVERSION_TEST_PAIR(short, unsigned long);
        CONVERSION_TEST_PAIR(short, long long);
        CONVERSION_TEST_PAIR(short, unsigned long long);

        CONVERSION_TEST(unsigned short, unsigned short);
        CONVERSION_TEST_PAIR(unsigned short, int);
        CONVERSION_TEST_PAIR(unsigned short, unsigned int);
        CONVERSION_TEST_PAIR(unsigned short, long);
        CONVERSION_TEST_PAIR(unsigned short, unsigned long);
        CONVERSION_TEST_PAIR(unsigned short, long long);
        CONVERSION_TEST_PAIR(unsigned short, unsigned long long);

        CONVERSION_TEST(int, int);
        CONVERSION_TEST_PAIR(int, unsigned int);
        CONVERSION_TEST_PAIR(int, long);
        CONVERSION_TEST_PAIR(int, unsigned long);
        CONVERSION_TEST_PAIR(int, long long);
        CONVERSION_TEST_PAIR(int, unsigned long long);

        CONVERSION_TEST(unsigned int, unsigned int);
        CONVERSION_TEST_PAIR(unsigned int, long);
        CONVERSION_TEST_PAIR(unsigned int, unsigned long);
        CONVERSION_TEST_PAIR(unsigned int, long long);
        CONVERSION_TEST_PAIR(unsigned int, unsigned long long);

        CONVERSION_TEST(long, long);
        CONVERSION_TEST_PAIR(long, unsigned long);
        CONVERSION_TEST_PAIR(long, long long);
        CONVERSION_TEST_PAIR(long, unsigned long long);

        CONVERSION_TEST(unsigned long, unsigned long);
        CONVERSION_TEST_PAIR(unsigned long, long long);
        CONVERSION_TEST_PAIR(unsigned long, unsigned long long);

        CONVERSION_TEST(long long, long long);
        CONVERSION_TEST_PAIR(long long, unsigned long long);

        CONVERSION_TEST(unsigned long long, unsigned long long);
#undef CONVERSION_TEST_PAIR
#undef CONVERSION_TEST
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConvertQObjectTest()
    {
        dukpp03::qt::registerMetaType<::Test>();    
        ::Test r;
        
        QVariant v = QVariant::fromValue(static_cast<QObject*>(&r));
        QVariant result;
        ASSERT_TRUE(dukpp03::qt::Convert::canConvert("Test*", &v))
        ASSERT_TRUE(dukpp03::qt::Convert::convert("Test*", &v, result));
        ASSERT_TRUE(result.value<::Test*>() == &r);        
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConvertTestQObject()
    {
        dukpp03::qt::registerMetaType<::Test>();    
        ::Test r;
        
        QVariant v = QVariant::fromValue(&r);
        QVariant result;
        ASSERT_TRUE(dukpp03::qt::Convert::canConvert("QObject*", &v))
        ASSERT_TRUE(dukpp03::qt::Convert::convert("QObject*", &v, result));
        ASSERT_TRUE(result.value<QObject*>() == &r);           
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConvertStdStringToQString()
    {
        std::string s = "Test";

        QVariant v = QVariant::fromValue(s);
        QVariant result;
        ASSERT_TRUE(dukpp03::qt::Convert::canConvert("QString", &v))
        ASSERT_TRUE(dukpp03::qt::Convert::convert("QString", &v, result));
        ASSERT_TRUE(result.value<QString>() == s.c_str());        
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConvertQStringToStdString()
    {
        QString s = "Test";

        QVariant v = QVariant::fromValue(s);
        QVariant result;
        ASSERT_TRUE(dukpp03::qt::Convert::canConvert("std::string", &v))
        ASSERT_TRUE(dukpp03::qt::Convert::convert("std::string", &v, result));
        ASSERT_TRUE(result.value<std::string>() == s.toStdString());         
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQObject()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, new GCCollectCheck());

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = dukpp03::GetValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, -1);
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 0 );
        
        GCCollectCheck::clearCounter();

        delete result.value();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQString()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        dukpp03::PushValue<QString, dukpp03::qt::BasicContext>::perform(ctx, "Test");

        dukpp03::Maybe<QString> result = dukpp03::GetValue<QString, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;
        
        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == "Test");

    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQVariant()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        dukpp03::PushValue<QVariant, dukpp03::qt::BasicContext>::perform(ctx, QVariant::fromValue(new GCCollectCheck()));

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = dukpp03::GetValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, -1);
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 1 );
        
        GCCollectCheck::clearCounter();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQVector()
    {
        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        QVector<int> test;
        test << 1 << 2 << 3;
        dukpp03::PushValue<QVector<int>, dukpp03::qt::BasicContext>::perform(ctx, test);

        dukpp03::Maybe<QVector<int> > result = dukpp03::GetValue<QVector<int>, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;

        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == test);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQList()
    {
        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        QList<int> test;
        test << 1 << 2 << 3;
        dukpp03::PushValue<QList<int>, dukpp03::qt::BasicContext>::perform(ctx, test);

        dukpp03::Maybe<QList<int> > result = dukpp03::GetValue<QList<int>, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;

        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == test);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQVectorQList()
    {
        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        QVector<int> test;
        test << 1 << 2 << 3;
        QList<int> ethalon;
        ethalon << 1 << 2 << 3;
        dukpp03::PushValue<QVector<int>, dukpp03::qt::BasicContext>::perform(ctx, test);

        dukpp03::Maybe<QList<int> > result = dukpp03::GetValue<QList<int>, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;

        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == ethalon);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQHash()
    {
        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        QHash<QString, int> test;
        test.insert("1", 1);
        test.insert("2", 1);
        test.insert("3", 1);
        dukpp03::PushValue< QHash<QString, int>, dukpp03::qt::BasicContext>::perform(ctx, test);

        dukpp03::Maybe< QHash<QString, int> > result = dukpp03::GetValue< QHash<QString, int>, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;

        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == test);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQMap()
    {
        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        QMap<QString, int> test;
        test.insert("1", 1);
        test.insert("2", 1);
        test.insert("3", 1);
        dukpp03::PushValue< QMap<QString, int>, dukpp03::qt::BasicContext>::perform(ctx, test);

        dukpp03::Maybe< QMap<QString, int> > result = dukpp03::GetValue< QMap<QString, int>, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;

        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == test);
    }


    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testGetPushQHashQMap()
    {
        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();
        QHash<QString, int> test;
        test.insert("1", 1);
        test.insert("2", 1);
        test.insert("3", 1);

        QMap<QString, int> ethalon;
        ethalon.insert("1", 1);
        ethalon.insert("2", 1);
        ethalon.insert("3", 1);
        dukpp03::PushValue< QHash<QString, int>, dukpp03::qt::BasicContext>::perform(ctx, test);

        dukpp03::Maybe< QMap<QString, int> > result = dukpp03::GetValue< QMap<QString, int>, dukpp03::qt::BasicContext>::perform(ctx, -1);
        
        delete ctx;

        ASSERT_TRUE( result.exists());
        ASSERT_TRUE( result.value() == ethalon);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testPushObjectWithOwnOwnership()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();

        dukpp03::qt::ObjectWithOwnership owo(new GCCollectCheck, dukpp03::qt::DQ_OWN);
        dukpp03::PushValue<dukpp03::qt::ObjectWithOwnership, dukpp03::qt::BasicContext>::perform(ctx, owo);

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = dukpp03::GetValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, -1);
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 0 );
        
        GCCollectCheck::clearCounter();

        delete result.value();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testPushObjectWithScriptOwnership()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();

        dukpp03::qt::ObjectWithOwnership owo(new GCCollectCheck, dukpp03::qt::DQ_SCRIPT);
        dukpp03::PushValue<dukpp03::qt::ObjectWithOwnership, dukpp03::qt::BasicContext>::perform(ctx, owo);

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = dukpp03::GetValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, -1);
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 1 );
        
        GCCollectCheck::clearCounter();
    }

} _values_test;
