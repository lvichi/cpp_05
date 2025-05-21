/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:38:23 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 21:38:23 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
  : AForm( "PresidentialPardonForm", PRESIDENTIAL_PARDON_SIGN,
  PRESIDENTIAL_PARDON_EXEC ),
  _target( target ) {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(
  const PresidentialPardonForm& original )
  : AForm( original ), _target( original._target ) {}

// Assignment Constructor
PresidentialPardonForm& PresidentialPardonForm::operator=(
  const PresidentialPardonForm& original )
{
  if ( this != &original ) {
    AForm::operator=( original );
  }
  return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Getters
const std::string& PresidentialPardonForm::getTarget() const { return _target; }

// Methods
void PresidentialPardonForm::executeAction() const
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
  if ( !getSigned() )
    throw FormNotSignedException();
  if ( executor.getGrade() > getExecGrade() )
    throw GradeTooLowException();
  executeAction();
}

// Exception
const char* PresidentialPardonForm::FormNotSignedException::what() const throw() {
  return "Form not signed.";
}

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const PresidentialPardonForm& form )
{
  out << "Form " << form.getName()
      << ( form.getSigned() ? " is signed. " : " is not signed. " )
      << "Sign grade is " << form.getSignGrade() << ". "
      << "Execute grade is " << form.getExecGrade() << ". "
      << "Target is " << form.getTarget() << ".";
  return out;
}
