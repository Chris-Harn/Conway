#include "Message.h"

#include <iostream>

void messsage( const char *message ) {
	std::cout << "  " << message << " \n";
}

void errorMessage( const char *errorMessage ) {
	std::cout << "** Error: " << errorMessage << " **\n";
}
