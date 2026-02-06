/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:51 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/06 14:54:50 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



void reorgDateAndValue(const std::string& line,
                       std::map<std::string, double>& btc)
{
    size_t pos = line.find(',');
     if (pos == std::string::npos)
        return;
    std::string date = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    date.erase(date.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
   // std::cout << "Insert: [" << date << "] = " << value << std::endl;
    btc[date] = atof(value.c_str());
    
}

int main(int ac, char **av)
{
     std::map<std::string, double> btcBD ; 
     std::string line;
     double value ;
    
   
    
    try {
        if (ac != 2) {
            std::cerr << "ERROR: only one argument accepted\n";
            return 1;
        }

        std::ifstream fd("data.csv");
        if (!fd)
            throw CantNotOpenFile();
        std::getline(fd, line);
        while (std::getline(fd, line))
        {
            
            if (line.empty())
                continue;
            reorgDateAndValue(line, btcBD);
        }
       
        std::ifstream inputfd(av[1]);
        if (!inputfd)
            throw CantNotOpenFile();
        std::getline(inputfd, line);
         
        while (std::getline(inputfd, line))
        {
           
            if (line.empty())
                continue;
            size_t pos = line.find('|');
            if (pos == std::string::npos)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            std::string dateStr = line.substr(0, pos);
            std::string valueStr = line.substr(pos + 1);
            dateStr.erase(dateStr.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            value =  atof(valueStr.c_str()); 
          
            if (value <= 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            } else if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            /*itérateur pointant sur la première clé qui n’est pas inférieure à key. Si la clé exacte n’existe pas, elle pointe sur la prochaine clé supérieure. Si toutes les clés sont inférieures à key, elle retourne btcBD.end().*/
            
             std::map<std::string, double>::iterator it = btcBD.lower_bound(dateStr);
            if (it == btcBD.end() || it->first != dateStr)
            {
                if (it == btcBD.begin())  //La clé recherchée est inférieure ou égale à la plus petite clé.
                {
                     std::cerr << "Error: date too early." << std::endl;
                    continue;
                }
                else 
                {
                    --it; // date la plus proche inférieure
                }
            }
            //it->second la valeur associée à cette clé
            double Valresult = value * it->second ;
            std::cout << dateStr << " => " << value << " = " << Valresult << std::endl;
        }
      
        

        
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}