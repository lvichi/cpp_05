/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:38:23 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 21:38:23 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
  : AForm( "ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC ),
  _target( target ), _executed( false ) {}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(
  const ShrubberyCreationForm& original )
  : AForm( original ), _target( original._target ), _executed( false ) {}

// Assignment Constructor
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
  const ShrubberyCreationForm& original )
{
  if ( this != &original ) {
    AForm::operator=( original );
    _executed = original._executed;
  }
  return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Getters
const std::string& ShrubberyCreationForm::getTarget() const { return _target; }
bool ShrubberyCreationForm::getExecuted() const { return _executed; }

// Methods
void ShrubberyCreationForm::executeAction() const
{
  std::ofstream file( ( _target + "_shrubbery" ).c_str() );
  if ( !file )
    throw std::runtime_error("Failed to create shrubbery file");
  file << "         ,@@@@@@@,"                        << std::endl
       << " ,,,.   ,@@@@@@/@@,  .oo8888o."            << std::endl
       << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"        << std::endl
       << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"    << std::endl
       << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"     << std::endl
       << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"      << std::endl
       << "`&%\\ ` /%&'    |.|        \\ '|8'"        << std::endl
       << "    |o|        | |         | |"            << std::endl
       << "    |.|        | |         | |"            << std::endl
       << " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
  file.close();
}

void ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
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
const char* ShrubberyCreationForm::FormNotSignedException::what() const throw() {
  return "Form not signed.";
}

const char* ShrubberyCreationForm::FormAlreadyExecutedException::what() const throw() {
  return "Form already executed.";
}

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const ShrubberyCreationForm& form )
{
  out << "Form " << form.getName()
      << ( form.getSigned() ? " is signed. " : " is not signed. " )
      << "Sign grade is " << form.getSignGrade() << ". "
      << "Execute grade is " << form.getExecGrade() << ". "
      << "Target is " << form.getTarget() << "."
      << ( form.getExecuted() ? " it was executed. " : " it was not executed. " );
  return out;
}
