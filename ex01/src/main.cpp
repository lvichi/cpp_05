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
#include "Form.hpp"

void bureaucraftPrint(const Bureaucrat& a);
void errorPrint(const std::exception& error);
void wait();
void formPrint(const Form& form);

int main() {
  std::cout << "\n=== Form Construction ===" << std::endl;
  Form form_a("A", 50, 100);
  formPrint(form_a);
  wait();

  std::cout << "=== Form Copy and Assignment ===" << std::endl;
  Form form_b = form_a;
  Form form_c("C", 100, 150);
  form_c = form_a;
  formPrint(form_b);
  formPrint(form_c);
  wait();

  std::cout << "=== Exception on Form Grade Too High ===" << std::endl;
  try {
    Form form_d("D", 0, 100);
  } catch (std::exception& error) {
    errorPrint(error);
  }
  wait();

  std::cout << "=== Exception on Form Grade Too Low ===" << std::endl;
  try {
    Form form_e("E", 100, 200);
  } catch (std::exception& error) {
    errorPrint(error);
  }
  wait();

  std::cout << "=== Form Sign Success ===" << std::endl;
  Bureaucrat bob("Bob", 40);
  bureaucraftPrint(bob);
  Form form_f("F", 50, 120);
  formPrint(form_f);
  bob.signForm(form_f);
  formPrint(form_f);
  wait();

  std::cout << "=== Form Sign Fail (Grade too low) ===" << std::endl;
  Bureaucrat tom("Tom", 100);
  bureaucraftPrint(tom);
  Form form_g("G", 50, 120);
  formPrint(form_g);
  tom.signForm(form_g);
  formPrint(form_g);
  wait();

  std::cout << "=== Form Sign Fail (Already signed) ===" << std::endl;
  Bureaucrat greg("Greg", 40);
  bureaucraftPrint(greg);
  Form form_h("H", 50, 120);
  formPrint(form_h);
  greg.signForm(form_h);
  formPrint(form_h);
  Bureaucrat kelly("Kelly", 20);
  bureaucraftPrint(kelly);
  kelly.signForm(form_h);
  wait();

  return 0;
}

void bureaucraftPrint(const Bureaucrat& a)
{
  std::cout << a << std::endl;
}

void errorPrint(const std::exception& error)
{
  std::cerr << "Caught exception: " << error.what();
  std::cerr << std::endl;
}

void formPrint(const Form& form)
{
  std::cout << form << std::endl;
}

void wait() {
  std::cin.ignore(10000, '\n');
}

