#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "weather_table.h"

int weather_min_temp(WeatherTable a);
/**retorna la menor temperatura regsitrada */
void weather_max_temp_per_year(WeatherTable a, int output[YEARS]);
/** almacena la mayor temperatura registrada por año */
void weather_max_rainfall_month_per_year(WeatherTable a, int output[MONTHS]);
/** almacena el mes con la mayor precipitación registrada por año*/

#endif /* _WEATHER_UTILS_H */