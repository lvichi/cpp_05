/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:15:01 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 14:15:11 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat( const std::string& name, int grade )
  : _name( name ), _grade( grade )
{
  checkGrade( grade );
}

// Copy Constructor
Bureaucrat::Bureaucrat( const Bureaucrat& original )
  : _name( original._name ), _grade( original._grade ) {}

// Assignment Constructor
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& original )
{
  if ( this != &original ) {
    _grade = original._grade;
  }
  return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Setters
void Bureaucrat::setGrade(int grade)
{
  checkGrade( grade );
  _grade = grade;
}

// Getters
const std::string& Bureaucrat::getName() const
{
  return _name;
}

int Bureaucrat::getGrade() const
{
  return _grade;
}

// Methods
void Bureaucrat::incrementGrade()
{
  checkGrade( _grade - 1 );
  _grade--;
}

void Bureaucrat::decrementGrade()
{
  checkGrade( _grade + 1 );
  _grade++;
}

void Bureaucrat::signForm( Form& form )
{
  try {
    form.beSigned( *this );
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (std::exception& error) {
    std::cerr << _name << " couldn’t sign ";
    std::cerr << form.getName() << " because ";
    std::cerr << error.what() << std::endl;
  }
}

// Helpers
void Bureaucrat::checkGrade( int grade ) {
  if ( grade < MAX_GRADE )
    throw GradeTooHighException();
  if ( grade > MIN_GRADE )
    throw GradeTooLowException();
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade Too High.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade Too Low.";
}

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
  out << bureaucrat.getName();
  out << ", bureaucrat grade " << bureaucrat.getGrade() << '.';
  return out;
}

