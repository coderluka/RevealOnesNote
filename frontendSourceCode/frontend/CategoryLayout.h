#ifndef CATEGORY_LAYOUT_H
#define CATEGORY_LAYOUT_H
#include "nana\gui.hpp"
#include "nana\gui\widgets\categorize.hpp"		/* header file for categorize widget,
												   represents the architecture of categories
												   and what category is chosen
												   ********************************************/

class CategoryLayout
{
	public:
		CategoryLayout(nana::form & prevForm);
	private:
		nana::categorize<int> * mCategory;

};

#endif