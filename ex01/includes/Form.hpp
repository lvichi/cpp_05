/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
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

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form
{
  private:
    const std::string     _name;
    bool                  _signed;
    const int             _sign_grade;
    const int             _exec_grade;

    // Helpers
    void checkGrade( int grade, int min_grade );

  public:
    // Canonical form
    Form( const std::string& name, int _sign_grade, int _exec_grade );
    Form( const Form& original );
    Form& operator=( const Form& original );
    ~Form();

    // Getters
    const std::string& getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Methods
    void beSigned( const Bureaucrat& agent );

    // Exceptions Classes
    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};

// Overload insertion operator
std::ostream& operator<<( std::ostream& out, const Form& form );
