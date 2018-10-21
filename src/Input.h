#ifndef __INPUT__
#define __INPUT__


class Input {
public:
	void update();
	void clean();

	static Input* Instance() {
		if( s_pInstance == 0 ) {
			s_pInstance = new Input();
		}
		return s_pInstance;
	}

private:
	Input();
	~Input();
	
	static Input* s_pInstance;
};

typedef Input TheInputHandler;
#endif
