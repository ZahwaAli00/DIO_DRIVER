/*
 * BIT_MATH.h
 *
 *  Created on: Sep 2, 2026
 *      Author: zahwa
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SET_BIT(var,bit) ((var)|=(1<<(bit)))
#define CLEAR_BIT(var,bit) ((var)&=(~(1<<(bit))))
#define GET_BIT(var,bit) ((var)<<(bit))&1)
#define TOGGEl_BIT(var,bit) ((var)^=(1<<(bit)))

#endif /* BIT_MATH_H_ */
