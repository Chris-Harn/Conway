#ifndef __TESTSUITE__
#define __TESTSUITE__

/**************************************************
 *  TestSuite
 *  Purpose: Test cases to prove all classes and
 *  functions are working correctly.
 *
 *************************************************/

class TestSuite {
public:
	void run();
	void clean();

	static TestSuite* instance() {
		if( s_pinstance == 0 ) {
			s_pinstance = new TestSuite();
		}
		return s_pinstance;
	}

private:
	TestSuite();
	void test1();
	void test2();
	int m_testRun;
	int m_testPassed;
	static TestSuite *s_pinstance;
};

typedef TestSuite TheTestSuite;

#endif
