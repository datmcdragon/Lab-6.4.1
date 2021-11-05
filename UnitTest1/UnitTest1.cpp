#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-6.4.1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int A[] = { 0,3, 9, 10 };
			int t = SerMax(A, 4);
			Assert::AreEqual(3, t);
		}
	};
}