/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:11:12 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/22 01:11:40 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Defining a function for each form
AForm* createShrubbery( const std::string& target )
{
  return new ShrubberyCreationForm( target );
}

AForm* createRobotomy( const std::string& target )
{
  return new RobotomyRequestForm( target );
}

AForm* createPardon( const std::string& target )
{
  return new PresidentialPardonForm( target );
}

// Defining forms alias
const char* Intern::_formNames[] = {
  "shrubbery creation",
  "robotomy request",
  "presidential pardon",
  NULL
};

// Function lists
AForm* ( *Intern::_formFactories[] )( const std::string& ) = {
  createShrubbery,
  createRobotomy,
  createPardon,
  NULL
};

// Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern( const Intern& intern )
{
  (void)intern;
}

// Assignment Constructor
Intern& Intern::operator=( const Intern& intern )
{
  (void)intern;
  return *this;
}

// Destructor
Intern::~Intern() {}

// Methods
AForm* Intern::makeForm( const std::string& form, const std::string& target )
  const
{
  int i = -1;
  while ( _formNames[++i] ) {
    if ( form == _formNames[i] ) {
      std::cout << "Intern creates " << form << std::endl;
      return _formFactories[i]( target );
    }
  }
  throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
  return "Form was not found";
}