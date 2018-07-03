#ifndef SETTINGS_H
#define SETTINGS_H
#include "nana\gui.hpp"

#include "nana\gui\wvl.hpp"						// header file for Application Interfaces with the namespace nana::gui::API
#include "nana\gui\widgets\label.hpp"			// header file for a label widget
#include "nana\gui\widgets\button.hpp"			// header file for a button widget			
#include "nana\gui\widgets\textbox.hpp"
#include "nana\gui\widgets\checkbox.hpp"
#include "nana\gui\widgets\combox.hpp"

class Settings
{
	public:
		Settings(nana::form & prevForm);
	private:
		nana::button   mButtonClose;
		nana::checkbox mCheckBox1;
		nana::combox   mComboBox1;
};

#endif