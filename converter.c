/*
 * Converter: By Dallas Foster, 251287541
 *
 * The purpose of this program is to create a simple converter
 * that allows the user to convert values between different units,
 * such as kilograms and pounds, hectares and acres, liters and gallons,
 * or kilometers and miles. The program will ask the user to choose the
 * conversion type and direction, and then input a numeric value for conversion.
 * After performing the conversion, it will display the result and return to the
 * main menu.
 */

#include <stdio.h>

// Define arrays for conversion rates and conversion type descriptions
float conversionRates[] = {2.20462, 2.47105, .264172, .621371};
char * metricToImperial[] = {"K for Kilograms to Pounds", "H for Hectares to Acres", "L for Litres to Gallons", "K for Kilometres to Miles"};
char * imperialToMetric[] = {"P for Pounds to Kilograms", "A for Acres to Hectares", "G for Gallons to Litres", "M for Miles to Kilometres"};

float getConversionRate(int conversionType, int conversionDirection);
int getConversionDirection (char allowedMetric, char allowedImperial);

int main() {
    int conversionType;
    int conversionDirection; // 0 = Metric-> Imperial, 1 = Imperial->Metric
    float conversionRate;

    do {

        // Set the selection types
        printf("1 - Convert Kilograms and Pounds.\n");
        printf("2 - Convert Hectares and Acres.\n");
        printf("3 - Convert Litres and Gallons.\n");
        printf("4 - Convert Kilometres and Miles.\n");
        printf("5 - Quit\n");
        printf("Please enter 1-5 for the type of conversion you would like to perform:\n");

        // Use scanf to attempt reading an integer
        scanf(" %d", &conversionType);

        if (conversionType >=1 && conversionType <=4) {
            // Print the conversion type descriptions
            printf("%s\n", metricToImperial[conversionType-1]);
            printf("%s\n", imperialToMetric[conversionType-1]);

            // Determine the conversion direction
            conversionDirection = getConversionDirection(metricToImperial[conversionType-1][0], imperialToMetric[conversionType-1][0]);

            // Get the conversion rate
            conversionRate = getConversionRate(conversionType, conversionDirection);

            float conversionValue;
            printf("Please enter a value to convert:\n");
            // Read the value to convert
            scanf(" %f", &conversionValue);
            // Perform the conversion and display the result
            printf("Your conversion is: %f\n", conversionRate * conversionValue);
        }
    } while (conversionType != 5);

}

// Function to get the conversion direction
int getConversionDirection (char allowedMetric, char allowedImperial) {
    char conversionDirection;
    int showError = 0;
    do {
        if (showError == 0) {
            printf("Please enter a valid value (%c or %c)\n", allowedMetric, allowedImperial);
        } else {
            printf("Please enter the direction of the conversion you want (%c or %c):\n", allowedMetric, allowedImperial);
        }
        // Read the conversion direction character
        scanf(" %c", &conversionDirection);

        if (allowedMetric == conversionDirection) {
            return 0; // Metric to Imperial
        }
        if (allowedImperial == conversionDirection) {
            return 1; // Imperial to Metric
        }
        showError++;
    } while (1==1); // This loop continues until a valid direction is entered

}

// Function to get the conversion rate
float getConversionRate(int conversionType, int conversionDirection) {
    float rate = conversionRates[conversionType - 1];
    if (conversionDirection == 0) {
        return rate; // Metric to Imperial
    } else {
        return 1/rate; // Imperial to Metric
    }
}

