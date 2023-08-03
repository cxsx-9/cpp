#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string	fname;
        std::string	lname;
        std::string	nname;
        std::string	pnum;
        std::string secret;
    public:
        std::string	get_fname(void);
        std::string	get_lname(void);
        std::string	get_nname(void);
        std::string	get_pnum(void);
        std::string	get_secret(void);
        void		set_fname(std::string str);
        void		set_lname(std::string str);
        void		set_nname(std::string str);
        void		set_pnum(std::string str);
        void		set_secret(std::string str);
};

#endif