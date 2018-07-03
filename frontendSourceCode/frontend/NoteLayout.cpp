#include "NoteLayout.h"

NoteLayout::NoteLayout(nana::form & prevForm, Note & note)
{
	mNote = &note;
	mLabelTitle.caption(mNote->GetTitle());
	mLabelTime.caption(mNote->GetTime());
}
