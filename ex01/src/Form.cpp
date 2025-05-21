/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:15:01 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 18:50:13 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form( const std::string& name, int sign_grade, int exec_grade )
  : _name( name ), _signed( false ), _sign_grade( sign_grade ),
  _exec_grade( exec_grade )
{
  checkGrade( sign_grade, MIN_GRADE );
  checkGrade( exec_grade, MIN_GRADE );
}

// Copy Constructor
Form::Form( const Form& original )
  : _name( original._name ), _signed( original._signed ),
  _sign_grade( original._sign_grade ), _exec_grade( original._exec_grade ) {}

// Assignment Constructor
Form& Form::operator=( const Form& original )
{
  if ( this != &original ) {
    _signed = original._signed;
  }
  return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string& Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getSignGrade() const { return _sign_grade; }

int Form::getExecGrade() const { return _exec_grade; }

// Methods
void Form::beSigned( const Bureaucrat& agent )
{
  checkGrade( agent.getGrade(), _sign_grade );
  _signed = true;
}

// Helpers
void Form::checkGrade( int grade, int min_grade ) {
  if ( grade < MAX_GRADE )
    throw GradeTooHighException();
  if ( grade > min_grade )
    throw GradeTooLowException();
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
  return "Grade Too High.";
}

const char* Form::GradeTooLowException::what() const throw()
{
  return "Grade Too Low.";
}

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const Form& form )
{
  out << "Form " << form.getName();
  if ( form.getSigned() ) {
    out << " is signed. ";
  }
  else {
    out << " is not signed. ";
  }
  out << "Sign grade is " << form.getSignGrade() << ". ";
  out << "Execute grade is " << form.getExecGrade() << ".";
  return out;
}
