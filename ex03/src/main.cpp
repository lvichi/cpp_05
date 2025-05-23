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
#include "Intern.hpp"

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

  std::cout << "=== Forms Creation via Intern ===" << std::endl;
  Intern someIntern;

  AForm* shrub = NULL;
  AForm* robo = NULL;
  AForm* pardon = NULL;
  AForm* another = NULL;

  try { 
    shrub = someIntern.makeForm(
        "shrubbery creation", "garden"
      );
  } catch ( std::exception& error ) { 
    errorPrint( error ); 
  }
  try {
    robo = someIntern.makeForm(
        "robotomy request", "Bender"
      );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    pardon = someIntern.makeForm(
        "presidential pardon", "Harry"
      );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    another = someIntern.makeForm(
        "get coffee", "Intern"
      );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  if ( shrub ) formPrint( *shrub );
  if ( robo ) formPrint( *robo );
  if ( pardon ) formPrint( *pardon );
  if ( another ) formPrint( *another );
  wait();

  std::cout << "=== Test 1: Signing Forms ===" << std::endl;
  try {
    low.signForm( *shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.signForm( *robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.signForm( *pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    mid.signForm(*shrub);
  } catch ( std::exception& error) {
    errorPrint( error );
  }
  try {
    mid.signForm( *robo );
  } catch ( std::exception& error) {
    errorPrint( error );
  }
  try {
    mid.signForm( *pardon );
  } catch ( std::exception& error) {
    errorPrint( error );
  }

  try {
    high.signForm( *shrub );
  } catch ( std::exception& error) {
    errorPrint( error );
  }
  try {
    high.signForm( *robo );
  } catch ( std::exception& error) {
    errorPrint( error );
  }
  try {
    high.signForm( *pardon );
  } catch ( std::exception& error) {
    errorPrint( error );
  }
  wait();

  std::cout << "=== Test 2: Executing Forms ===" << std::endl;
  try {
    low.executeForm( *shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.executeForm( *robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    low.executeForm( *pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    mid.executeForm( *shrub );
  }catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    mid.executeForm( *robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    mid.executeForm( *pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  try {
    high.executeForm( *shrub );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    high.executeForm( *robo );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  try {
    high.executeForm( *pardon );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }

  delete shrub;
  delete robo;
  delete pardon;

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
