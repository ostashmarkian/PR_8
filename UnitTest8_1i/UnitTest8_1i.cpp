#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8_1i/Lab8.1i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8_1i
{
	TEST_CLASS(UnitTest8_1i)
	{
	public:
		TEST_METHOD(TestCount)
		{
			char str[] = "a+b-c=d";
			int t = Count(str);
			Assert::AreEqual(3, t);
		}

		TEST_METHOD(TestCountEmpty)
		{
			char str[] = "abc";
			int t = Count(str);
			Assert::AreEqual(0, t);
		}

		TEST_METHOD(TestChange)
		{
			char str[] = "a+b-c=d";
			char* t = Change(str);
			Assert::AreEqual("a**b**c**d", t);
			delete[] t;
		}

		TEST_METHOD(TestChangeAllSigns)
		{
			char str[] = "+-=";
			char* t = Change(str);
			Assert::AreEqual("******", t);
			delete[] t;
		}
	};
}
