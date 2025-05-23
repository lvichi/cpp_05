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

void bureaucratPrint( const Bureaucrat& a );
void errorPrint( const std::exception& error );
void wait();

int main() {
  std::cout << "=== Valid Construction ===" << std::endl;
  Bureaucrat alice( "Alice", 42 );
  bureaucratPrint( alice );
  wait();

  std::cout << "=== Grade Increment ===" << std::endl;
  alice.incrementGrade();
  bureaucratPrint( alice );
  wait();

  std::cout << "=== Grade Decrement ===" << std::endl;
  alice.decrementGrade();
  bureaucratPrint( alice );
  wait();

  std::cout << "=== Set Grade ===" << std::endl;
  alice.setGrade( 100 );
  bureaucratPrint( alice );
  wait();

  std::cout << "=== Copy Constructor ===" << std::endl;
  Bureaucrat alice_copy( alice );
  bureaucratPrint( alice_copy );
  wait();

  std::cout << "=== Assignment Operator ===" << std::endl;
  Bureaucrat charlie( "Charlie", 1 );
  std::cout << "Before assignment: " << std::endl;
  bureaucratPrint( charlie );
  charlie = alice;
  std::cout << "After assignment: " << std::endl;
  bureaucratPrint( charlie) ;
  wait();

  std::cout << "=== Exception on Too High Grade ===" << std::endl;
  try {
    Bureaucrat John( "John", 0 );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  wait();

  std::cout << "=== Exception on Too Low Grade ===" << std::endl;
  try {
    Bureaucrat Ingrid( "Ingrid", 200 );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  wait();

  std::cout << "=== Exception on Set Grade ===" << std::endl;
  try {
    alice.setGrade( 300 );
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  wait();

  std::cout << "=== Exception on Incrementing Too Far ===" << std::endl;
  try {
    Bureaucrat mark( "Mark", 1 );
    bureaucratPrint( mark );
    mark.incrementGrade();
  } catch ( std::exception& error ) {
    errorPrint( error );
  }
  wait();

  std::cout << "=== Exception on Decrementing Too Far ===" << std::endl;
  try {
    Bureaucrat robert( "Robert", 150 );
    bureaucratPrint( robert );
    robert.decrementGrade();
  } catch ( std::exception& error ) {
    errorPrint(error);
  }
  wait();

  return 0;
}

// Format print information about a Bureaucrat
void bureaucratPrint( const Bureaucrat& a )
{
  std::cout << a << std::endl;
}

// Formated printing error
void errorPrint( const std::exception& error )
{
  std::cerr << "Caught exception: " << error.what() << std::endl;
}

// Wait between tests
void wait() {
  std::cin.ignore(10000, '\n');
}
