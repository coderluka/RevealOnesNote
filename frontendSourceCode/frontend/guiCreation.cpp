/* header file for layout management
-> an object of the class is attached to a widget
   and it automagically positions and resizes the widgets
   that are children of the attached widget
*********************************************************/
#include "nana\gui\place.hpp"
#include "nana\gui\wvl.hpp"						// header file for Application Interfaces with the namespace nana::gui::API
#include "nana\gui\widgets\label.hpp"			// header file for a label widget
#include "nana\gui\widgets\button.hpp"			// header file for a button widget			
#include "nana\gui\widgets\textbox.hpp"			// header file for a textbox

#include "nana\gui\widgets\categorize.hpp"		/* header file for categorize widget,
												   represents the architecture of categories
												   and what category is chosen
												********************************************/

// declaration of 'RON' Functions
#include "guiCreation.h"

// ****** HELPER     METHODS ******
//void selected(nana::categorize<int> & cat, int&)
//{
//	nana::msgbox message{ cat, "categorize" };
//	message.icon(message.icon_information);
//	message << "The value of selected is " << cat.value() << ", caption is \"" << cat.caption() << "\"";
//	message();
//}
// ****** END HELPER METHODS ******

// creates the layout, labels and buttons, all positioned, aligned for the login Form
void LoginLayout(nana::form & form)
{
	/****** FUNCTION     HEADER ******
	- Create, Initialise, Set Events, and define the layout of the LogIn Form
	******* END FUNCTION HEADER ******/

	using namespace nana;				// open the namespace

	// Define Widgets
	label lbl{ form };					// define a label on the form with a specified area
	textbox user{ form }, pass{ form };
	button login{ form, rectangle{20,20,150,30} };
	button cancel{ form, rectangle{ 20,20,150,30 } };

	// Initialise Widgets
	lbl.caption("Servus!");				// set the label caption
	user.tip_string("User:").multi_lines(false);
	pass.tip_string("Password:").multi_lines(false).mask('*');
	login.caption("Login");
	cancel.caption("Logout");

	// Widget Logic (Events)
	login.events().click([&form]
	{
		// TO-DO
	});

	cancel.events().click([&form]
	{
		form.close();
	});

	// Define a place (layout) for the Form (Positioning)
	place formPosition{ form };

	/****************************************************************
	Divide the Form into fields
	the div-text layout creation, value assignment and positioning
	*****************************************************************/
	formPosition.div(
		"<><weight=80% vertical <><weight=80% vertical <vertical <user><><pass><> weight=60% <<horizontal buttonuser><><horizontal buttonpass>>>><>><>"
	);
	formPosition["labeluser"] << lbl;		// replace placeholder here with label
	formPosition["labelpass"] << lbl;		// replace placeholder here with label
	formPosition["user"] << user;
	formPosition["pass"] << pass;
	formPosition["buttonuser"] << login;
	formPosition["buttonpass"] << cancel;

	/*************************************
	Now the widgets need to be collocated:
	*************************************/
	formPosition.collocate();			// build the layout to be displayed

	/*************************************
	Now the widgets need to be collocated:
	*************************************/
	form.show();						// dispaly the form

	/*********************************************************************
	block user input until Nana event service is done with the form
	->  form is closed, after that control is passed back to the user
	*********************************************************************/
	exec();
}

void AppLayout(nana::form & form)
{
	/****** FUNCTION     HEADER ******
	- Create, Initialise, Set Events for the:
		- Menu Bars
		- Categories
		- Creation, Deletion, and Edit Buttons
		- Display of Notes (look at Function NoteLayout())
	******* END FUNCTION HEADER ******/

	using namespace nana;				// open the namespace

	// Define Widgets
	categorize<int> cat{ form, rectangle{200,10,10,24} };		// create a category bar

	// Initialise Widgets
	cat.childset("Invalid Category", 0);		// because of empty current category
	cat.insert("First", 0);						// this is now the current category!
	cat.insert("Second", 1);					/* this is a child of the First category
													 -> this is now the current category
												****************************************/
	/* childset() always inserts categories into current category and does not displace
	   the current category, and therefore the 'this' category is a child of a category
	************************************************************************************/

	// Widget Logic (Events)
	//cat.events().selected(selected);

	// Define a place (layout) for the Form (Positioning)
	place formPosition{ form };


	/****************************************************************
	Divide the Form into fields
	the div-text layout creation, value assignment and positioning
	*****************************************************************/
	formPosition.div(
		"<vertical categories><vertical <horizontal><horizontal>><vertical>"
	);
	formPosition["categories"] << cat.caption();

	/*************************************
	Now the widgets need to be collocated:
	*************************************/
	form.show();						// dispaly the form

	/*********************************************************************
	block user input until Nana event service is done with the form
	->  form is closed, after that control is passed back to the user
	*********************************************************************/
	exec();
}

void CreateLayout()
{
	/****** FUNCTION     HEADER ******
	- Call the Functions to build the parts of the application respectfully:
		- LoginLayout()				... build the LogIn Page
			- AppLayout()			... if LogIn successfull show the App
				- NoteLayout()		... Display all the Notes and be prepared for events
					- Settings()	... be prepared to display Settings if clicked upon
	******* END FUNCTION HEADER ******/

	using namespace nana;				// open the namespace

	/* define a form object
	->  the class form will create a window
	when the instance is created.
	***************************************/
	form form;

	LoginLayout(form);
	
	/******************************************************************************************
	written here only for testing! will be called from the LoginLayout() if credentials are valid
	*******************************************************************************************/
	//AppLayout(form);
}
