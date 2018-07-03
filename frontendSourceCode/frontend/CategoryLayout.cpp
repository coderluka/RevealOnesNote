#include "CategoryLayout.h"

CategoryLayout::CategoryLayout(nana::form & prevForm)
{
	nana::form Form;
	mCategory = &nana::categorize<int>{ Form, nana::rectangle{ 200,10,10,24 } };		// create a category bar
	
	// Do Stuff before form.close() !!!
	
	prevForm.close();
}
