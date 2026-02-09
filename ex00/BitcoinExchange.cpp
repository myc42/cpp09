/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:46 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/09 19:38:36 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include <iomanip>

Btc::Btc():value(0){};

Btc::~Btc() {
    _fd.close();
    _inputfd.close();
}
const char *Btc::CantNotOpenFile::what() const throw()
{
    return "Cant not open file !";};  
     
void Btc::reorgDB(const std::string& line)
{
    size_t pos = line.find(',');
     if (pos == std::string::npos)
        return;
    std::string date = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    date.erase(date.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
   // std::cout << "Insert: [" << date << "] = " << value << std::endl;
    btcBD[date] = atof(value.c_str());
    
}

 void Btc::OpenDb(const std::string& val)
 {
    
        _fd.open(val.c_str());
        if (!_fd)
            throw CantNotOpenFile();
        std::getline(_fd, line);
        while (std::getline(_fd, line))
        {
            
            if (line.empty())
                continue;
            reorgDB(line);
        }
 }

  void Btc::CompareDb(const std::string& val)
  {
        _inputfd.open(val.c_str());
          if (!_inputfd)
            throw CantNotOpenFile();
        std::getline(_inputfd, line);
         
        while (std::getline(_inputfd, line))
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
            //lexicographique
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
            double Valresult = (value * it->second );
            std::cout << dateStr << " => " << value << " = " <<std::fixed <<  std::setprecision(2) << Valresult << std::endl;
        }
  }

Btc::Btc( Btc &other) : btcBD(other.btcBD) , line(other.line) ,value(other.value)
{
    
}

 Btc &Btc::operator=( Btc &other)
 {
    if (this != &other) {
      btcBD = other.btcBD;
      line = other.line ;
      value = other.value;
    }
    return *this;
}


