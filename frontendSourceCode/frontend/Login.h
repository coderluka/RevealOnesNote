#ifndef LOGIN_H
#define LOGIN_H
#include "nana\gui.hpp"

class Login
{
	public:
		Login(nana::form & Form);
	private:
		std::string mUser;
		std::string mPass;
		bool CheckCredentials(std::string const & user, std::string const & pass) const;
};

#endif