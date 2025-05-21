/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:38:23 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 21:38:23 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
  : AForm( "RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC ),
  _target( target ) {}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(
  const RobotomyRequestForm& original )
  : AForm( original ), _target( original._target ) {}

// Assignment Constructor
RobotomyRequestForm& RobotomyRequestForm::operator=(
  const RobotomyRequestForm& original )
{
  if ( this != &original ) {
    AForm::operator=( original );
  }
  return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Getters
const std::string& RobotomyRequestForm::getTarget() const { return _target; }

// Methods
void RobotomyRequestForm::executeAction() const
{
  std::cout << "** drilling noises ** BZZZZZZZZ..." << std::endl;
  sleep( 2 );
  if ( rand() % 2 == 0 ) {
    std::cout << _target << " has been robotomized successfully" << std::endl;
  } else {
    std::cout << "Robotomy failed on " << _target << " ." << std::endl;
  }
}

void RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
  if ( !getSigned() )
    throw FormNotSignedException();
  if ( executor.getGrade() > getExecGrade() )
    throw GradeTooLowException();
  executeAction();
}

// Exception
const char* RobotomyRequestForm::FormNotSignedException::what() const throw() {
  return "Form not signed.";
}

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const RobotomyRequestForm& form )
{
  out << "Form " << form.getName()
      << ( form.getSigned() ? " is signed. " : " is not signed. " )
      << "Sign grade is " << form.getSignGrade() << ". "
      << "Execute grade is " << form.getExecGrade() << ". "
      << "Target is " << form.getTarget() << ".";
  return out;
}
