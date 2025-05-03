
#ifndef UTIL_H_
#define UTIL_H_

#define SET_BIT(x,b) (x |=(1<<b))
#define TOG_BIT(x,b) (x=x^(1<<b))
#define CLR_BIT(x,b) (x=x&~(1<<b))
#define GET_BIT(x,b) ((x>>b) & 1)


#endif /* UTIL_H_ */