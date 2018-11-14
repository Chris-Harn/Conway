#ifndef __TESTSUITE__
#define __TESTSUITE__

class TestSuite {
public:
	void init();
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
	static TestSuite *s_pinstance;
};

typedef TestSuite TheTestSuite;

#endif
