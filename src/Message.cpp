#include "Message.h"

#include <iostream>


/**************************************************
 *  message
 *  Purpose: Print string literal that is passed in
 *  to console. 
 *  Input: const char * from string literal.
 *  Return: None.
 *
 *************************************************/

void messsage( const char *message ) {
	std::cout << "  " << message << " \n";
}


/**************************************************
 *  errorMessage 
 *  Purpose: Print string literal that is passed in
 *  to console as error message.
 *  Input: const char * from string literal.
 *  Return: None.
 *
 *************************************************/

void errorMessage( const char *errorMessage ) {
	std::cout << "** Error: " << errorMessage << " **\n";
}
