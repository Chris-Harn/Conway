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


/**************************************************
 *  TestSuite::compareInt
 *  Purpose: functionAnswer comes from the function
 *  being tested, and is compared to the expected-
 *  Answer.
 *  Input: Takes in two ints.
 *  Return: True if it fails. False if it passes.
 *
 *************************************************/

bool compareInt( int functionAnswer, int expectedAnswer ) {

	return true;
}


/**************************************************
 *  TestSuite::compareFloat
 *  Purpose: functionAnswer comes from the function
 *  being tested, and is compared to the expected-
 *  Answer. Must be inside the tolerance.
 *  Input: Takes in two floats and checks them
 *  using a tolerance value to check the difference.
 *  Return: True if it fails. False if it passes.
 *
 *************************************************/

bool compareFloat( float functionAnswer, float expectedAnswer, float tolerance ) {

	return true;
}


/**************************************************
 *  TestSuite::compareDouble
 *  Purpose: functionAnswer comes from the function
 *  being tested, and is compared to the expected-
 *  Answer. Must be inside the tolerance.
 *  Input: Takes in two doubles and checks them
 *  using a tolerance value to check the difference.
 *  Return: True if it fails. False if it passes.
 *
 *************************************************/

bool compareDouble( double functionAnswer, double expectedAnswer, double tolerance ) {

	return true;
}

