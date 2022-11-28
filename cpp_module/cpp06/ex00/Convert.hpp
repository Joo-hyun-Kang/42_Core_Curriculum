#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cmath>
# include <sstream>
# include <limits>

class Convert {
 private:
	std::string value;
	char	val_char;
	int		val_int;
	float	val_float;
	double	val_double;
	bool	err;
 public:
	Convert(void);
	Convert(const Convert& obj);
	Convert& operator=(const Convert& obj);
	~Convert(void);
	Convert(std::string s);
	void setValue(std::string s);
	char getChar(void) const;
	int getInt(void) const;
	float getFloat(void) const;
	double getDouble(void) const;
	bool getErr(void) const;
	char printChar(void) const;
	int printInt(void) const;
	float printFloat(void) const;
	double printDouble(void) const;
};

std::ostream& operator<<(std::ostream &out, const Convert &b);

#endif
