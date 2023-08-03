/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:48:37 by csantivi          #+#    #+#             */
/*   Updated: 2023/08/03 11:34:21 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::get_fname(void)
{
	return (this->fname);
}

std::string	Contact::get_lname(void)
{
	return (this->lname);
}

std::string	Contact::get_nname(void)
{
	return (this->nname);
}

std::string	Contact::get_pnum(void)
{
	return (this->pnum);
}

std::string	Contact::get_secret(void)
{
	return (this->secret);
}

void	Contact::set_fname(std::string str)
{
	this->fname = str;
}

void	Contact::set_lname(std::string str)
{
	this->lname = str;
}

void	Contact::set_nname(std::string str)
{
	this->nname = str;
}

void	Contact::set_pnum(std::string str)
{
	this->pnum = str;
}

void	Contact::set_secret(std::string str)
{
	this->secret = str;
}
