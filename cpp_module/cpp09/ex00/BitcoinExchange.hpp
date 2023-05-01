#include <iostream>
#include <vector>

class BitcoinExchange
{
    public:
        BitcoinExchange(int database);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &othter);

        // std::stream calculateExchangeRateByFile(int fd);
        // 
    
    private:
        BitcoinExchange();
        std::vector<int> date;
        std::vector<int> value;
};