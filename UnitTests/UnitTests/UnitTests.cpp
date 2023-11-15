#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\tes7a\Documents\lab_ing\labc\labc"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
    TEST_CLASS(UnitTests)
    {
    public:

        TEST_METHOD(nIsLessThan1)
        {
            int a = 1;
            int b = 2;
            int h = 1;
            int n = 0;
            bool fstream = false;

            Assert::AreEqual(calculateY(a, b, h, n, fstream), 0);
        }

        TEST_METHOD(fstreamIsTrue)
        {
            int a = 1;
            int b = 2;
            int h = 1;
            int n = 2;
            bool fstream = true;

            calculateY(a, b, h, n, fstream);

            std::ifstream fin("results.txt");
            Assert::IsTrue(fin.is_open());

            std::string line;
            while (std::getline(fin, line)) {
                Assert::IsTrue(line.find("X:") != std::string::npos);
                Assert::IsTrue(line.find("Y:") != std::string::npos);
            }

            fin.close();
        }

        TEST_METHOD(fstreamIsFalse)
        {
            int a = 1;
            int b = 2;
            int h = 1;
            int n = 2;
            bool fstream = false;

            calculateY(a, b, h, n, fstream);

            std::ifstream fin("results.txt");
            Assert::IsTrue(fin.is_open());

            std::string line;
            while (std::getline(fin, line)) {
                Assert::IsFalse(line.find("X:") != std::string::npos);
                Assert::IsFalse(line.find("Y:") != std::string::npos);
            }

            fin.close();
        }
    };
}
