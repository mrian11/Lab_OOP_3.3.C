#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_OOP_3.3.C/CharLine.h"
#include "../Lab_OOP_3.3.C/CharLine.cpp"
#include "../Lab_OOP_3.3.C/Object.h"
#include "../Lab_OOP_3.3.C/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLabOOP33C
{
	TEST_CLASS(UnitTestLabOOP33C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testString = "Test String";
			CharLine charLine(11, testString);
			Assert::AreEqual(11, charLine.getN());
			Assert::AreEqual(testString, charLine.getS());
		}
	};
}
