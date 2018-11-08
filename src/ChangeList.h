#ifndef __CHANGELIST__
#define __CHANGELIST__

class ChangeList {
	public:
	ChangeList( int sizeOfArray );
	~ChangeList();
	
	void addNumberToList( int number );
	bool removeNumberFromList( int &number );

	private:
	int *m_pcurrentList;
	int m_currentNumber;
	int m_totalNumbersInList;
};

#endif
