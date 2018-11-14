#include "TestSuite.h"

#include <iostream>

TestSuite* TestSuite::s_pinstance = 0;

TestSuite::TestSuite() : m_testRun( 0 ), m_testPassed( 0 ) {

}

void TestSuite::run() {

}

void TestSuite::clean() {
	std::cout << "\n\n---------------------------------------------\n";
	std::cout << "Test Suite finished without issue.\n";
	std::cout << "Total Test Run: " << m_testRun << "/r Total Test Passed: " << m_testPassed << ".\n";
}

void TestSuite::test1() {

}

void TestSuite::test2() {

}
