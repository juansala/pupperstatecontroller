#ifndef IK_H
#define IK_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

enum SolutionFlag{
	UNDEFINED, 
	SINGULARITY_1, // 2R arm is fully stretched.
	TARGET_ON_L1,
	SINGULARITY_2, // 2R arm is folded onto itself (target = origin).
	TWO_SOLUTIONS
};

SolutionFlag two_r_manip_ik(double x_target, double y_target, double L1, 
                            double L2, double sol[]);

double compute_three_r_heading(double q2, double q3, double L1, double L2, 
                               double L3, double x_target, double y_target, 
                               bool direction);

SolutionFlag three_r_manip_ik(double x_target, double y_target, double z_target, 
                              double L1, double L2, double L3, bool dir, 
                              double sol[]);

int leg_ik();

#endif