/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:13:06 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 21:13:11 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PRESIDENTIAL_PARDON_SIGN 25
#define PRESIDENTIAL_PARDON_EXEC 5

class PresidentialPardonForm : public AForm
{
  private:
    const std::string   _target;
    mutable bool        _executed;

    // Helpers
    void executeAction() const;

  public:
    // Canonical form
    PresidentialPardonForm( const std::string& target );
    PresidentialPardonForm( const PresidentialPardonForm& original );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& original );
    virtual ~PresidentialPardonForm();

    // Getters
    const std::string& getTarget() const;
    bool getExecuted() const;

    // Methods
    void execute(const Bureaucrat& executor) const;

    // Exceptions
    class FormNotSignedException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    class FormAlreadyExecutedException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};