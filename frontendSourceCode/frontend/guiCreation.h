#ifndef GUI_CREATION_H
#define GUI_CREATION_H
// header file enables nana c++ library for the program
#include "nana\gui\widgets\textbox.hpp"			// header file for a textbox
#include "nana\gui\widgets\form.hpp"

void LoginLayout();
bool CheckCredentials(nana::textbox const & user, nana::textbox const & pass);
void AppLayout(nana::form & prevForm, nana::textbox const & user);
void NoteLayout();
void Settings();

void CreateLayout();
#endif