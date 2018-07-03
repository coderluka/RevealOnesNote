#include "Login.h"
#include "nana\gui\place.hpp"					/* header file for layout management
												-> an object of the class is attached to a widget
												and it automagically positions and resizes the widgets
												that are children of the attached widget
												*********************************************************/
#include "nana\gui\wvl.hpp"						// header file for Application Interfaces with the namespace nana::gui::API
#include "nana\gui\widgets\label.hpp"			// header file for a label widget
#include "nana\gui\widgets\button.hpp"			// header file for a button widget			
#include "nana\gui\widgets\textbox.hpp"

#include "nana\gui\widgets\categorize.hpp"		/* header file for categorize widget,
												represents the architecture of categories
												and what category is chosen
												********************************************/
#include "nana\gui\widgets\menubar.hpp"			// header file for a menubar widget
#include "nana\datetime.hpp"					// header file for datetime display
#include "nana\paint\graphics.hpp"				// header file for image dispaly, graphs and points

#include "AppLayout.h"

// Constructor call
// creates the layout, labels and buttons, all positioned, aligned for the login Form
Login::Login(nana::form & Form)
{
	/****** FUNCTION     HEADER ******
	- Create, Initialise, Set Events, and define the layout of the LogIn Form
	******* END FUNCTION HEADER ******/

	using namespace nana;				// open the namespace

	// set window size
	nana::API::track_window_size(Form, { 350, 300 }, false); //minimum
	nana::API::track_window_size(Form, { 350, 300 }, true);  //maximum

															 // Define Widgets
	label lbl{ Form };					// define a label on the form with a specified area
	textbox user{ Form }, pass{ Form };
	button login{ Form, rectangle{ 20,20,150,30 } };
	button cancel{ Form, rectangle{ 20,20,150,30 } };

	// Initialise Widgets
	lbl.caption("Servus!");				// set the label caption
	user.tip_string("User:").multi_lines(false);
	pass.tip_string("Password:").multi_lines(false).mask('*');
	login.caption("Login");
	cancel.caption("Logout");

	// Widget Logic (Events)
	login.events().click([this, &Form, &user, &pass]
	{
		if (this->CheckCredentials(user.caption(), pass.caption()))
			AppLayout MainScreen{ Form, user.caption() };
		//else
		// give error message !!!
	});

	cancel.events().click([&Form]
	{
		Form.close();
	});

	// Define a place (layout) for the Form (Positioning)
	place formPosition{ Form };

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
	Form.show();						// dispaly the form

										/*********************************************************************
										block user input until Nana event service is done with the form
										->  form is closed, after that control is passed back to the user
										*********************************************************************/
	nana::exec();
}

// validate if the credentials satisfy the login requirements
bool Login::CheckCredentials(std::string const & user, std::string const & pass) const
{
	return true;
}
