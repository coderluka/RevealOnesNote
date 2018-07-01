#include "nana\gui\place.hpp"					/* header file for layout management
												-> an object of the class is attached to a widget
												   and it automagically positions and resizes the widgets
												   that are children of the attached widget
												*********************************************************/
#include "nana\gui\wvl.hpp"						// header file for Application Interfaces with the namespace nana::gui::API
#include "nana\gui\widgets\label.hpp"			// header file for a label widget
#include "nana\gui\widgets\button.hpp"			// header file for a button widget			

#include "nana\gui\widgets\categorize.hpp"		/* header file for categorize widget,
												   represents the architecture of categories
												   and what category is chosen
												********************************************/
#include "nana\gui\widgets\menubar.hpp"			// header file for a menubar widget
#include "nana\datetime.hpp"					// header file for datetime display
#include "nana\paint\graphics.hpp"				// header file for image dispaly, graphs and points

// declaration of 'RON' Functions
#include "guiCreation.h"

#include <sstream>

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
void LoginLayout()
{
	/****** FUNCTION     HEADER ******
	- Create, Initialise, Set Events, and define the layout of the LogIn Form
	******* END FUNCTION HEADER ******/

	using namespace nana;				// open the namespace

	/* define a form object
	->  the class form will create a window
	when the instance is created.
	***************************************/
	nana::form form;
	// set window size
	nana::API::track_window_size(form, { 350, 300 }, false); //minimum
	nana::API::track_window_size(form, { 350, 300 }, true);  //maximum

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
	login.events().click([&form, &user, &pass]
	{
		if (CheckCredentials(user, pass))
			AppLayout(form, user);
		//else
			// give error message !!!
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
	nana::exec();
}

// validate if the credentials satisfy the login requirements
bool CheckCredentials(nana::textbox const & user, nana::textbox const & pass)
{
	// if check database -> is ok then	return true;
	// else return false;
	return true;			// for testing purposes
}

void AppLayout(nana::form & prevForm, nana::textbox const & user)
{
	/****** FUNCTION     HEADER ******
	- Create, Initialise, Set Events for the:
		- Menu Bars
		- Categories
		- Creation, Deletion, and Edit Buttons
		- Display of Notes (look at Function NoteLayout())
	******* END FUNCTION HEADER ******/

	using namespace nana;				// open the namespace

	/* define a form object
	->  the class form will create a window
	when the instance is created.
	***************************************/
	nana::form form;
	// set window size
	nana::API::track_window_size(form, { 800, 750 }, false); //minimum
	nana::API::track_window_size(form, { 800, 750 }, true);  //maximum

	// close previous form!
	prevForm.close();

	// Define Widgets
	categorize<int> cat{ form, rectangle{200,10,10,24} };		// create a category bar
	menubar infoMenu{ form };									// create a info menu bar
	date theDate;												// create a date object
	nana::paint::graphics graph;
	button addNote{ form };
	button edtNote{ form };
	button delNote{ form };

	// Initialise Widgets
	cat.childset("Invalid Category", 0);		// because of empty current category
	cat.insert("First", 0);						// this is now the current category!
	cat.insert("Second", 1);					/* this is a child of the First category
													 -> this is now the current category
												****************************************/
												/* childset() always inserts categories into current category and does not displace
												the current category, and therefore the 'this' category is a child of a category
												************************************************************************************/
	infoMenu.push_back("Total: ");				// display number of notes
	infoMenu.push_back(std::to_string(theDate.read().day) + "/" + std::to_string(theDate.read().month) + "/" + std::to_string(theDate.read().year));	// display datetime
	infoMenu.push_back(user.caption());			// display username

	nana::paint::image categoriesBkg{ "resources\\img\\categoriesView.bmp" };
	nana::paint::image categoryNotesBkg{ "resources\\img\\categorizedNotesView.bmp" };
	categoriesBkg.paste(graph, nana::point());
	categoryNotesBkg.paste(graph, nana::point());

	// Widget Logic (Events)
	//cat.events().selected(selected);

	// Define a place (layout) for the Form (Positioning)
	place formPosition{ form };


	/****************************************************************
	Divide the Form into fields
	the div-text layout creation, value assignment and positioning
	*****************************************************************/
	formPosition.div(
		//"vert<weight=80% vertical <weight=20% categories><weight=80% horizontal <><INFO>>>"
		"<cat><weight=60% <vertical <note><weight=5% <weight=33.3% add><weight=33.3% edit><weight=33.3% delete>>><weight=10% info horizontal>"
	);
	//formPosition.field("cat") << cat.caption();
	formPosition.field("info") << infoMenu.caption();
	formPosition.field("add") << addNote.caption("Add");
	formPosition.field("edit") << edtNote.caption("Edit");
	formPosition.field("delete") << delNote.caption("Delete");


	/*************************************
	Now the widgets need to be collocated:
	*************************************/
	formPosition.collocate();			// build the layout to be displayed
	form.show();						// dispaly the form

	// Draw Objects (Graphics)
	drawing draw{ form };
	draw.draw([&categoriesBkg](nana::paint::graphics & graph) {categoriesBkg.paste(graph, nana::point{ 0,0 }); });
	draw.draw([&categoryNotesBkg](nana::paint::graphics & graph) {categoryNotesBkg.paste(graph, nana::point{ 200,0 }); });
	draw.update();

	// Background Effects

	/*********************************************************************
	block user input until Nana event service is done with the form
	->  form is closed, after that control is passed back to the user
	*********************************************************************/
	nana::exec();
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

	LoginLayout();
	
	/******************************************************************************************
	written here only for testing! will be called from the LoginLayout() if credentials are valid
	*******************************************************************************************/
	//AppLayout(form);
}
