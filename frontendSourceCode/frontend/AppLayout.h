#ifndef APP_LAYOUT_H
#define APP_LAYOUT_H
#include <map>
#include "Note.h"
#include "nana\gui.hpp"
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

class AppLayout
{
	public:
		typedef std::pair<std::string, Note> TNote;
		typedef std::pair<std::string, std::string> Data;		// change in the future (after adding photos etc....)
		typedef enum{pdf, txt } FileType;
																// Data is made out of title, and username
		typedef std::pair<Data, nana::date> TData;

		AppLayout(nana::form & prevForm, std::string const & userName);

		TNote CreateNote(std::string const & Title, TData);
		bool AddNote(TNote const & note);
		bool RemoveNote(TNote & note);
		size_t TotalNotes() const;
		std::string GetDateTime();
		
		void ChangeCategory(std::string const & nextCategory);
		bool AddCategory(std::string const & newCategory);
		bool RemoveCategory(std::string const & oldCategory);

		void ViewByTitle() const;
		void ViewByDate() const;
		bool ExportToFile(FileType const & typeOfFile, std::string const & fileName);

	private:
		std::map<std::string, Note> mNoteCollection;
		nana::menubar				mMenubar;
		nana::button				mAddNoteButton;
		nana::button				mEditNoteButton;
		nana::button				mDeleteNoteButton;
		nana::paint::image			mCategoriesBkg;
		nana::paint::image			mCategoryNotesBkg;
		nana::place					mGrid;
		std::string BuildDate(nana::date const & date);
};

#endif