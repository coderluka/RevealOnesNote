#include "frontend.h"
#include "Login.h"

void frontend::CreateLayout()
{
	/****** FUNCTION     HEADER ******
	- Call the Functions to build the parts of the application respectfully:
		- LoginLayout()				... build the LogIn Page
			- AppLayout()			... if LogIn successfull show the App
				- NoteLayout()		... Display all the Notes and be prepared for events
					- Settings()	... be prepared to display Settings if clicked upon
	******* END FUNCTION HEADER ******/
	Login l1{mForm};
}
