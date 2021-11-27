using System;
using System.Collections.Generic;
using System.Text;

bool  TryFixData(uint* usersPerDay, size_t users, double* revenuePerDay, size_t revenues)
{
	if (users != revenues)
    {
		return false;
    }

    int fixDataCount = 0;
    double revenue = 0;

    for (int i = 0; i < users; i++)
   	{

 		if (*usersPerDay > 1000)
        {
			revenue = Math.Round(245743 + (double)usersPerDay[i] / 4, 2);
        }
        else if (*usersPerDay > 100)
        {
            revenue = Math.Round((double)usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007, 2);
        }
        else if (*usersPerDay > 10)
        {
            revenue = Math.Round(16 * (double)usersPerDay[i] / 5 - 27, 2);
        }
        else
        {
            revenue = Math.Round((double)usersPerDay[i] / 2, 2);
        }

        if (revenuePerDay[i] != revenue)
        {
			fixDataCount++;
            revenuePerDay[i] = revenue;
        }
	}

    return fixDataCount > 0;            
}

        public static int GetInvalidEntryCount(uint[] usersPerDay, double[] revenuePerDay)
        {
            if (usersPerDay.Length != revenuePerDay.Length)
            {
                return -1;
            }

            int fixDataCount = 0;
            double revenue = 0;

            for (int i = 0; i < usersPerDay.Length; i++)
            {

                if (usersPerDay[i] > 1000)
                {
                    revenue = Math.Round(245743 + (double)usersPerDay[i] / 4, 2);
                }
                else if (usersPerDay[i] > 100)
                {
                    revenue = Math.Round((double)usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007, 2);
                }
                else if (usersPerDay[i] > 10)
                {
                    revenue = Math.Round(16 * (double)usersPerDay[i] / 5 - 27, 2);
                }
                else
                {
                    revenue = Math.Round((double)usersPerDay[i] / 2, 2);
                }

                if (revenuePerDay[i] != revenue)
                {
                    fixDataCount++;
                }
            }

            return fixDataCount;
        }

        public static double CalculateTotalRevenue(double[] revenuePerDay, uint start, uint end)
        {
            
            if (revenuePerDay.Length == 0 || start > end || end >= revenuePerDay.Length)
            {
                return -1;
            }

            double revenueLangeTotal = 0;

            for (uint i = start; i <= end; i++)
            {
                revenueLangeTotal += revenuePerDay[i];
            }

            return revenueLangeTotal;
        }
    }
}
