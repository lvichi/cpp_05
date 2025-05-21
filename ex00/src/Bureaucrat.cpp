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
Bureaucrat::Bureaucrat(const std::string& name, int grade)
  : _name(name), _grade(grade)
{
  checkGrade(grade);
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& original)
  : _name(original._name), _grade(original._grade) {}

// Assignment Constructor
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
  if (this != &original) {
    _grade = original._grade;
  }
  return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Setters
void Bureaucrat::setGrade(int grade)
{
  checkGrade(grade);
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
  checkGrade(_grade - 1);
  _grade--;
}

void Bureaucrat::decrementGrade()
{
  checkGrade(_grade + 1);
  _grade++;
}

// Helpers
void Bureaucrat::checkGrade(int grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
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

// Overload redirect operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << '.';
  return os;
}

