#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    setSigned(other.getIsSigned());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkFormStatus(executor);

	std::ofstream fout;
	std::string fileName = getName() + "_shrubbery";

	fout.open(fileName);
	if (fout.is_open() == false)
	{
        std::cout << "Can't open " << fileName << " Please check your input" << std::endl;
        return ;
	}
	
	std::string tree = 
"         _-_\n\
       ~~     ~~\n\
     ~~         ~~\n\
    {              }\n\
    /  _-     -_  /\n\
      ~  \\ //  ~\n\
    _- -   | | _- _\n\
    _ -  | |   -_\n\
         // \\\\ \n\
";

	fout << tree;
	fout.close();

	//std::cout << "make " << outfile << " done." << std::endl;
}