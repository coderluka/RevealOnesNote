return_type FunctionName(Paramters)
{
	/****** FUNCTION     HEADER ******
	Describe the Functionality of the Function:...
	******* END FUNCTION HEADER ******/

	using namespace nana;	// open the namespace

	// Define Widgets
	
	// Initialise Widgets
	
	// Widget Logic (Events)
	
	// Define a place (layout) for the Form (Positioning)
	
	/****************************************************************
	Divide the Form into fields
	the div-text layout creation, value assignment and positioning
	*****************************************************************/
	
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