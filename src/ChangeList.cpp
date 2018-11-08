#include "ChangeList.h"

ChangeList::ChangeList( int sizeOfArray ) {
	m_pcurrentList = 0;
	m_pcurrentList = new int[ sizeOfArray ];

	m_currentNumber = 0;
	m_totalNumbersInList = 0;
}

ChangeList::~ChangeList() {
	if( m_pcurrentList != 0 ) {
		delete []m_pcurrentList;
		m_pcurrentList = 0;
	}
}
	
void ChangeList::addNumberToList( int number ) {

}

bool ChangeList::removeNumberFromList( int &number ) {

}

