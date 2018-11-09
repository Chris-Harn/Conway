#ifndef __CHANGELIST__
#define __CHANGELIST__

/**************************************************
 *  ChangeList
 *  Purpose: Data structure that is one size, and 
 *  holds all the tiles designated to change. This
 *  allows counting of all the living cells in the
 *  first pass and then changing only the ones that
 *  were designated. Array does not change size.
 *
 *************************************************/

class ChangeList {
	public:
	ChangeList( int sizeOfArray );
	~ChangeList();
	
	void addNumberToList( int number );
	bool removeNumberFromList( int &number );

	private:
	int *m_pcurrentList;
	int m_totalNumbersInList;
	int m_maxMemory;
};

#endif
