/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  tau_p_ = Kpi;
  tau_i_ = Kii;
  tau_d_ = Kdi;
  
  output_lim_mini_ = output_lim_mini;
  output_lim_maxi_ = output_lim_maxi;
  
  cte_ = 0;
  cte_int_ = 0;
  cte_diff_ = 0;
  cte_prev_ = 0;
  
  dt_ = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  
  cte_ = cte;
  cte_diff_ = cte - cte_prev_/dt_;
  cte_int_ = cte*dt_; 
  cte_prev_ = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
  
  	control = (tau_p_ * cte_) - (tau_d_ * cte_diff_) - (tau_i_ * cte_int_);
  
  
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  dt_ = new_delta_time;
}