/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:09:48 by youjeon           #+#    #+#             */
/*   Updated: 2022/09/01 00:56:43 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void)
{
	this->val_char = 0;
	this->val_int = 0;
	this->val_float = 0;
	this->val_double = 0;
	this->err = false;
}

Convert::Convert(const Convert& obj)
{
	this->val_char = obj.getChar();
	this->val_int = obj.getInt();
	this->val_float = obj.getFloat();
	this->val_double = obj.getDouble();
	this->err = obj.getErr();
	this->err = false;

}

Convert& Convert::operator=(const Convert& obj)
{
	this->val_char = obj.getChar();
	this->val_int = obj.getInt();
	this->val_float = obj.getFloat();
	this->val_double = obj.getDouble();
	this->err = obj.getErr();
	return (*this);
}

Convert::~Convert(void)
{
}

Convert::Convert(std::string s)
{
	this->val_char = 0;
	this->val_int = 0;
	this->val_float = 0;
	this->val_double = 0;
	this->err = false;
	setValue(s);
}

void Convert::setValue(std::string s)
{
	std::string::size_type n;
	std::string::size_type f;
	
	try
	{
		this->value = s;
	}
	catch(const std::bad_alloc& e)
	{
		err = true;
		return ;
	}
	
	n = s.find('.');
	f = s.find('f', s.length() - 1);
	// 특수 기호일 때
	if (value == "nan" || value == "inf" || value == "+inf" || value == "-inf" || value == "nanf" || value == "inff" || value == "+inff" || value == "-inff")
	{
		if (value == "nan" || value == "nanf")
		{
			val_double = sqrt(-1.0);
		}
		else
		{
			if (value[0] == '-')
			{
				val_double = __DBL_MAX__ * -1000;
			}
			else
			{
				val_double = __DBL_MAX__ * 1000;
			}
		}
	}
	// 문자열일 때 문자인 경우
	else if (s.length() == 1 && !std::isdigit(static_cast<char>(s[0])))
	{
		val_char = static_cast<char>(s[0]);
		val_int = static_cast<int>(val_char);
		val_float = static_cast<float>(val_char);
		val_double = static_cast<double>(val_char);
	}
	// 정수일 때(1개 짜리 문자열 포함)
	else if (n == std::string::npos)
	{
		val_int = atoi(s.c_str());

		std::stringstream ss;
		ss << val_int;
 
		if (ss.str() != value)
		{
			std::cout << "here1" << std::endl;
			// 요건 잘못된 로직인듯.. 
			// f일 때는 반드시 .이 있어야 함
			// if (val_int > 0 && f == s.length() - 1)
			// {
			// 	std::cout << "here222" << std::endl;
			// 	val_char = static_cast<char>(val_int);
			// 	val_float = static_cast<float>(val_int);
			// 	val_double = static_cast<double>(val_int);
			// }
			// else
			// {
			// 	err = true;
			// }
			err = true;
		}
		else
		{
			val_char = static_cast<char>(val_int);
			val_float = static_cast<float>(val_int);
			val_double = static_cast<double>(val_int);
		}
	}
	//더블일 또는 flaot
	else
	{
		const char *str = s.c_str();
		char *end = NULL;

		val_double = strtod(str, &end);
		
		// 남은 문자열이 있거나
		// 만약에 널 문자이면 그냥 0 false라서 넘어감
		// 마지막에 남은 게 f가 아니라면 에러 입력
		if((*end && !(*end == 'f' && end == &str[s.length() - 1])))
		{
			err = true;
		}
		else
		{
			val_int = static_cast<int>(val_double);
			val_char = static_cast<char>(val_double);
			val_float = static_cast<float>(val_double);
		}
	}	
}

char Convert::printChar(void) const
{
	std::stringstream ss;
	
	ss << val_int;
	if (err || std::isnan(val_double) || std::isinf(val_double))
		throw std::runtime_error("impossible");
	else if (val_int >= 32 && val_int <= 126)
		return (val_char);
	else if (val_int < 32 && val_int >= 0)
		throw std::runtime_error("Non displayable");
	else
		throw std::runtime_error("impossible");
}

int Convert::printInt(void) const
{
	std::stringstream ss;
	
	ss << val_int;
	if (err || std::isnan(val_double) || std::isinf(val_double))
		throw std::runtime_error("impossible");
	return (val_int);
}

float Convert::printFloat(void) const
{
	if (err)
		throw std::runtime_error("impossible");
	if (std::isnan(val_double))
		throw std::runtime_error("nanf");
	if (std::isinf(val_double) && val_double > 0)
		throw std::runtime_error("inff");
	else if (std::isinf(val_double) && val_double < 0)
		throw std::runtime_error("-inff");
	return (val_float);
}

double Convert::printDouble(void) const
{
	if (err)
		throw std::runtime_error("impossible");
	if (std::isnan(val_double))
		throw std::runtime_error("nan");
	if (std::isinf(val_double) && val_double > 0)
		throw std::runtime_error("inf");
	else if (std::isinf(val_double) && val_double < 0)
		throw std::runtime_error("-inf");
	return (val_double);	
}

char Convert::getChar(void) const
{
	return (val_char);

}

int Convert::getInt(void) const
{
	return (val_int);

}

float Convert::getFloat(void) const
{
	return (val_float);

}

double Convert::getDouble(void) const
{
	return (val_double);
	
}

bool Convert::getErr(void) const
{
	return (err);
}


std::ostream& operator<<(std::ostream &out, const Convert &b)
{
	std::stringstream ss;
	ss << b.getInt();

	try
	{
		out << "char: " << b.printChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		out << "int: " << b.printInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		if (static_cast<float>(b.getInt()) == b.getFloat())
		{
			if (ss.str().length() > 6)
			{
				out << "float: " << b.printFloat() << "f" << std::endl;
			}
			else
			{
				out << "float: " << b.printFloat() << ".0f" << std::endl;
			}
		}
		else
		{
			out << "float: " << b.printFloat() << "f" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		if (static_cast<double>(b.getInt()) == b.getDouble())
		{
			if (ss.str().length() > 6)
			{
				out << "double: " << b.printDouble() << std::endl;
			}
			else
			{
				out << "double: " << b.printDouble() << ".0" << std::endl;
			}

		}
		else
		{
			out << "double: " << b.printDouble() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (out);
}
