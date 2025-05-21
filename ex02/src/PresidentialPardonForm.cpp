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
  PRESIDENTIAL_PARDON_EXEC ), _target( target ), _executed( false ) {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(
  const PresidentialPardonForm& original )
  : AForm( original ), _target( original._target ), _executed( false ) {}

// Assignment Constructor
PresidentialPardonForm& PresidentialPardonForm::operator=(
  const PresidentialPardonForm& original )
{
  if ( this != &original ) {
    AForm::operator=( original );
    _executed = original._executed;
  }
  return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Getters
const std::string& PresidentialPardonForm::getTarget() const { return _target; }
bool PresidentialPardonForm::getExecuted() const { return _executed; }

// Methods
void PresidentialPardonForm::executeAction() const
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
  if ( !getSigned() )
    throw FormNotSignedException();
  if ( getExecuted() )
    throw FormAlreadyExecutedException();
  if ( executor.getGrade() > getExecGrade() )
    throw GradeTooLowException();
  executeAction();
  _executed = true;
}

// Exception
const char* PresidentialPardonForm::FormNotSignedException::what() const throw() {
  return "Form not signed.";
}

const char* PresidentialPardonForm::FormAlreadyExecutedException::what() const throw() {
  return "Form already executed.";
}

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const PresidentialPardonForm& form )
{
  out << "Form " << form.getName()
      << ( form.getSigned() ? " is signed. " : " is not signed. " )
      << "Sign grade is " << form.getSignGrade() << ". "
      << "Execute grade is " << form.getExecGrade() << ". "
      << "Target is " << form.getTarget() << " and "
      << ( form.getExecuted() ? " it was executed. " : " it was not executed. " );
  return out;
}
