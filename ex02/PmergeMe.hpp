/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:16 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/07 13:49:57 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <climits>   // INT_MAX
#include <cctype> 
#include <vector>
#include <cstdlib>
#include <deque>

class IntError : public std::exception
 {
                public :
                     
                        virtual const char* what()  const throw() {
                             return "nous acceptons que des chiffres positifs en argv!";
                        };       
} ;