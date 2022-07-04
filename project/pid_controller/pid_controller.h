/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/

    /*
    * Errors
    */
  	double cte_; // for p
  	double cte_int_; // for i
  	double cte_diff_; // for d
  	double cte_prev_;
  	

    /*
    * Coefficients
    */
  	double tau_p_;
  	double tau_i_;
  	double tau_d_;

    /*
    * Output limits
    */
  	double output_lim_mini_;
  	double output_lim_maxi_;
  
    /*
    * Delta time
    */
  	double dt_;

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


