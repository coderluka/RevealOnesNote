#include "Note.h"

Note::Note(std::string const & Title, std::string const & Time, std::string const & userName, Data * const & data)
	: mTitle{ Title }, mTime{ Time }, mUsername{ userName }, mData{ data }
{

}

std::string Note::GetTitle() const
{
	return mTitle;
}

std::string Note::GetTime() const
{
	return mTime;
}
