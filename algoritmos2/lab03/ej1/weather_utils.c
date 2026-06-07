#include <stdio.h>
#include "weather_utils.h"

/** Funcion 1
 *
 * Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba según los datos del arreglo
 *
 */
int weather_min_temp(WeatherTable a)
{
    int min_temperature = a[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year)
    {
        for (month_t month = january; month <= december; ++month)
        {
            for (unsigned int day = 0u; day < DAYS; ++day)
            {
                if (a[year][month][day]._min_temp < min_temperature)
                {
                    min_temperature = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return min_temperature;
}

/** Funcion 2
 * Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura máxima registrada durante ese año
 *
 */
void weather_max_temp_per_year(WeatherTable a, int output[YEARS])
{
    for (unsigned int year = 0u; year < YEARS; ++year)
    {
        int max_temperature = a[year][0][0]._max_temp;
        for (month_t month = january; month <= december; ++month)
        {
            for (unsigned int day = 0u; day < DAYS; ++day)
            {
                if (a[year][month][day]._max_temp > max_temperature)
                {
                    max_temperature = a[year][month][day]._max_temp;
                }
            }
        }
        output[year] = max_temperature;
    }
}

/** Funcion 3
 * Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones (campo rainfall)
 *
 */
int sum_rainfall_per_month(WeatherTable a, unsigned int year, month_t month)
{
    unsigned int sum = 0;
    for (unsigned int day = 0u; day < DAYS; ++day)
    {
        sum += a[year][month][day]._rainfall;
    }

    return sum;
}

void weather_max_rainfall_month_per_year(WeatherTable a, int output[MONTHS])
{
    for (unsigned int year = 0u; year < YEARS; year++)
    {
        unsigned int max_sum = sum_rainfall_per_month(a, year, january);
        month_t max_month = january;
        for (month_t month = february; month < december; month++)
        {
            unsigned int sum = sum_rainfall_per_month(a, year, month);
            if (sum > max_sum)
            {
                max_sum = sum;
                max_month = month;
            }
        }
        output[year] = max_month + 1;
    }
}
