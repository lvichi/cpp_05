/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:13:06 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 21:13:11 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_SIGN 145
#define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public AForm
{
  private:
    const std::string   _target;

    // Helpers
    void executeAction() const;

  public:
    // Canonical form
    ShrubberyCreationForm( const std::string& target );
    ShrubberyCreationForm( const ShrubberyCreationForm& original );
    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& original );
    virtual ~ShrubberyCreationForm();

    // Getters
    const std::string& getTarget() const;

    // Methods
    void execute(const Bureaucrat& executor) const;

    // Exceptions
    class FormNotSignedException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};