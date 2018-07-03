#include "AppLayout.h"

// Constructor call
AppLayout::AppLayout(nana::form & prevForm, std::string const & userName)
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
	categorize<int> cat{ form, rectangle{ 200,10,10,24 } };		// create a category bar
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
	infoMenu.push_back(userName);			// display username

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

bool AppLayout::AddNote(TNote const & note)
{
	// check with the database!
	mNoteCollection.insert(note);
	return true;
}

bool AppLayout::RemoveNote(TNote & note)
{
	mNoteCollection.erase(note.first);
	return true;
}

size_t AppLayout::TotalNotes() const
{
	return mNoteCollection.size();
}

std::string AppLayout::GetDateTime()
{
	return BuildDate(nana::date{});
}

std::string AppLayout::BuildDate(nana::date const & date)
{
	std::string result = std::to_string(date.read().day) +
						 "/" +
						 std::to_string(date.read().month) +
						 "/" +
						 std::to_string(date.read().year);
	// return datetime
	return result;
}
