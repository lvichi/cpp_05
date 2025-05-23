/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:26:38 by lvichi            #+#    #+#             */
/*   Updated: 2025/05/21 17:18:47 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void bureaucratPrint( const Bureaucrat& a );
void errorPrint( const std::exception& error );
void wait();
void formPrint( const AForm& form );

int main() {
  std::cout << "=== Bureaucrats Creation ===" << std::endl;
  Bureaucrat high( "Alice", 1 );
  Bureaucrat mid( "Bob", 70 );
  Bureaucrat low( "Charlie", 140 );
  bureaucratPrint( high );
  bureaucratPrint( mid );
  bureaucratPrint( low );
  wait();

  std::cout << "=== Forms Creation ===" << std::endl;
  ShrubberyCreationForm shrub( "garden" );
  RobotomyRequestForm robo( "Bender" );
  PresidentialPardonForm pardon( "Harry" );
  formPrint( shrub );
  formPrint( robo );
  formPrint( pardon );
  wait();

  std::cout << "=== Test 1: Signing Forms ===" << std::endl;
  try {
    low.signForm( shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.signForm( robo );
  } catch ( std::exception& error ){
    errorPrint( error );
  }
  try {
    low.signForm( pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    mid.signForm( shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    mid.signForm( robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    mid.signForm( pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    high.signForm( shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    high.signForm( robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    high.signForm( pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  wait();

  std::cout << "=== Test 2: Executing Forms ===" << std::endl;
  try {
    low.executeForm( shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.executeForm( robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.executeForm( pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    mid.executeForm( shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    mid.executeForm( robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    mid.executeForm( pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    high.executeForm( shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    high.executeForm( robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    high.executeForm( pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  return 0;
}

void bureaucratPrint( const Bureaucrat& a )
{
  std::cout << a << std::endl;
}

void errorPrint( const std::exception& error )
{
  std::cerr << "Caught exception: " << error.what();
  std::cerr << std::endl;
}

void formPrint( const AForm& form )
{
  std::cout << form << std::endl;
}

void wait() {
  std::cin.ignore( 10000, '\n' );
}
