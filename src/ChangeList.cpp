#include "ChangeList.h"

ChangeList::ChangeList( int sizeOfArray ) {
	m_pcurrentList = 0;
	m_pcurrentList = new int[ sizeOfArray ];

	m_totalNumbersInList = 0;
	m_maxMemory = sizeOfArray;
}

ChangeList::~ChangeList() {
	if( m_pcurrentList != 0 ) {
		delete []m_pcurrentList;
		m_pcurrentList = 0;
	}
}
	
void ChangeList::addNumberToList( int number ) {
	if( m_totalNumbersInList < m_maxMemory ) {
		m_pcurrentList[ m_totalNumbersInList ] = number;
		m_totalNumbersInList++;
	} else {
		// produce SDL error
	}
}

bool ChangeList::removeNumberFromList( int &number ) {
	if( m_totalNumbersInList > 0 ) {
		number = m_pcurrentList[ m_totalNumbersInList - 1 ];
		m_totalNumbersInList--;
		return true;
	} 

	number = 0;
	return false;
}

