/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:02:17 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/22 01:02:23 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
  private:
    static const char* _formNames[];
    static AForm* ( *_formFactories[] )( const std::string& target );

  public:
    // Canonical form
    Intern();
    Intern( const Intern& original );
    Intern& operator=( const Intern& original);
    ~Intern();

    // Methods
    AForm* makeForm( const std::string& form, const std::string& target ) const;

    class FormNotFoundException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};
