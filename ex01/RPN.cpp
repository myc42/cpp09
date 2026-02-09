/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:02 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/09 17:22:40 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RNP::errorHandling(std::string av)
{
     /*Expression vide → erreur.  Moins de deux nombres quand on rencontre un opérateur → erreur. 
      Reste plus d’un nombre à la fin → erreur.  Division par zéro → erreur.*/ 
    if (av.length() == 1 && std::isdigit(av[0]))
        return true;
    if (av == "+" || av == "-" || av == "*" || av == "/")
        return true;
    return false ;
}

const char *RNP::ErrorExcp::what() const throw()
{ return "Error ";};

void RNP::functionPr(std::string av)
{
     std::istringstream iss(av);
     std::string token;
     //l’opérateur d’extraction
     while (iss >> token) { 
            if(!errorHandling(token)){
                 throw ErrorExcp();
            }
               
            if(token != "+" &&   token != "-"  &&  token != "/" && token != "*" )
                  st.push(atof(token.c_str())) ;
           else{
            
            if(st.size() < 2)
                    throw ErrorExcp();
            if(token == "+" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx + firstx );
            }
             if(token == "-" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx - firstx );
            }
             if(token == "*" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx * firstx );
                 
            }
             if(token == "/" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx / firstx );
            }  
              
       }
       
        
    }
    if (!st.empty()) {
         std::cout << st.top() << std::endl;
       }
}

// cano

RNP::RNP (RNP &other)
    : st(other.st) {}

RNP &RNP::operator=( RNP &other) {
    if (this != &other) {
        st = other.st; 
    }
    return *this;
}

