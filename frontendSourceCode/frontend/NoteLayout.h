#ifndef NOTE_LAYOUT_H
#define NOTE_LAYOUT_H
#include <string>
#include "Note.h"
#include "nana\gui.hpp"
#include "nana\gui\widgets\label.hpp"			// header file for a label widget

class NoteLayout
{
	public:
		NoteLayout(nana::form & prevForm, Note & note);
	private:
		Note * mNote;
		nana::label mLabelTitle;
		nana::label mLabelTime;
		// mDataBox typ?
};

#endif