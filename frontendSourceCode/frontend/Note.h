#ifndef NOTES_H
#define NOTES_H
#include <string>

class Note
{
	public:
		typedef std::string Data;		// change in the future (after adding photos etc....)

		Note(std::string const & Title, std::string const & Time, std::string const & userName, Data * const & data);
		std::string GetTitle() const;
		std::string GetTime() const;

	private:
		static size_t noteID;
		std::string mTitle;
		std::string mTime;
		std::string mUsername;
		Data	 *  mData;

};

#endif