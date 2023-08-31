/**
 * File : 01229749125_Task1_4.c
 * Author : Youssef Ahmed Kamle Ali
 * Description : this is Kalman Missile program
 * Date : [13/8/2023]
*/

/* Header files */
#include <iostream>
using namespace std;

/* functions Declaratoins */
/**
 * @brief this is a function that calulates the fair array
 * 
 * @param the first parameter is an array that has the data of the first sensor
 * @param the second parameter is an array that has the data of the second sensor
 * @return it returns the address of the fused array 
*/
float* calculate_fair(float sensor1[], float sensor2[]);

/**
 * @brief this is a function that calulates the good array
 * 
 * @param the first parameter is an array that has the data of the first sensor
 * @param the second parameter is an array that has the data of the second sensor
 * @param the third parameter is the accuracy percentage of the first sensor
 * @param the fourth parameter is the accuracy percentage of the fourth sensor
 * @return it returns the address of the fused array 
*/
float *calculate_good(float sensor1[], float sensor2[], float accur1,float accur2);

/* main function */
int main()
{
    /* Sensors data */
    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};


    /* Sensor accuracies (expressed as percentages) */
    float accuracy_mpu6050 = 0.79;
    float accuracy_bno55 = 0.92;
    
    /* calculating the Fair array */
    float *Fair = calculate_fair(mpu6050, bno55);

    /* calculating the fused array (Good) using kalman filter*/
    float *Good = calculate_good(mpu6050, bno55, accuracy_mpu6050, accuracy_bno55);
    
    /* Reading the Fair array */
    cout << "Here is the fair array:\n";
    for (int i = 0; i < 10; i++)
        cout << Fair[i] << endl;
    
    cout << "\n";

    /* Reading the Good array */
    cout << "Here is the good array:\n";
    for (int i = 0; i < 10; i++)
        cout << Good[i] << endl;

    /* deallocate the memory */
    delete[] Fair;
    delete[] Good;

    return (0);
}


/* functions Definitions */
/**
 * @brief this is a function that calulates the fair array which is the average of sensors
 *  
 * @param the first parameter is an array that has the data of the first sensor
 * @param the second parameter is an array that has the data of the second sensor
 * @return it returns the address of the fused array 
*/
float *calculate_fair(float sensor1[], float sensor2[])
{
    float *fused_array = new float[10];
    /* Generate the fused array */
    for (int i = 0; i < 10; i++){ 
        fused_array[i] = (sensor1[i] + sensor2[i]) / 2;
    }
    return (fused_array);
}

/**
 * @brief this is a function that calulates the fused array which is more accuracy 
 * than the fair array because i used the two accuricies of the two sensors to calculate 
 * weights and i used it to output better readings 
 *  
 * @param the first parameter is an array that has the data of the first sensor
 * @param the second parameter is an array that has the data of the second sensor
 * @param the third parameter is the accuracy percentage of the first sensor
 * @param the fourth parameter is the accuracy percentage of the fourth sensor
 * @return it returns the address of the fused array 
*/
float *calculate_good(float sensor1[], float sensor2[], float accur1,float accur2)
{
    float *fused_array = new float[10];
    // Calculate weights based on accuracies
    float weight1 = accur1 / (accur1 + accur2);
    float weight2 = accur2/ (accur1+ accur2);
    /* Generate the fused array using weighted average*/
    for (int i = 0; i < 10; ++i) {
        fused_array[i] = weight1 * sensor1[i] + weight2 * sensor2[i];
    }
    return (fused_array);
}