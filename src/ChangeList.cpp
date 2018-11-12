#include "ChangeList.h"


/**************************************************
 *  ChangeList::ChangeList
 *  Purpose: Constructor that is set to the size of
 *  the board... allowing all spaces to be set to 
 *  alive. 
 *  Input: int that is sized to the board.
 *  Return: None.
 *
 *************************************************/

ChangeList::ChangeList( int sizeOfArray ) {
	m_pcurrentList = 0;
	m_pcurrentList = new int[ sizeOfArray ];

	m_totalNumbersInList = 0;
	m_maxMemory = sizeOfArray;
}


/**************************************************
 *  ChangeList::~ChangeList
 *  Purpose: Deconstructor that deletes the memory 
 *  allocated on the heap.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

ChangeList::~ChangeList() {
	if( m_pcurrentList != 0 ) {
		delete []m_pcurrentList;
		m_pcurrentList = 0;
	}
}


/**************************************************
 *  ChangeList::addNumberToList
 *  Purpose: Adds a tile number (int) to the top of
 *  the stack. First In, Last Out.
 *  Input: int number to add to top of stack.
 *  Return: None.
 *
 *************************************************/
	
void ChangeList::addNumberToList( int number ) {
	if( m_totalNumbersInList < m_maxMemory ) {
		m_pcurrentList[ m_totalNumbersInList ] = number;
		m_totalNumbersInList++;
	} else {
		// produce SDL error
	}
}


/**************************************************
 *  ChangeList::removeNumberFromList
 *  Purpose: Pops last value off the stack. Value is
 *  done by passing by reference.
 *  Input: int num that is empty.
 *  Return: bool (true) if the value returned is popped
 *  off the top of the stack. bool (false) if no more
 *  numbers to pop off.
 *
 *************************************************/

bool ChangeList::removeNumberFromList( int &number ) {
	if( m_totalNumbersInList > 0 ) {
		number = m_pcurrentList[ m_totalNumbersInList - 1 ];
		m_totalNumbersInList--;
		return true;
	} 

	number = 0;
	return false;
}

