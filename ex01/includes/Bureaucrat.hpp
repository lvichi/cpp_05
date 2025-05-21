/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:14:40 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 14:14:48 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
  private:
    const std::string     _name;
    int                   _grade;

    // Helpers
    void checkGrade( int grade );

  public:
    // Canonical form
    Bureaucrat( const std::string& name, int grade );
    Bureaucrat( const Bureaucrat& original );
    Bureaucrat&           operator=( const Bureaucrat& original );
    ~Bureaucrat();

    // Setters
    void setGrade( int grade );

    // Getters
    const std::string&    getName() const;
    int                   getGrade() const;

    // Methods
    void incrementGrade();
    void decrementGrade();
    void signForm( Form& form );

    // Exceptions Classes
    class GradeTooHighException : public std::exception
    {
      public:
        const char*         what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char*         what() const throw();
    };
};

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const Bureaucrat& bureaucrat );
