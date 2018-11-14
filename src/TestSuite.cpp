#include "TestSuite.h"

#include <iostream>

TestSuite* TestSuite::s_pinstance = 0;

TestSuite::TestSuite() {

}

void TestSuite::init() {
	std::cout << "Test Suite started Without issue.\n";
}

void TestSuite::run() {

}

void TestSuite::clean() {
	std::cout << "Test Suite finished without issue.\n";
}

void TestSuite::test1() {

}

void TestSuite::test2() {

}
