#include "TestSuite.h"

#include <iostream>


TestSuite* TestSuite::s_pinstance = 0;


/**************************************************
 *  TestSuite::TestSuite
 *  Purpose: Constructor.  
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

TestSuite::TestSuite() : m_testRun( 0 ), m_testPassed( 0 ) {

}


/**************************************************
 *  TestSuite::run
 *  Purpose: 
 *  Input: None.
 *  Return: None.
 *
 *************************************************/


void TestSuite::run() {

}


/**************************************************
 *  TestSuite::results
 *  Purpose: Prints results. 
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void TestSuite::results() {
	std::cout << "\n\n---------------------------------------------\n";
	std::cout << "Test Suite finished without issue.\n";
	std::cout << "Total Test Run: " << m_testRun << "/r Total Test Passed: " << m_testPassed << ".\n";
}

