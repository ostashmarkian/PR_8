#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8_1r/Lab8.1r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8_1r
{
	TEST_CLASS(UnitTest8_1r)
	{
	public:
		TEST_METHOD(TestCount)
		{
			char str[] = "a+b-c=d";
			int t = Count(str, 0, 0);
			Assert::AreEqual(3, t);
		}

		TEST_METHOD(TestCountEmpty)
		{
			char str[] = "abc";
			int t = Count(str, 0, 0);
			Assert::AreEqual(0, t);
		}

		TEST_METHOD(TestChange)
		{
			char str[] = "a+b-c=d";
			char dest[20];
			char* t = Change(str, dest, 0, 0);
			Assert::AreEqual("a**b**c**d", t);
		}

		TEST_METHOD(TestChangeAllSigns)
		{
			char str[] = "+-=";
			char dest[20];
			char* t = Change(str, dest, 0, 0);
			Assert::AreEqual("******", t);
		}
	};
}
