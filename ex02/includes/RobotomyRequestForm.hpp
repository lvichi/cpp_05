/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:13:06 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 21:13:11 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <unistd.h>
#include <cstdlib>

#define ROBOTOMY_SIGN 72
#define ROBOTOMY_EXEC 45

class RobotomyRequestForm : public AForm
{
  private:
    const std::string   _target;

    // Helpers
    void executeAction() const;

  public:
    // Canonical form
    RobotomyRequestForm( const std::string& target );
    RobotomyRequestForm( const RobotomyRequestForm& original );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& original );
    virtual ~RobotomyRequestForm();

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