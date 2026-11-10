#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8_1string/Lab8.1string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8_1string
{
	TEST_CLASS(UnitTest8_1string)
	{
	public:
		TEST_METHOD(TestCount)
		{
			string str = "a+b-c=d";
			int t = Count(str);
			Assert::AreEqual(3, t);
		}

		TEST_METHOD(TestCountEmpty)
		{
			string str = "abc";
			int t = Count(str);
			Assert::AreEqual(0, t);
		}

		TEST_METHOD(TestChange)
		{
			string str = "a+b-c=d";
			string t = Change(str);
			Assert::AreEqual("a**b**c**d", t.c_str());
		}

		TEST_METHOD(TestChangeAllSigns)
		{
			string str = "+-=";
			string t = Change(str);
			Assert::AreEqual("******", t.c_str());
		}
	};
}
