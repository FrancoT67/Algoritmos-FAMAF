/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[])
{
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2)
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table;

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    /* show the table in the screen */
    table_dump(table);

    /* Función 1: menor temperatura mínima histórica */
    int min_temp = weather_min_temp(table);
    printf("Menor temperatura minima historica: %d\n", min_temp);

    /* Función 2: mayor temperatura máxima por año */
    int max_temps[YEARS];
    weather_max_temp_per_year(table, max_temps);
    printf("\nAño\tMax temp\n");
    for (unsigned int year = 0u; year < YEARS; year++)
    {
        printf("%u\t%d\n", year + FST_YEAR, max_temps[year]);
    }

    /* Función 3: mes de mayor lluvia por año */
    int max_rainfall_months[YEARS];
    weather_max_rainfall_month_per_year(table, max_rainfall_months);
    printf("\nAño\tMes max lluvia\n");
    for (unsigned int year = 0u; year < YEARS; year++)
    {
        printf("%u\t%d\n", year + FST_YEAR, max_rainfall_months[year]);
    }
    return EXIT_SUCCESS;
}
